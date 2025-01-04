#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QSpinBox>
#include <QCheckBox>

class Address
{
public:
    Address();
    Address(QString i_name);
    Address(QString i_name, QString i_address);
    ~Address();

    Address(const Address& other);
    Address(Address&& other);

    Address& operator=(const Address& other);

    void set_name(QString new_name);
    void set_address(QString new_address);
    void add_row_lst();
    void delete_row_lst();
    void fill_tablet_works();

    QString get_name();
    QString get_address();

    QWidget *tab_page = nullptr;
    QPushButton *btn_page = nullptr;
    std::list<QList<QTableWidgetItem*>> list_adding_works;
    std::list<QList<QTableWidgetItem*>> list_works;

    QGroupBox *page1 = nullptr;
    //{====================================
    QPushButton *button_add_emp = nullptr;
    QTableWidget *tablet = nullptr;
    //====================================}

    QGroupBox *page2 = nullptr;
    //{====================================
    QLabel *name_obj = nullptr;
    QLineEdit *name_str = nullptr;
    QLabel *adr_obj = nullptr;
    QLineEdit *adr_str = nullptr;
    QLabel *developer_obj = nullptr;
    QLineEdit *developer_str = nullptr;
    //************************************
    QLabel *floors = nullptr;
    QSpinBox *floors_cnt = nullptr;
    QLabel *entrances = nullptr;
    QSpinBox *entrances_cnt = nullptr;
    QLabel *apartments = nullptr;
    QSpinBox *apartments_cnt = nullptr;
    QCheckBox *first_floor_lived = nullptr;
    QLabel *apartments_on_1fl = nullptr;
    QSpinBox *apartments_on_1fl_cnt = nullptr;
    QLabel *apartments_total = nullptr;
    QSpinBox *apartments_total_cnt = nullptr;
    //************************************
    QLabel *budget = nullptr;
    QLineEdit *budget_str_cnt = nullptr;
    QLabel *budget_executed = nullptr;
    QLineEdit *budget_executed_str_cnt = nullptr;
    QLabel *budget_remains = nullptr;
    QLineEdit *budget_remains_str_cnt = nullptr;
    //************************************
    QLabel *price_for_apartment = nullptr;
    QLabel *first_stage_ap = nullptr;
    QLineEdit *first_stage_ap_str_cnt = nullptr;
    QLabel *second_stage_ap = nullptr;
    QLineEdit *second_stage_ap_str_cnt = nullptr;
    QLabel *total_price_ap = nullptr;
    QLineEdit *total_price_ap_str_cnt = nullptr;
    //************************************
    QLabel *price_for_entrance = nullptr;
    QLabel *first_stage_ent = nullptr;
    QLineEdit *first_stage_ent_str_cnt = nullptr;
    QLabel *second_stage_ent = nullptr;
    QLineEdit *second_stage_ent_str_cnt = nullptr;
    QLabel *total_price_ent = nullptr;
    QLineEdit *total_price_ent_str_cnt = nullptr;
    //************************************
    QGroupBox *adding_work = nullptr;
    QTableWidget *tablet_adding_work = nullptr;
    QPushButton *add_row = nullptr;
    QPushButton *delete_row = nullptr;
    //************************************
    QGroupBox *total_work = nullptr;
    QTableWidget *tablet_total_work = nullptr;
    //************************************
    QLabel *budget_auto = nullptr;
    QLineEdit *budget_cnt_auto = nullptr;
    QLabel *budget_executed_auto = nullptr;
    QLineEdit *budget_executed_cnt_auto = nullptr;
    QLabel *budget_remains_auto = nullptr;
    QLineEdit *budget_remains_cnt_auto = nullptr;
    //====================================}

private:
    QString name = "";
    QString address = "";
    QList<QString> name_works {"Квартира 1 этап", "Квартира 2 этап","Коридор 1 этап","Коридор 2 этап"};
    bool general_works = false;

    void new_obj();
    void clear_mem();
    void delete_mem();
};

#endif // ADDRESS_H
