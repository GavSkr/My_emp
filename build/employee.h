#ifndef EMPLOYEE_H
#define EMPLOYEE_H

//#include <iostream>
#include <QString>

class Employee
{
public:
    Employee();
    Employee(QString full_name);
    ~Employee();

    QString get_full_name();
    void set_name(QString full_name);
private:
    QString name;
    QString last_name;
};

#endif // EMPLOYEE_H
