#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    int acNo;
    double balance;
    static int count;

public:
    BankAccount()
    {
        cout << "Acoount Created" << endl;
        count++;
    }

    void input()
    {
        cout << "------------------------------------------\n";
        cout << "Enter name of account holder: ";
        cin >> name;
        cout << "Enter A/c No. of holder: ";
        cin >> acNo;
        cout << "Enter the balance: ";
        cin >> balance;
        cout << "------------------------------------------\n\n";
    }

    void deposit(double deposit)
    {
        if (deposit >= 0)
        {
            balance += deposit;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }

    void withdraw(double withdraw)
    {
        if (withdraw >= 0)
        {
            if (withdraw <= balance)
            {
                balance -= withdraw;
            }
            else
            {
                cout << "Withdraw amount can't be more than Balance" << endl;
            }
        }
        else
        {
            cout << "Withdraw can't we negetive" << endl;
        }
    }

    void display() const
    {
        cout << "\n--------------------------------\n";
        cout << "Name         :" << name << endl;
        cout << "A/c No.      :" << acNo << endl;
        cout << "Balance      :" << balance << endl;
        cout << "------------------------------------\n";
    }

    static void richestHolder(BankAccount *a, int n)
    {
        int rich = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].balance > a[rich].balance)
            {
                rich = i;
            }
        }
        cout << "\n*---*---*---*---*---*---*---*---*---*---*---*---*---*\n";
        cout << "Richest person is            : " << a[rich].name << endl;
        cout << "Balance of richest person is : " << a[rich].balance << endl;
        cout << "--------------------------------------------------------\n";
    }

    static void displayCount()
    {
        cout << "No. of Acounts created: " << count << endl;
    }

    ~BankAccount()
    {
        cout << "Account Deleted\n";
        count--;
    }
};

int BankAccount::count = 0;

int main()
{
    int n;
    cin >> n;

    BankAccount *a = new BankAccount[n];

    cout << "=======Enter A/c Holder Details=======\n";
    for (int i = 0; i < n; i++)
    {
        a[i].input();
    }

    cout << "\n----------------------------------------------------\n";
    int choice;
    bool g = true;
    while(g){
    cout << "Enter your choice\n";
    cout << "1. Deposit\n2. Withdraw\n3. Display All\n4. Find Richest\n5. Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        int m, t;
        cout << "Enter no. of holder: ";
        cin >> t;
        cout << "Enter Amt: ";
        cin >> m;
        a[t-1].deposit(m);
        break;
    case 2:
        int p, r;
        cout << "Enter no. of holder: ";
        cin >> r;
        cout << "Enter Amt: ";
        cin >> p;
        a[r-1].withdraw(p);
        break;
    case 3:
        for (int i = 0; i < n; i++)
        {
           a[i].display();
        }
        break;
    case 4:
        BankAccount::richestHolder(a, n);
        break;
    case 5:
       g =  false;
        break;
    default:
        cout << "Invalid input" << endl;
    }
}
    

    cout << "\n--------------------------------------------------\n";

    BankAccount::displayCount();

    delete[] a;

    return 0;
}