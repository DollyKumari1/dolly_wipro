#include <iostream>
#include <string>
using namespace std;

struct Item {
    int ItemNumber;
    string ItemName;
    int QOH; 
    bool isItemRemoved; 
    double SellRate;
};

void SellItem(Item items[], int numItems) {
    int itemNumber;
    int sellQty;

    cout << "Enter Item Number to sell: ";
    cin >> itemNumber;

    bool found = false;
    int index = -1;
    for (int i = 0; i < numItems; ++i) {
        if (items[i].ItemNumber == itemNumber) {
            found = true;
            index = i;
            break;
        }
    }

    if (!found) {
        cout << "Item is Not Present" << endl;
        return;
    }

    if (items[index].isItemRemoved) {
        cout << "Item is not for sale" << endl;
        return;
    }

    // Enter Qty To Sell
    cout << "Enter Quantity to sell: ";
    cin >> sellQty;

    if (sellQty > items[index].QOH) {
        cout << "Quantity not Available" << endl;
        return;
    }

    cout << "Transaction Details:" << endl;
    cout << "Item Number: " << items[index].ItemNumber << endl;
    cout << "Item Name: " << items[index].ItemName << endl;
    cout << "Sell Quantity: " << sellQty << endl;
    cout << "Sell Rate: " << items[index].SellRate << endl;


    items[index].QOH -= sellQty;
}

int main() {
    const int MAX_ITEMS = 100; 
    Item items[MAX_ITEMS] = {
        {1, "Item A", 10, false, 25.0},
        {2, "Item B", 5, true, 30.0},
    };
    int numItems = 2; 
    SellItem(items, numItems);

    return 0;
}
