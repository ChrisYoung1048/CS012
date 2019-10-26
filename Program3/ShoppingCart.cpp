#include<iostream> 
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string n, string d) {
    customerName = n;
    currentDate = d;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == name) {
            cartItems.erase(cartItems.begin()+i); 
            cout << endl; //fix 
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl << endl; //fix
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            if (cartItems.at(i).GetDescription() != "none" && cartItems.at(i).GetPrice() != 0 && cartItems.at(i).GetQuantity() != 0) {
                //cartItems.at(i).SetDescription(item.GetDescription());
                //cartItems.at(i).SetPrice(item.GetPrice());
                cartItems.at(i).SetQuantity(item.GetQuantity());
                cout << endl; //fix
                return;
            }
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl << endl;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

int ShoppingCart::GetNumItemsInCart() {
    int totalQuantity = 0; 
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        totalQuantity += cartItems.at(i).GetQuantity();
    }
    return totalQuantity;
}

int ShoppingCart::GetCostOfCart() {
    int totalPrice = 0;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        totalPrice += cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity();
    }
    return totalPrice; 
}

void ShoppingCart::PrintTotal() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
    if(GetNumItemsInCart() == 0) {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        cartItems.at(i).PrintItemCost();
    } 
    cout << endl << "Total: $" << GetCostOfCart() << endl << endl;
}

void ShoppingCart::PrintDescription() {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned i = 0; i < cartItems.size(); ++i) {
        cartItems.at(i).PrintItemDescription();
    }
    cout << endl;
}

