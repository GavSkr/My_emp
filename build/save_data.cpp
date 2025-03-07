#include "save_data.h"
#include <QDebug>

#include "address.h"

void save_data::save_file(std::list<Address> builds)
{
    QSettings settings("123MY_settings.ini", QSettings::IniFormat);

    QString data = "";

    for(auto beg = builds.begin(); beg != builds.end(); ++beg)
    {
        data = beg->get_name();

        QTime e = QTime::currentTime();
        QDateTime f = QDateTime::currentDateTime();
        settings.beginGroup("Settings");
        settings.setValue( "data", data);
        settings.setValue("e",e.toString());
        settings.setValue("f",f.toString());
        settings.endGroup();
    }
    qDebug() << "Save a data successfull: data = " << data;
}

void save_data::load_file(QSettings &settings, std::list<Address> &builds)
{
    //QSettings settings("123MY_settings.ini", QSettings::IniFormat);

    QString data = "";

    for(auto beg = builds.begin(); beg != builds.end(); ++beg)
    {
        settings.beginGroup("Settings");
        data = settings.value("data", -1).toString();
        beg->set_name(data);
        beg->name_str->setText(data);
        qDebug() << "Load a data successfull: beg->name = " << beg->get_name();
        qDebug() << "Load a data successfull: beg->name_str = " << beg->name_str->text();
    }
    qDebug() << "Load a data successfull: data = " << data;
}
