#include "save_data.h"
#include <QDebug>

#include "address.h"

void save_data::save_file(std::list<Address> &builds)
{
    QSettings settings("data.ini", QSettings::IniFormat);
    settings.clear();

    QDateTime date = QDateTime::currentDateTime();
    settings.beginGroup("General");
    settings.setValue("description", "Don't edit this file");
    settings.setValue("date", date.toString());
    settings.setValue("count_obj", builds.size());
    settings.endGroup();

    QString data = "";
    int ind = 0;
    for(auto beg = builds.begin(); beg != builds.end(); ++beg, ++ind)
    {
        //===================================Наименование объекта===================================//
        //=====================================Name of an object====================================//
        settings.beginGroup("Object_" + QString::number(ind));

        data = beg->get_name();
        settings.setValue("name", data);

        data = beg->adr_str->text();
        settings.setValue("address", data);

        data = beg->developer_str->text();
        settings.setValue("company", data);

        data.clear();
        //settings.endGroup();

        //===================================Кол-во этажей, подъездов, квартир===================================//
        //================================Count of floors, entrances, apartments=================================//
        //settings.beginGroup("Count_rooms_" + QString::number(ind));

        data = QString::number(beg->floors_cnt->value());
        settings.setValue("floors", data);

        data = QString::number(beg->entrances_cnt->value());
        settings.setValue("entrances", data);

        data = QString::number(beg->apartments_cnt->value());
        settings.setValue("apartments", data);

        data = beg->first_floor_lived->isChecked()? "true" : "false";
        settings.setValue("first_floor_lived", data);

        data = QString::number(beg->apartments_on_1fl_cnt->value());
        settings.setValue("apartments_on_1fl_cnt", data);

        data = QString::number(beg->apartments_total_cnt->value());
        settings.setValue("apartments_total_cnt", data);

        data.clear();
        //settings.endGroup();

        //===================================Бюджет===================================//
        //===================================Budget===================================//
        //settings.beginGroup("Budget_" + QString::number(ind));

        data = beg->budget_str_cnt->text();
        settings.setValue("budget", data);

        data = beg->budget_executed_str_cnt->text();
        settings.setValue("executed", data);

        data = beg->budget_remains_str_cnt->text();
        settings.setValue("remains", data);

        data.clear();
        //settings.endGroup();

        //===================================Цена за квартиру===================================//
        //================================Price for an apartment================================//
        //settings.beginGroup("Price_apartment_" + QString::number(ind));

        data = beg->first_stage_ap_str_cnt->text();
        settings.setValue("first_stage_price_ap", data);

        data = beg->second_stage_ap_str_cnt->text();
        settings.setValue("second_stage_price_ap", data);

        data = beg->total_price_ap_str_cnt->text();
        settings.setValue("total_price_ap", data);

        data.clear();
        //settings.endGroup();

        //===================================Цена за подъезд===================================//
        //================================Price for an entrance================================//
        //settings.beginGroup("Price_entrance_" + QString::number(ind));

        data = beg->first_stage_ent_str_cnt->text();
        settings.setValue("first_stage_price_ent", data);

        data = beg->second_stage_ent_str_cnt->text();
        settings.setValue("second_stage_price_ent", data);

        data = beg->total_price_ent_str_cnt->text();
        settings.setValue("total_price_ent", data);

        data.clear();
        //settings.endGroup();

        //===================================Дополнительные работы===================================//
        //========================================Adding work========================================//
        //settings.beginGroup("Adding_works" + QString::number(ind));
        int i = 0;

        data = QString::number(beg->list_adding_works.size());
        settings.setValue("size_adding_works", data);
        data.clear();

        for(auto row = beg->list_adding_works.begin(); row != beg->list_adding_works.end(); ++row, ++i)
        {
            for(auto col = row->begin(); col != row->end(); ++col)
            {
                if(col == row->begin())
                {
                    data = (*col)->text();
                    settings.setValue("name_adding_work_" + QString::number(i), data);
                    data.clear();
                    continue;
                }

                data += (*col)->text();
                if(col != --row->end())
                    data += " ";
            }
            settings.setValue("count_adding_work_" + QString::number(i), data);
            data.clear();
        }

        data.clear();
        //settings.endGroup();

        //===================================Объём работ===================================//
        //=====================================All work====================================//
        //settings.beginGroup("All_works" + QString::number(ind));

        data = QString::number(beg->list_works.size());
        settings.setValue("size_works", data);
        data.clear();

        i = 0;
        for(auto row = beg->list_works.begin(); row != beg->list_works.end(); ++row, ++i)
        {
            for(auto col = row->begin(); col != row->end(); ++col)
            {
                if(col == row->begin())
                {
                    data = (*col)->text();
                    settings.setValue("name_work_" + QString::number(i), data);
                    data.clear();
                    continue;
                }

                data += (*col)->text();
                if(col != --row->end())
                    data += " ";
            }
            settings.setValue("count_work_" + QString::number(i), data);
            data.clear();
        }

        data.clear();
        //settings.endGroup();

        //===================================Расчётный бюджет===================================//
        //======================================Auto Budget=====================================//
        //settings.beginGroup("Auto_budget_" + QString::number(ind));

        data = beg->budget_cnt_auto->text();
        settings.setValue("auto_budget", data);

        data = beg->budget_executed_cnt_auto->text();
        settings.setValue("auto_executed", data);

        data = beg->budget_remains_cnt_auto->text();
        settings.setValue("auto_remains", data);

        data.clear();
        //settings.endGroup();

        //===================================Бригады===================================//
        //====================================Groups===================================//
        //settings.beginGroup("Groups_" + QString::number(ind));

        data = QString::number(beg->list_groups.size());
        settings.setValue("count_groups", data);
        data.clear();
        i = 0;
        for(auto row = 0; row < beg->tablet_list_groups->rowCount(); ++row, ++i)
        {
            data = beg->tablet_list_groups->item(row, 0)->text();
            settings.setValue("name_group_" + QString::number(i), data);

            data = beg->tablet_list_groups->item(row, 1)->text();
            settings.setValue("pay_group_" + QString::number(i), data);
            data.clear();
        }

        data.clear();
        //settings.endGroup();

        //===================================Состав Бригады===================================//
        //=================================Members of a group=================================//
        //settings.beginGroup("Members_groups_" + QString::number(ind));
        i = 0;
        for(auto group = beg->list_groups.begin(); group != beg->list_groups.end(); ++group, ++i)
        {
            data = QString::number((*group)->list_employees.size());
            settings.setValue("count_employees_gr_" + QString::number(i), data);
            data.clear();

            int j = 0;

            for(int row = 0; row < (*group)->tablet_list_employees->rowCount(); ++row, ++j)
            {
                data = (*group)->tablet_list_employees->item(row, 0)->text();
                settings.setValue("name_employee_gr_" + QString::number(i) + "_" + QString::number(j), data);

                data = (*group)->tablet_list_employees->item(row, 1)->text();
                settings.setValue("pay_employee_gr_" + QString::number(i) + "_" + QString::number(j), data);
                data.clear();
            }

            data = QString::number((*group)->list_tasks.size());
            settings.setValue("size_tasks_gr_" + QString::number(i), data);
            data.clear();

            data = QString::number((*group)->tablet_list_tasks->columnCount());
            settings.setValue("count_columns_tasks_gr_" + QString::number(i), data);
            data.clear();

            j = 0;
            for(auto row = (*group)->list_tasks.begin(); row != (*group)->list_tasks.end(); ++row, ++j)
            {
                for(auto col = row->begin(); col != row->end(); ++col)
                {
                    if(col == row->begin())
                    {
                        data = (*col)->text();
                        settings.setValue("name_work_gr_" + QString::number(i) + "_" + QString::number(j), data);
                        data.clear();
                        continue;
                    }

                    data += (*col)->text();
                    if(col != --row->end())
                        data += " ";
                }
                settings.setValue("count_work_gr_" + QString::number(i) + "_" + QString::number(j), data);
                data.clear();
            }

            data = QString::number((*group)->list_pay.size());
            settings.setValue("size_pay_gr_" + QString::number(i), data);
            data.clear();

            j = 0;

            for(int row = 0; row < (*group)->tablet_list_pay->rowCount(); ++row, ++j)
            {
                if(row == 0)
                {
                    qDebug() << "save_data::save_file(std::list<Address> &builds): size calendar = " << (*group)->calendar.size();
                    for(auto date = (*group)->calendar.begin(); date != (*group)->calendar.end(); ++date)
                    {
                        data += (*date)->text();
                        if(date != --(*group)->calendar.end())
                            data += " ";
                    }
                    settings.setValue("dates_pay_gr_" + QString::number(i) + "_" + QString::number(j), data);
                    data.clear();
                }
                else if(row == 1)
                {
                    for(int col = 1; col < (*group)->tablet_list_pay->columnCount(); ++col)
                    {
                        data += (*group)->tablet_list_pay->item(row, col)->text();
                        if(col != (*group)->tablet_list_pay->columnCount() - 1)
                            data += " ";
                    }
                    settings.setValue("count_cal_pay_gr_" + QString::number(i) + "_" + QString::number(j), data);
                    data.clear();
                }
                else if(row == 2)
                {
                    for(int col = 1; col < (*group)->tablet_list_pay->columnCount(); ++col)
                    {
                        data += (*group)->tablet_list_pay->item(row, col)->text();
                        if(col != (*group)->tablet_list_pay->columnCount() - 1)
                            data += " ";
                    }
                    settings.setValue("count_real_pay_gr_" + QString::number(i) + "_" + QString::number(j), data);
                    data.clear();
                }
                else if(row == 3)
                {
                    for(int col = 1; col < (*group)->tablet_list_pay->columnCount(); ++col)
                    {
                        data += (*group)->tablet_list_pay->item(row, col)->text();
                        if(col != (*group)->tablet_list_pay->columnCount() - 1)
                            data += " ";
                    }
                    settings.setValue("count_ream_pay_gr_" + QString::number(i) + "_" + QString::number(j), data);
                    data.clear();
                }
                data.clear();
            }
            data.clear();
        }

        data.clear();
        settings.endGroup();
    }
    qDebug() << "Save a data successfull: data = " << data;
}

