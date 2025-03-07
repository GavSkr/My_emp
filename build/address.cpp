#include "address.h"

Address::Address()
{
    name = "Новый";
    address = "Якутск";

    new_obj();
}

Address::Address(QString i_name)
{
    name = i_name;
    address = "";

    new_obj();
}

Address::Address(QString i_name, QString i_address)
{
    name = i_name;
    address = i_address;

    new_obj();
}

Address::~Address()
{
    clear_mem();
}

Address::Address(const Address &other) // copy
{
    qDebug() << "Address::Address(Address &&other) copy ...";
    name = other.name;
    address = other.address;

    clear_mem();
    new_obj();
}

Address::Address(Address &&other) // r-value
{
    qDebug() << "Address::Address(Address &&other) r-value ...";
    name = other.name;
    address = other.address;

    delete_mem();

    tab_page = other.tab_page;
    btn_page = other.btn_page;
    list_adding_works = other.list_adding_works;
    list_works = other.list_works;

    page1 = other.page1;
    //{====================================
    button_add_emp = other.button_add_emp;
    button_delete_emp = other.button_delete_emp;
    tablet_list_groups = other.tablet_list_groups;
    //tablet_pay_groups = other.tablet_pay_groups;
    //====================================}

    page2 = other.page2;
    //{====================================
    name_obj = other.name_obj;
    name_str = other.name_str;
    adr_obj = other.adr_obj;
    adr_str = other.adr_str;
    developer_obj = other.developer_obj;
    developer_str = other.developer_str;
    //************************************
    floors = other.floors;
    floors_cnt = other.floors_cnt;
    entrances = other.entrances;
    entrances_cnt = other.entrances_cnt;
    apartments = other.apartments;
    apartments_cnt = other.apartments_cnt;
    first_floor_lived = other.first_floor_lived;
    apartments_on_1fl = other.apartments_on_1fl;
    apartments_on_1fl_cnt = other.apartments_on_1fl_cnt;
    apartments_total = other.apartments_total;
    apartments_total_cnt = other.apartments_total_cnt;
    //************************************
    budget = other.budget;
    budget_str_cnt = other.budget_str_cnt;
    budget_executed = other.budget_executed;
    budget_executed_str_cnt = other.budget_executed_str_cnt;
    budget_remains = other.budget_remains;
    budget_remains_str_cnt = other.budget_remains_str_cnt;
    //************************************
    price_for_apartment = other.price_for_apartment;
    first_stage_ap = other.first_stage_ap;
    first_stage_ap_str_cnt = other.first_stage_ap_str_cnt;
    second_stage_ap = other.second_stage_ap;
    second_stage_ap_str_cnt = other.second_stage_ap_str_cnt;
    total_price_ap = other.total_price_ap;
    total_price_ap_str_cnt = other.total_price_ap_str_cnt;
    //************************************
    price_for_entrance = other.price_for_entrance;
    first_stage_ent = other.first_stage_ent;
    first_stage_ent_str_cnt = other.first_stage_ent_str_cnt;
    second_stage_ent = other.second_stage_ent;
    second_stage_ent_str_cnt = other.second_stage_ent_str_cnt;
    total_price_ent = other.total_price_ent;
    total_price_ent_str_cnt = other.total_price_ent_str_cnt;
    //************************************
    adding_work = other.adding_work;
    tablet_adding_work = other.tablet_adding_work;
    add_row = other.add_row;
    delete_row = other.delete_row;
    //************************************
    total_work = other.total_work;
    tablet_total_work = other.tablet_total_work;
    //************************************
    budget_auto = other.budget_auto;
    budget_cnt_auto = other.budget_cnt_auto;
    budget_executed_auto = other.budget_executed_auto;
    budget_executed_cnt_auto = other.budget_executed_cnt_auto;
    budget_remains_auto = other.budget_remains_auto;
    budget_remains_cnt_auto = other.budget_remains_cnt_auto;
    //====================================}

    other.btn_page = nullptr;


    //{====================================
    other.button_add_emp = nullptr;
    other.button_delete_emp = nullptr;
    other.tablet_list_groups = nullptr;
    //other.tablet_pay_groups = nullptr;
    //====================================}

    //{====================================
    other.name_obj = nullptr;
    other.name_str = nullptr;
    other.adr_obj = nullptr;
    other.adr_str = nullptr;
    other.developer_obj = nullptr;
    other.developer_str = nullptr;
    //************************************
    other.floors = nullptr;
    other.floors_cnt = nullptr;
    other.entrances = nullptr;
    other.entrances_cnt = nullptr;
    other.apartments = nullptr;
    other.apartments_cnt = nullptr;
    other.first_floor_lived = nullptr;
    other.apartments_on_1fl = nullptr;
    other.apartments_on_1fl_cnt = nullptr;
    other.apartments_total = nullptr;
    other.apartments_total_cnt = nullptr;
    //************************************
    other.budget = nullptr;
    other.budget_str_cnt = nullptr;
    other.budget_executed = nullptr;
    other.budget_executed_str_cnt = nullptr;
    other.budget_remains = nullptr;
    other.budget_remains_str_cnt = nullptr;
    //************************************
    other.price_for_apartment = nullptr;
    other.first_stage_ap = nullptr;
    other.first_stage_ap_str_cnt = nullptr;
    other.second_stage_ap = nullptr;
    other.second_stage_ap_str_cnt = nullptr;
    other.total_price_ap = nullptr;
    other.total_price_ap_str_cnt = nullptr;
    //************************************
    other.price_for_entrance = nullptr;
    other.first_stage_ent = nullptr;
    other.first_stage_ent_str_cnt = nullptr;
    other.second_stage_ent = nullptr;
    other.second_stage_ent_str_cnt = nullptr;
    other.total_price_ent = nullptr;
    other.total_price_ent_str_cnt = nullptr;
    //************************************
    other.tablet_adding_work = nullptr;
    other.add_row = nullptr;
    other.delete_row = nullptr;
    other.adding_work = nullptr;
    //************************************
    other.tablet_total_work = nullptr;
    other.total_work = nullptr;
    //************************************
    other.budget_auto = nullptr;
    other.budget_cnt_auto = nullptr;
    other.budget_executed_auto = nullptr;
    other.budget_executed_cnt_auto = nullptr;
    other.budget_remains_auto = nullptr;
    other.budget_remains_cnt_auto = nullptr;
    //====================================}

    other.page1 = nullptr;
    other.page2 = nullptr;

    other.tab_page = nullptr;
}

