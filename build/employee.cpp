#include "employee.h"
#include "funcs.h"

Employee::Employee() {}

Employee::Employee(QString full_name)
{
    adding_funcs::separate_name(full_name, name, last_name);
}

QString Employee::get_full_name()
{
    return last_name + " " + name;
}

void Employee::set_name(QString full_name)
{
    adding_funcs::separate_name(full_name, name, last_name);
}
