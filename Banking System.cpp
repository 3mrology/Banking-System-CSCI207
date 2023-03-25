#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<bits/stdc++.h>

using namespace std;
//Transaction Class
class Transaction {
private:
    //Data
    int transactionID;
    string transactionName;
    string transactionDate;
public:
    //setters and getters
    void setTransactionName(string name) {
        transactionName = name;
    }

    string getTransactionName() {
        return transactionName;
    }

    void setTransactionID(int ID) {
        transactionID = ID;
    }

    int getTransactionID() {
        return transactionID;
    }

    void setTransactionDate(string date) {
        transactionDate = date;
    }

    string getTransactionDate() {
        return transactionDate;
    }
    //constructor
    Transaction(int id, string name, string date) {
        transactionID = id;
        transactionName = name;
        transactionDate = date;
    }

    Transaction() {
        transactionID = rand();
        transactionName = "Transaction" + std::to_string(rand()) + "/" + std::to_string(rand());
        transactionDate = "202" + std::to_string(rand()) + "/Dec/" + std::to_string(rand());
    }
    //display info
    void Tinfo() {
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Transaction Name: " << transactionName << endl;
        cout << "Transaction Date: " << transactionDate << endl;
    }
};
//client class
class Client {
private:
    //data
    string clientName;
    string clientEmail;
    string clientPhone;
    string clientAddress;
    string clientPassword;
    int clientID, n;
    Transaction t[5];
public:
    //setters and getters
    void setName(string name) {
        clientName = name;
    }

    string getName() {
        return clientName;
    }

    void setEmail(string email) {
        clientEmail = email;
    }

    string getEmail() {
        return clientEmail;
    }

    void setPhone(string phone) {
        clientPhone = phone;
    }

    int getN() {
        return n;
    }

    string getPhone() {
        return clientPhone;
    }

    void setAddress(string address) {
        clientAddress = address;
    }

    string getAddress() {
        return clientAddress;
    }

    void setPassword(string password) {
        clientPassword = password;
    }

    string getPassword() {
        return clientPassword;
    }

    void setID(int id) {
        clientID = id;
    }

    int getID() {
        return clientID;
    }

    Transaction *Tpnt() {
        return t;
    }
    //constructor
    Client(string cname = "\0", string cemail = "\0", string cphone = "\0", string caddress = "\0") {
        clientName = cname;
        clientEmail = cemail;
        clientPhone = cphone;
        clientAddress = caddress;
        clientID = rand();
        n = 0;
    }
    //Function that shows info
    void printClientInfo() {
        cout << "Client Information:" << endl;
        cout << "Client name: " << clientName << endl;
        cout << "Client phone: " << clientPhone << endl;
        cout << "Client email: " << clientEmail << endl;
        cout << "Client address: " << clientAddress << endl;
    }

};
//end of client class
//LLNode class
class LinkedListNode {
private:
    //data
    Client C;
    LinkedListNode *Next;
public:
    //Constructor
    LinkedListNode(Client C1, LinkedListNode *next = NULL) {
        C = C1;
        Next = next;
    }
    //setters and getters
    Client getData() {
        return C;
    }

    LinkedListNode *getNext() {
        return Next;
    }

    void setNext(LinkedListNode *n) {
        Next = n;
    }
};
//Array of Clients
LinkedListNode *seq[10];
//Hash table class
class Hash {
public:
    //Hash insert function
    void hashInsert(Client C3) {
        LinkedListNode *node = new LinkedListNode(C3, NULL);
        int key = C3.getID() % 10;
        if (seq[key] == NULL) {
            seq[key] = node;
        } else {
            LinkedListNode *tmp = seq[key];
            while (tmp->getNext()) {
                tmp = tmp->getNext();
            }
            tmp->setNext(node);
        }
    }
//Hash table print function
    void print() {
        for (int i = 0; i < 10; i++) {
            LinkedListNode *temp = seq[i];
            if (seq[i] != NULL) {
                cout << "Chain of : " << i << endl;
                while (temp) {
                    temp->getData().printClientInfo();
                    temp = temp->getNext();
                }
            }
        }
    }
//swap function for array
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
//creating partition for quicksort
    int partition(int arr[], int l, int h) {
        int pivot = arr[h]; //Partioning
        int i = (l - 1);
        for (int j = l; j <= h - 1; j++) {
            //smaller
            if (arr[j] < pivot) {
                i++; // increment smaller
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[h]);
        return (i + 1);
    }
//Quicksort Function
    void quickS(int arr[], int low, int high) {
        if (low < high) {
            int parti = partition(arr, low, high);
            quickS(arr, low, parti - 1);
            quickS(arr, parti + 1, high);
        }
    }
//Function that prints sorted array
    void printArray(int arr[], int size) {
        int i;
        for (i = 0; i < size; i++)
            cout << "Index[" << i << "] contains linked list of" << arr[i] << " clients" << endl;
    }
//Function that creates array to be sorted
    void quickSort() {
        int count = 0;
        int arr[10];
        for (int i = 0; i < 10; i++) {
            LinkedListNode *temp = seq[i];
            if (seq[i] != NULL) {
                cout << "Chain of : " << i << endl;
                while (temp) {
                    count = count + 1;
                    temp = temp->getNext();
                }
                arr[i] = count;
                count = 0;
            } else {
                arr[i] = 0;
            }
        }
//        for(int z = 0; z < 10;z++){
//            cout<<"index : "<<z<<" contains "<<arr[z]<<" elements"<<endl;
//        }
//Sorting
        quickS(arr, 0, 9);
        //printing
        printArray(arr, 10);
    }
};
//Client List class
class ClientList {
private:
    //Data
    LinkedListNode *Head;
    LinkedListNode *Current_User;
    int listSize;
    int counting;
public:
    //Constructor
    ClientList(LinkedListNode *head = NULL) {
        Head = head;
        listSize = -1;
        counting = 0;
    }
    LinkedListNode * last(LinkedListNode * head)
    {
        LinkedListNode * tmp = head;
        while (tmp != NULL && tmp->getNext() != NULL) {
            tmp = tmp->getNext();
        }
        return tmp;
    }