Address &Address::operator=(const Address &other)
{
    qInfo() << "Operator= ...";
    if(&other != this)
    {
        name = other.name;
        address = other.address;
        list_adding_works = other.list_adding_works;
        list_works = other.list_works;

        clear_mem();
        new_obj();
    }

    return *this;
}

void Address::set_name(QString new_name)
{
    name = new_name;
}

void Address::set_address(QString new_address)
{
    address = new_address;
}

void Address::add_row_lst()
{
    int row_t = tablet_total_work->rowCount();
    tablet_total_work->insertRow(row_t);
    QList<QTableWidgetItem*> *list_tmp_t = new QList<QTableWidgetItem*>(tablet_total_work->columnCount());
    list_works.push_back(*list_tmp_t);

    for(int i = 0; i < tablet_total_work->columnCount(); ++i)
    {
        list_works.back()[i] = new QTableWidgetItem();
        list_works.back()[i]->setFlags(Qt::ItemIsEnabled);

        if(i != 0)
        {
            list_works.back()[i]->setText("0");
            list_works.back()[i]->setTextAlignment(Qt::AlignCenter);
        }

        tablet_total_work->setItem(row_t, i, list_works.back()[i]);
        qInfo() << "Add item in table " << i;
    }

    delete list_tmp_t;
    list_tmp_t = nullptr;

    update_tablet_list_tasks();

    int row = tablet_adding_work->rowCount();

    //qInfo() << "Count row " << row << " - Count column" << tablet_adding_work->columnCount();

    tablet_adding_work->insertRow(row);
    QList<QTableWidgetItem*> *list_tmp = new QList<QTableWidgetItem*>(tablet_adding_work->columnCount());

    //qInfo() << "Size list_tmp " << list_tmp->size();

    if(list_tmp == nullptr)
    {
        //qInfo() << "list_tmp is nullptr";
        return;
    }

    list_adding_works.push_back(*list_tmp);

    //qInfo() << "Size list_adding_works " << list_adding_works.size();
    //qInfo() << "obj->name " << tablet_adding_work->objectName();

    for(int col = 0; col < tablet_adding_work->columnCount(); ++col)
    {
        //qInfo() << "Add item in table begin" << col;

        list_adding_works.back()[col] = new QTableWidgetItem();
        tablet_adding_work->setItem(row, col, list_adding_works.back()[col]);

        //qInfo() << "Add item in table new QTWI" << col;
        if(col == 0) list_adding_works.back()[col]->setText("name work");
        if(col != 0) list_adding_works.back()[col]->setText("0");
        if(col == 1) list_adding_works.back()[col]->setTextAlignment(Qt::AlignCenter);
        if(col == 2 || col == 3 ) list_adding_works.back()[col]->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
        //qInfo() << "Add item in table set QTWI col: " << col << " - row: " << row << " | count row:" << tablet_adding_work->rowCount();
        //qInfo() << "Add item in table set QTWI col: " << col << " - text " << list_adding_works.back()[col]->text() << ";";

        //qInfo() << "Add item in table end" << col;
    }

    delete list_tmp;
    list_tmp = nullptr;

    if(tablet_adding_work->rowCount() > 0) delete_row->setEnabled(true);
    adding_works = true;
}

