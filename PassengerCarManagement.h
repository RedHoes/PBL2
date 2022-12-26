#include <bits/stdc++.h>
using namespace std;

class PassengerCarManangement 
{
    private:
        PassengerCarNode *p;

    public:
        void init() 
        {
            this->setPassengerCarNode(NULL);
        }

        PassengerCarNode *createPassengerCarNode(PassengerCar x)
        {
            PassengerCarNode *temp = new PassengerCarNode;
            temp->next = NULL;
            temp->data = x; 
            return temp;
        }

        PassengerCarNode *addElement(PassengerCarNode*p, PassengerCar x)
        {
            PassengerCarNode *temp = createPassengerCarNode(x);
            temp->next = p;
            return temp;
        }

        PassengerCarNode *deleteById(PassengerCarNode*p, int id)
        {
            PassengerCarNode *temp = NULL;
            while (p != NULL)
            {
                if (p->data.getId() != id)
                    temp = addElement(temp, p->data);
                p = p->next;
            }
            return temp;
        }


        void searchPassengerCar(PassengerCarNode*p, string bienSo)
        {
            PassengerCarNode *t = NULL;
            while (p != NULL)
            {
                if (p->data.getBienSo() == bienSo)
                    t = p;
                p = p->next;
            }
            if (t != NULL)
                cout << t->data;
            else
                cout << "Khong co xe can tim." << endl;
        }

        void printList(PassengerCarNode *l)
        {
            PassengerCarNode *p = l;
            while (p != NULL)
            {
                cout << p->data;
                p = p->next;
            }
        }

        void updateSoCho(PassengerCarNode *l, int id, int quantity)
        {
            PassengerCarNode *p = l;
            while (p != NULL)
            {
                if (p->data.getId() == id) 
                {
                    p->data.updateQuantity(quantity);
                }
                p = p->next;
            }
        }

        int findSoChoConLaiById(PassengerCarNode *l, int id)
        {
            int soChoConLai = -1;
            PassengerCarNode *p = l;
            while (p != NULL)
            {
                if (p->data.getId() == id) 
                {
                    soChoConLai = p->data.getSoChoConLai();
                }
                p = p->next;
            }
            return soChoConLai;
        }

        void writePassengerCars(PassengerCarNode*p, string year, string month, string day)
        {
            ofstream ofs;
            ofs.open("files/" + year + "-" + month + "-" + day + "/passengercars.txt");
            while (p != NULL)
            {
                ofs << p->data;
                p = p->next; 
            }
        }

        void setPassengerCarNode(PassengerCarNode* p1) 
        {
            p = p1;
        }

        PassengerCarNode* getPassengerCarNode() 
        {
            return p;
        }

        // Cac ham xu li
    
        void add() 
        {
            PassengerCar x;
            cin >> x;
            p = this->addElement(p, x);
        }

        void deleteById(int id) 
        {
            p = this->deleteById(p, id);
        }

        void searchPassengerCar(string bienSo) 
        {
            this->searchPassengerCar(p, bienSo);
        }

        void printList() 
        {
            printList(p);
        }

        void writePassengerCars(string year, string month, string day) 
        {
            this->writePassengerCars(p, year, month, day);
        }

        void updateSoCho(int id, int quantity) 
        {
            this->updateSoCho(p, id, quantity);
        }

        int findSoChoConLaiById(int id) 
        {
            return this->findSoChoConLaiById(p, id);
        }

        void readPassengerCars(string year, string month, string day) 
        {
            p = NULL;
            ifstream ifs;
            Util util;
            string s;
            PassengerCar passengerCar;
            ifs.open("files/" + year + "-" + month + "-" + day + "/passengercars.txt");
            while (!ifs.eof()) 
            {
                getline(ifs, s, ',');
                if (s.length() == 0)
                    break;
                passengerCar.setId(util.getDataInt(s));
                getline(ifs, s, ',');
                passengerCar.setBienSo(util.getDataString(s));
                getline(ifs, s, ',');
                passengerCar.setGioXuatBen(util.getDataString(s));
                getline(ifs, s, ',');
                passengerCar.setGioVeBen(util.getDataString(s));
                getline(ifs, s, ',');
                passengerCar.setSoCho(util.getDataInt(s));
                getline(ifs, s, ',');
                passengerCar.setSoChoDaBook(util.getDataInt(s));
                getline(ifs, s);
                passengerCar.updateQuantity(1);
                p = addElement(p, passengerCar);
            }
        }
};