    LinkedListNode * partition(LinkedListNode * f, LinkedListNode * l)
    {
        // first
        LinkedListNode * pivot = f;
        LinkedListNode * front = f;
        int tmpo = 0;
        while (front != NULL && front != l) {
            if (front->getData().getID() < l->getData().getID()) {
                pivot = f;

                // Swap
                tmpo = f->getData().getID();
                f->getData().setID(front->getData().getID());
                front->getData().setID(tmpo);

                // traverse to next node
                f = f->getNext();
            }

            // Visiting the next node
            front = front->getNext();
        }

        // Change last node value to current node
        tmpo = f->getData().getID();
        f->getData().setID(l->getData().getID());
        l->getData().setID(tmpo);
        return pivot;
    }
    void quick_sort1(LinkedListNode * f, LinkedListNode * l)
    {
        if (f == l) {
            return;
        }
        LinkedListNode * pivot = partition(f, l);

        if (pivot != NULL && pivot->getNext() != NULL) {
            quick_sort1(pivot->getNext(), l);
        }

        if (pivot != NULL && f != pivot) {
            quick_sort1(f, pivot);
        }
    }
    //some setters and getters
    Transaction get_arr(int n) {
        return Current_User->getData().Tpnt()[n];
    }
    //set static data for transactions
    void set_arr() {
        Transaction transaction1(rand(), "Transaction 1", "01/Jan/2022");
        Transaction transaction2(rand(), "Transaction 2", "02/Jan/2022");
        Transaction transaction3(rand(), "Transaction 3", "03/Jan/2022");
        Transaction transaction4(rand(), "Transaction 4", "04/Jan/2022");
        Transaction transaction5(rand(), "Transaction 5", "05/Jan/2022");
        if (counting <= 4) {
            if (counting == 0)
                Current_User->getData().Tpnt()[counting] = transaction1;
            if (counting == 1)
                Current_User->getData().Tpnt()[counting] = transaction2;
            if (counting == 2)
                Current_User->getData().Tpnt()[counting] = transaction3;
            if (counting == 3)
                Current_User->getData().Tpnt()[counting] = transaction4;
            if (counting == 4)
                Current_User->getData().Tpnt()[counting] = transaction5;
            counting++;
            cout << "Transaction inserted" << endl;
        } else
            cout << "Maximum transactions reached" << endl;
    }
    //remove transaction by id
    void remove_transaction(int index) {
        for (int i = index; i < counting - 1; i++) {
            Current_User->getData().Tpnt()[i] = Current_User->getData().Tpnt()[i + 1];
        }
        counting--;
        cout << "Number of transactions = " << counting << endl;
    }
    //function to display forgotten password
    void forgotPassword() {
        string email;
        cout << "Please enter email: " << endl;
        cin >> email;
        LinkedListNode *here = Head;
        while (here != NULL) {
            if (email == here->getData().getEmail()) {
                cout << "Password is: " << here->getData().getPassword() << endl;
                main_menu();
            } else {
                here = here->getNext();
            }
        }
        cout << "Email does not exist";
        main_menu();
    }
    //main menu function
    void main_menu() {
        cout
                << "======================================================================================================="
                << endl;
        cout << "+++++++++++++++++++++++ welcome to the Banking System ++++++++++++++++++++++++++++++++++++++++++++"
             << endl;
        cout << " CHOOSE ONE OF THE FOLLOWING Method " << endl;
        cout
                << "(1) Login to your account.\n(2) New client?\n(3) Forgot your password?\n(4) Sort clients by linked list size using the quick sort algorithm \n(5) Exit the program.\n(6) Sort By ID"
                << endl;
        int Method;
        cin >> Method;
        if (Method == 1) {
            loginMenu();
        } else if (Method == 2) {
            newClientMenu();
        } else if (Method == 3) {
            forgotPassword();
        } else if (Method == 4) {
            Hash h1;
            h1.quickSort();
            main_menu();
        } else if (Method == 5) {
            exit(0);
        } else if (Method == 6) {
            quick_sort1(Head, last(Head));
            LinkedListNode * h = Head;
            while(h!=NULL){
                cout<<h->getData().getID()<<endl;
                h = h->getNext();
            }
            main_menu();
        } else {
            cout << "Invalid input, please try again." << endl;
            main_menu();
        }
    }
//getter
    LinkedListNode *getHead() {
        return Head;
    }
//Insert function for linked list
    bool insertion(Client *C) {
        LinkedListNode *newC = new LinkedListNode(*C, NULL);
        if (Head == NULL) {
            Head = newC;
            cout << "Head inserted" << endl;
            return true;
        } else {
            LinkedListNode *here = Head;
            while (here != NULL) {
                if (here->getData().getEmail() == C->getEmail()) {
                    cout << "Email already exists" << endl;
                    return false;
                }
                here = here->getNext();
            }
            LinkedListNode *h = Head;
            while (h->getNext() != NULL) {
                h = h->getNext();
            }
            h->setNext(newC);
            cout << "Node inserted" << endl;
        }
    }
//New Client Menu
    void newClientMenu() {
        Hash h1;
        string name, email, phone, address, password;
        int id;
        cout << "Enter your name: " << endl;
        cin >> name;
        cout << "Enter the email: " << endl;
        cin >> email;
        cout << "Enter the phone: " << endl;
        cin >> phone;
        cout << "Enter the address: " << endl;
        cin >> address;
        cout << "Enter the password: " << endl;
        cin >> password;
        Client *newC = new Client(name, email, phone, address);
        newC->setPassword(password);
        //Insertion to linked list
        insertion(newC);
        //Insertion to hash table
        h1.hashInsert(*newC);
        //Printing hash table
        h1.print();
        main_menu();
    }
//Login Menu Function
    void loginMenu() {
        string email, password;
        cout << "Enter the email: " << endl;
        cin >> email;
        cout << "Enter the password: " << endl;
        cin >> password;
        LinkedListNode *here = Head;
        while (here != NULL) {
            if (here->getData().getEmail() == email && here->getData().getPassword() == password) {
                cout << "Log in successful!" << endl;
                Current_User = here;
                clientMenu();
            } else {
                here = here->getNext();
            }
            cout << "Invalid Info\nReturning to main menu..." << endl;
            main_menu();
        }
    }
//Client Menu Function
    void clientMenu() {
        int option;
        cout << "++++++++++++++++++++  welcome to the banking System +++++++++++++++++++" << endl;
        cout << "++++++++++++++++++++  welcome to the home page ++++++++++++++++++++++++" << endl;
        cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS: " << endl;
        cout << "1. transactions menu\n2. view personal info\n3. logout" << endl;
        cin >> option;
        if (option == 1) {
            transactionsMenu();
        }
        if (option == 2) {
            Current_User->getData().printClientInfo();
            clientMenu();
        } else if (option == 3) {
            main_menu();
        }
    }

