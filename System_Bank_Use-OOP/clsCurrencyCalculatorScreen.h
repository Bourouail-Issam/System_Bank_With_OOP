#pragma once
#include"clsScreen.h"

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card : ")
	{
		cout << "\n" << Title;
		cout << "\n_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;

		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not Found , Choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}	 

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static double _ReadAmount()
	{
		double Amount = 0;
		cout << "\nEnter Amount To Exchange : ";
		Amount = clsInputValidate::ReadDblNumber();

		return Amount;
	}

	static void _PrintCalculationsResults(double Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "Convert From : ");

		double AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() != "USD")
		{
			cout << "\nConverting from USD to : \n";
			_PrintCurrencyCard(Currency2, "To : ");

			double AmountInCurrency2 = Currency1.ConvertToAnotherCurrency(Amount, Currency2);

			cout << Amount << " " << Currency1.CurrencyCode() << " = "
				<< AmountInCurrency2 << " " << Currency2.CurrencyCode();
		}
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char KeepConvert = 'n';
		do
		{
			_DrawScreenHeader("\tCalculate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency 1 Code : ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency 2 Code : ");
			double Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another Calculation ? y/n : ";
			cin >> KeepConvert;
			system("cls");

		} while ('y' == KeepConvert || 'Y' == KeepConvert);
	
	}
};