void Address::delete_row_lst()
{
    int row = tablet_adding_work->currentRow();

    if(row == -1) return;

    auto beg = list_adding_works.begin();
    //qInfo() << "list_adding_works beg.size() = "<< beg->size();

    for(int i = 0; beg != list_adding_works.end(); beg++, ++i)
    {
        if(i == row)
        {
            while(!beg->empty())
            {
                delete beg->back();
                beg->back() = nullptr;
                beg->pop_back();
                //qInfo() << "delete item from ADDING_WORK";
            }
            list_adding_works.erase(beg);

            tablet_adding_work->removeRow(row);
            //qInfo() << "delete item from ADDING_WORK row" << row;
            break;
        }
    }

    auto it = list_works.begin();
    //qInfo() << "list_works beg.size() = "<< it->size();

    int i = 0;
    if(general_works)
    {
        i += name_works.size();
        row += name_works.size();
        for(int i = 0; it != list_works.end() && i < name_works.size(); ++i)
            it++;
    }
    for(; it != list_works.end(); it++, ++i)
    {
        if(i == row)
        {
            while(!it->empty())
            {
                delete it->back();
                it->back() = nullptr;
                it->pop_back();
                //qInfo() << "delete item from TOTAL_WORK";
            }
            list_works.erase(it);
            tablet_total_work->removeRow(row);
            //qInfo() << "delete item from TOTAL_WORK row" << row;
            break;
        }
    }

    for(auto beg = list_groups.begin(); beg != list_groups.end(); ++beg)
    {
        auto it = (*beg)->list_tasks.begin();
        int i = 0;
        if(general_works)
        {
            i += name_works.size();
            //row += name_works.size();
            for(int i = 0; it != (*beg)->list_tasks.end() && i < name_works.size(); ++i)
                it++;
        }
        for(; it != (*beg)->list_tasks.end(); it++, ++i)
        {
            if(i == row)
            {
                while(!it->empty())
                {
                    delete it->back();
                    it->back() = nullptr;
                    it->pop_back();
                    //qInfo() << "delete item from TOTAL_WORK";
                }
                (*beg)->list_tasks.erase(it);
                (*beg)->tablet_list_tasks->removeRow(row);
                //qInfo() << "delete item from TOTAL_WORK row" << row;
                break;
            }
        }
    }

    if(tablet_adding_work->rowCount() == 0)
    {
        adding_works = false;
        delete_row->setEnabled(false);
    }
    calculated_budget();
}

