#include "Car.h"

using namespace std;

class PassengerCar:public Car
{
    private:
        int soCho, soChoDaBook, soChoConLai;
    public:
        void input() 
        {
            Car::input();
            cout << "Nhap so cho: ";
            cin >> soCho;
        }

        void output() 
        {
            cout << "PassengerCar [" << "BienSo: " << this->getBienSo() << ", Gio Xuat ben: " << getGioXuatBen() << ", gio ve ben: " << getGioVeBen() << ", So cho: " << getSoCho() << "]" << endl;
        }

        int randomID() const
        {
            srand((unsigned) time(NULL));
            return rand() % 1000;
        }

        int updateQuantity(int quantity) 
        {
            this->soChoDaBook += quantity;
            this->soChoConLai = this->soCho - this->soChoDaBook;
        }

        void setSoCho(int soCho) 
        {
            this->soCho = soCho;
        }

        int getSoCho() const 
        {
            return this->soCho;
        }

        void setSoChoDaBook(int soChoDaBook) 
        {
            this->soChoDaBook = soChoDaBook;
        }

        int getSoChoDaBook() const 
        {
            return this->soChoDaBook;
        }

        void setSoChoConLai(int soChoConLai) 
        {
            this->soChoConLai = soChoConLai;
        }

        int getSoChoConLai() const 
        {
            return this->soChoConLai;
        }
};

istream & operator >> (istream &in,  PassengerCar &p)
{
    string gioXuatBen, gioVeBen, bienSo;
    int soCho;
    p.setId(p.randomID());
    cout << "Nhap bien so: ";
    cin >> bienSo;
    cout << "Nhap gio xuat ben: ";
    cin >> gioXuatBen;
    cout << "Nhap gio ve ben: ";
    cin >> gioVeBen;
    cout << "Nhap so cho: ";
    cin >> soCho;
    p.setBienSo(bienSo);
    p.setGioXuatBen(gioXuatBen);
    p.setGioVeBen(gioVeBen);
    p.setSoCho(soCho);
    p.setSoChoDaBook(0);
    p.setSoChoConLai(soCho);
}

ostream & operator << (ostream &out, const PassengerCar &p) 
{
    out << "PassengerCar [Id: " << p.getId() << ", Bien So: " << p.getBienSo() << ", Gio Xuat ben: ";
    out << p.getGioXuatBen() << ", gio ve ben: " << p.getGioVeBen() << ", So cho: " << p.getSoCho();
    out << ", So cho da book: " << p.getSoChoDaBook() << ", So cho con lai: " << p.getSoChoConLai() << "]" << endl;
    return out;
}