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
        cout << "Contact Created\n";
    }
}

void d_command(map<string, phone_nums> &db)
{
    string lastname, firstname;
    cin >> lastname >> firstname;
    if (db.find(lastname + "," + firstname) != db.end())
    {
        db.erase(lastname + "," + firstname);
        cout << "Contact Deleted\n";
    }

    else
    {
        cout << "Contact not found\n";
    }
}

void l_command(map<string, phone_nums> &db)
{
    for (map<string, phone_nums>::iterator it = db.begin(), n = db.end(); it != n; ++it)
    {
        cout << it -> first << "\n";
    }
}

void p_command(map<string, phone_nums> &db)
{
    // TODO
    return;
}

void n_command(map<string, phone_nums> &db)
{
    // TODO
    return;
}

void x_command(map<string, phone_nums> &db)
{
    // TODO
    return;
}

void s_command(map<string, phone_nums> &db)
{
    // TODO
    return;
}

void r_command(map<string, phone_nums> &db)
{
    // TODO
    return;
}


