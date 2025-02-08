#include "employee.h"
//#include "funcs.h"

Employee::Employee()
{
    name_group = "New name";
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

    button_add_emp = other.button_add_emp;
    button_delete_emp = other.button_delete_emp;
    button_add_pay = other.button_add_pay;

    item_name = other.item_name;
    item_total_pays = other.item_total_pays;

    item_name_emp = other.item_name_emp;
    item_total_pays_emp = other.item_total_pays_emp;

    other.tablet_list_tasks = nullptr;
    other.tablet_list_employees = nullptr;

    other.button_add_emp = nullptr;
    other.button_delete_emp = nullptr;
    other.button_add_pay = nullptr;

    other.item_name = nullptr;
    other.item_total_pays = nullptr;

    other.item_name_emp = nullptr;
    other.item_total_pays_emp = nullptr;
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

    QList<QTableWidgetItem*> *list_tmp = new QList<QTableWidgetItem*>(tablet_list_employees->columnCount());
    list_employees.push_back(*list_tmp);

    for(int i = 0; i < tablet_list_employees->columnCount(); ++i)
    {
        list_employees.back()[i] = new QTableWidgetItem();
        if(i != 0)
        {
            list_employees.back()[i]->setText("0");
            list_employees.back()[i]->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        }

        tablet_list_employees->setItem(row, i, list_employees.back()[i]);
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
    int col = tablet_list_tasks->columnCount();
    tablet_list_tasks->insertColumn(col);

    int i = 0;
    for(auto beg = list_tasks.begin(); beg != list_tasks.end(); ++beg, ++i)
    {
        tablet_list_tasks->setHorizontalHeaderItem(col, new QTableWidgetItem(QString::number(col)));

        QTableWidgetItem* tmp = new QTableWidgetItem();

        tmp->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        //tmp->setText("add_" + QString::number(i));
        beg->push_back(tmp);

        tablet_list_tasks->setItem(i, col, beg->back());
        tablet_list_tasks->setColumnWidth(col, tablet_list_tasks->columnWidth(1));
    }
}

void Employee::new_obj()
{
    tablet_list_tasks = new QTableWidget();
    tablet_list_employees = new QTableWidget();

    item_name = new QTableWidgetItem(name_group);
    item_total_pays = new QTableWidgetItem("0");

    button_add_emp = new QPushButton();
    button_delete_emp = new QPushButton();
    button_add_pay = new QPushButton();

    item_name_emp = new QTableWidgetItem(name_group);
    item_total_pays_emp = new QTableWidgetItem("0");

    item_total_pays->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
    item_total_pays_emp->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
}

void Employee::clear_mem()
{
    delete_mem();

    tablet_list_tasks = nullptr;
    tablet_list_employees = nullptr;

    button_add_emp = nullptr;
    button_delete_emp = nullptr;
    button_add_pay = nullptr;

    item_name = nullptr;
    item_total_pays = nullptr;

    item_name_emp = nullptr;
    item_total_pays_emp = nullptr;
}

void Employee::delete_mem()
{
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

    delete tablet_list_tasks;
    delete tablet_list_employees;

    delete button_add_emp;
    delete button_delete_emp;
    delete button_add_pay;

    delete item_name;
    delete item_total_pays;

    delete item_name_emp;
    delete item_total_pays_emp;
}
