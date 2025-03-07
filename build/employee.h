#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QTableWidget>
#include <QPushButton>
#include <QDateEdit>

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

    std::list<std::list<QTableWidgetItem*>> list_tasks;
    QTableWidget *tablet_list_tasks = nullptr;
    std::list<std::list<QTableWidgetItem*>> list_employees;
    QTableWidget *tablet_list_employees = nullptr;
    std::list<std::list<QTableWidgetItem*>> list_pay;
    QTableWidget *tablet_list_pay = nullptr;

    QPushButton *button_add_emp = nullptr;
    QPushButton *button_delete_emp = nullptr;
    QPushButton *button_add_pay = nullptr;

    QTableWidgetItem* item_group_name = nullptr;
    QTableWidgetItem* item_group_total_pays = nullptr;

    std::list<QDateEdit*> calendar;

    void add_employee();
    void delete_employee();
    void add_pay();
    void calculate_pay();
    void fill_done_tasks();
    void fill_tablet_list_pay();
    QList<int> get_done_tasks();

private:
    QString name_group;
    //QString last_name;
    QList<QString> name_pay {"Дата выплаты", "Расчётная сумма выплаты", "Фактическая сумма выплаты","Остаток выплаты"};
    QList<int> done_taks;

    void new_obj();
    void clear_mem();
    void delete_mem();

};

#endif // EMPLOYEE_H
