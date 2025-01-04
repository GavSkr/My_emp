#include "funcs.h"
//#include "address.h"

void adding_funcs::separate_name(const QString full_name, QString &name, QString &last_name)
{
    bool space = false;

    for(auto i: full_name)
    {
        if(i != ' ' && !space) last_name += i;
        if(i == ' ' && last_name.size()) space = true;

        if(space && i != ' ') name += i;
        if(space && i == ' ' && name.size()) break;
    }
}

QString adding_funcs::delete_letter(QString str)
{
    for(auto i: str)
    {
        if(!i.isDigit())
        {
            //qInfo() << "isLetter: " << i;
            str.remove(i);
        }
    }
    return str;
}
