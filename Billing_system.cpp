# include <iostream>											                                       															
# include <fstream>
# include <string>
# include <cstring>
# include <conio.h>
# include <windows.h>
# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>
# include <sstream>																											
# include <iomanip> 
# include <ctime> 

using namespace std;

const int MAX_ITEMS = 100;
// USING STRUCTUR ARRAYS AND FILE HANDLING FOR "Sale_Menu" DISPLAY MENU
struct item {
    string name;
    float price;
    int quantity;
};

// USING STRUCTUR AND FILE HANDLING FOR COUSTOMERS DISPLAY MENU
struct amber {
    std::string F_name;
    int quantity;
    std::string F_price;
};

// USING STRUCTUR AND FILE HANDLING FOR BILING SYSTEM 
struct BakeryItems {
    int item_code;
    string name;
    float price;
    int quantity;
};

// MAIN MENU FUNCTION DECLRATION
void login();
void dis_Menu();
void a_Infor();
// SUB MAIN MENU FUNCTION DECLRATION 
void sub_Menu();
void sale();
void Menu();
void print_Menu();
void print();
//  SALE MENU FUNCATION DECLRATION
void addItem();
void updateItem();
void deleteItem();
void displayItem();
void searchItem();
//PRINT BILL FUNCTION DECLRATION 
void bill();
void print_Bill();
// USERNAME & PASSWORD FUNCATION DECLRATION 
string username = "";
string password = "";
string name = "Mr. Banuak";
bool isLoggedIn = false;

// IDENTIFY BILL TAX RATE 8% FOR BILL 
const double  TAX_RATE = 0.08;


