#ifndef FUNCS_H
#define FUNCS_H

/*
 *This file defines some functions.
 */

#include <QString>

namespace adding_funcs
{
    void separate_name(const QString full_name, QString& name, QString& last_name);
    QString delete_letter(QString str);
}

#endif // FUNCS_H
