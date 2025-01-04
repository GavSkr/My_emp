#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QScreen>
#include "funcs.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //If we don't have objects;
    if(builds.empty()) ui->tabWidget->setVisible(false);

    //Set position of the button_exit from a size of a screen
    auto btn_exit_x = QApplication::primaryScreen()->geometry().width() - ui->Button_exit->geometry().width() - 10;
    ui->Button_exit->setGeometry(btn_exit_x, 10, 150, 25);

    //Set position and size of the tab_widget from a size of a screen

    mainwindow_width = QApplication::primaryScreen()->geometry().width();
    mainwindow_height = QApplication::primaryScreen()->geometry().height();

    //qInfo() << "Size MainWindow: " << mainwindow_width << "x" << mainwindow_height;

    auto tab_width = mainwindow_width - 20;
    auto tab_height = mainwindow_height - 70; // - 10 - 25 - 10 - 21;
    ui->tabWidget->setGeometry(10, 45, tab_width, tab_height);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_add_address_clicked()
{
    Address adrs;
    builds.push_back(adrs);

    if(builds.back().tab_page)
    {
        ui->tabWidget->addTab(builds.back().tab_page, builds.back().get_name());
        builds.back().tab_page->setObjectName("tab_page_" + QString::number(builds.size() - 1));
    }

    add_page1();
    add_page2();

    if(builds.back().btn_page)
    {
        builds.back().btn_page->setParent(builds.back().tab_page);

        auto btn_x = ui->tabWidget->geometry().width() - 170; //(10 + 150 + 10);
        auto btn_y = ui->tabWidget->geometry().height() - 70; //(10 + 60);

        builds.back().btn_page->setGeometry(btn_x, btn_y, 150, 25);
        builds.back().btn_page->setText("<");
        builds.back().btn_page->setObjectName("btn_page_" + QString::number(builds.size() - 1));

        connect(builds.back().btn_page, SIGNAL(clicked()), this, SLOT(change_page()));
    }

    if(!ui->tabWidget->isVisible())
    {
        ui->tabWidget->setVisible(true);
    }

    ui->tabWidget->setCurrentIndex(builds.size() - 1);
}

void MainWindow::on_Button_exit_clicked()
{
    QApplication::quit();
}

void MainWindow::add_employee()
{
    QString btn_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    for(; beg != builds.end(); ++beg)
    {
        if(btn_name == beg->button_add_emp->objectName())
        {
            break;
        }
    }

    QTableWidgetItem *itm1 = new QTableWidgetItem("Fuck off");
    QTableWidgetItem *itm2 = new QTableWidgetItem("123456789");
    QTableWidgetItem *itm3 = new QTableWidgetItem("100000001");

    beg->tablet->setItem(0, 0, itm1);
    beg->tablet->setItem(0, 1, itm2);
    beg->tablet->setItem(0, 2, itm3);
}

void MainWindow::change_page()
{
    QString btn_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    for(; beg != builds.end(); ++beg)
    {
        if(btn_name == beg->btn_page->objectName())
        {
            break;
        }
    }

    if(beg->page1->isVisible())
    {
        beg->btn_page->setText("<");
        beg->page1->setVisible(false);
        beg->page2->setVisible(true);
    }
    else if(beg->page2->isVisible())
    {
        beg->btn_page->setText(">");
        beg->page1->setVisible(true);
        beg->page2->setVisible(false);
    }
}

void MainWindow::add_page1()
{
    if(builds.back().page1)
    {
        builds.back().page1->setParent(builds.back().tab_page);

        auto p1_width = ui->tabWidget->geometry().width() - 6 ;
        auto p1_height = ui->tabWidget->geometry().height() - 30;

        builds.back().page1->setGeometry(1, 1, p1_width, p1_height);
        builds.back().page1->setTitle("");
        builds.back().page1->setObjectName("groupbox_name_obj_" + QString::number(builds.size() - 1));
        builds.back().page1->setVisible(false);
    }

    if(builds.back().button_add_emp)
    {
        builds.back().button_add_emp->setParent(builds.back().page1);

        builds.back().button_add_emp->setGeometry(10, 10, 150, 25);
        builds.back().button_add_emp->setText("Добавить работника");
        builds.back().button_add_emp->setObjectName("btn_add_emp_" + QString::number(builds.size() - 1));

        connect(builds.back().button_add_emp, SIGNAL(clicked()), this, SLOT(add_employee()));
    }

    int columns = 3;
    int rows = 3;
    if(builds.back().tablet)
    {
        builds.back().tablet->setParent(builds.back().page1);

        auto tablet_width = ui->tabWidget->geometry().width() - 25;
        auto tablet_height = ui->tabWidget->geometry().height() - 125; //(10 + 25 + 10 + 40 + 40);

        builds.back().tablet->setObjectName("tablet_" + QString::number(builds.size() - 1));
        builds.back().tablet->setGeometry(10, 45, tablet_width, tablet_height-500);
        builds.back().tablet->setColumnCount(columns);
        builds.back().tablet->setRowCount(rows);

        QStringList name_columns;
        name_columns << "Name" << "Pay" << "Total";

        builds.back().tablet->setHorizontalHeaderLabels(name_columns);
    }
}

