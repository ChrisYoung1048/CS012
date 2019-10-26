#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <iostream> 
using namespace std;

class ItemToPurchase {
    private:
        string itemName;
        string itemDescription;
        int itemPrice;
        int itemQuantity;
    public:
        ItemToPurchase();
        ItemToPurchase(string n, string d, int p, int q);
        void PrintItemCost();
        void PrintItemDescription();
        void SetName(string name);
        string GetName();
        void SetDescription(string description); 
        string GetDescription();
        void SetPrice(int price);
        int GetPrice();
        void SetQuantity(int quantity);
        int GetQuantity();
};

#endif