    bool isInserted = false;
//Transactions Menu
    void transactionsMenu() {
        cout << "++++++++++++++ Welcome to the Transactions system ++++++++++++++" << endl;
        cout << "CHOOSE ONE OF THE FOLLOWING OPTIONS:" << endl;
        cout << "1) Create a new transaction" << endl;
        cout << "2) View your transactions" << endl;
        cout << "3) Delete a transaction by its ID" << endl;
        cout << "4) Return to the Home Page " << endl;

        int o;
        while (true) {
            cin >> o;
            if (o == 1) {
                //Set transactions
                set_arr();
                transactionsMenu();
            } else if (o == 2) {
                cout << "Transactions: " << endl;
                for (int i = 0; i < counting; i++)
                    //Display transactions
                    get_arr(i).Tinfo();
                transactionsMenu();
            } else if (o == 3) {
                bool check = false;
                int id;
                cout << "Enter ID: ";
                cin >> id;
                for (int i = 0; i < Current_User->getData().getN(); i++) {
                    if (Current_User->getData().getID() == id) {
                        remove_transaction(i);
                        cout << "Transaction deleted" << endl;
                        check = true;
                        break;
                    }
                }
                if (!check)
                    cout << "Transaction not found" << endl;
                transactionsMenu();
            } else if (o == 4) {
                main_menu();
            }
        }
    }

};
//Intialize function for Array of Clients
void intial() {
    for (int i = 0; i < 10; i++) {
        seq[i] = NULL;
    }
}
// Main
int main() {
    ClientList l1;
    intial();
    l1.main_menu();
}