void MainWindow::add_page2()
{
    if(builds.back().page2)
    {
        builds.back().page2->setParent(builds.back().tab_page);

        auto p2_width = ui->tabWidget->geometry().width() - 6 ;
        auto p2_height = ui->tabWidget->geometry().height() - 30;

        builds.back().page2->setGeometry(1, 1, p2_width, p2_height);
        builds.back().page2->setTitle("");
        builds.back().page2->setObjectName("groupbox_name_obj_" + QString::number(builds.size() - 1));
        builds.back().page2->setVisible(true);
    }

    //===================================Наименование объекта===================================//
    //=====================================Name of an object====================================//
    int shift_x = 10;
    int shift_y = 10;
    int height = 25;
    int step_a = 10;
    int step_w = 30;
    int step_y = 40;

    {
        if(builds.back().name_obj)
        {
            builds.back().name_obj->setParent(builds.back().page2);

            int width = 55;
            builds.back().name_obj->setGeometry(shift_x, shift_y, width, height);
            builds.back().name_obj->setText("Название:");
            builds.back().name_obj->setObjectName("label_name_obj_" + QString::number(builds.size() - 1));
        }

        if(builds.back().name_str)
        {
            builds.back().name_str->setParent(builds.back().page2);

            shift_x += builds.back().name_obj->geometry().width() + step_a;
            int width = 200;
            builds.back().name_str->setGeometry(shift_x, shift_y, width, height);
            builds.back().name_str->setObjectName("lineedit_name_str_" + QString::number(builds.size() - 1));

            connect(builds.back().name_str, SIGNAL(textChanged(QString)), this, SLOT(change_name_tab()));
        }

        if(builds.back().adr_obj)
        {
            builds.back().adr_obj->setParent(builds.back().page2);

            shift_x += builds.back().name_str->geometry().width() + step_w;
            int width = 35;
            builds.back().adr_obj->setGeometry(shift_x, shift_y, width, height);
            builds.back().adr_obj->setText("Адрес:");
            builds.back().adr_obj->setObjectName("label_adr_obj_" + QString::number(builds.size() - 1));
        }

        if(builds.back().adr_str)
        {
            builds.back().adr_str->setParent(builds.back().page2);

            shift_x += builds.back().adr_obj->geometry().width() + step_a;
            int width = 800;
            builds.back().adr_str->setGeometry(shift_x, shift_y, width, height);
            builds.back().adr_str->setObjectName("lineedit_adr_str_" + QString::number(builds.size() - 1));
        }

        if(builds.back().developer_obj)
        {
            builds.back().developer_obj->setParent(builds.back().page2);

            shift_x += builds.back().adr_str->geometry().width() + step_w;
            int width = 75;
            builds.back().developer_obj->setGeometry(shift_x, shift_y, width, height);
            builds.back().developer_obj->setText("Застройщик:");
            builds.back().developer_obj->setObjectName("label_developer_obj_" + QString::number(builds.size() - 1));
        }

        if(builds.back().developer_str)
        {
            builds.back().developer_str->setParent(builds.back().page2);

            shift_x += builds.back().developer_obj->geometry().width() + step_a;
            int width = 300;
            builds.back().developer_str->setGeometry(shift_x, shift_y, width, height);
            builds.back().developer_str->setObjectName("lineedit_developer_str_" + QString::number(builds.size() - 1));
        }
    }

    //===================================Кол-во этажей, подъездов, квартир===================================//
    //================================Count of floors, entrances, apartments=================================//
    {
        shift_x = 10;
        shift_y += step_y;
        int width_sb = 40;

        if(builds.back().floors)
        {
            builds.back().floors->setParent(builds.back().page2);

            int width = 85;
            builds.back().floors->setGeometry(shift_x, shift_y, width, height);
            builds.back().floors->setText("Кол-во этажей:");
            builds.back().floors->setObjectName("label_floors_" + QString::number(builds.size() - 1));
        }

        if(builds.back().floors_cnt)
        {
            builds.back().floors_cnt->setParent(builds.back().page2);

            shift_x += builds.back().floors->geometry().width() + step_a;
            builds.back().floors_cnt->setGeometry(shift_x, shift_y, width_sb, height);
            builds.back().floors_cnt->adjustSize();
            builds.back().floors_cnt->setObjectName("spinbox_floors_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().floors_cnt, SIGNAL(valueChanged(int)), this, SLOT(calculate_total_apartments()));
        }

        if(builds.back().entrances)
        {
            builds.back().entrances->setParent(builds.back().page2);

            shift_x += builds.back().floors_cnt->geometry().width() + step_w;
            int width = 100;
            builds.back().entrances->setGeometry(shift_x, shift_y, width, height);
            builds.back().entrances->setText("Кол-во подъездов:");
            builds.back().entrances->setObjectName("label_entrances_" + QString::number(builds.size() - 1));
        }

        if(builds.back().entrances_cnt)
        {
            builds.back().entrances_cnt->setParent(builds.back().page2);

            shift_x += builds.back().entrances->geometry().width() + step_a;
            builds.back().entrances_cnt->setGeometry(shift_x, shift_y, width_sb, height);
            builds.back().entrances_cnt->adjustSize();
            builds.back().entrances_cnt->setObjectName("spinbox_entrances_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().entrances_cnt, SIGNAL(valueChanged(int)), this, SLOT(calculate_total_apartments()));
        }

        if(builds.back().apartments)
        {
            builds.back().apartments->setParent(builds.back().page2);

            shift_x += builds.back().entrances_cnt->geometry().width() + step_w;
            int width = 140;
            builds.back().apartments->setGeometry(shift_x, shift_y, width, height);
            builds.back().apartments->setText("Кол-во квартир на этаже:");
            builds.back().apartments->setObjectName("label_apartments_" + QString::number(builds.size() - 1));
        }

        if(builds.back().apartments_cnt)
        {
            builds.back().apartments_cnt->setParent(builds.back().page2);

            shift_x += builds.back().apartments->geometry().width() + step_a;
            builds.back().apartments_cnt->setGeometry(shift_x, shift_y, width_sb, height);
            builds.back().apartments_cnt->adjustSize();
            builds.back().apartments_cnt->setObjectName("spinbox_apartments_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().apartments_cnt, SIGNAL(valueChanged(int)), this, SLOT(calculate_total_apartments()));
        }

        if(builds.back().first_floor_lived)
        {
            builds.back().first_floor_lived->setParent(builds.back().page2);
            builds.back().first_floor_lived->setChecked(false);

            shift_x += builds.back().apartments_cnt->geometry().width() + step_w;
            int width = 140;
            builds.back().first_floor_lived->setGeometry(shift_x, shift_y, width, height);
            builds.back().first_floor_lived->setText("Первый этаж жилой");
            //builds.back().first_floor_lived->adjustSize();
            builds.back().first_floor_lived->setObjectName("checkbox_first_floor_lived_" + QString::number(builds.size() - 1));

            connect(builds.back().first_floor_lived, SIGNAL(checkStateChanged(Qt::CheckState)), this, SLOT(check_first_floor()));
        }

        if(builds.back().apartments_on_1fl)
        {
            builds.back().apartments_on_1fl->setParent(builds.back().page2);

            shift_x += builds.back().first_floor_lived->geometry().width() + step_w;
            int width = 190;
            builds.back().apartments_on_1fl->setGeometry(shift_x, shift_y, width, height);
            builds.back().apartments_on_1fl->setText("Кол-во квартир на первом этаже:");
            builds.back().apartments_on_1fl->setObjectName("label_apartments_on_1fl_" + QString::number(builds.size() - 1));
        }

        if(builds.back().apartments_on_1fl_cnt)
        {
            builds.back().apartments_on_1fl_cnt->setParent(builds.back().page2);
            if(!builds.back().first_floor_lived->isChecked()) builds.back().apartments_on_1fl_cnt->setEnabled(false);

            shift_x += builds.back().apartments_on_1fl->geometry().width() + step_a;
            builds.back().apartments_on_1fl_cnt->setGeometry(shift_x, shift_y, width_sb, height);
            builds.back().apartments_on_1fl_cnt->adjustSize();
            builds.back().apartments_on_1fl_cnt->setObjectName("spinbox_apartments_on_1fl_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().apartments_on_1fl_cnt, SIGNAL(valueChanged(int)), this, SLOT(calculate_total_apartments()));
        }

        if(builds.back().apartments_total)
        {
            builds.back().apartments_total->setParent(builds.back().page2);

            shift_x += builds.back().apartments_on_1fl_cnt->geometry().width() + step_w;
            int width = 125;
            builds.back().apartments_total->setGeometry(shift_x, shift_y, width, height);
            builds.back().apartments_total->setText("Кол-во квартир всего:");
            builds.back().apartments_total->setObjectName("label_apartments_total_" + QString::number(builds.size() - 1));
        }

        if(builds.back().apartments_total_cnt)
        {
            builds.back().apartments_total_cnt->setParent(builds.back().page2);

            shift_x += builds.back().apartments_total->geometry().width() + step_a;
            builds.back().apartments_total_cnt->setGeometry(shift_x, shift_y, width_sb, height);
            builds.back().apartments_total_cnt->adjustSize();
            builds.back().apartments_total_cnt->setMaximum(1000);
            builds.back().apartments_total_cnt->setObjectName("spinbox_apartments_total_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().apartments_total_cnt, SIGNAL(valueChanged(int)), this, SLOT(enter_job()));
        }
    }

    //===================================Бюджет===================================//
    //===================================Budget===================================//
    {
        shift_x = 10;
        shift_y += step_y;
        int width_l = 60;
        int width_le = 200;

        if(builds.back().budget)
        {
            builds.back().budget->setParent(builds.back().page2);

            builds.back().budget->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget->setText("Бюджет:");
            builds.back().budget->setObjectName("label_budget_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_str_cnt)
        {
            builds.back().budget_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().budget->geometry().width() + step_a;
            builds.back().budget_str_cnt->setGeometry(80, shift_y, width_le, height);

            builds.back().budget_str_cnt->setText("0");
            builds.back().budget_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().budget_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().budget_str_cnt->setObjectName("lineedit_budget_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().budget_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
        }

        if(builds.back().budget_executed)
        {
            builds.back().budget_executed->setParent(builds.back().page2);

            shift_x += builds.back().budget_str_cnt->geometry().width() + step_w;
            builds.back().budget_executed->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget_executed->setText("Исполнен:");
            builds.back().budget_executed->setObjectName("label_budget_executed_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_executed_str_cnt)
        {
            builds.back().budget_executed_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().budget_executed->geometry().width() + step_a;
            builds.back().budget_executed_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().budget_executed_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().budget_executed_str_cnt->setText("0");
            builds.back().budget_executed_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().budget_executed_str_cnt->setObjectName("lineedit_budget_executed_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().budget_executed_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
        }

        if(builds.back().budget_remains)
        {
            builds.back().budget_remains->setParent(builds.back().page2);

            shift_x += builds.back().budget_executed_str_cnt->geometry().width() + step_w;
            builds.back().budget_remains->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget_remains->setText("Остаток:");
            builds.back().budget_remains->setObjectName("label_budget_remains_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_remains_str_cnt)
        {
            builds.back().budget_remains_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().budget_remains->geometry().width() + step_a;
            builds.back().budget_remains_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().budget_remains_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().budget_remains_str_cnt->setText("0");
            builds.back().budget_remains_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().budget_remains_str_cnt->setObjectName("lineedit_budget_remains_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().budget_remains_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
        }
    }

    //===================================Цена за квартиру===================================//
    //================================Price for an apartment================================//
    int shift_y4 = 0;
    {
        shift_x = 10;
        shift_y += step_y;
        shift_y4 = shift_y; // for the widget "total_work"
        int width_le = 200;


        if(builds.back().price_for_apartment)
        {
            builds.back().price_for_apartment->setParent(builds.back().page2);

            int width = 105;
            builds.back().price_for_apartment->setGeometry(shift_x, shift_y, width, height);
            builds.back().price_for_apartment->setText("Цена за квартиру:");
            builds.back().price_for_apartment->setObjectName("label_price_for_apartment_" + QString::number(builds.size() - 1));
        }

        if(builds.back().first_stage_ap)
        {
            builds.back().first_stage_ap->setParent(builds.back().page2);

            shift_x += builds.back().price_for_apartment->geometry().width() + step_a;
            int width = 35;
            builds.back().first_stage_ap->setGeometry(shift_x, shift_y, width, height);
            builds.back().first_stage_ap->setText("1 этап");
            builds.back().first_stage_ap->setObjectName("label_first_stage_ap_" + QString::number(builds.size() - 1));
        }

        if(builds.back().first_stage_ap_str_cnt)
        {
            builds.back().first_stage_ap_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().first_stage_ap->geometry().width() + step_a;
            builds.back().first_stage_ap_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().first_stage_ap_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().first_stage_ap_str_cnt->setText("0");
            builds.back().first_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().first_stage_ap_str_cnt->setObjectName("lineedit_first_stage_ap_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().first_stage_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().first_stage_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_price()));
        }

        shift_x = 10;
        shift_y += step_y;

        if(builds.back().second_stage_ap)
        {
            builds.back().second_stage_ap->setParent(builds.back().page2);

            shift_x += builds.back().price_for_apartment->geometry().width() + step_a;
            int width = 35;
            builds.back().second_stage_ap->setGeometry(shift_x, shift_y, width, height);
            builds.back().second_stage_ap->setText("2 этап");
            builds.back().second_stage_ap->setObjectName("label_first_stage_ap_" + QString::number(builds.size() - 1));
        }

        if(builds.back().second_stage_ap_str_cnt)
        {
            builds.back().second_stage_ap_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().second_stage_ap->geometry().width() + step_a;
            builds.back().second_stage_ap_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().second_stage_ap_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().second_stage_ap_str_cnt->setText("0");
            builds.back().second_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().second_stage_ap_str_cnt->setObjectName("lineedit_second_stage_ap_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().second_stage_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().second_stage_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_price()));
        }

        shift_x = 10;
        shift_y += step_y;

        if(builds.back().total_price_ap)
        {
            builds.back().total_price_ap->setParent(builds.back().page2);

            shift_x += builds.back().price_for_apartment->geometry().width() + step_a;
            int width = 35;
            builds.back().total_price_ap->setGeometry(shift_x, shift_y, width, height);
            builds.back().total_price_ap->setText("Итого");
            builds.back().total_price_ap->setObjectName("label_total_price_ap_" + QString::number(builds.size() - 1));
        }

        if(builds.back().total_price_ap_str_cnt)
        {
            builds.back().total_price_ap_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().total_price_ap->geometry().width() + step_a;
            builds.back().total_price_ap_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().total_price_ap_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().total_price_ap_str_cnt->setText("0");
            builds.back().second_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().total_price_ap_str_cnt->setObjectName("lineedit_total_price_ap_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().total_price_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().total_price_ap_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_budget_auto()));
        }
    }

    //===================================Цена за подъезд===================================//
    //================================Price for an entrance================================//
    {
        shift_x = 10;
        shift_y += step_y;
        int width_le = 200;

        if(builds.back().price_for_entrance)
        {
            builds.back().price_for_entrance->setParent(builds.back().page2);

            int width = 105;
            builds.back().price_for_entrance->setGeometry(shift_x, shift_y, width, height);
            builds.back().price_for_entrance->setText("Цена за подъезд:");
            builds.back().price_for_entrance->setObjectName("label_price_for_entrance_" + QString::number(builds.size() - 1));
        }

        if(builds.back().first_stage_ent)
        {
            builds.back().first_stage_ent->setParent(builds.back().page2);

            shift_x += builds.back().price_for_entrance->geometry().width() + step_a;
            int width = 35;
            builds.back().first_stage_ent->setGeometry(shift_x, shift_y, width, height);
            builds.back().first_stage_ent->setText("1 этап");
            builds.back().first_stage_ent->setObjectName("label_first_stage_ent_" + QString::number(builds.size() - 1));
        }

        if(builds.back().first_stage_ent_str_cnt)
        {
            builds.back().first_stage_ent_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().first_stage_ent->geometry().width() + step_a;
            builds.back().first_stage_ent_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().first_stage_ent_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().first_stage_ent_str_cnt->setText("0");
            builds.back().second_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().first_stage_ent_str_cnt->setObjectName("lineedit_first_stage_ent_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().first_stage_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().first_stage_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_price()));
        }

        shift_x = 10;
        shift_y += step_y;

        if(builds.back().second_stage_ent)
        {
            builds.back().second_stage_ent->setParent(builds.back().page2);

            shift_x += builds.back().price_for_entrance->geometry().width() + step_a;
            int width = 35;
            builds.back().second_stage_ent->setGeometry(shift_x, shift_y, width, height);
            builds.back().second_stage_ent->setText("2 этап");
            builds.back().second_stage_ent->setObjectName("label_second_stage_ent_" + QString::number(builds.size() - 1));
        }

        if(builds.back().second_stage_ent_str_cnt)
        {
            builds.back().second_stage_ent_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().second_stage_ent->geometry().width() + step_a;
            builds.back().second_stage_ent_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().second_stage_ent_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().second_stage_ent_str_cnt->setText("0");
            builds.back().second_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().second_stage_ent_str_cnt->setObjectName("lineedit_second_stage_ent_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().second_stage_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().second_stage_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_price()));
        }

        shift_x = 10;
        shift_y += step_y;

        if(builds.back().total_price_ent)
        {
            builds.back().total_price_ent->setParent(builds.back().page2);

            shift_x += builds.back().price_for_entrance->geometry().width() + step_a;
            int width = 35;
            builds.back().total_price_ent->setGeometry(shift_x, shift_y, width, height);
            builds.back().total_price_ent->setText("Итого");
            builds.back().total_price_ent->setObjectName("label_total_price_ent_" + QString::number(builds.size() - 1));
        }

        if(builds.back().total_price_ent_str_cnt)
        {
            builds.back().total_price_ent_str_cnt->setParent(builds.back().page2);

            shift_x += builds.back().total_price_ent->geometry().width() + step_a;
            builds.back().total_price_ent_str_cnt->setGeometry(shift_x, shift_y, width_le, height);
            builds.back().total_price_ent_str_cnt->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
            builds.back().total_price_ent_str_cnt->setText("0");
            builds.back().second_stage_ap_str_cnt->setMaxLength(9); //for int max value 2 147 483 647 = 10 symbols
            builds.back().total_price_ent_str_cnt->setObjectName("lineedit_total_price_ent_str_cnt_" + QString::number(builds.size() - 1));

            connect(builds.back().total_price_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(check_symbols()));
            connect(builds.back().total_price_ent_str_cnt, SIGNAL(textChanged(QString)), this, SLOT(calculate_total_budget_auto()));
        }
    }

    //===================================Дополнительные работы===================================//
    //========================================Adding work========================================//
    {
        shift_x = 10;
        shift_y += step_y;
        int width_gb = 700;
        int height_gb = 500;
        int width_t = width_gb - 20;
        int height_t = height_gb - 30 - (height + 10);
        int shift_y_btn = 20 + height_t + 10;
        int width_btn = 100;
        int columns = 4;
        //int rows = 0;

        if(builds.back().adding_work)
        {
            builds.back().adding_work->setParent(builds.back().page2);

            builds.back().adding_work->setGeometry(shift_x, shift_y, width_gb, height_gb);
            builds.back().adding_work->setTitle("Дополнительные работы");
            builds.back().adding_work->setObjectName("groupbox_adding_work_" + QString::number(builds.size() - 1));
        }

        if(builds.back().tablet_adding_work)
        {
            builds.back().tablet_adding_work->setParent(builds.back().adding_work);

            builds.back().tablet_adding_work->setGeometry(10, 20, width_t, height_t);
            builds.back().tablet_adding_work->setObjectName("tablet_tablet_adding_work_" + QString::number(builds.size() - 1));

            builds.back().tablet_adding_work->setColumnCount(columns);
            //builds.back().tablet_adding_work->setRowCount(rows);

            QStringList name_columns;
            name_columns << "Наименование" << "Кол-во" << "Цена" << "Сумма";

            builds.back().tablet_adding_work->setHorizontalHeaderLabels(name_columns);
            builds.back().tablet_adding_work->setColumnWidth(0, 350);
            builds.back().tablet_adding_work->setColumnWidth(3, 110);
        }

        if(builds.back().add_row)
        {
            builds.back().add_row->setParent(builds.back().adding_work);

            builds.back().add_row->setGeometry(shift_x, shift_y_btn, width_btn, height);
            builds.back().add_row->setText("Добавить строку");
            builds.back().add_row->setObjectName("pushbutton_add_row_" + QString::number(builds.size() - 1));

            connect(builds.back().add_row, SIGNAL(clicked()), this, SLOT(edit_tablet_adding_work()));
        }

        if(builds.back().delete_row)
        {
            builds.back().delete_row->setParent(builds.back().adding_work);

            shift_x += builds.back().add_row->geometry().width() + step_w;
            builds.back().delete_row->setGeometry(shift_x, shift_y_btn, width_btn, height);
            builds.back().delete_row->setText("Удалить строку");
            builds.back().delete_row->setObjectName("pushbutton_delete_row_" + QString::number(builds.size() - 1));

            connect(builds.back().delete_row, SIGNAL(clicked()), this, SLOT(edit_tablet_adding_work()));
        }
    }

    //===================================Расчётный бюджет===================================//
    //======================================Auto Budget=====================================//
    {
        shift_x = 10;
        shift_y += step_y + builds.back().adding_work->geometry().height() - 10;
        int width = 200;

        if(builds.back().budget_auto)
        {
            builds.back().budget_auto->setParent(builds.back().page2);

            int width_l = 115;
            builds.back().budget_auto->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget_auto->setText("Расчётный бюджет:");
            builds.back().budget_auto->setObjectName("label_budget_auto_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_cnt_auto)
        {
            builds.back().budget_cnt_auto->setParent(builds.back().page2);

            shift_x += builds.back().budget_auto->geometry().width() + step_a;
            builds.back().budget_cnt_auto->setGeometry(shift_x, shift_y, width, height);
            builds.back().budget_cnt_auto->setAlignment(Qt::AlignRight);
            builds.back().budget_cnt_auto->setReadOnly(true);
            builds.back().budget_cnt_auto->setText("0.0");
            builds.back().budget_cnt_auto->setObjectName("lineedit_budget_cnt_auto_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_executed_auto)
        {
            builds.back().budget_executed_auto->setParent(builds.back().page2);

            shift_x += builds.back().budget_cnt_auto->geometry().width() + step_w;
            int width_l = 65;
            builds.back().budget_executed_auto->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget_executed_auto->setText("Исполнен:");
            builds.back().budget_executed_auto->setObjectName("label_budget_executed_auto_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_executed_cnt_auto)
        {
            builds.back().budget_executed_cnt_auto->setParent(builds.back().page2);

            shift_x += builds.back().budget_executed_auto->geometry().width() + step_a;
            builds.back().budget_executed_cnt_auto->setGeometry(shift_x, shift_y, width, height);
            builds.back().budget_executed_cnt_auto->setAlignment(Qt::AlignRight);
            builds.back().budget_executed_cnt_auto->setReadOnly(true);
            builds.back().budget_executed_cnt_auto->setText("0.0");
            builds.back().budget_executed_cnt_auto->setObjectName("lineedit_budget_executed_cnt_auto_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_remains_auto)
        {
            builds.back().budget_remains_auto->setParent(builds.back().page2);

            shift_x += builds.back().budget_executed_cnt_auto->geometry().width() + step_w;
            int width_l = 55;
            builds.back().budget_remains_auto->setGeometry(shift_x, shift_y, width_l, height);
            builds.back().budget_remains_auto->setText("Остаток:");
            builds.back().budget_remains_auto->setObjectName("label_budget_remains_auto_" + QString::number(builds.size() - 1));
        }

        if(builds.back().budget_remains_cnt_auto)
        {
            builds.back().budget_remains_cnt_auto->setParent(builds.back().page2);

            shift_x += builds.back().budget_remains_auto->geometry().width() + step_a;
            builds.back().budget_remains_cnt_auto->setGeometry(shift_x, shift_y, width, height);
            builds.back().budget_remains_cnt_auto->setAlignment(Qt::AlignRight);
            builds.back().budget_remains_cnt_auto->setReadOnly(true);
            builds.back().budget_remains_cnt_auto->setText("0.0");
            builds.back().budget_remains_cnt_auto->setObjectName("lineedit_budget_remains_cnt_auto_" + QString::number(builds.size() - 1));
        }
    }

    //===================================Объём работ===================================//
    //=====================================All work====================================//
    {
        shift_x = builds.back().adding_work->geometry().width() + step_w;
        shift_y = shift_y4;
        int width_gb = 700;
        int height_gb = 740;
        int width_t = width_gb - 20;
        int height_t = height_gb - 30;
        int columns = 4;
        int rows = 0;

        if(builds.back().total_work)
        {
            builds.back().total_work->setParent(builds.back().page2);


            builds.back().total_work->setGeometry(shift_x, shift_y, width_gb, height_gb);
            builds.back().total_work->setTitle("Объём работ");
            builds.back().total_work->setObjectName("groupbox_total_work_" + QString::number(builds.size() - 1));
        }

        if(builds.back().tablet_total_work)
        {
            builds.back().tablet_total_work->setParent(builds.back().total_work);

            builds.back().tablet_total_work->setGeometry(10, 20, width_t, height_t);
            builds.back().tablet_total_work->setObjectName("tablet_tablet_total_work_" + QString::number(builds.size() - 1));
            builds.back().tablet_total_work->setColumnCount(columns);
            builds.back().tablet_total_work->setRowCount(rows);

            QStringList name_columns;
            name_columns << "Наименование" << "Всего" << "Завершено" << "Осталось";

            builds.back().tablet_total_work->setHorizontalHeaderLabels(name_columns);
            builds.back().tablet_total_work->setColumnWidth(0, 375);
        }
    }
}

void MainWindow::change_name_tab()
{
    QString lineedit_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    int index = 0;
    for(; beg != builds.end(); ++beg, ++index)
    {
        if(lineedit_name == beg->name_str->objectName())
        {
            ui->tabWidget->setTabText(index, beg->name_str->text());
            break;
        }
    }
}

void MainWindow::check_first_floor()
{
    QString checkbox_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(checkbox_name == beg->first_floor_lived->objectName())
        {
            if(beg->first_floor_lived->isChecked())
            {
                beg->apartments_on_1fl_cnt->setEnabled(true);
            }
            else
            {
                beg->apartments_on_1fl_cnt->setEnabled(false);
                beg->apartments_on_1fl_cnt->setValue(0);
            }
            break;
        }
    }
}

void MainWindow::calculate_total_apartments()
{
    QString spinbox_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(spinbox_name == beg->floors_cnt->objectName() ||
           spinbox_name == beg->entrances_cnt->objectName() ||
           spinbox_name == beg->apartments_cnt->objectName() ||
           spinbox_name == beg->apartments_on_1fl_cnt->objectName()
          )
        {
            int total = (beg->floors_cnt->value() - 1) * beg->entrances_cnt->value() * beg->apartments_cnt->value();

            if(beg->apartments_on_1fl_cnt != 0)
                total += beg->apartments_on_1fl_cnt->value() * beg->entrances_cnt->value();

            beg->apartments_total_cnt->setValue(total);

            //calculate_total_budget_auto
            int total_ap = beg->apartments_total_cnt->value() * beg->total_price_ap_str_cnt->text().toInt();
            int total_en = beg->entrances_cnt->value() * beg->total_price_ent_str_cnt->text().toInt();
            int total_price = total_ap + total_en;

            beg->budget_cnt_auto->setText(QString::number(total_price));

            int executed = 0;
            beg->budget_executed_cnt_auto->setText(QString::number(executed));

            int remains = total_price - executed;
            beg->budget_remains_cnt_auto->setText(QString::number(remains));
            break;
        }
    }
}

void MainWindow::enter_job() //TODO упростить код создания строчек, уменьшить выделение временных объектов и сделать их удаление
{
    QString spinbox_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(spinbox_name == beg->apartments_total_cnt->objectName())
        {
            beg->fill_tablet_works();

            // //builds[index].apartments_total_cnt->value()
            // int rows = 4;
            // beg->tablet_total_work->setRowCount(rows);
            // qInfo() << QString("%1 _ %2").arg("Row").arg(rows);

            // //Enter name of a job in col = 0(first)
            // int col = 0;
            // QTableWidgetItem *appartment_1_stage = new QTableWidgetItem("Квартиры 1 этап");
            // beg->tablet_total_work->setItem(0, col, appartment_1_stage);

            // QTableWidgetItem *appartment_2_stage = new QTableWidgetItem("Квартиры 2 этап");
            // beg->tablet_total_work->setItem(1, col, appartment_2_stage);

            // QTableWidgetItem *entrances_1_stage = new QTableWidgetItem("Подъезды 1 этап");
            // beg->tablet_total_work->setItem(2, col, entrances_1_stage);

            // QTableWidgetItem *entrances_2_stage = new QTableWidgetItem("Подъезды 2 этап");
            // beg->tablet_total_work->setItem(3, col, entrances_2_stage);

            // //Enter count of a job in col = 1
            // col = 1;
            // QTableWidgetItem *appartment_1_stage_cnt = new QTableWidgetItem(QString::number(beg->apartments_total_cnt->value()));
            // beg->tablet_total_work->setItem(0, col, appartment_1_stage_cnt);

            // QTableWidgetItem *appartment_2_stage_cnt = new QTableWidgetItem(QString::number(beg->apartments_total_cnt->value()));
            // beg->tablet_total_work->setItem(1, col, appartment_2_stage_cnt);

            // QTableWidgetItem *entrances_1_stage_cnt = new QTableWidgetItem(QString::number(beg->entrances_cnt->value()));
            // beg->tablet_total_work->setItem(2, col, entrances_1_stage_cnt);

            // QTableWidgetItem *entrances_2_stage_cnt = new QTableWidgetItem(QString::number(beg->entrances_cnt->value()));
            // beg->tablet_total_work->setItem(3, col, entrances_2_stage_cnt);

            // //Enter count of a finished job in col = 2
            // col = 2;
            // int finished_ap = 0;
            // int finished_en = 0;

            // QTableWidgetItem *appartment_1_stage_finished = new QTableWidgetItem(QString::number(finished_ap));
            // beg->tablet_total_work->setItem(0, col, appartment_1_stage_finished);

            // QTableWidgetItem *appartment_2_stage_finished = new QTableWidgetItem(QString::number(finished_ap));
            // beg->tablet_total_work->setItem(1, col, appartment_2_stage_finished);

            // QTableWidgetItem *entrances_1_stage_finished = new QTableWidgetItem(QString::number(finished_en));
            // beg->tablet_total_work->setItem(2, col, entrances_1_stage_finished);

            // QTableWidgetItem *entrances_2_stage_finished = new QTableWidgetItem(QString::number(finished_en));
            // beg->tablet_total_work->setItem(3, col, entrances_2_stage_finished);

            // //Enter count of a remain job in col = 3
            // col = 3;
            // int remain_ap = beg->apartments_total_cnt->value() - finished_ap;
            // int remain_en = beg->entrances_cnt->value() - finished_en;

            // QTableWidgetItem *appartment_1_stage_remain = new QTableWidgetItem(QString::number(remain_ap));
            // //appartment_1_stage_remain->setTextAlignment(Qt::AlignCenter);
            // beg->tablet_total_work->setItem(0, col, appartment_1_stage_remain);
            // beg->tablet_total_work->item(0, col)->setTextAlignment(Qt::AlignCenter);

            // QTableWidgetItem *appartment_2_stage_remain = new QTableWidgetItem(QString::number(remain_ap));
            // appartment_2_stage_remain->setTextAlignment(Qt::AlignCenter);
            // beg->tablet_total_work->setItem(1, col, appartment_2_stage_remain);

            // QTableWidgetItem *entrances_1_stage_remain = new QTableWidgetItem(QString::number(remain_en));
            // entrances_1_stage_remain->setTextAlignment(Qt::AlignCenter);
            // beg->tablet_total_work->setItem(2, col, entrances_1_stage_remain);

            // QTableWidgetItem *entrances_2_stage_remain = new QTableWidgetItem(QString::number(remain_en));
            // entrances_2_stage_remain->setTextAlignment(Qt::AlignCenter);
            // beg->tablet_total_work->setItem(3, col, entrances_2_stage_remain);

            //calculate_total_budget_auto
            int total_ap = beg->apartments_total_cnt->value() * beg->total_price_ap_str_cnt->text().toInt();
            int total_en = beg->entrances_cnt->value() * beg->total_price_ent_str_cnt->text().toInt();
            int total_price = total_ap + total_en;

            beg->budget_cnt_auto->setText(QString::number(total_price));

            int executed = 0;
            beg->budget_executed_cnt_auto->setText(QString::number(executed));

            int remains = total_price - executed;
            beg->budget_remains_cnt_auto->setText(QString::number(remains));

            break;
        }
    }
}

void MainWindow::calculate_total_price()
{
    QString lineedit_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(lineedit_name == beg->first_stage_ap_str_cnt->objectName() ||
           lineedit_name == beg->second_stage_ap_str_cnt->objectName()   )
        {
            int total = beg->first_stage_ap_str_cnt->text().toInt() + beg->second_stage_ap_str_cnt->text().toInt();

            beg->total_price_ap_str_cnt->setText(QString::number(total));
            break;
        }
        if(lineedit_name == beg->first_stage_ent_str_cnt->objectName() ||
           lineedit_name == beg->second_stage_ent_str_cnt->objectName()   )
        {
            int total = beg->first_stage_ent_str_cnt->text().toInt() + beg->second_stage_ent_str_cnt->text().toInt();

            beg->total_price_ent_str_cnt->setText(QString::number(total));
            break;
        }
    }
}

void MainWindow::calculate_total_budget_auto()
{
    QString lineedit_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(lineedit_name == beg->total_price_ap_str_cnt->objectName() ||
           lineedit_name == beg->total_price_ent_str_cnt->objectName() )
        {
            int total_ap = beg->apartments_total_cnt->value() * beg->total_price_ap_str_cnt->text().toInt();
            int total_en = beg->entrances_cnt->value() * beg->total_price_ent_str_cnt->text().toInt();
            int total = total_ap + total_en;

            beg->budget_cnt_auto->setText(QString::number(total));

            int executed = 0;
            beg->budget_executed_cnt_auto->setText(QString::number(executed));

            int remains = total - executed;
            beg->budget_remains_cnt_auto->setText(QString::number(remains));

            break;
        }
    }
}

void MainWindow::edit_tablet_adding_work()
{
    QString pushbutton_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(pushbutton_name == beg->add_row->objectName())
        {
            beg->add_row_lst();

            connect(beg->tablet_adding_work, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(check_symbols()));

            break;
        }
        if(pushbutton_name == beg->delete_row->objectName())
        {
            beg->delete_row_lst();
            break;
        }
    }
}

void MainWindow::check_symbols()
{
    QString w_name = QObject::sender()->objectName();

    auto beg = builds.begin();
    //int index = 0;
    for(; beg != builds.end(); ++beg)//, ++index)
    {
        if(w_name == beg->budget_str_cnt->objectName())
        {
            beg->budget_str_cnt->setText(adding_funcs::delete_letter(beg->budget_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->budget_executed_str_cnt->objectName())
        {
            beg->budget_executed_str_cnt->setText(adding_funcs::delete_letter(beg->budget_executed_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->budget_remains_str_cnt->objectName())
        {
            beg->budget_remains_str_cnt->setText(adding_funcs::delete_letter(beg->budget_remains_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->first_stage_ap_str_cnt->objectName())
        {
            beg->first_stage_ap_str_cnt->setText(adding_funcs::delete_letter(beg->first_stage_ap_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->second_stage_ap_str_cnt->objectName())
        {
            beg->second_stage_ap_str_cnt->setText(adding_funcs::delete_letter(beg->second_stage_ap_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->total_price_ap_str_cnt->objectName())
        {
            beg->total_price_ap_str_cnt->setText(adding_funcs::delete_letter(beg->total_price_ap_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->first_stage_ent_str_cnt->objectName())
        {
            beg->first_stage_ent_str_cnt->setText(adding_funcs::delete_letter(beg->first_stage_ent_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->second_stage_ent_str_cnt->objectName())
        {
            beg->second_stage_ent_str_cnt->setText(adding_funcs::delete_letter(beg->second_stage_ent_str_cnt->text()));
            //qInfo() << text;
            break;
        }
        if(w_name == beg->total_price_ent_str_cnt->objectName())
        {
            beg->total_price_ent_str_cnt->setText(adding_funcs::delete_letter(beg->total_price_ent_str_cnt->text()));
            //qInfo() << beg->total_price_ent_str_cnt->text();
            break;
        }
        if(w_name == beg->tablet_adding_work->objectName())
        {
            if(beg->tablet_adding_work->currentRow() >= 0)
            {
                int row = beg->tablet_adding_work->currentRow();
                int column = beg->tablet_adding_work->currentColumn();

                if(column != 0)
                    beg->tablet_adding_work->item(row, column)->setText(adding_funcs::delete_letter(beg->tablet_adding_work->item(row, column)->text()));
            }
            break;
        }
    }
}
