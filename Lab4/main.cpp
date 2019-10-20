#include <iostream> 
using namespace std;

#include "ItemToPurchase.h"

int main() {
    ItemToPurchase item1;
    ItemToPurchase item2;
    int totalCost;

    string inputStr; 
    int inputNum; 

    cout << "Item 1\nEnter the item name:" << endl;
    getline(cin, inputStr);
    item1.SetName(inputStr);
    cout << "Enter the item price:" << endl;
    cin >> inputNum;
    item1.SetPrice(inputNum);
    cout << "Enter the item quantity:" << endl;
    cin >> inputNum;
    item1.SetQuantity(inputNum);
    
    cout << endl;
    cin.ignore();

    cout << "Item 2\nEnter the item name:" << endl;
    getline(cin, inputStr);
    item2.SetName(inputStr);
    cout << "Enter the item price:" << endl;
    cin >> inputNum;
    item2.SetPrice(inputNum);
    cout << "Enter the item quantity:" << endl;
    cin >> inputNum;
    item2.SetQuantity(inputNum);

    cout << endl;

    cout << "TOTAL COST" << endl;
    cout << item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << (item1.GetQuantity() * item1.GetPrice()) << endl; 
    cout << item2.GetName() << " " << item2.GetQuantity() << " @ $" << item2.GetPrice() << " = $" << (item2.GetQuantity() * item2.GetPrice()) << endl;
    
    cout << endl;

    totalCost = (item1.GetQuantity() * item1.GetPrice()) + (item2.GetQuantity() * item2.GetPrice());
    cout << "Total: $" << totalCost << endl;

    return 0;
}