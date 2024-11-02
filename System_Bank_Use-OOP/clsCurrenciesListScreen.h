#pragma once
#include"clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrenciesListScreen :protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(42) << left << Currency.CurrencyName()
			<< "| " << setw(6) << left << Currency.CurrencyCode()
			<< "| " << setw(35) << left << Currency.Country()
			<< "| " << setw(10) << left << Currency.Rate();
	}
public:

	static void ShowCurrenciesList()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Titel = "\tCurrencies List Screen";
		string Subtitle = "\t   (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(Titel, Subtitle);

		 
		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;


		cout << setw(8) << left << "" << "| " << setw(42) << left << "Country"
			 << "| " << setw(6) << left << "Code" 
			 << "| " << setw(35) << left << "Name"
			 << "| " << setw(10) << left << "Rate(1$)";

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;


		if (vCurrencies.size()== 0)
		{
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else
		{
			for (clsCurrency& C : vCurrencies )
			{
				_PrintCurrency(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;

	}
};

