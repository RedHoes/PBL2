#include <bits/stdc++.h>

using namespace std;

class Person 
{
    private:
        string sdt, name, cmnd;
    public:
        void input() 
        {
            cout << "Nhap So dien thoai: ";
            cin >> this->sdt;
            cout << "Nhap ten: ";
            cin >> this->name;
            cout << "Nhap so CMND/CCCD: ";
            cin >> this->cmnd;
        }

        void output() 
        {
            cout << "Person [" << "Ten: " << this->name << ", SDT: " << this->sdt << ", So CMND: " << this->cmnd << "]" << endl;
        }

        void setSdt(string sdt) 
        {
            this->sdt = sdt;
        }

        string getSdt() const 
        {
            return this->sdt;
        }

        void setName(string name) 
        {
            this->name = name;
        }

        string getName() const 
        {
            return this->name;
        }

        void setCMND(string CMND) 
        {
            this->cmnd = CMND;
        }

        string getCMND() const 
        {
            return this->cmnd;
        }

};