void Address::fill_tablet_works()
{
    int rows = name_works.size();

    if(tablet_total_work->rowCount() == 0)
    {
        for(int i = 0; i < rows; ++i)
        {
            tablet_total_work->insertRow(i);

            QList<QTableWidgetItem*> *list_tmp = new QList<QTableWidgetItem*>(tablet_total_work->columnCount());

            //qInfo() << "Size list_tmp " << list_tmp->size();

            list_works.push_back(*list_tmp);
            for(int j = 0; j < tablet_total_work->columnCount(); ++j)
            {
                list_works.back()[j] = new QTableWidgetItem();
                list_works.back()[j]->setFlags(Qt::ItemIsEnabled);

                if(j == 0)
                    list_works.back()[j]->setText(name_works[i]);
                else
                {
                    list_works.back()[j]->setText("0");
                    list_works.back()[j]->setTextAlignment(Qt::AlignCenter);
                }
                tablet_total_work->setItem(i, j, list_works.back()[j]);
            }
            //qInfo() << "list_works.back() size() = "<< list_works.back().size();

            delete list_tmp;
            list_tmp = nullptr;
        }
        general_works = true;
    }
    else if(!general_works)
    {
        //qInfo() << "general_works " << general_works;
        //qInfo() << "GW list_works size() = "<< list_works.size();
        //auto pos = list_works.begin();
        //qInfo() << "ADD GW item to LIST_WORK pos.size() " << pos->size() << "  pos->front()->text()  " << pos->front()->text();

        for(int i = 0; i < rows; ++i)
        {
            tablet_total_work->insertRow(0);

            QList<QTableWidgetItem*> *list_tmp = new QList<QTableWidgetItem*>(tablet_total_work->columnCount());

            //qInfo() << "Size list_tmp " << list_tmp->size();
            list_works.push_front(*list_tmp);
            auto it = list_works.begin();
            //qInfo() << "GW in FOR list_works size() = "<< list_works.size();

            for(int j = 0; j < tablet_total_work->columnCount(); ++j)
            {
                (*it)[j] = new QTableWidgetItem();
                (*it)[j]->setFlags(Qt::ItemIsEnabled);

                if(j == 0)
                {
                    (*it)[j]->setText(name_works[name_works.size() - i - 1]);
                    //qInfo() << "ADD GW in FOR item to LIST_WORK it.size() " << it->size() << "  it->front()->text()  " << ((it->front()->text().size())? it->front()->text() : "NONE");
                }
                else
                {
                    (*it)[j]->setText("0");
                    (*it)[j]->setTextAlignment(Qt::AlignCenter);
                }
                tablet_total_work->setItem(0, j, (*it)[j]);
            }
            //qInfo() << "list_works.back() size() = "<< list_works.back().size();

            delete list_tmp;
            list_tmp = nullptr;
        }
        general_works = true;

        //DEBUG
        // for(auto beg = list_works.begin(); beg != list_works.end(); beg++)
        // {
        //     qInfo() << "ADD in END_BLOCK beg->front()->text()" << beg->front()->text();
        // }
    }
    if(apartments_total_cnt->text().toInt() == 0 && general_works)
    {
        //qInfo() << "START delete item from LIST_WORK row " << rows;
        //qInfo() << "list_works.size() = " << list_works.size();

        for(int i = 0; i < rows; ++i)
        {
            auto beg = list_works.begin();

            //qInfo() << "DELETE list_works size() = "<< list_works.size();
            //qInfo() << "DELETE item from LIST_WORK beg.size() " << beg->size();// << "  beg->back()->text()  " << beg->back()->text();

            while(!beg->empty())
            {
                //qInfo() << "delete item from LIST_WORK beg.size() " << beg->size() << "  beg->back()->text()  " << beg->back()->text();

                delete beg->back();
                beg->back() = nullptr;
                beg->pop_back();
            }
            //qInfo() << "delete after WHILE  list_works size() =" << list_works.size();

            list_works.erase(beg);
            //qInfo() << "delete after ERASE  list_works size() =" << list_works.size();

            tablet_total_work->removeRow(0);
            //qInfo() << "delete item from LIST_WORK row " << tablet_total_work->rowCount();

            for(auto beg = list_groups.begin(); beg != list_groups.end(); ++beg)
            {
                auto beg_t = (*beg)->list_tasks.begin();

                while(!beg_t->empty())
                {
                    delete beg_t->back();
                    beg_t->back() = nullptr;
                    beg_t->pop_back();
                }
                (*beg)->list_tasks.erase(beg_t);

                (*beg)->tablet_list_tasks->removeRow(0);
            }
        }
        general_works = false;
    }
    //qInfo() << "list_works size() = "<< list_works.size();

    update_tablet_list_tasks();
}