// MAIN MENU 
int main() {
    system("color 6");
    int shop;
    cout << "\n\n\n\n" << endl;
    cout << "\t\t\t        ************************************************************************************************" << endl;
    cout << "\t\t\t        *============================================================================================= *" << endl;
    cout << "\t\t\t        *                                          WELCOME AMBER                                       *" << endl;
    cout << "\t\t\t        *==========================================    LOG IN    ======================================*" << endl;
    cout << "\t\t\t        *                                      [ TASTE FODD IS FIRST ]                                 *" << endl;
    cout << "\t\t\t        *                                                                                              *" << endl;
    cout << "\t\t\t        *                                             1.LOGIN                                          *" << endl;
    cout << "\t\t\t        *                                             2.MENU                                           *" << endl;
    cout << "\t\t\t        *                                             3.CONTACT US                                     *" << endl;
    cout << "\t\t\t        *                                             4.EXIT                                           *" << endl;
    cout << "\t\t\t        *                                                                                              *" << endl;
    cout << "\t\t\t        *==============================================================================================*" << endl;
    cout << "\t\t\t        ************************************************************************************************";
    cout << "\t\t\t                                                  SELECT YOURS OPTION :";
    cin >> shop;
    switch (shop)
    {
    case 1:
        login();
        break;
    case 2:
        dis_Menu();
        break;
    case 3:
        a_Infor();
        break;
    case 4:
        cout << "\n\t\t\t\t                   ARE YOU SURE EXIT " << name << "..." << endl;
        break;
        // IF THE USER SELETS FIVE ,SIX OR ANY OTHER NUMBER THAT IS NOT THE LOGIN  PAGE; THEN I WILL DISPLAY THE MESSAGE SAYING  	
    default:
        system("cls"); // THAT IS CLEAR SCREEN 
        cout << "\n\n\n\n\n";
        cout << "\t\t\PLEASE SELECT FROM THE OPTIONS GIVEN BELOW \n" << endl;
        while (true) {
            int log;
            cout << "\t\t\t\t                  PRESS ENTER 01 RETURN LOGIN PAGE : ";
            cin >> log;
            if (log == 1);
            system("cls");
            main();
            break;
        }

    }

}
void login() {
    system("color A");
    while (true) {
        cout << "\n\n\n\n" << endl;
        cout << "\t\t\t\t\t\t******************************************\n" << endl;
        cout << "\t\t\t\t               >>>~~ ENTER USERNAME HERE: ";
        cin >> username;
        cout << "\t\t\t\t               >>>~~ ENTER PASSWORD HERE: ";
        cin >> password;
        char c;

        //PASSWORD CHANGE TO START  
        while ((c = _getch()) != '\r')
        {
            password += c;
            cout << '*';
        }
        // VALIDATION FOR USERNAME AND PASSWORD ;

        if (username == "icbt" && password == "1234") {
            system("color B");
            system("cls");
            cout << "\n\n\n\n";
            cout << "\t\t\t\t\t\t******************************************\n" << endl;
            cout << "\t\t\t\t\t     >>>LOGGED IN SUCCESSFULLY !!<<< " << endl;
            username = username;
            password = password;
            isLoggedIn = true;
            Menu();
            sub_Menu();
            break;
        }
        else {
            system("color c");
            cout << "\n\n\t\t\t\t\t\t\tINVALID USERNAME AND PASSWORD " << endl;
            username = username;
            password = password;
            isLoggedIn = false;
            login();
        }
    }
}
// CREATE CUSTOMER VIEW FOOD ITEM MENU 
void dis_Menu() {
    system("cls");
    const int MAX_ITEMS = 100; // ASSUMING THERE ARE AT MOST 100 PERSONS IN THE FILE 
    amber Food[MAX_ITEMS];
    int numitem = 0;

    std::ifstream fin("items.txt"); // HERE I USED FILE HANDLING - TEXT FILE NAME "records.txt".

    if (!fin) {
        std::cout << "ERROR OPENING FILE.\n";
    }
    std::string line;

    while (getline(fin, line)) {
        std::istringstream one(line);
        one >> Food[numitem].F_name >> Food[numitem].F_price >> Food[numitem].quantity;
        numitem++;
    }
    fin.close();

    // DATA IS STORED IN THE CUSTOMER ARRAY OF STRUCTURES; I CAN USE IT AS I LIKE; PRINT THE INFORMATION OF EACH CUSTOMER ;

    cout << "\n\n\n\n";
    cout << "\n\t\t\t\t\t\t                      TODAT AVALIABLE AMEBR FOOD ITEM                " << endl;
    cout << "\n\t\t\t\t\t\t      FOOD NAME               FOOD  PRICE                   FOOD QUANTITY  " << endl;

    for (int i = 0; i < numitem; i++) {
        std::cout << "\n\t\t\t\t\t\t\t" << Food[i].F_name << "\t\t      " << Food[i].F_price << "\t\t\t    " << Food[i].quantity << "\n";

    }
    //RETURN TO LOGIN PAGE 
    while (true) {
        int section;
        cout << " PRESS ENTER 01 RETURN LOGIN PAGE : ";
        cin >> section;
        if (section == 1);
        system("cls");
        main();
        break;
    }

}
//CREATE COMPANY DETAILS FUNCATION 
void a_Infor() {
    system("color A");
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t\t\t|*****************************************************************************************|" << endl;
    cout << "\t\t\t\t\t|*                             AMBER BAKERY COMPANY DETAILS                              *|" << endl;
    cout << "\t\t\t\t\t|*                                     *************                                     *|" << endl;
    cout << "\t\t\t\t\t|*                                [TASTE FOOD IS FIRST]                                  *|" << endl;
    cout << "\t\t\t\t\t|*                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                             *|" << endl;
    cout << "\t\t\t\t\t|*                                                                                       *|" << endl;
    cout << "\t\t\t\t\t|*         FIND US                      HOURS                     CALL US                *|" << endl;
    cout << "\t\t\t\t\t|*                                                                                       *|" << endl;
    cout << "\t\t\t\t\t|*         121 Rock Street,             Monday - Saturday         Peter                  *|" << endl;
    cout << "\t\t\t\t\t|*         21 Avenue,London,UK          9am - 7pm                 (+45) 3456-8977        *|" << endl;
    cout << "\t\t\t\t\t|*         92103 -9000                  Sunday                    Amenda                 *|" << endl;
    cout << "\t\t\t\t\t|*                                      Closed                    (+45) 3456-8978        *|" << endl;
    cout << "\t\t\t\t\t|*                                                                                       *|" << endl;
    cout << "\t\t\t\t\t|*                                                                                       *|" << endl;
    cout << "\t\t\t\t\t|* --------------------------------------------------------------------------------------*|" << endl;
    cout << "\t\t\t\t\t|*****************************************************************************************|" << endl;
    cout << "\t\t\t\t\t|-----------------------------------------------------------------------------------------|" << endl;

    while (true) {
        int details;
        cout << " PRESS ENTER 02 RETURN LOGIN PAGE : ";
        cin >> details;
        if (details == 2);
        system("cls");
        main();
        break;
    }
}
// ENTER MESSAGE FOR THE CRUD OPERATION 
void Menu() {
    system("color B");
    int choice;
    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t        *****************************************************************************************" << endl;
    cout << "\t\t\t        *                                                                                       *" << endl;
    cout << "\t\t\t        *                             1. SALE AND PACKAGE DETAILS                               *" << endl;
    cout << "\t\t\t        *                                                                                       *" << endl;
    cout << "\t\t\t        *****************************************************************************************" << endl;
    cout << "\t\t\t                                          PRESS 01 AND CONTINUE ! ";
    cin >> choice;
    switch (choice) {
    case 1:
        sale();
        break;
    }
}
// YES AND NO CODE DECLARATION  
void sale() {
    char response;
    bool isYes = false;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t   DO YOU WANT TO CONTINUE ? (y/n) ";
    cin >> response;

    if (response == 'y' || response == 'Y') {
        isYes = true;
    }if (isYes) {
        cout << "\t\t\t\t\t   YOU CHOOSE YES!" << endl;
    }
    else {
        cout << "\t\t\t\t\t   YOU CHOOSE YES!" << endl;
    }
}
// CREATE SUB MENU 
void sub_Menu() {
    system("color 9");
    system("cls");
    int choice;
    cout << "\n\n\n\n" << endl;
    cout << "\t\t\t        ************************************************************************************************" << endl;
    cout << "\t\t\t        *============================================================================================= *" << endl;
    cout << "\t\t\t        *                                          WELCOME AMBER                                       *" << endl;
    cout << "\t\t\t        *_________________________________________    MENU BAR   ______________________________________*" << endl;
    cout << "\t\t\t        *                                      [ TASTE FODD IS FIRST ]                                 *" << endl;
    cout << "\t\t\t        *                                                                                              *" << endl;
    cout << "\t\t\t        *                                           1.ADD ITEM RECORD                                  *" << endl;
    cout << "\t\t\t        *                                           2.UPDATE ITEM RECORD                               *" << endl;
    cout << "\t\t\t        *                                           3.DELETE ITEM RECORD                               *" << endl;
    cout << "\t\t\t        *                                           4.DISPLAY ITEM RECORD                              *" << endl;
    cout << "\t\t\t        *                                           5.SEARCH ITEM RECORD                               *" << endl;
    cout << "\t\t\t        *                                           6.PRINT BILL                                       *" << endl;
    cout << "\t\t\t        *                                                                                              *" << endl;
    cout << "\t\t\t        *==============================================================================================*" << endl;
    cout << "\t\t\t        ************************************************************************************************";
    cout << "\t\t\t                                                  SELECT YOURS OPTION :";
    cin >> choice;
    switch (choice) {
    case 1:
        addItem();
        break;
    case 2:
        updateItem();
        break;
    case 3:
        deleteItem();
        break;
    case 4:
        displayItem();
        break;
    case 5:
        searchItem();
        break;
    case 6:
        print_Bill();
    case 7:
        cout << " EXITING PROGRAM...\n";
        break;
    default:

        cout << " INVALID CHOICE.PLEASE TRY AGIN\n";
        break;
    }
    while (choice != 6);

}
item items[MAX_ITEMS];
int numItems = 0;
// CREATE ADDITEM FUNCATION 
void addItem() {
    item newItem;
    cout << "\n\n\n\n" << endl;
    system("color 8");
    cout << "\t\t\t\t\t\t\            ******************************************\n" << endl;
    cout << "\t\t\t\t                  >>>~~ ENTER FOOD ITEM NAME HERE      : ";
    cin >> newItem.name;
    cout << "\n\t\t\t\t                >>>~~ ENTER FOOD ITEM PRICE HERE     : ";
    cin >> newItem.price;
    cout << "\n\t\t\t\t                >>>~~ ENTER FOOD ITEM QUANTITY HERE  : ";
    cin >> newItem.quantity;
    // CHECK FOR DUPLICATE ITEM 
    bool found = false;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == newItem.name) {
            found = true;
            items[i].price = newItem.price;
            break;
        }
    }
    if (!found) {
        items[numItems] = newItem;
        numItems++;
    }
    ofstream fout("items.txt", ios::app);
    fout << newItem.name << " " << newItem.price << " " << newItem.quantity << endl;
    fout.close();
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t               >>>~~ ITEM ADDED SUCCESSFULLY .\n";

    while (true) {
        int add;
        cout << " PRESS ENTER 02 RETURN SUB MENU PAGE : ";
        cin >> add;
        if (add == 2);
        system("cls");
        sub_Menu();
        break;
    }

}

