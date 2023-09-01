#include "funcs.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void c_command(map<string, phone_nums> &db)
{
    string lastname, firstname;
    cin >> lastname >> firstname;
    if (db.find(lastname + "," + firstname) != db.end())
    {
        cout << "Contact already exists\n";
    }

    else
    {
        db[lastname + "," + firstname] = {{"HOME", ""}, {"CELL", ""}, {"WORK", ""}, {"FAX", ""}, {"VOIP", ""}};
    }
}

void l_command(map<string, phone_nums> &db)
{
    string lastname, firstname;
    cin >> lastname >> firstname;
    if (db.find(lastname + "," + firstname) != db.end())
    {
        cout << "Contact not found\n";
    }

    else
    {
        db.erase(lastname + "," + firstname);
    }
}

void d_command(map<string, phone_nums> &db)
{
    return;
}

void p_command(map<string, phone_nums> &db)
{
    return;
}

void n_command(map<string, phone_nums> &db)
{
    return;
}

void x_command(map<string, phone_nums> &db)
{
    return;
}

void s_command(map<string, phone_nums> &db)
{
    return;
}

void r_command(map<string, phone_nums> &db)
{
    return;
}


