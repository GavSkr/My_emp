#include "employee.h"
//#include "funcs.h"

Employee::Employee()
{
    name_group = "New group name";
    //last_name = "last_name";

    new_obj();
}

Employee::Employee(QString full_name)
{
    //adding_funcs::separate_name(full_name, name, last_name);
    name_group = full_name;
}

Employee::~Employee()
{
    clear_mem();
}

Employee::Employee(const Employee &other) // copy
{
    name_group = other.name_group;
    //last_name = other.last_name;
    qInfo() << "Employee::Employee(const Employee &other): coping ...";
    clear_mem();
    new_obj();
}

Employee::Employee(Employee &&other) // r-value
{
    name_group = other.name_group;
    //last_name = other.last_name;

    delete_mem();

    list_tasks = other.list_tasks;
    tablet_list_tasks = other.tablet_list_tasks;

    list_employees = other.list_employees;
    tablet_list_employees = other.tablet_list_employees;

    list_pay = other.list_pay;
    tablet_list_pay = other.tablet_list_pay;

    button_add_emp = other.button_add_emp;
    button_delete_emp = other.button_delete_emp;
    button_add_pay = other.button_add_pay;

    item_group_name = other.item_group_name;
    item_group_total_pays = other.item_group_total_pays;

    other.tablet_list_tasks = nullptr;
    other.tablet_list_employees = nullptr;
    other.tablet_list_pay = nullptr;

    other.button_add_emp = nullptr;
    other.button_delete_emp = nullptr;
    other.button_add_pay = nullptr;

    other.item_group_name = nullptr;
    other.item_group_total_pays = nullptr;
}

QString Employee::get_full_name()
{
    return name_group;
}

void Employee::set_name(QString full_name)
{
    //adding_funcs::separate_name(full_name, name, last_name);
    name_group = full_name;
}

void Employee::add_employee()
{
    auto row = tablet_list_employees->rowCount();
    tablet_list_employees->insertRow(row);

    std::list<QTableWidgetItem*> *list_tmp = new std::list<QTableWidgetItem*>(tablet_list_employees->columnCount());
    list_employees.push_back(*list_tmp);

    int col = 0;
    for(auto beg = list_employees.back().begin(); beg != list_employees.back().end(); ++beg, ++col)
    {
        *beg = new QTableWidgetItem();
        if(col != 0)
        {
            (*beg)->setText("0");
            (*beg)->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        }

        tablet_list_employees->setItem(row, col, *beg);
        //qInfo() << "Add item in table " << i;
    }

    delete list_tmp;
    list_tmp = nullptr;

    if(tablet_list_employees->columnCount() > 0) button_delete_emp->setEnabled(true);
}

void Employee::delete_employee()
{
    int row = tablet_list_employees->currentRow();

    auto beg = list_employees.begin();
    //qInfo() << "list_adding_works beg.size() = "<< beg->size();

    for(int i = 0; beg != list_employees.end(); beg++, ++i)
    {
        if(i == row)
        {
            while(!beg->empty())
            {
                delete beg->back();
                beg->back() = nullptr;
                beg->pop_back();
            }
            list_employees.erase(beg);

            tablet_list_employees->removeRow(row);
            break;
        }
    }

    if(tablet_list_employees->columnCount() <= 0) button_delete_emp->setEnabled(false);
}

void Employee::add_pay()
{
    if(list_tasks.empty()) return;

    int col = tablet_list_tasks->columnCount();
    tablet_list_tasks->insertColumn(col);
    tablet_list_pay->insertColumn(col);

    int row = 0;
    for(auto beg = list_tasks.begin(); beg != list_tasks.end(); ++beg, ++row)
    {
        tablet_list_tasks->setHorizontalHeaderItem(col, new QTableWidgetItem(QString::number(col)));

        QTableWidgetItem* tmp_tasks = new QTableWidgetItem();

        tmp_tasks->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        //tmp->setText("add_" + QString::number(i));
        beg->push_back(tmp_tasks);

        tablet_list_tasks->setItem(row, col, beg->back());
        tablet_list_tasks->setColumnWidth(col, tablet_list_tasks->columnWidth(1));
    }

    row = 0;
    for(auto beg = list_pay.begin(); beg != list_pay.end(); ++beg, ++row)
    {
        tablet_list_pay->setHorizontalHeaderItem(col, new QTableWidgetItem(QString::number(col)));

        QTableWidgetItem* tmp_pay = new QTableWidgetItem();

        tmp_pay->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        //tmp->setText("add_" + QString::number(i));
        beg->push_back(tmp_pay);

        tablet_list_pay->setItem(row, col, beg->back());
        tablet_list_pay->setColumnWidth(col, tablet_list_tasks->columnWidth(1));

        calendar.push_back(new QDateEdit());
        calendar.back()->setCalendarPopup(true);
        calendar.back()->setDate(QDate::currentDate());
        tablet_list_pay->setCellWidget(0, col, calendar.back());
    }
}

