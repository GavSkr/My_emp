#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QTableWidget>

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

    QTableWidgetItem* item_name = nullptr;
    QTableWidgetItem* item_total_pays = nullptr;

private:
    QString name;
    QString last_name;

    void new_obj();
    void clear_mem();
    void delete_mem();
};

#endif // EMPLOYEE_H
