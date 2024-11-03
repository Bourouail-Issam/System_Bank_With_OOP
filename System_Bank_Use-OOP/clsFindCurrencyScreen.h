#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found : -)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found : -(\n";
			_PrintCurrency(Currency);
		}
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n\n";

	}

public:
	static void ShowFindCuurencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Main Screen");

		short Answer;
		cout << "\nFind By : [1] Code or [2] Country ? : ";
		Answer = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number 1 or 2 :");

		if ( 1 == Answer)
		{
			string CurrencyCode;
			cout << "\nPlease Enter Currency Code : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string CurrencyCode;
			cout << "\nPlease Enter Country: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCode);
			_ShowResults(Currency);
		}
	}
};

