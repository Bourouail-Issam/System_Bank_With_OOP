#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsUpdateCurrencyRateScreen  :protected clsScreen
{
private:

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

	static float _ReadRate()
	{
		cout << "\nEnter New Rate : ";
		float NewRate = 0;
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t  Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Curreny Code : ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not Found , Choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);


		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this Currency y/n : ";
		cin >> Answer;

		if ('y' == Answer || 'Y' == Answer)
		{
			cout << "\nUpdate Currencu Rate : \n";
			cout << "_____________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rtae Update Successfully :-)\n";
			_PrintCurrency(Currency);
		}

		
	}
};

