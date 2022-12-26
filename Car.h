#include <bits/stdc++.h>

using namespace std;

class Car 
{
    private:
        int id;
        string bienSo, gioXuatBen, gioVeBen;
    public:
        void input() 
        {
            cout << "Nhap bien so: ";
            cin >> this->bienSo;
            cout << "Nhap gio xuat ben: ";
            cin >> this->gioXuatBen;
            cout << "Nhap gio ve ben: ";
            cin >> this->gioVeBen;
        }

        void output() 
        {
            cout << "Car [" << "BienSo: " << getBienSo() << ", Gio Xuat ben: " << getGioVeBen() << ", gio ve ben: " << getGioVeBen() << "]" << endl;
        }

        void setId(int id) 
        {
            this->id = id;
        }

        int getId() const 
        {
            return this->id;
        }

        void setBienSo(string bienSo) 
        {
            this->bienSo = bienSo;
        }

        string getBienSo() const 
        {
            return this->bienSo;
        }

        void setGioXuatBen(string gioXuatBen) 
        {
            this->gioXuatBen = gioXuatBen;
        }

        string getGioXuatBen() const 
        {
            return this->gioXuatBen;
        }

        void setGioVeBen(string gioVeBen) 
        {
            this->gioVeBen = gioVeBen;
        }

        string getGioVeBen() const 
        {
            return this->gioVeBen;
        }
};