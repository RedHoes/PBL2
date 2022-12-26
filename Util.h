#include <bits/stdc++.h>
using namespace std;

class Util 
{
    public:
        int menu() 
        {
            cout << "+-----------------------------------------MENU-------------------------------------+" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 1. Chon ngay quan ly.                                                            |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 2. Quan ly xe khach.                                                             |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 3. Quan ly khach hang.                                                           |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 0. Thoat.                                                                        |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "\nNhap lua chon cua ban: ";
            int choose;
            cin >> choose;
            cout << endl;
            return choose;
        }

        int menuPassengerCar() 
        {
            cout << endl;
            cout << "+--------------------------------------PassengerCar--------------------------------+" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 1. Them 1 xe khach                                                               |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 2. Xem danh sach xe khach                                                        |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 3. Tim kiem xe khach                                                             |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 4. Xoa xe khach                                                                  |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 0. Quay lai                                                                      |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "\nNhap lua chon cua ban: ";
            int choose;
            cin >> choose;
            cout << endl;
            return choose; 
        }

        int menuCustomer() 
        {
            cout << "+-----------------------------------------Customer---------------------------------+" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 1. Them 1 khach hang                                                             |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 2. Xem danh sach khach hang                                                      |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 3. Tim kiem khach hang                                                           |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 4. Xoa khach hang                                                                |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "| 0. Quay lai                                                                      |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "\nNhap lua chon cua ban: ";
            int choose; 
            cin >> choose;
            cout << endl;
            return choose;
        }

        string getDataString(string s) 
        {
            int index = s.find(":");
            return s.substr(index + 2, s.length()- index - 1);
        }

        int getDataInt(string s) 
        {
            string str = getDataString(s);
            int number = 0;
            for (int i = 0; i < str.length(); i++)
                number = number * 10 + (str[i] - '0');
            return number;
        }

        void initFile(string year, string month, string day) 
        {
            ofstream ofs;
            ofs.open("files/" + year + "-" + month + "-" + day + "/customers.txt");
            ofs << "No object";
            ofs.close();
            ofs.open("files/" + year + "-" + month + "-" + day + "/passengercars.txt");
            ofs << "No object";
            ofs.close();
        }
};