void Address::fill_tablet_list_tasks()
{
    int row_t = tablet_total_work->rowCount();

    //qInfo() << "Count row " << row << " - Count column" << tablet_adding_work->columnCount();

    list_groups.back()->tablet_list_tasks->setRowCount(row_t);

    for(int row_i = 0; row_i < tablet_total_work->rowCount(); ++row_i)
    {

        std::list<QTableWidgetItem*> *qlist_tmp_t = new std::list<QTableWidgetItem*>(list_groups.back()->tablet_list_tasks->columnCount());

        //qInfo() << "Size list_tmp " << list_tmp->size();

        list_groups.back()->list_tasks.push_back(*qlist_tmp_t);

        //qInfo() << "obj->name " << tablet_adding_work->objectName();

        int col = 0;
        for(auto item = list_groups.back()->list_tasks.back().begin(); item != list_groups.back()->list_tasks.back().end(); item++)
        {
            *item = new QTableWidgetItem();
            if(col == 0)
            {
                (*item)->setText(tablet_total_work->item(row_i, col)->text());
                (*item)->setFlags(Qt::ItemIsEnabled);
            }

            if(col != 0)
            {
                (*item)->setText("");
                (*item)->setTextAlignment(Qt::AlignCenter);
            }

            list_groups.back()->tablet_list_tasks->setItem(row_i, col, *item);
            ++col;
            //qInfo() << "Add item in table " << i;
        }

        delete qlist_tmp_t;
        qlist_tmp_t = nullptr;
    }
    qDebug() << "Address::fill_tablet_list_tasks(): list_tasks.size() = " << list_groups.back()->list_tasks.size();
}

void Address::calculated_budget()
{
    int count_floor = (first_floor_lived->isChecked())? floors_cnt->value() : floors_cnt->value() - 1;
    int count_entrances = entrances_cnt->value();
    int count_apartments = apartments_total_cnt->value();

    int price_apartments = total_price_ap_str_cnt->text().toInt();
    int price_entrances = total_price_ent_str_cnt->text().toInt();

    int sum_entrances = (count_floor * count_entrances) * price_entrances;
    int sum_apartments = count_apartments * price_apartments;

    int sum_adding_work = 0;

    //qInfo() << "Calculate sum -> Calculated budget: tablet_adding_work->rowCount() = " << row_count;

    for(int i = 0; i < tablet_adding_work->rowCount(); ++i)
    {
        //qInfo() << "Calculate sum -> Calculated budget: tablet_adding_work->item(" << i << ", 3)->text() start step";
        if(!tablet_adding_work->item(i, 3))
        {
            //qInfo() << "Calculate sum -> Calculated budget: tablet_adding_work->item(" << i << ", 3)->text() is NULL";
            break;
        }
        //qInfo() << "Calculate sum -> Calculated budget: tablet_adding_work->item(" << i << ", 3)->text() " << tablet_adding_work->item(i, 3)->text();
        //qInfo() << "Calculate sum -> Calculated budget: tablet_adding_work->item(" << i << ", 3)->text() next step";
        sum_adding_work += tablet_adding_work->item(i, 3)->text().toInt();
    }

    int sum_total = sum_entrances + sum_apartments + sum_adding_work;
    budget_cnt_auto->setText(QString::number(sum_total));

    int executed = budget_executed_cnt_auto->text().toInt();

    int remains = sum_total - executed;
    budget_remains_cnt_auto->setText(QString::number(remains));
}

void Address::set_list_price()
{
    list_prices.clear();
    if(general_works)
    {
        list_prices.push_back(first_stage_ap_str_cnt->text().toInt());
        list_prices.push_back(second_stage_ap_str_cnt->text().toInt());

        list_prices.push_back(first_stage_ent_str_cnt->text().toInt());
        list_prices.push_back(second_stage_ent_str_cnt->text().toInt());
    }

    for(int i = 0; i < tablet_adding_work->rowCount(); ++i)
    {
        list_prices.push_back(tablet_adding_work->item(i, 3)->text().toInt());
    }
}

