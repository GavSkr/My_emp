#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "address.h"
//#include "employee.h"
#include "save_data.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Button_add_address_clicked();

    void on_Button_exit_clicked();

    void add_group();
    void delete_group();

    void change_page();

    void add_page1();
    void add_page2();

    void change_name_tab();
    void check_first_floor();
    void calculate_total_apartments();
    void enter_job();
    void calculate_total_price();
    void calculate_total_budget_auto();
    void edit_tablet_adding_work();
    void check_symbols();
    void check_symbols_g();
    void clone_items_tablet();
    void calculate_sum();
    void tablet_list_tasks_setVisible();
    void add_employee();
    void delete_employee();
    void add_pay();
    void calculate_pay();
    void set_name_group();

    void on_Button_delete_address_clicked();

    void save_to_file();

private:
    Ui::MainWindow *ui;

    std::list<Address> builds;

    int mainwindow_width;
    int mainwindow_height;
};
#endif // MAINWINDOW_H