void Employee::fill_done_tasks()
{
    done_taks.clear();
    for(int i = 0; i < tablet_list_tasks->rowCount(); ++i)
    {
        done_taks.push_back(0);
        for(int j = 1; j < tablet_list_tasks->columnCount(); ++j)
        {
            done_taks.back() += tablet_list_tasks->item(i, j)->text().toInt();
        }
    }
}

QList<int> Employee::get_done_tasks()
{
    return done_taks;
}

void Employee::new_obj()
{
    tablet_list_tasks = new QTableWidget();
    tablet_list_employees = new QTableWidget();
    tablet_list_pay = new QTableWidget();

    item_group_name = new QTableWidgetItem(name_group);
    item_group_total_pays = new QTableWidgetItem("0");

    button_add_emp = new QPushButton();
    button_delete_emp = new QPushButton();
    button_add_pay = new QPushButton();

    item_group_total_pays->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
}

void Employee::clear_mem()
{
    delete_mem();

    tablet_list_tasks = nullptr;
    tablet_list_employees = nullptr;
    tablet_list_pay = nullptr;

    button_add_emp = nullptr;
    button_delete_emp = nullptr;
    button_add_pay = nullptr;

    item_group_name = nullptr;
    item_group_total_pays = nullptr;
}

void Employee::delete_mem()
{
    qInfo() << "Employee::delete_mem(): starting ... ";

    for(auto beg = list_employees.begin(); beg !=list_employees.end(); beg++)
    {
        while(!beg->empty())
        {
            delete beg->back();
            beg->back() = nullptr;
            beg->pop_back();
            qInfo() << "delete item from LIST_EMPLOYEES";
        }
    }

    while(!calendar.empty())
    {
        qDebug() << "Employee::delete_mem(): calendar.size()" << calendar.size();
        qDebug() << "Employee::delete_mem(): calendar.back()" << calendar.back()->date();
        delete calendar.back();
        calendar.back() = nullptr;
        calendar.pop_front();
    }

    for(auto beg = list_pay.begin(); beg !=list_pay.end(); beg++)
    {
        while(!beg->empty())
        {
            delete beg->back();
            beg->back() = nullptr;
            beg->pop_back();
            qInfo() << "delete item from LIST_PAY";
        }
    }

    for(auto beg = list_tasks.begin(); beg !=list_tasks.end(); beg++)
    {
        while(!beg->empty())
        {
            delete beg->back();
            beg->back() = nullptr;
            beg->pop_back();
            qInfo() << "delete item from LIST_TASKS";
        }
    }

    delete tablet_list_employees;
    delete tablet_list_pay;
    delete tablet_list_tasks;

    delete button_add_emp;
    delete button_delete_emp;
    delete button_add_pay;

    delete item_group_name;
    delete item_group_total_pays;
}

void Employee::fill_tablet_list_pay()
{
    int row_t = name_pay.size();
    int col_t = 2;

    //qInfo() << "Count row " << row << " - Count column" << tablet_adding_work->columnCount();

    tablet_list_pay->setRowCount(row_t);
    tablet_list_pay->setColumnCount(col_t);

    for(int row_i = 0; row_i < row_t; ++row_i)
    {

        std::list<QTableWidgetItem*> *qlist_tmp_t = new std::list<QTableWidgetItem*>(tablet_list_pay->columnCount());

        //qInfo() << "Size list_tmp " << list_tmp->size();

        list_pay.push_back(*qlist_tmp_t);

        //qInfo() << "obj->name " << tablet_adding_work->objectName();

        int col = 0;

        for(auto item = list_pay.back().begin(); item != list_pay.back().end(); item++, ++col)
        {
            *item = new QTableWidgetItem();
            if(col == 0)
            {
                (*item)->setText(name_pay[row_i]);
                (*item)->setFlags(Qt::ItemIsEnabled);
            }
            else if(col == 1 && row_i == 0)
            {
                //delete *item;
                //*item = nullptr;
                QDateEdit* it = new QDateEdit(QDate::currentDate());
                if(it)
                {
                    calendar.push_back(it);
                    calendar.back()->setCalendarPopup(true);
                    //calendar.back()->setDate(QDate::currentDate());
                    tablet_list_pay->setCellWidget(row_i, col, calendar.back());
                    continue;
                }
                else
                    qDebug() << "Employee::fill_tablet_list_pay(): QDateEdit = nullptr"  ;
            }
            else
            {
                (*item)->setText("");
                (*item)->setTextAlignment(Qt::AlignCenter);
            }
            tablet_list_pay->setItem(row_i, col, *item);
            //qInfo() << "Add item in table " << i;
        }

        delete qlist_tmp_t;
        qlist_tmp_t = nullptr;
    }
}
