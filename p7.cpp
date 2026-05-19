#include <bits/stdc++.h>
using namespace std;

class Employee
{
protected:
    string name;
    int Id;

public:
    static int count;

    Employee()
    {
        count++;
    }

    // PURE VIRTUAL FUNCTIONS
    virtual void calcSalary() = 0;
    virtual void display() const = 0;

    static void displayCount();

    virtual ~Employee()
    {
        count--;
    }
};

class FullTime : public Employee
{
public:
    double salary;

    FullTime(string name, int Id, double monthly_salary)
    {
        this->name = name;
        this->Id = Id;

        calcSalary(monthly_salary);
    }

    void calcSalary(double monthly_salary)
    {
        salary = monthly_salary;
    }

    // overriding pure virtual function
    void calcSalary()
    {
    }

    void display() const
    {
        cout << "\n---------------------------------\n";
        cout << "Name      : " << name << endl;
        cout << "Id        : " << Id << endl;
        cout << "Type      : Full Time Employee" << endl;
        cout << "Salary    : " << salary << endl;
        cout << "\n----------------------------------\n";
    }

    ~FullTime()
    {
        cout << "FullTime Employee Destructor" << endl;
    }
};

class PartTime : public Employee
{
public:
    double salary;

    PartTime(string name, int Id, int wrkdHrs, int rate)
    {
        this->name = name;
        this->Id = Id;

        calcSalary(wrkdHrs, rate);
    }

    void calcSalary(int wrkdHrs, int rate)
    {
        salary = wrkdHrs * rate;
    }

    // overriding pure virtual function
    void calcSalary()
    {
    }

    void display() const
    {
        cout << "\n---------------------------------\n";
        cout << "Name      : " << name << endl;
        cout << "Id        : " << Id << endl;
        cout << "Type      : Part Time Employee" << endl;
        cout << "Salary    : " << salary << endl;
        cout << "\n----------------------------------\n";
    }

    ~PartTime()
    {
        cout << "PartTime Employee Destructor" << endl;
    }
};

int Employee::count = 0;

void Employee::displayCount()
{
    cout << "Total no. Employees: " << count << endl;
}

int main()
{
    int n;

    cout << "Enter no. Employees: ";
    cin >> n;

    // ARRAY OF BASE CLASS POINTERS
    Employee **e = new Employee*[n];

    for(int i = 0; i < n; i++)
    {
        int choice;

        cout << "\n1. Full Time\n2. Part Time\n";
        cout << "Enter Choice: ";
        cin >> choice;

        string name;
        int Id;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Id: ";
        cin >> Id;

        if(choice == 1)
        {
            double monthly_salary;

            cout << "Enter Monthly Salary: ";
            cin >> monthly_salary;

            e[i] = new FullTime(name, Id, monthly_salary);
        }

        else if(choice == 2)
        {
            int hrs, rate;

            cout << "Enter Working Hours: ";
            cin >> hrs;

            cout << "Enter Hourly Rate: ";
            cin >> rate;

            e[i] = new PartTime(name, Id, hrs, rate);
        }
    }

    cout << "\n=========== EMPLOYEE DETAILS ===========\n";

    for(int i = 0; i < n; i++)
    {
        e[i]->display();
    }

    Employee::displayCount();

    // DELETE MEMORY
    for(int i = 0; i < n; i++)
    {
        delete e[i];
    }

    delete[] e;

    return 0;
}