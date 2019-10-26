#include <iostream> 
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart &);

int main() {
    //Pass in data
    string input1;
    string input2;
    cout << "Enter customer's name:" << endl;
    getline(cin, input1);
    cout << "Enter today's date:" << endl;
    getline(cin, input2);

    //Print shopping cart info
    ShoppingCart myShoppingCart(input1, input2);
    cout << endl << "Customer name: " << myShoppingCart.GetCustomerName();
    cout << endl << "Today's date: " << myShoppingCart.GetDate() << endl << endl;

    PrintMenu(myShoppingCart);

    return 0;
}

void PrintMenu(ShoppingCart &sc){
    while (true) {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl; 

        string inputSelection;
        while (true) {
            cout << "Choose an option:" << endl;
            cin >> inputSelection;
            if (inputSelection == "a" || inputSelection ==  "d" || inputSelection == "c" || inputSelection == "i" || 
            inputSelection == "o" || inputSelection == "q") {
                break;
            }
        } cin.ignore();


        if(inputSelection == "a") {
            cout << "ADD ITEM TO CART" << endl;
            string n, d;
            int p, q;
            cout << "Enter the item name:" << endl;
            getline(cin , n);
            cout << "Enter the item description:" << endl;
            getline(cin , d);
            cout << "Enter the item price:" << endl;
            cin >> p;
            cout << "Enter the item quantity:" << endl;
            cin >> q;
            cout << endl;
            sc.AddItem(ItemToPurchase(n, d, p ,q));
        } else if (inputSelection == "d") {
            cout << "REMOVE ITEM FROM CART" << endl;
            string inputName;  
            cout << "Enter name of item to remove:" << endl;
            getline(cin, inputName);
            sc.RemoveItem(inputName);
        } else if (inputSelection == "c") {
            cout << "CHANGE ITEM QUANTITY" << endl; 
            string inputName;
            int inputQuantity; 
            cout << "Enter the item name:" << endl;
            getline(cin, inputName);
            cout << "Enter the new quantity:" << endl;
            cin >> inputQuantity;
            ItemToPurchase modifiedItem;
            modifiedItem.SetName(inputName);
            modifiedItem.SetQuantity(inputQuantity);
            sc.ModifyItem(modifiedItem);
        } else if (inputSelection == "i") {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            sc.PrintDescription();
        } else if (inputSelection == "o") {
            cout << "OUTPUT SHOPPING CART" << endl;
            sc.PrintTotal();
        } else if (inputSelection == "q") {
           break; 
        }
    }
} 