QList<int> Address::get_list_price()
{
    return list_prices;
}

void Address::fill_done_tasks()
{
    int  budget_executed = 0;
    done_taks = QList<int>(list_works.size(), 0);
    for(auto beg = list_groups.begin(); beg != list_groups.end(); ++beg)
    {
        (*beg)->fill_done_tasks();
        QList<int> lst = (*beg)->get_done_tasks();
        for(int j = 0; j < lst.size(); ++j)
        {
            done_taks[j] += lst[j];
        }
    }

    for(int i = 0; i < done_taks.size(); ++i)
    {
        int cnt = tablet_total_work->item(i, 1)->text().toInt();

        tablet_total_work->item(i, 2)->setText(QString::number(done_taks[i]));
        tablet_total_work->item(i, 3)->setText(QString::number(cnt - done_taks[i]));
        budget_executed += done_taks[i] * list_prices[i];
    }
    budget_executed_cnt_auto->setText(QString::number(budget_executed));
    int budget = budget_cnt_auto->text().toInt();
    budget_remains_cnt_auto->setText(QString::number(budget - budget_executed));
}

void Address::update_tablet_list_tasks()
{
    for(auto group = list_groups.begin(); group != list_groups.end(); group++)
    {
        qDebug() << "group address" << &group;
        qDebug() << "group size" << list_groups.size();
        qDebug() << "tasks size" << (*group)->list_tasks.size();
        qDebug() << "group name" << (*group)->item_group_name->text();
        auto task = (*group)->list_tasks.begin();
        auto task_a = (*group)->list_tasks.begin();
        int row_task = 0;
        int count_rows_tasks = 0;

        if((*group)->list_tasks.empty())
        {
            fill_tablet_list_tasks();
            return;
        }

        for(auto work = list_works.begin(); work != list_works.end(); work++, task++, row_task++)
        {
            count_rows_tasks = (*group)->tablet_list_tasks->rowCount();
            qDebug() << "work->front()" << work->front()->text();

            // qDebug() << "task->front() size" << task->front()->text();
            //qDebug() << "task->front() row_task = " << row_task;

            qDebug() << "tablet_total_work->rowCount() = " << tablet_total_work->rowCount();
            qDebug() << "group->tablet_list_tasks->rowCount() = " << (*group)->tablet_list_tasks->rowCount();

            qDebug() << "row_task = " << row_task;
            qDebug() << "count_rows_tasks = " << count_rows_tasks;

            if(task != (*group)->list_tasks.end() && work->front()->text() == task->front()->text())
            {
                continue;
            }
            else if(row_task == count_rows_tasks)
            {
                (*group)->tablet_list_tasks->insertRow(row_task);

                std::list<QTableWidgetItem*> *qlist_tmp_t = new std::list<QTableWidgetItem*>((*group)->tablet_list_tasks->columnCount());

                (*group)->list_tasks.push_back(*qlist_tmp_t);

                int col = 0;
                for(auto item = (*group)->list_tasks.back().begin(); item != (*group)->list_tasks.back().end(); item++)
                {
                    *item = new QTableWidgetItem();
                    if(col == 0)
                    {
                        (*item)->setText(work->front()->text());
                        (*item)->setFlags(Qt::ItemIsEnabled);
                    }
                    (*group)->tablet_list_tasks->setItem(row_task, col, *item);
                    ++col;
                }

                delete qlist_tmp_t;
                qlist_tmp_t = nullptr;
            }
            else if(general_works && row_task < name_works.size())
            {
                (*group)->tablet_list_tasks->insertRow(row_task);

                std::list<QTableWidgetItem*> *qlist_tmp_t = new std::list<QTableWidgetItem*>((*group)->tablet_list_tasks->columnCount());

                auto it_tasks = (*group)->list_tasks.insert(task_a, *qlist_tmp_t);

                int col = 0;
                for(auto item = it_tasks->begin(); item != it_tasks->end(); item++)
                {
                    *item = new QTableWidgetItem();
                    if(col == 0)
                    {
                        (*item)->setText(work->front()->text());
                        (*item)->setFlags(Qt::ItemIsEnabled);
                    }
                    (*group)->tablet_list_tasks->setItem(row_task, col, *item);
                    ++col;
                }

                delete qlist_tmp_t;
                qlist_tmp_t = nullptr;
            }

            for(auto it = (*group)->list_tasks.begin(); it != (*group)->list_tasks.end(); ++it)
            {
                qDebug() << "group->list_tasks: it = " << it->front()->text();
            }
        }
    }
}

