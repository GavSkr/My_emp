#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "address.h"
//#include "employee.h"

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

    void add_employee();

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
    void clone_items_tablet();


private:
    Ui::MainWindow *ui;

    std::list<Address> builds;

    int mainwindow_width;
    int mainwindow_height;
};
#endif // MAINWINDOW_H
