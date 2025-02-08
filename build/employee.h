#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QTableWidget>
#include <QPushButton>

class Employee
{
public:
    Employee();
    Employee(QString full_name);
    ~Employee();

    Employee(const Employee& other);
    Employee(Employee&& other);

    QString get_full_name();
    void set_name(QString full_name);

    std::list<QList<QTableWidgetItem*>> list_tasks;
    QTableWidget *tablet_list_tasks = nullptr;
    std::list<QList<QTableWidgetItem*>> list_employees;
    QTableWidget *tablet_list_employees = nullptr;

    QPushButton *button_add_emp = nullptr;
    QPushButton *button_delete_emp = nullptr;
    QPushButton *button_add_pay = nullptr;

    QTableWidgetItem* item_name = nullptr;
    QTableWidgetItem* item_total_pays = nullptr;

    QTableWidgetItem* item_name_emp = nullptr;
    QTableWidgetItem* item_total_pays_emp = nullptr;

    void add_employee();
    void delete_employee();
    void add_pay();

private:
    QString name_group;
    //QString last_name;

    void new_obj();
    void clear_mem();
    void delete_mem();
};

#endif // EMPLOYEE_H
