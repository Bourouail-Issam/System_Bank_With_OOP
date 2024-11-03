#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMenueScreen :protected clsScreen
{
private:

	enum _enCurrenciesMainMenueOptions
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRateCurrency = 3,
		eCurrencyCalculator = 4, eMainMenue = 5,
	};

	static short _ReadCurrenciesMainMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5] : ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 : ");
		return Choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\nPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowCurrenciesListScreen()
	{
		//cout << "\nCurrencies List Screen Will be here...\n";
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be here...\n";
		clsFindCurrencyScreen::ShowFindCuurencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
	     //cout << "\nUpdate Currency Rate Screen Will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nShow Currency Calculator Screen Will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}


	static void _PerformCurrenciesMainMenueOptions(_enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	{
		switch (CurrenciesMainMenueOptions)
		{
		case _enCurrenciesMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case _enCurrenciesMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case _enCurrenciesMainMenueOptions::eUpdateRateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case _enCurrenciesMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case _enCurrenciesMainMenueOptions::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
		}
	}

public:

	static void  ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("   Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "============================================\n";
					 				   
		cout << setw(37) << left << "" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "[3] Update Rate.\n";
		cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "[5] Main Menu.\n";
					 				   
		cout << setw(37) << left << "" << "============================================\n";

		_PerformCurrenciesMainMenueOptions((_enCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueOptions());
	}
};

