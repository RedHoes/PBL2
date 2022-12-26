#include <bits/stdc++.h>
#include "PassengerCar.h"
#include "Customer.h"
#include "model.h"
#include "Util.h"
#include "Color.h"
#include "PassengerCarManagement.h"
#include "CustomerManagement.h"
#include <direct.h>
#include <cstdio>

int main() 
{
    Color();

    PassengerCarManangement pm;
    CustomerManagement cm;
    pm.init();
    cm.init();
    Util util;
    
    int choose, choose2, id, soChoConLai, temp;
    string tempStr;
    string day, month, year;
    day = month = year = "";
    char* cc;

    if (day.length() == 0) 
    {
        cout << "\nHien chua chon ngay quan ly.\n" << endl;
    } 
    else 
    {
        cout << "Dang quan ly ngay " << day << " Thang " << month << " Nam " << year << endl;
        cout << endl;
    }
    fflush(stdin);
    cout << "An phim bat ki de thay doi ngay quan ly, bam Enter de bo qua: ";
    getline(cin, tempStr);
    if (tempStr.length() > 0) 
    {
        cout << "\nNhap ngay: ";
        getline(cin, day);
        cout << "Nhap thang: ";
        getline(cin, month);
        cout << "Nhap nam: ";
        getline(cin, year);
        cout << "\nDa doi ngay quan ly thanh cong." << endl;
    }
    tempStr = "files/" + year + "-" + month + "-" + day;
    cc = new char[tempStr.size()];
    copy(tempStr.begin(), tempStr.end(), cc);
    cc[tempStr.size()] = '\0';
    
    temp = _mkdir(cc);
    if (temp == 0) 
    {
        cout << "\nDu lieu moi " << day << " Thang " << month << " Nam " << year << endl;
        cout << endl;
        util.initFile(year, month, day);
    }
    else 
    {
        pm.readPassengerCars(year, month, day);
        cm.readCustomers(year, month, day);
        cout << "\nDa doc du lieu cua ngay " << day << " Thang " << month << " Nam " << year << endl;
        cout << endl;
    }

    do 
    {
        choose = util.menu();
        switch (choose) 
        {
            case 1:
                if (day.length() == 0) 
                {
                    cout << "\nHien chua chon ngay quan ly.\n" << endl;
                } 
                else 
                {
                    cout << "Dang quan ly ngay " << day << " Thang " << month << " Nam " << year << endl;
                    cout << endl;
                }
                fflush(stdin);
                cout << "An phim bat ki de thay doi ngay quan ly, bam Enter de bo qua: ";
                getline(cin, tempStr);
                if (tempStr.length() > 0) 
                {
                    cout << "\nNhap ngay: ";
                    getline(cin, day);
                    cout << "Nhap thang: ";
                    getline(cin, month);
                    cout << "Nhap nam: ";
                    getline(cin, year);
                    cout << "\nDa doi ngay quan ly thanh cong." << endl;
                }

                tempStr = "files/" + year + "-" + month + "-" + day;
                cc = new char[tempStr.size()];
                copy(tempStr.begin(), tempStr.end(), cc);
                cc[tempStr.size()] = '\0';
                
                temp = _mkdir(cc);
                if (temp == 0) 
                {
                    cout << "\nDu lieu moi " << day << " Thang " << month << " Nam " << year << endl;
                    cout << endl;
                    util.initFile(year, month, day);
                } 
                else 
                {
                    pm.readPassengerCars(year, month, day);
                    cm.readCustomers(year, month, day);
                    cout << "\nDa doc du lieu cua ngay " << day << " Thang " << month << " Nam " << year << endl;
                    cout << endl;
                }
                break;
            case 2:
                do 
                {
                    choose2 = util.menuPassengerCar();
                    switch (choose2) 
                    {
                        case 1:
                            cout << "\nNhap thong tin xe khac moi.\n" << endl;
                            pm.add();
                            pm.writePassengerCars(year, month, day);
                            break;
                        case 2:
                            pm.printList();
                            break;
                        case 3:
                            cout << "Nhap bien so cua xe can tim: ";
                            cin >> tempStr;
                            cout << endl;
                            pm.searchPassengerCar(tempStr);
                            break;
                        case 4:
                            cout << "Nhap id xe khach can xoa: ";
                            cin >> id;
                            cout << endl;
                            pm.deleteById(id);
                            pm.printList();
                            pm.writePassengerCars(year, month, day);
                            break;
                    }
                } 
                while(choose2 !=  0);
                break;
            case 3:
                do 
                {
                    choose2 = util.menuCustomer();
                    switch (choose2) 
                    {
                        case 1:
            
                            do 
                            {
                                cout << "Chon mot trong nhung xe khach:" << endl;
                                cout << endl;
                                pm.printList();
                                cout << "Nhap id xe khach: ";
                                cin >> id;
                                cout << endl;
                                soChoConLai = pm.findSoChoConLaiById(id);
                                if (soChoConLai == 0) 
                                    cout << "Xe khach da het cho, vui long chon xe khac." << endl;
                                else if (soChoConLai == -1)
                                    cout << "Xe khong ton tai, vui long chon xe khac." << endl;
                            } 
                            while (soChoConLai <= 0);
                            cout << "Nhap thong tin khach." << endl;
                            cm.add(id);
                            pm.updateSoCho(id, 1);
                            cm.writeCustomers(year, month, day);
                            pm.writePassengerCars(year, month, day);
                            break;
                        case 2:
                            cm.printList();
                            break;
                        case 3:
                            cout << "Nhap so CMND cua khach hang can tim: ";
                            cin >> tempStr;
                            cout << endl;
                            cm.searchCustomer(tempStr);
                            break;
                        case 4:
                            cout << "Nhap id khach hang can xoa: ";
                            cin >> id;
                            cout << endl;
                            cm.deleteById(id);
                            pm.updateSoCho(cm.findIdPassengerCarByIdCustomer(id), -1);
                            cm.printList();
                            cm.writeCustomers(year, month, day);
                            break;
                    }
                } 
                while(choose2 !=  0);
                break;
        }
    } 
    while (choose != 0);
    cout << "\nKet Thuc!";
}