#include<iostream> 
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemDescription = "none";
    itemPrice = 0;
    itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string n, string d, int p, int q) {
    itemName = n;
    itemDescription = d;
    itemPrice = p;
    itemQuantity = q;
}

void ItemToPurchase::SetName(string name) {
    itemName = name; 
}

string ItemToPurchase::GetName() {
    return itemName;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description; 
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice = price; 
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}

void ItemToPurchase::PrintItemCost() {
    int subtotal = itemQuantity * itemPrice;
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << subtotal << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl; 
}