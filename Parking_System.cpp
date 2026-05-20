#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    string OwnerName;
    int VehicleNo;
    int ParkingHrs;

public:
    static int count;

    Vehicle()
    {
        cout << "Object created" << endl;
        count++;
    }

    virtual void calcParkingFee() = 0;
    virtual void display() const = 0;

    // IMPORTANT ADDITION
    virtual double getFee() const = 0;

    static void displayCount();

    virtual ~Vehicle()
    {
        cout << "Object Destroyed" << endl;
        count--;
    }
};

class Car : public Vehicle
{
public:
    double fee;

    Car(string n, int vN, int pHrs)
    {
        cout << "Car Object Created" << endl;

        OwnerName = n;
        VehicleNo = vN;
        ParkingHrs = pHrs;

        calcParkingFee();
    }

    void calcParkingFee()
    {
        fee = ParkingHrs * 50;
    }

    double getFee() const
    {
        return fee;
    }

    void display() const
    {
        cout << "\n-------------------------------------------\n";
        cout << "Name              : " << OwnerName << endl;
        cout << "Type              : Car" << endl;
        cout << "Vehicle No.       : " << VehicleNo << endl;
        cout << "Parking Hours     : " << ParkingHrs << endl;
        cout << "Parking Fee       : " << fee << endl;
        cout << "\n--------------------------------------------\n";
    }

    ~Car()
    {
        cout << "Car object destroyed" << endl;
    }
};

class Bike : public Vehicle
{
public:
    double fee;

    Bike(string n, int vN, int pHrs)
    {
        cout << "Bike Object Created" << endl;

        OwnerName = n;
        VehicleNo = vN;
        ParkingHrs = pHrs;

        calcParkingFee();
    }

    void calcParkingFee()
    {
        fee = ParkingHrs * 20;
    }

    double getFee() const
    {
        return fee;
    }

    void display() const
    {
        cout << "\n-------------------------------------------\n";
        cout << "Name              : " << OwnerName << endl;
        cout << "Type              : Bike" << endl;
        cout << "Vehicle No.       : " << VehicleNo << endl;
        cout << "Parking Hours     : " << ParkingHrs << endl;
        cout << "Parking Fee       : " << fee << endl;
        cout << "\n--------------------------------------------\n";
    }

    ~Bike()
    {
        cout << "Bike object destroyed" << endl;
    }
};

class Truck : public Vehicle
{
public:
    double fee;

    Truck(string n, int vN, int pHrs)
    {
        cout << "Truck Object Created" << endl;

        OwnerName = n;
        VehicleNo = vN;
        ParkingHrs = pHrs;

        calcParkingFee();
    }

    void calcParkingFee()
    {
        fee = ParkingHrs * 100;
    }

    double getFee() const
    {
        return fee;
    }

    void display() const
    {
        cout << "\n-------------------------------------------\n";
        cout << "Name              : " << OwnerName << endl;
        cout << "Type              : Truck" << endl;
        cout << "Vehicle No.       : " << VehicleNo << endl;
        cout << "Parking Hours     : " << ParkingHrs << endl;
        cout << "Parking Fee       : " << fee << endl;
        cout << "\n--------------------------------------------\n";
    }

    ~Truck()
    {
        cout << "Truck object destroyed" << endl;
    }
};

int Vehicle::count = 0;

void Vehicle::displayCount()
{
    cout << "\nTotal Vehicles: " << count << endl;
}

// OUTSIDE FUNCTION
void HighestFee(Vehicle **v, int n)
{
    int high = 0;

    for(int i = 1; i < n; i++)
    {
        if(v[i]->getFee() > v[high]->getFee())
        {
            high = i;
        }
    }

    cout << "\n=========== HIGHEST PARKING FEE ===========\n";

    v[high]->display();
}

int main()
{
    int n;

    cout << "Enter Number of Vehicles: ";
    cin >> n;

    Vehicle **v = new Vehicle*[n];

    for(int i = 0; i < n; i++)
    {
        int choice;

        cout << "\n1. Car\n2. Bike\n3. Truck\n";
        cout << "Enter Choice: ";
        cin >> choice;

        string name;
        int no, hrs;

        cout << "Enter Owner Name: ";
        cin >> name;

        cout << "Enter Vehicle Number: ";
        cin >> no;

        cout << "Enter Parking Hours: ";
        cin >> hrs;

        if(choice == 1)
        {
            v[i] = new Car(name, no, hrs);
        }

        else if(choice == 2)
        {
            v[i] = new Bike(name, no, hrs);
        }

        else if(choice == 3)
        {
            v[i] = new Truck(name, no, hrs);
        }
    }

    cout << "\n=========== VEHICLE DETAILS ===========\n";

    for(int i = 0; i < n; i++)
    {
        v[i]->display();
    }

    HighestFee(v, n);

    Vehicle::displayCount();

    // MEMORY CLEANUP
    for(int i = 0; i < n; i++)
    {
        delete v[i];
    }

    delete[] v;

    return 0;
}