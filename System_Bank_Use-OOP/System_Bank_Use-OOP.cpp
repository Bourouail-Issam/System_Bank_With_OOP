// System_Bank_Use-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsCurrency.h"


static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();

    cout << "\n_____________________________\n";

}

int main()
{
	//while (true)
	//{
	//	if (!clsLoginScreen::ShowLoginScreen())
	//	{
	//		break;
	//	}
	//}
    clsCurrency Currency1 = Currency1.FindByCode("jod");

    if (Currency1.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency1);
    }

    clsCurrency Currency2 = Currency2.FindByCountry("Egypt");

    if (Currency2.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency2);
    }

    cout << "Currency1 after updating Rate:\n";
    Currency1.UpdateRate(0.71);
    _PrintCurrency(Currency1);

   return 0;
}

