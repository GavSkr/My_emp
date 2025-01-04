#ifndef FUNCS_H
#define FUNCS_H

//#include <iostream>
#include <QString>

class Address;

namespace adding_funcs
{
    void separate_name(const QString full_name, QString& name, QString& last_name);
    QString delete_letter(QString str);
}

#endif // FUNCS_H
