#include "item.h"
#include <iostream>
 
void displayMenu(void);
int getOption(void);
void sellItem(ITEM *iPtr, int num);
int getItem(int itemNum, ITEM *iPtr, int num);
void displayItems(ITEM *items, int num);
 
int main()
{
    ITEM items[] = {
        {101, "Shirts", 100.0, 100, 80.0, 0.0, false},
        {102, "Pants", 150.0, 50, 120.0, 0.0, false},
        {103, "Shorts", 200.0, 80, 180.0, 0.0, false},
        {104, "Skirts", 250.0, 70, 220.0, 0.0, false},
        {105, "Saree", 300.0, 90, 150.0, 0.0, false},
        {106, "Socks", 350.0, 95, 320.0, 0.0, false},
        {107, "Ties", 400.0, 85, 350.0, 0.0, false},
        {108, "T-Shirts", 450.0, 75, 410.0, 0.0, false},
    };
 
    while (true)
    {
        displayMenu();
        int option = getOption();
        if (option == 6)
            break;
 
        switch(option)
        {
            case 1:
                sellItem(items, 8);
                break;
            case 5:
                displayItems(items, 8);
            }
    }
}
 
void displayItems(ITEM *items, int num)
{
    for (int idx = 0; idx < num; idx++)
    {
        cout << items[idx].num << ", "
             << items[idx].name << ", "
             << items[idx].QOH << ", "
             << items[idx].sellRate << ", "
             << items[idx].buyRate << ", "
             << items[idx].discountRate << ", "
             << items[idx].bIsRemoved << endl;
    }
}
 
void sellItem(ITEM *items, int num)
{
    int itemNum;
    int idx;
 
    cout << "Enter Item to Sell: ";
    cin >> itemNum;
    idx = getItem(itemNum, items, num);
    if (idx == -1)
    {
        cout << "Item is not present : " << itemNum << endl;
        return;
    }
    if (items[idx].bIsRemoved)
    {
        cout << "Item is removed: " << itemNum << endl;
        return;
    }
 
    int qty;
    cout << "Enter Qty to Sell: ";
    cin >> qty;
    if (qty > items[idx].QOH)
    {
        cout << "Qty not available" << endl;
        return;
    }
 
    cout << "Sell Transaction: {" << items[idx].num << ", "
         << items[idx].name << ", " << qty << ", " << items[idx].sellRate
         << ", " << qty * items[idx].sellRate << "}" << endl;
    items[idx].QOH -= qty;
}
 
int getItem(int iNum, ITEM *items, int num)
{
    for (int idx = 0; idx < num; idx++)
    {
        if (items[idx].num == iNum)
            return idx;
    }
 
    return -1;
}
 
void displayMenu(void)
{
    cout << "1. Sell Item" << endl;
    cout << "2. Stock Item" << endl;
    cout << "3. Remove Item" << endl;
    cout << "4. Put Item on Sale" << endl;
    cout << "5. Display Items" << endl;
    cout << "6. Exit" << endl;
}
 
int getOption(void)
{
    int option;
 
    do
    {
        cout << "Enter Option (1-5): ";
        cin >> option;
    } while (option < 1 || option > 5);
    return option;
}
 
 
 