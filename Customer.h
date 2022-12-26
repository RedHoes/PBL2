#include "Person.h"

using namespace std;

class Customer:public Person
{
    private:
        int id;
        int passengerCar_id;
    public:
        void input() 
        {
            Person::input();
        }

        void output() 
        {
            cout << "Customer [" << "Id: " << this->id << ", Ten: " << this->getName() << ", SDT: " << this->getSdt() << ", So CMND: " << this->getCMND() << "]" << endl;
        }

        int randomID() 
        {
            srand((unsigned) time(NULL));
            return rand();
        }

        void setId(int id) 
        {
            this->id = id;
        }

        int getId() const 
        {
            return this->id;
        }

        void setPassengerCarId(int passengerCar_id) 
        {
            this->passengerCar_id = passengerCar_id;
        }

        int getPassengerCarId() const
        {
            return this->passengerCar_id;
        }
};

istream & operator >> (istream &in,  Customer &c)
{
    int id;
    string name, sdt, cmnd;
    fflush(stdin);
    id = c.randomID();
    cout << "\nNhap ten: ";
    getline(cin, name);
    cout << "Nhap So dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap so CMND/CCCD: ";
    cin >> cmnd;
    c.setId(id);
    c.setName(name);
    c.setCMND(cmnd);
    c.setSdt(sdt);
}

ostream & operator << (ostream &out, const Customer &c) 
{
    out << "Customer [" << "Id: " << c.getId() << ", Ten: " << c.getName() << ", SDT: " << c.getSdt() << ", So CMND: " << c.getCMND() << ", PassengerCar_id: " << c.getPassengerCarId() << "]" << endl;
    return out;
}