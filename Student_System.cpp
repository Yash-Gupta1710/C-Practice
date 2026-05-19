#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollno;
    float marks[3];

    static int count;

public:

    // Default Constructor
    Student()
    {
        count++;
    }

    // Input Function
    void input()
    {
        cout << "\nEnter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> rollno;

        cout << "Enter Marks of 3 Subjects:\n";

        for(int i = 0; i < 3; i++)
        {
            cin >> marks[i];
        }
    }

    // Total Calculation
    float calcTotal() const
    {
        return marks[0] + marks[1] + marks[2];
    }

    // Average Calculation
    float calcAvg() const
    {
        return calcTotal() / 3;
    }

    // Grade Function
    char grade() const
    {
        float avg = calcAvg();

        if(avg >= 75)
            return 'A';

        else if(avg >= 50)
            return 'B';

        else
            return 'C';
    }

    // Display Function
    void display() const
    {
        cout << "\n---------------------------";
        cout << "\nName      : " << name;
        cout << "\nRoll No   : " << rollno;

        cout << "\nMarks     : ";

        for(int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }

        cout << "\nTotal     : " << calcTotal();
        cout << "\nAverage   : " << calcAvg();
        cout << "\nGrade     : " << grade();
        cout << "\n---------------------------\n";
    }

    // Getter for Average
    float getAvg() const
    {
        return calcAvg();
    }

    // Getter for Name
    string getName() const
    {
        return name;
    }

    // Static Function
    static void displayCount()
    {
        cout << "\nTotal Students Created: " << count << endl;
    }

    // Destructor
    ~Student()
    {
        count--;
    }
};

// Static Variable Initialization
int Student::count = 0;


// Function to Find Topper
void displayTopper(Student *s, int n)
{
    int top = 0;

    for(int i = 1; i < n; i++)
    {
        if(s[i].getAvg() > s[top].getAvg())
        {
            top = i;
        }
    }

    cout << "\nTopper is: " << s[top].getName();
    cout << "\nAverage Marks: " << s[top].getAvg() << endl;
}


int main()
{
    int n;

    cout << "Enter Number of Students: ";
    cin >> n;

    // Dynamic Array of Objects
    Student *s = new Student[n];

    // Input
    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter Details of Student " << i + 1 << endl;
        s[i].input();
    }

    // Display All Students
    cout << "\n\n===== STUDENT DETAILS =====\n";

    for(int i = 0; i < n; i++)
    {
        s[i].display();
    }

    // Display Topper
    displayTopper(s, n);

    // Display Count
    Student::displayCount();

    // Free Memory
    delete[] s;

    return 0;
}