//
//  main.cpp
//  CPP-PRG-11-13-Drink-Machine-Simulator
//
//  Created by Keith Smith on 11/10/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that simulates a soft drink machine. The program should use a structure
//  that stores the following data:
//
//      Drink Name
//      Drink Cost
//      Number of Drinks in Machine
//
//  The program should create an array of five structures. The elements should be
//  initialized with the following data:
//
//      Drink Name          Cost            Number in Machine
//      -----------------------------------------------------
//      Cola                .75             20
//      Root Beer           .75             20
//      Lemon-Lime          .75             20
//      Grape Soda          .80             20
//      Cream Soda          .80             20
//
//  Each time the program runs, it should enter a loop that performs the following steps:
//  A list of drinks is displayed on the screen. The user should be allowed to either quit the
//  program or pick a drink. If the user selects a drink, he or she will next enter the amount
//  of money that is to be inserted into the drink machine. The program should display the
//  amount of change that would be returned, and subtract one from the number of that
//  drink left in the machine. If the user selects a drink that has sold out, a message should
//  be displayed. The loop then repeats. When the user chooses to quit the program, it
//  should display the total amount of money the machine earned.
//
//  Input Validation: When the user enters an amount of money, do not accept negative
//  values or values greater than $1.00.
//

#include <iostream>
#include <iomanip>

using namespace std;

const int INT_NUM_DRINKS = 6;

struct StructDrink
{
    string strName;
    double dblCost;
    int intDrinks;
};

StructDrink *createDrinksArray();
StructDrink *getDrinkInfo(int *);
int *makeMenuSelection();
double *getPayment();
bool *validateTotal(StructDrink *, double *);
void returnChange(StructDrink *, double *);

using namespace std;

int main()
{
    int *intMenuSelection = nullptr;
    intMenuSelection = new int;
    *intMenuSelection = -1;
    
    double *dblPayment = nullptr;
    dblPayment = new double;
    *dblPayment = 0.0;
    
    double *dblProfitTotal = nullptr;
    dblProfitTotal = new double;
    *dblProfitTotal = 0.0;
    
    StructDrink *sdDrinksArray = nullptr;
    sdDrinksArray = new StructDrink;
    
    sdDrinksArray = createDrinksArray();
    
    intMenuSelection = makeMenuSelection();
    
    while (*intMenuSelection != 6)
    {
        while (*validateTotal(&sdDrinksArray[*intMenuSelection], dblPayment) == false)
        {
            cout << sdDrinksArray[*intMenuSelection].strName << endl;
            *dblPayment += *getPayment();
            cout << "Total: $" << *dblPayment << endl;
        }
        
        *dblProfitTotal += sdDrinksArray[*intMenuSelection].dblCost;
        
        returnChange(&sdDrinksArray[*intMenuSelection], dblPayment);
        
        *dblPayment = 0.0;
        
        intMenuSelection = makeMenuSelection();
    }
    
    cout << "\nThe machine made $" << *dblProfitTotal << endl;
    
    cout << endl << endl << "You have exited the program." << endl;
    
    return 0;
}

StructDrink *createDrinksArray()
{
    StructDrink *sdDrinksArr = nullptr;
    sdDrinksArr = new StructDrink[INT_NUM_DRINKS];
    
    int *intIndex = nullptr;
    intIndex = new int;
    
    for (*intIndex = 0 ; *intIndex < INT_NUM_DRINKS ; *intIndex += 1)
    {
        sdDrinksArr[*intIndex] = *getDrinkInfo(intIndex);
    }
    
    return sdDrinksArr;
}

StructDrink *getDrinkInfo(int *intDrinkNum)
{
    StructDrink *sdDrink = nullptr;
    sdDrink = new StructDrink;
    
    string *strName = nullptr;
    strName = new string;
    
    int *intQuantity = nullptr;
    intQuantity = new int;
    *intQuantity = 20;
    
    double *dblCostA = nullptr;
    dblCostA = new double;
    *dblCostA = 0.75;
    
    double *dblCostB = nullptr;
    dblCostB = new double;
    *dblCostB = 0.8;
    
    switch(*intDrinkNum)
    {
        case 1:
            sdDrink->strName = "Cola";
            sdDrink->dblCost = *dblCostA;
            sdDrink->intDrinks = *intQuantity;
            break;
        case 2:
            sdDrink->strName = "Root Beer";
            sdDrink->dblCost = *dblCostA;
            sdDrink->intDrinks = *intQuantity;
            break;
        case 3:
            sdDrink->strName = "Lemon-Lime";
            sdDrink->dblCost = *dblCostA;
            sdDrink->intDrinks = *intQuantity;
            break;
        case 4:
            sdDrink->strName = "Grape Soda";
            sdDrink->dblCost = *dblCostB;
            sdDrink->intDrinks = *intQuantity;
            break;
        case 5:
            sdDrink->strName = "Cream Soda";
            sdDrink->dblCost = *dblCostB;
            sdDrink->intDrinks = *intQuantity;
            break;
        default:
            break;
    }
    return sdDrink;
}

int *makeMenuSelection()
{
    int *intSelection = nullptr;
    intSelection = new int;
    
    cout << "\nPlease select from the following menu options:\n";
    cout << "\t1. Cola\n";
    cout << "\t2. Root Beer\n";
    cout << "\t3. Lemon-Lime\n";
    cout << "\t4. Grape Soda\n";
    cout << "\t5. Cream Soda\n";
    cout << "\t6. Exit\n";
    
    cout << "Selection: ";
    cin >> *intSelection;
    while(!cin || *intSelection < 1 || *intSelection > 6)
    {
        cout << "\nPlease select from the available menu options.\n";
        cin.clear();
        cin.ignore();
        cin >> *intSelection;
    }
    
    return intSelection;
}

double *getPayment()
{
    double *dblPay = nullptr;
    dblPay = new double;
    
//    double *dblRunningTotal = nullptr;
//    dblRunningTotal = new double;
//    *dblRunningTotal = 0.0;
    
    
    cout << "Please enter the amount of money\n";
    cout << "you will insert into the machine:\n$";
//    cout << "Current total: " << *dblRunningTotal;
    cin >> *dblPay;
    while(!cin || *dblPay <= 0.0 || *dblPay > 1.0)
    {
        cout << "Please enter a dollar amount\n";
        cout << "between $0.00 and $1.00:\n$";
        cin.clear();
        cin.ignore();
        cin >> *dblPay;
    }
    
//    *dblRunningTotal += *dblPay;
    
    return dblPay;
}

bool *validateTotal(StructDrink *sdDrink, double *dblPayTotal)
{
    bool *booIsValid = nullptr;
    booIsValid = new bool;
    *booIsValid = false;
    
    if (*dblPayTotal < sdDrink->dblCost)
    {
        *booIsValid = false;
    }
    else if (*dblPayTotal >= sdDrink->dblCost)
    {
        *booIsValid = true;
    }
    
    return booIsValid;
}

void returnChange(StructDrink *sdDrink, double *dblMoney)
{
    cout << endl << sdDrink->strName << endl;
    
    *dblMoney = *dblMoney - sdDrink->dblCost;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Here is your change:\n$";
    cout << *dblMoney;
}