QString  Address::get_name()
{
    return name;
}

QString  Address::get_address()
{
    return address;
}

void Address::new_obj()
{
    tab_page = new QWidget();
    btn_page = new QPushButton();

    page1 = new QGroupBox();
    //{====================================
    button_add_emp = new QPushButton();
    button_delete_emp = new QPushButton();
    tablet_list_groups = new QTableWidget();
    //tablet_pay_groups = new QTableWidget();
    //====================================}

    page2 = new QGroupBox();
    //{====================================
    name_obj = new QLabel();
    name_str = new QLineEdit();
    adr_obj = new QLabel();
    adr_str = new QLineEdit();
    developer_obj = new QLabel();
    developer_str = new QLineEdit();
    //************************************
    floors = new QLabel();
    floors_cnt = new QSpinBox();
    entrances = new QLabel();
    entrances_cnt = new QSpinBox();
    apartments = new QLabel();
    apartments_cnt = new QSpinBox();
    first_floor_lived = new QCheckBox();
    apartments_on_1fl = new QLabel();
    apartments_on_1fl_cnt = new QSpinBox();
    apartments_total = new QLabel();
    apartments_total_cnt = new QSpinBox();
    //************************************
    budget = new QLabel();
    budget_str_cnt = new QLineEdit();
    budget_executed = new QLabel();
    budget_executed_str_cnt = new QLineEdit();
    budget_remains = new QLabel();
    budget_remains_str_cnt = new QLineEdit();
    //************************************
    price_for_apartment = new QLabel();
    first_stage_ap = new QLabel();
    first_stage_ap_str_cnt = new QLineEdit();
    second_stage_ap = new QLabel();
    second_stage_ap_str_cnt = new QLineEdit();
    total_price_ap = new QLabel();
    total_price_ap_str_cnt = new QLineEdit();
    //************************************
    price_for_entrance = new QLabel();
    first_stage_ent = new QLabel();
    first_stage_ent_str_cnt = new QLineEdit();
    second_stage_ent = new QLabel();
    second_stage_ent_str_cnt = new QLineEdit();
    total_price_ent = new QLabel();
    total_price_ent_str_cnt = new QLineEdit();
    //************************************
    adding_work = new QGroupBox();
    tablet_adding_work = new QTableWidget();
    add_row = new QPushButton();
    delete_row = new QPushButton();
    //************************************
    total_work = new QGroupBox();
    tablet_total_work = new QTableWidget();
    //************************************
    budget_auto = new QLabel();
    budget_cnt_auto = new QLineEdit();
    budget_executed_auto = new QLabel();
    budget_executed_cnt_auto = new QLineEdit();
    budget_remains_auto = new QLabel();
    budget_remains_cnt_auto = new QLineEdit();
    //====================================}
}

