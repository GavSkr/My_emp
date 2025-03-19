#ifndef SAVE_DATA_H
#define SAVE_DATA_H

/*
 *This file defines a saving and loading of data of an application.
 */

#include <list>
#include <QSettings>
class Address;

namespace save_data
{
    void save_file(std::list<Address> &builds);
    void load_file(QSettings &settings, std::list<Address> &builds, int index);
}

#endif // SAVE_DATA_H
