#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <iostream> 
#include <vector>
using namespace std;

class ShoppingCart {
    private:
        string customerName;
        string currentDate;
        vector<ItemToPurchase> cartItems;
    public:
        ShoppingCart();
        ShoppingCart(string n, string d);
        void AddItem(ItemToPurchase item);
        void RemoveItem(string name);
        void ModifyItem(ItemToPurchase item);
        void PrintTotal();
        void PrintDescription();
        string GetCustomerName();
        string GetDate();
        int GetNumItemsInCart();
        int GetCostOfCart();
};



#endif