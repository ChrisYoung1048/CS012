#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>
using namespace std;

class ItemToPurchase {
    public:
        void SetName(string name);
        string GetName();
        void SetPrice(int price);
        int GetPrice();
        void SetQuantity(int quantity);
        int GetQuantity();
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
};

#endif