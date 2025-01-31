#include "employee.h"
#include "funcs.h"

Employee::Employee()
{
    name = "New name";
    last_name = "last_name";

    new_obj();
}

Employee::Employee(QString full_name)
{
    adding_funcs::separate_name(full_name, name, last_name);
}

Employee::~Employee()
{
    clear_mem();
}

Employee::Employee(const Employee &other) // copy
{
    name = other.name;
    last_name = other.last_name;

    clear_mem();
    new_obj();
}

Employee::Employee(Employee &&other) // r-value
{
    name = other.name;
    last_name = other.last_name;

    delete_mem();

    list_tasks = other.list_tasks;
    tablet_list_tasks = other.tablet_list_tasks;
    item_name = other.item_name;
    item_total_pays = other.item_total_pays;

    other.tablet_list_tasks = nullptr;
    other.item_name = nullptr;
    other.item_total_pays = nullptr;
}

QString Employee::get_full_name()
{
    return last_name + " " + name;
}

void Employee::set_name(QString full_name)
{
    adding_funcs::separate_name(full_name, name, last_name);
}

void Employee::new_obj()
{
    tablet_list_tasks = new QTableWidget();
    item_name = new QTableWidgetItem(name + " " + last_name);
    item_total_pays = new QTableWidgetItem("0");

    item_total_pays->setTextAlignment(Qt::AlignVCenter | Qt::AlignRight);
}

void Employee::clear_mem()
{
    delete_mem();

    tablet_list_tasks = nullptr;
    item_name = nullptr;
    item_total_pays = nullptr;
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

    delete tablet_list_tasks;

    delete item_name;
    delete item_total_pays;
}