void Address::clear_mem()
{
    delete_mem();

    btn_page = nullptr;


    //{====================================
    button_add_emp = nullptr;
    button_delete_emp = nullptr;
    tablet_list_groups = nullptr;
    //tablet_pay_groups = nullptr;
    //====================================}

    //{====================================
    name_obj = nullptr;
    name_str = nullptr;
    adr_obj = nullptr;
    adr_str = nullptr;
    developer_obj = nullptr;
    developer_str = nullptr;
    //************************************
    floors = nullptr;
    floors_cnt = nullptr;
    entrances = nullptr;
    entrances_cnt = nullptr;
    apartments = nullptr;
    apartments_cnt = nullptr;
    first_floor_lived = nullptr;
    apartments_on_1fl = nullptr;
    apartments_on_1fl_cnt = nullptr;
    apartments_total = nullptr;
    apartments_total_cnt = nullptr;
    //************************************
    budget = nullptr;
    budget_str_cnt = nullptr;
    budget_executed = nullptr;
    budget_executed_str_cnt = nullptr;
    budget_remains = nullptr;
    budget_remains_str_cnt = nullptr;
    //************************************
    price_for_apartment = nullptr;
    first_stage_ap = nullptr;
    first_stage_ap_str_cnt = nullptr;
    second_stage_ap = nullptr;
    second_stage_ap_str_cnt = nullptr;
    total_price_ap = nullptr;
    total_price_ap_str_cnt = nullptr;
    //************************************
    price_for_entrance = nullptr;
    first_stage_ent = nullptr;
    first_stage_ent_str_cnt = nullptr;
    second_stage_ent = nullptr;
    second_stage_ent_str_cnt = nullptr;
    total_price_ent = nullptr;
    total_price_ent_str_cnt = nullptr;
    //************************************
    tablet_adding_work = nullptr;
    add_row = nullptr;
    delete_row = nullptr;
    adding_work = nullptr;
    //************************************
    tablet_total_work = nullptr;
    total_work = nullptr;
    //************************************
    budget_auto = nullptr;
    budget_cnt_auto = nullptr;
    budget_executed_auto = nullptr;
    budget_executed_cnt_auto = nullptr;
    budget_remains_auto = nullptr;
    budget_remains_cnt_auto = nullptr;
    //====================================}

    page1 = nullptr;
    page2 = nullptr;

    tab_page = nullptr;
}

void Address::delete_mem()
{
    for(auto beg = list_adding_works.begin(); beg !=list_adding_works.end(); beg++)
    {
        while(!beg->empty())
        {
            delete beg->back();
            beg->back() = nullptr;
            beg->pop_back();
            qInfo() << "delete item from ADDING_WORK";
        }
    }

    for(auto beg = list_works.begin(); beg !=list_works.end(); beg++)
    {
        while(!beg->empty())
        {
            delete beg->back();
            beg->back() = nullptr;
            beg->pop_back();
            qInfo() << "delete item from WORKS";
        }
    }

    for(auto beg = list_groups.begin(); beg !=list_groups.end(); beg++)
    {
        delete *beg;
        *beg = nullptr;
        qInfo() << "delete item from GROUPS";
    }

    delete btn_page;

    //{====================================
    delete button_add_emp;
    delete button_delete_emp;
    delete tablet_list_groups;
    //delete tablet_pay_groups;
    //====================================}

    //{====================================
    delete name_obj;
    delete name_str;
    delete adr_obj;
    delete adr_str;
    delete developer_obj;
    delete developer_str;
    //************************************
    delete floors;
    delete floors_cnt;
    delete entrances;
    delete entrances_cnt;
    delete apartments;
    delete apartments_cnt;
    delete first_floor_lived;
    delete apartments_on_1fl;
    delete apartments_on_1fl_cnt;
    delete apartments_total;
    delete apartments_total_cnt;
    //************************************
    delete budget;
    delete budget_str_cnt;
    delete budget_executed;
    delete budget_executed_str_cnt;
    delete budget_remains;
    delete budget_remains_str_cnt;
    //************************************
    delete price_for_apartment;
    delete first_stage_ap;
    delete first_stage_ap_str_cnt;
    delete second_stage_ap;
    delete second_stage_ap_str_cnt;
    delete total_price_ap;
    delete total_price_ap_str_cnt;
    //************************************
    delete price_for_entrance;
    delete first_stage_ent;
    delete first_stage_ent_str_cnt;
    delete second_stage_ent;
    delete second_stage_ent_str_cnt;
    delete total_price_ent;
    delete total_price_ent_str_cnt;
    //************************************
    delete tablet_adding_work;
    delete add_row;
    delete delete_row;
    delete adding_work;
    //************************************
    delete tablet_total_work;
    delete total_work;
    //************************************
    delete budget_auto;
    delete budget_cnt_auto;
    delete budget_executed_auto;
    delete budget_executed_cnt_auto;
    delete budget_remains_auto;
    delete budget_remains_cnt_auto;
    //====================================}

    delete page1;
    delete page2;

    delete tab_page;
}
