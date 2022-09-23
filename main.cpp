#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

class Account
{
    string first_name;
    string last_name;
    int Balance = 0;
    int Account_no = 0;

public:
    Account()
    {
    }
    void set_data(string fname, string lname, int balance, int acc_no)
    {
        first_name = fname;
        last_name = lname;
        Balance = balance;
        Account_no = acc_no;
    }
    int get_accno()
    {
        return Account_no;
    }
    string get_fname()
    {
        return first_name;
    }
    string get_lname()
    {
        return last_name;
    }
    int get_balance()
    {
        return Balance;
    }
    void deposit(int a)
    {
        Balance += a;
    }
    void withdrawal(int a)
    {
        Balance -= a;
    }
    void display()
    {
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: " << last_name << endl;
        cout << "Balance: " << Balance << endl;
        cout << "Account Number: " << Account_no << endl;
        cout << endl;
    }
};

void balance_enq(int a, vector<Account> a1)
{
    vector<Account>::iterator i;
    for (i = a1.begin(); i != a1.end(); i++)
    {
        if (a == (*i).get_accno())
        {
            cout << "Your Account Details" << endl;
            (*i).display();
            return;
        }
    }
    if (i == a1.end())
    {
        cout << "Invalid account number!!" <<endl<<endl <<endl;
        return;
    }
}

void deposit(int a, vector<Account> &a1)
{
    int amount = 0;
    vector<Account>::iterator i;
    for (i = a1.begin(); i != a1.end(); i++)
    {
        if (a == (*i).get_accno())
        {
            cout << "Enter amount to deposit" << endl;
            cin >> amount;
            (*i).deposit(amount);
            return;
        }
    }
    if (i == a1.end())
    {
     cout << "Invalid account number!!" <<endl<<endl <<endl;
        return;
    }
}

void Withdrawal(int a, vector<Account> &a1)
{
    int amount = 0;
    vector<Account>::iterator i;
    for (i = a1.begin(); i != a1.end(); i++)
    {
        if (a == (*i).get_accno())
        {
            cout << "Enter amount to withdraw" << endl;
            cin >> amount;
            (*i).withdrawal(amount);
            return;
        }
    }
    if (i == a1.end())
    {
        cout << "Invalid account number!!" <<endl<<endl <<endl;
        return;
    }
}

void delete_acc(int a, vector<Account> &a1)
{
    vector<Account>::iterator i;
    for (i = a1.begin(); i != a1.end(); i++)
    {
        if (a == (*i).get_accno())
            break;
    }

    if (i == a1.end())
    {
        cout << "Invalid account number" << endl;
        return;
    }
    for (; i != a1.end(); i++)
    {
        (*i) = (*(i + 1));
    }
    a1.pop_back();
}

int main()
{
    int choice, acc_no = 0, a, amount;
    string fname = "not", lname = "true";
    int Balance = -200;
    vector<Account> a1;
    ofstream file("record1.txt", ios::app);
    ifstream in("record1.txt", ios::in);
    while (!in.eof())
    {
        Account a;
        in >> fname >> lname >> Balance >> acc_no;
        a.set_data(fname, lname, Balance, acc_no);
        a1.push_back(a);
    }
    a1.pop_back();

    cout << "*** Banking System ***" << endl
         << endl;

    while (choice != 7)
    {
    
        cout << "\t Select one option below" << endl;
        cout << "\t 1 Open an Account" << endl;
        cout << "\t 2 Balance Enquiry" << endl;
        cout << "\t 3 Deposit" << endl;
        cout << "\t 4 Withdrawal" << endl;
        cout << "\t 5 Close an Account" << endl;
        cout << "\t 6 Show all Accounts" << endl;
        cout << "\t 7 Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Account a;
            acc_no++;
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter Initial Balance: ";
            cin >> Balance;
            cout << "Congratulations Account is Created" << endl
                 << endl;
            a.set_data(fname, lname, Balance, acc_no);
            a.display();
            a1.push_back(a);

            cout << "Congratulations Account is Created" << endl;

            break;
        }
        case 2:
        {
            cout << "Enter Account Number: ";
            cin >> a;
            balance_enq(a, a1);
            break;
        }
        case 3:
        {
            cout << "Enter Account Number: ";
            cin >> a;
            deposit(a, a1);
            break;
        }
        case 4:
        {
            cout << "Enter Account Number: ";
            cin >> a;
            Withdrawal(a, a1);
            break;
        }
        case 5:
        {
            cout << "Enter Account Number: ";
            cin >> a;
            delete_acc(a, a1);
            break;
        }
        case 6:
        {
            vector<Account>::iterator i;
            for (i = a1.begin(); i != a1.end(); i++)
            {
                (*i).display();
                cout << endl;
            }
            break;
        }

        case 7:
        {

            return 0;
        }
        }
        ofstream file("record1.txt", ios::out| ios::trunc);
        vector<Account>::iterator i;
        for(i = a1.begin(); i != a1.end(); i++){
            file<<i->get_fname()<<endl;
            file<<i->get_lname()<<endl;
            file<<i->get_balance()<<endl;
            file<<i->get_accno()<<endl;
        }
        file.close();
    }
    file.close();
    in.close();

}