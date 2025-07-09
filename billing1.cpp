#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu() // Main menu
{
    m:
    int choice;
    string email;
    string password;
   
        cout << "\t\t\t\t_____________________________________________________" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|               Supermarket Main Menu                 |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|_____________________________________________________|" << endl;
        cout << "\t\t\t\t|                1. Administrator                     |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|                2. Buyer                             |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t|                3. Exit                              |" << endl;
        cout << "\t\t\t\t|                                                     |" << endl;
        cout << "\t\t\t\t          Please select: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\t\t\t\tPlease Login \n" << endl;
            cout << "\t\t\t\tEnter Email: ";
            cin >> email;
            cout << "\n\t\t\t\tEnter Password: ";
            cin >> password;
            if (email == "admin@email.com" && password == "lakan") {
                administrator();
            }
            else {
				cout << "\n\t\t\t\tInvalid email/password";
            }

			break;  


         case 2:
            buyer();
			break; 


        case 3:
            exit(0);
			break;


        default:
			cout << "\n\t\t\t\tPlease select a valid option!" << endl;

        }

        goto m;
    

}

void shopping::administrator() // Admin panel
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t\tAdministrator Menu" << endl;
    cout << "\t\t\t\t|_____1. Add Product________|" << endl;
	cout << "\t\t\t\t|                            |" << endl;
    cout << "\t\t\t\t|______2. Modify Product______|"<< endl;
    cout << "\t\t\t\t|                            |" << endl;
    cout << "\t\t\t\t|_____3.Delete the Product____|" << endl;
    cout << "\t\t\t\t|                            |" << endl;
    cout << "\t\t\t\t|_____4.Back to main menu____|" << endl;
	cout << "\n\t\t\t\t Please enter your choice: ";
    cin >> choice;
   
    switch (choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4 :
            menu();
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice! Please try again." << endl;

            
    }
    goto m;
}

void shopping::buyer()  // Buyer menu
{
    m:
    int choice;
    cout << "\n\n\t\t\t\t_______Buyer Menu________" << endl;
	cout << "\t\t\t\t|                            |" << endl;
    cout << "\t\t\t\t|_____1. Buy Product________|" << endl;
    cout << "\t\t\t\t|                            |" << endl;
    cout << "\t\t\t\t|_____2.Back to main menu____|" << endl;
    cout << "\n\n\t\t\t\t Please enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice! Please try again." << endl;
            
    }
   goto m;
}

void shopping :: add() // setter function
{   
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t\t   Add New Product" << endl;
    cout << "\t\t\t\tEnter Product Code: ";
    cin >> pcode;
    cout << "\n\t\t\t\tEnter Product Name: ";
    cin >> pname;
    cout << "\n\t\t\t\tEnter Product Price: ";
    cin >> price;
    cout << "\n\t\t\t\tEnter Discount on Product: ";
    cin >> dis;
    data.open("database.txt", ios::in); // ios::in opens file in read mode
    
    if (!data) {
		data.open("database.txt", ios::app | ios::out);// ios::app opens file in append mode , ios::out opens file in write mode
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else {
        data >> c >> n >> p >> d;
        while (!data.eof()) {// eof end of file
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();




        if (token == 1)
            goto m;
        else {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }
    cout << "\n\n\t\t\t\t Record inserted !";
}

void shopping::edit() {
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\n\t\t\t\t Modify record";
    cout << "\n\n\t\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n\t\t\t\tFile doesn't exist! ";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
    
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t\t\t\t Product new code : ";
                cin >> c;
                cout << "\n\n\t\t\t\t Name of the product : ";
                cin >> n;
                cout << "\n\n\t\t\t\t Price : ";
                cin >> p;
                cout << "\n\t\t\t\t Discount : ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d <<"\n";
				cout << "\n\n\t\t\t\t Record edited successfully!" << endl;
                token++;
            }
            else {
				data1<< " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
			data >> pcode >> pname >> price >> dis;
        }
        data.close();
		data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n\t\t\t\t Record not found! ";
		}
    }


}


void shopping::rem() {
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t\t\t Delete Record";
    cout << "\n\n\t\t\t Product code : ";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    }
    else {
        data1.open("database1.txt", ios::app | ios::out);
    
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            if (pkey == pcode) {
                cout << "\n\n\t\t\t Product deleted successfully!" << endl;
                token++;
            }
            else {
                data1<< " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0) {
            cout << "\n\n\t\t\t Record not found! ";
        }
    }
}

void shopping::list() {
    fstream data;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    }
    else {
        cout << "\n\n\t\t\t______________Product List_______________________" << endl;
        cout << "\n\n\t\t\t|_____________________________________________________|" << endl;
        cout << "\t\t\tProduct Code\t\t\tProduct Name\t\t\tPrice\t\t\tDiscount" << endl;
        cout << "\n\n\t\t\t|_____________________________________________________|" << endl;
        data >> pcode >> pname >> price >> dis;
        while (!data.eof()) {
            cout << pcode << "\t\t\t" << pname << "\t\t\t" << price << "\t\t\t" << dis << endl;
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }
}

void shopping::receipt() {
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;
    cout << "\n\n\t\t\t\tReceipt" << endl;
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\nFile doesn't exist! ";
    }
    else {
        data.close();
        list();
		cout << "\n\n\t\t\t--------------------------------------" << endl;
        cout << "\n\n\t\t\t|                                      |" << endl;
        cout << "\n\n\t\t\t      Please place your order:          " << endl;
        cout << "\n\n\t\t\t|                                      |" << endl;
        cout << "\n\n\t\t\t--------------------------------------" << endl;
        do {
            m:
            cout << "\n\n\t\t\tEnter Product Code: ";
            cin >> arrc[c];
            cout << "\n\n\t\t\tEnter Quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n\t\t\tProduct already added!" << endl;
                    goto m;
                }
            }

            c++;
            
            cout << "\n\n\t\t\tDo you want to add more products? (y/n): ";
            cin >> choice;
        }

		while (choice == 'y' || choice == 'Y');
		cout << "\n\n\t\t\t--------------------RECEIPT------------------" << endl;
		cout << "\n\n\t\t\tProduct No.\tProduct Name\tQuantity\tPrice\tAmount\tDiscount\tTotal" << endl;

        for(int i= 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    discount = amount * dis / 100;
                    total = amount - discount;
                    cout << "\n\n" << i + 1 << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << dis << "%\t" << total;
                }
                data >> pcode >> pname >> price >> dis;
            }
		}
		data.close();
    }
	cout << "\n\n\t\t\t\t--------------------------------------" << endl;
	cout << "\n\n\t\t\t\tTotal Amount: " << total << endl;
}

int main() {
    shopping s;
    s.menu();
    return 0;
}