void save_data::load_file(QSettings &settings, std::list<Address> &builds, int ind)
{
    QString data = "";
    auto build = &builds.back();

    //===================================Наименование объекта===================================//
    //=====================================Name of an object====================================//
    settings.beginGroup("Object_" + QString::number(ind));
    data = settings.value("name", "").toString();
    build->set_name(data);
    build->name_str->setText(data);

    data = settings.value("address", "").toString();
    build->adr_str->setText(data);

    data = settings.value("company", "").toString();
    build->developer_str->setText(data);

    qDebug() << "Load a data successfull: beg->name_str = " << build->name_str->text();
    data.clear();


    //===================================Кол-во этажей, подъездов, квартир===================================//
    //================================Count of floors, entrances, apartments=================================//
    //settings.beginGroup("Count_rooms_" + QString::number(ind));

    data = settings.value("floors", "0").toString();
    build->floors_cnt->setValue(data.toInt());

    data = settings.value("entrances", "0").toString();
    build->entrances_cnt->setValue(data.toInt());

    data = settings.value("apartments", "0").toString();
    build->apartments_cnt->setValue(data.toInt());

    data = settings.value("first_floor_lived", "false").toString();
    bool chk = (data == "true")? true : false;
    build->first_floor_lived->setChecked(chk);

    data = settings.value("apartments_on_1fl_cnt", "0").toString();
    build->apartments_on_1fl_cnt->setValue(data.toInt());

    data = settings.value("apartments_total_cnt", "0").toString();
    build->apartments_total_cnt->setValue(data.toInt());

    data.clear();
    //settings.endGroup();

    //===================================Бюджет===================================//
    //===================================Budget===================================//
    //settings.beginGroup("Budget_" + QString::number(ind));

    data = settings.value("budget", "").toString();
    build->budget_str_cnt->setText(data);

    data = settings.value("executed", "").toString();
    build->budget_executed_str_cnt->setText(data);

    data = settings.value("remains", "").toString();
    build->budget_remains_str_cnt->setText(data);

    data.clear();
    //settings.endGroup();

    //===================================Цена за квартиру===================================//
    //================================Price for an apartment================================//
    //settings.beginGroup("Price_apartment_" + QString::number(ind));

    data = settings.value("first_stage_price_ap", "").toString();
    build->first_stage_ap_str_cnt->setText(data);

    data = settings.value("second_stage_price_ap", "").toString();
    build->second_stage_ap_str_cnt->setText(data);

    data = settings.value("total_price_ap", "").toString();
    build->total_price_ap_str_cnt->setText(data);

    data.clear();
    //settings.endGroup();

    //===================================Цена за подъезд===================================//
    //================================Price for an entrance================================//
    //settings.beginGroup("Price_entrance_" + QString::number(ind));

    data = settings.value("first_stage_price_ent", "").toString();
    build->first_stage_ent_str_cnt->setText(data);

    data = settings.value("second_stage_price_ent", "").toString();
    build->second_stage_ent_str_cnt->setText(data);

    data = settings.value("total_price_ent", "").toString();
    build->total_price_ent_str_cnt->setText(data);

    data.clear();
    //settings.endGroup();

    //===================================Дополнительные работы===================================//
    //========================================Adding work========================================//
    //settings.beginGroup("Adding_works" + QString::number(ind));

    int size_adding_works = settings.value("size_adding_works", "0").toInt();

    for(int i = 0; i < size_adding_works; ++i)
    {
        build->add_row_tablet_adding_works();

        data = settings.value("name_adding_work_" + QString::number(i), "").toString();
        build->list_adding_works.back().front()->setText(data);

        data = settings.value("count_adding_work_" + QString::number(i), "").toString();

        QStringList datas = data.split(" ");

        auto cnt = ++build->list_adding_works.back().begin();
        for(auto it = datas.begin(); it != datas.end() && cnt != build->list_adding_works.back().end(); it++, cnt++)
        {
            (*cnt)->setText(*it);
        }
    }

    data.clear();
    //settings.endGroup();

    //===================================Объём работ===================================//
    //=====================================All work====================================//
    //settings.beginGroup("All_works" + QString::number(ind));

    int size_works = settings.value("size_works", "0").toInt();

    int i_tw = 0;
    for(auto it = build->list_works.begin(); it != build->list_works.end(); ++it, ++i_tw)
    {
        data = settings.value("name_work_" + QString::number(i_tw), "").toString();
        it->front()->setText(data);

        data = settings.value("count_work_" + QString::number(i_tw), "").toString();

        QStringList datas = data.split(" ");

        auto cnt = ++(it->begin());
        for(auto word = datas.begin(); word != datas.end() && cnt != it->end(); word++, cnt++)
        {
            (*cnt)->setText(*word);
        }
    }

    for(; i_tw < size_works; ++i_tw)
    {
        build->add_row_tablet_total_works();

        data = settings.value("name_work_" + QString::number(i_tw), "").toString();
        build->list_works.back().front()->setText(data);

        data = settings.value("count_work_" + QString::number(i_tw), "").toString();

        QStringList datas = data.split(" ");

        auto cnt = ++build->list_works.back().begin();
        for(auto it = datas.begin(); it != datas.end() && cnt != build->list_works.back().end(); it++, cnt++)
        {
            (*cnt)->setText(*it);
        }
    }

    data.clear();
    //settings.endGroup();

    //===================================Расчётный бюджет===================================//
    //======================================Auto Budget=====================================//
    //settings.beginGroup("Auto_budget_" + QString::number(ind));

    data = settings.value("auto_budget", "").toString();
    build->budget_cnt_auto->setText(data);

    data = settings.value("auto_executed", "").toString();
    build->budget_executed_cnt_auto->setText(data);

    data = settings.value("auto_remains", "").toString();
    build->budget_remains_cnt_auto->setText(data);

    data.clear();
    //settings.endGroup();

    //===================================Бригады===================================//
    //====================================Groups===================================//
    //settings.beginGroup("Groups_" + QString::number(ind));


    int count_groups = settings.value("count_groups", "0").toInt();
    bool clk = count_groups > 0? true : false;
    for(int i = 0; i < count_groups; ++i)
    {
        if(build->button_add_emp)
            build->button_add_emp->clicked(clk);

        data = settings.value("name_group_" + QString::number(i), "").toString();
        build->tablet_list_groups->item(i, 0)->setText(data);

        data = settings.value("pay_group_" + QString::number(i), "").toString();
        build->tablet_list_groups->item(i, 1)->setText(data);
    }

    data.clear();
    //settings.endGroup();

    //===================================Состав Бригады===================================//
    //=================================Members of a group=================================//
    //settings.beginGroup("Members_groups_" + QString::number(ind));

    int i_g = 0;
    for(auto group = build->list_groups.begin(); group != build->list_groups.end(); ++group, ++i_g)
    {
        int count_employees_gr = settings.value("count_employees_gr_" + QString::number(i_g), "0").toInt();

        for(int row = 0; row < count_employees_gr; ++row)
        {
            (*group)->add_employee();

            data = settings.value("name_employee_gr_" + QString::number(i_g) + "_" + QString::number(row), "").toString();
            (*group)->tablet_list_employees->item(row, 0)->setText(data);

            data = settings.value("pay_employee_gr_" + QString::number(i_g) + "_" + QString::number(row), "").toString();
            (*group)->tablet_list_employees->item(row, 1)->setText(data);

            data.clear();
        }

        int size_tasks_gr = settings.value("size_tasks_gr_" + QString::number(i_g), "0").toInt();
        int count_columns_tasks_gr = settings.value("count_columns_tasks_gr_" + QString::number(i_g), "1").toInt();


        for(int col = 2; col < count_columns_tasks_gr; ++col)
        {
            (*group)->add_pay();
        }

        int j = 0;
        for(auto row = (*group)->list_tasks.begin(); row != (*group)->list_tasks.end(); ++row, ++j)
        {
            data = settings.value("count_work_gr_" + QString::number(i_g)+ "_" + QString::number(j), "").toString();

            QStringList datas = data.split(" ");

            auto cnt = ++(row->begin());
            for(auto word = datas.begin(); word != datas.end() && cnt != row->end(); word++, cnt++)
            {
                (*cnt)->setText(*word);
            }
        }

        //int size_pay_gr = settings.value("size_pay_gr_" + QString::number(i_g), "0").toInt();

        j = 0;

        for(int row = 0; row < (*group)->tablet_list_pay->rowCount(); ++row, ++j)
        {
            if(row == 0)
            {
                data = settings.value("dates_pay_gr_" + QString::number(i_g)+ "_" + QString::number(j), "").toString();

                QStringList datas = data.split(" ");

                auto cnt = (*group)->calendar.begin();
                for(auto word = datas.begin(); word != datas.end() && cnt != (*group)->calendar.end(); word++, cnt++)
                {
                    (*cnt)->setDate(QDate::fromString(*word, "dd.MM.yyyy"));
                }
            }
            else if(row == 1)
            {
                data = settings.value("count_cal_pay_gr_" + QString::number(i_g)+ "_" + QString::number(j), "").toString();

                QStringList datas = data.split(" ");

                int col = 1;
                for(auto word = datas.begin(); word != datas.end() && col < (*group)->tablet_list_pay->columnCount(); word++, col++)
                {
                    (*group)->tablet_list_pay->item(row, col)->setText(*word);
                }
            }
            else if(row == 2)
            {
                data = settings.value("count_real_pay_gr_" + QString::number(i_g)+ "_" + QString::number(j), "").toString();

                QStringList datas = data.split(" ");

                int col = 1;
                for(auto word = datas.begin(); word != datas.end() && col < (*group)->tablet_list_pay->columnCount(); word++, col++)
                {
                    (*group)->tablet_list_pay->item(row, col)->setText(*word);
                }
            }
            else if(row == 3)
            {
                data = settings.value("count_ream_pay_gr_" + QString::number(i_g)+ "_" + QString::number(j), "").toString();

                QStringList datas = data.split(" ");

                int col = 1;
                for(auto word = datas.begin(); word != datas.end() && col < (*group)->tablet_list_pay->columnCount(); word++, col++)
                {
                    (*group)->tablet_list_pay->item(row, col)->setText(*word);
                }
            }
            data.clear();
        }
        data.clear();
    }

    data.clear();

    settings.endGroup();
    qDebug() << "Load a data successfully ...";
}
