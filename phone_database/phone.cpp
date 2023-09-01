#include <iostream>
#include <map>
#include <string>
#include "funcs.h"

using namespace std;

int main()
{
    map<string, phone_nums> phone_db;

    cout << "Info: Welcome to the phone database!\n";
    cout << "Info: Please enter a command\n";
    char command;
    cin >> command;
    while (command != 'Q')
    {
        switch (command)
        {
            case 'C':
                c_command(phone_db);
                break;
            
            case 'D':
                d_command(phone_db);
                break;

            case 'L':
                l_command(phone_db);
                break;

            case 'P':
                p_command(phone_db);
                break;

            case 'N':
                n_command(phone_db);
                break;

            case 'X':
                x_command(phone_db);
                break;

            case 'S':
                s_command(phone_db);
                break;

            case 'R':
                r_command(phone_db);
                break;
            
            default:
                cout << "Invalid command, try again\n";
                break;
        }
        cout << "Info: Please enter a command\n";
        cin >> command;
    }

    cout << "Info: Thank you for using the phone database!" << endl;
}