// CREATE UPDATE ITEM FUNCTION	
void updateItem() {

    string name;
    system("color 5");
    bool found = false;
    cout << "\t\t\t\t\t\t************************************************************************\n" << endl;
    cout << "\n\t\t\t\t                       >>>~~ ENTER FOOD ITEM NAME TO UPDATE  HERE: ";
    cin >> name;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == name) {
            cout << "\n\t\t\t\t               >>>~~ ENTER NEW FOOD ITEM PRICE : ";
            cin >> items[i].price;
            cout << "\n\t\t\t\t               >>>~~ ENTER NEW FOOD ITEM QUANTITY : ";
            cin >> items[i].quantity;
            found = true;
            ofstream fout("temp.txt");// FILE HANDLING TECHNIC 
            for (int j = 0; j < numItems; j++) {
                fout << items[j].name << " " << items[j].price << " " << items[j].quantity << endl;
            }
            fout.close();
            rename("temp.txt", "items.txt");
            cout << "\n\t\t\t\t               >>>~~ NEW ITEM UPDATE SUCCESSFULLY ~~<<<\n";
            while (true) {
                int update;
                cout << " PRESS ENTER 02 RETURN SUB MENU PAGE : ";
                cin >> update;
                if (update == 2);
                system("cls");
                sub_Menu();
                break;
            }
        }
    }
    if (!found) {
        cout << "\n\t\t\t\t               >>>~~ ITEM NOT FOUND . \n";
        while (true) {
            int update;
            cout << " PRESS ENTER 02 RETURN SUB MENU PAGE : ";
            cin >> update;
            if (update == 2);
            system("cls");
            sub_Menu();
            break;
        }
    }
}
// CREATE DELETE FUNCTION
void  deleteItem() {
    system("color 4");
    string name;
    bool found = false;
    cout << "\t\t\t\t\t\t\************************************************************************\n" << endl;
    cout << "\n\t\t\t\t                  >>>~~ ENTER FOOD ITEM NAME TO DELETE  HERE: ";
    cin >> name;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == name) {
            found = true;
            for (int j = i; j < numItems - 1; j++) {
                items[j] = items[j + 1];
            }
            numItems--;
            ofstream fout("items.txt");// FILE HANDLING TECHNIC 
            for (int j = 0; j < numItems; j++) {
                fout << items[j].name << " " << items[j].price << " " << items[j].quantity << endl;// HERE I USED ARRAYS 
            }
            fout.close();
            rename("temp.txt", "items.txt");
        }
        cout << "\n\t\t\t\t                  >>>~~ITEM DELETED SUCCESS.\n";

    }
    if (!found) {
        cout << "\n\t\t\t\t                  >>>~~ITEM NOT FOUND.\n";
    }
    while (true) {
        int display;
        cout << " PRESS ENTER 02 RETURN SUB MENU PAGE : ";
        cin >> display;
        if (display == 2);
        system("cls");
        sub_Menu();
        break;
    }
}

