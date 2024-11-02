#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManagerUsersScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"


class clsMainScreen :protected clsScreen
{
private:
	enum _enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange= 9 ,eExit = 10
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10] : ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10 : ");
		return Choice;
	}

	static  void _GoBackToCurrenciesMenue()
	{
		cout << "Press any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientsScreen()
	{
		// cout << "\nAdd New Client Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		// cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

 	static void _ShowFindClientScreen()
	{
		// cout << "\nFind Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		// cout << "\nTransactions Menue Will be here...\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		//cout << "\nUsers Menue Will be here...\n";
		clsManageUsersScreen::ShowManagerUsers();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowListUserLoginRegister();
	}

	static void _ShowCurrencyExchangeMainMenue()
	{
		clsCurrencyExchangeScreen::ShowCurrenciesMenue();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	
	static void _PerfromMainMenueOption(_enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		    case _enMainMenueOptions::eListClients:
				system("cls");
				_ShowAllClientsScreen();
				_GoBackToCurrenciesMenue();
		    	break;

		    case _enMainMenueOptions::eAddNewClient:
				system("cls"); 
				_ShowAddNewClientsScreen();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eDeleteClient:
				system("cls");
				_ShowDeleteClientScreen();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eUpdateClient:
				system("cls");
				_ShowUpdateClientScreen();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eFindClient:
				system("cls");
				_ShowFindClientScreen();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eShowTransactionsMenue:
				system("cls"); 
				_ShowTransactionsMenue();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eManageUsers:
				system("cls");
				_ShowManageUsersMenue();
				_GoBackToCurrenciesMenue();
				break;

			case _enMainMenueOptions::eLoginRegister:
				system("cls");
				_ShowLoginRegisterScreen();
				_GoBackToCurrenciesMenue();
				break;

			case _enMainMenueOptions::eCurrencyExchange:
				system("cls");
				_ShowCurrencyExchangeMainMenue();
				_GoBackToCurrenciesMenue();
				break;

		    case _enMainMenueOptions::eExit:
				system("cls"); 
				_Logout();
				break;
		}
	}

public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "[1] Show Client List.\n";
		cout << setw(37) << left << "" << "[2] Add New Client\n";
		cout << setw(37) << left << "" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "[6] Transactions.\n";
		cout << setw(37) << left << "" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "[8] Login Register.\n";
		cout << setw(37) << left << "" << "[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "[10] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
	}
};

