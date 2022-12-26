using namespace std;

class CustomerManagement 
{
    private:
        CustomerNode *c;

    public:
        void init() 
        {
            this->setCustomerNode(NULL);
        }

        CustomerNode *createCustomerNode(Customer x)
        {
            CustomerNode *temp = new CustomerNode;
            temp->next = NULL;
            temp->data = x; 
            return temp;
        }

        void printList(CustomerNode *l)
        {
            CustomerNode *p = l;
            while (p != NULL){
                cout << p->data;
                p = p->next;
            }
        }

        CustomerNode *addElement(CustomerNode*p, Customer x)
        {
            CustomerNode *temp = createCustomerNode(x);
            temp->next = p;
            return temp;
        }

        void searchCustomer(CustomerNode*p, string CMND)
        {
            CustomerNode *t = NULL;
            while (p != NULL)
            {
                if (p->data.getCMND() == CMND)
                    t = p;
                p = p->next;
            }
            if (t != NULL)
                cout << t->data;
            else
                cout << "Khong co khach hang can tim." << endl;
        }

        CustomerNode *deleteById(CustomerNode*p, int id)
        {
            CustomerNode *temp = NULL;
            while (p != NULL)
            {
                if (p->data.getId() != id)
                    temp = addElement(temp, p->data);
                p = p->next;
            }
            return temp;
        }

        int findIdPassengerCarByIdCustomer(CustomerNode*p, int id)
        {
            while (p != NULL)
            {
                if (p->data.getId() != id)
                    return p->data.getPassengerCarId();
                p = p->next;
            }
            return -1;
        }

        void writeCustomers(CustomerNode*p, string year, string month, string day)
        {
            ofstream ofs;
            ofs.open("files/" + year + "-" + month + "-" + day + "/customers.txt");
            while (p != NULL)
            {
                ofs << p->data;
                p = p->next;
            }
        }

        void add(int id) 
        {
            Customer x;
            cin >> x;
            x.setPassengerCarId(id);
            c = this->addElement(c, x);
        }

        void printList() 
        {
            this->printList(c);
        }

        void searchCustomer(string CMND) 
        {
            this->searchCustomer(c, CMND);
        }

        void deleteById(int id) 
        {
            c = this->deleteById(c, id);
        }

        int findIdPassengerCarByIdCustomer(int id) 
        {
            return this->findIdPassengerCarByIdCustomer(c, id);
        }

        void readCustomers(string year, string month, string day) 
        {
            c = NULL;
            Util util;
            ifstream ifs;
            string s;
            Customer customer;
            ifs.open("files/" + year + "-" + month + "-" + day + "/customers.txt");
            while (!ifs.eof()) 
            {
                getline(ifs, s, ',');
                if (s.length() == 0)
                    break;
                customer.setId(util.getDataInt(s));
                getline(ifs, s, ',');
                customer.setName(util.getDataString(s));
                getline(ifs, s, ',');
                customer.setSdt(util.getDataString(s));
                getline(ifs, s, ',');
                customer.setCMND(util.getDataString(s));
                getline(ifs, s, ']');
                customer.setPassengerCarId(util.getDataInt(s));
                getline(ifs, s);
                c = addElement(c, customer);
            }
        }

        void writeCustomers(string year, string month, string day) 
        {
            this->writeCustomers(c, year, month, day);
        }

        void setCustomerNode(CustomerNode*p) 
        {
            c = p;
        }

        CustomerNode* getCustomerNode() 
        {
            return c;
        }
};