// CREATE THE ITEM DISPLAY FUNCTION 
void displayItem() {
    system("color 1");
    ifstream fin("items.txt");
    item displayedItem;
    cout << "\n\t\t\t\t\t\t      FOOD NAME              FOOD  PRICE                    FOOD QUANTITY  " << endl;
    while (fin >> displayedItem.name >> displayedItem.price >> displayedItem.quantity) {
        cout << "\n\t\t\t\t\t\t\t" << displayedItem.name << "\t\t      " << displayedItem.price << "\t\t\t    " << displayedItem.quantity << endl;
    }
    fin.close();
    while (true) {
        int display;
        cout << " PRESS ENTER 02 RETURN SUB MENU PAGE : ";
        cin >> display;
        if (display == 2);
        system("cls");
        sub_Menu();
        break;
    }
}
// CREATE SEARCH MENU FUNCTION 
void searchItem() {
    system("color 7");
    string name;
    bool found = false;
    cout << "\n\t\t\t\t                  >>>~~ENTER ITEM NAME TO SEARCH : ";
    cin >> name;
    for (int i = 0; i < numItems; i++) {
        if (items[i].name == name) {
            found = true;
            cout << "\n\t\t\t\t\t\t       FOOD NAME              FOOD  PRICE            FOOD QUANTITY  " << endl;
            cout << "\n\t\t\t\t\t\t\t" << items[i].name << "\t\t       " << items[i].price << "\t\t      " << items[i].quantity << endl;
        }
    }
    if (!found) {
        cout << "\n\t\t\t\t                  >>>~~ITEM NOT FOUND :\n";

    }
    while (true) {
        cout << "\n\n\n";
        int check;
        cout << "\t\t\t\t\t PRESS ENTER 02 RETURN SUB MENU PAGE : ";
        cin >> check;
        if (check == 3);
        system("cls");
        sub_Menu();
        break;
    }
}
// CREATE GENETATE BILL FUNCTION 	
void print_Bill() {
    system("color 9");
    int quantity;
    string F_name;
    double price, subtotal, tax, total;


    //GET THE QUANTITY AND PRICE OF THE ITEM 
    cout << "\t\t\t\t\t ENTER THE FOOD ITEM NAME :  ";
    cin >> F_name;
    cout << "\t\t\t\t\t ENTER THE QUANTITY       : ";
    cin >> quantity;
    cout << "\t\t\t\t\t ENTER THE PRICE PER ITEM : ";
    cin >> price;

    //CALCULATE THE SUBTOTAL,TAX AND TOTAL

    subtotal = quantity * price;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;
    time_t now = time(0);
    char* dt = ctime(&now);

    // DISPLAY THE BILL

    //THE TAX RATE BBY MODIFYING THE TAX_RATE CONSTANT.
    //ADDITIONLLY YOU CAN MODIFY THE FORMATTING  OF THE OUTPUT USING THE "fixed" AND "setprecision" 
    //MANIPULATORS FROM THE <iomanip> HEADER.

    cout << "\n\n\n\n\n\n";
    cout << fixed << setprecision(2);
    cout << "\t\t\t\t\t************ BILL **************" << endl;
    cout << "\t\t\t\t\tDate: " << dt << endl;
    cout << "\t\t\t\t\tQuantity         : " << quantity << endl;
    cout << "\t\t\t\t\tPrice per item   : $" << price << endl;
    cout << "\t\t\t\t\tSubtotal         : $" << subtotal << endl;
    cout << "\t\t\t\t\tTax              : $" << tax << endl;
    cout << "\t\t\t\t\tTotal            : $" << total << endl;
    cout << "\t\t\t\t\t********************************" << endl;

}
