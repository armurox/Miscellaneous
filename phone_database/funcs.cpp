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
        cout << "Result: " << it -> first << "\n";
    }
}

void p_command(map<string, phone_nums> &db)
{
    string lastname, firstname;
    cin >> lastname >> firstname;
    map<string, phone_nums>::iterator it = db.find(lastname + "," + firstname);
    if (it != db.end())
    {
        for (phone_nums::iterator it_2 = (it -> second).begin(), n = (it -> second).end(); it_2 != n; ++it_2)
        {
            if (it_2 -> second != "")
            {
                cout << "Result: " << it_2 -> first << "," << it_2 -> second << "\n";
            }
            
        }
    }

    else
    {
        cout << "Contact not found\n";
    }
}

void n_command(map<string, phone_nums> &db)
{
    string lastname, firstname;
    cin >> lastname >> firstname;
    if (db.find(lastname + "," + firstname) == db.end())
    {
        cout << "Contact not found\n";
        return;
    }

    string type;
    string phone_num;
    cin >> type;
    cin >> phone_num;
    if (db[lastname + "," + firstname].find(type) == db[lastname + "," + firstname].end())
    {
        cout << "Invalid phone number type" << endl;
        return;
    }

    if (db[lastname + "," + firstname][type] == "")
    {
        db[lastname + "," + firstname][type] = phone_num;
        cout << "Phone number added\n";
    }

    else
    {
        db[lastname + "," + firstname][type] = phone_num;
        cout << "Phone number replaced\n";
    }
    
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


