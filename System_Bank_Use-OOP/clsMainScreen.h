#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"

class clsMainScreen :protected clsScreen
{
private:
	enum _enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eExit = 8
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8] : ";
		short Choice = clsInputValidate::ReadFloatNumberBetween(1, 8, "Enter Number between 1 to 8 : ");
		return Choice;
	}

	static  void _GoBackToMainMenue()
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
		cout << "\nDelete Client Screen Will be here...\n";
	}

	static void _ShowUpdateClientScreen()
	{
		cout << "\nUpdate Client Screen Will be here...\n";
	}

	static void _ShowFindClientScreen()
	{
		cout << "\nFind Client Screen Will be here...\n";
	}

	static void _ShowTransactionsMenue()
	{
		cout << "\nTransactions Menue Will be here...\n";
	}

	static void _ShowManageUsersMenue()
	{
		cout << "\nUsers Menue Will be here...\n";
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen Will be here...\n";
	}

	
	static void _PerfromMainMenueOption(_enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		    case clsMainScreen::eListClients:
				system("cls");
				_ShowAllClientsScreen();
				_GoBackToMainMenue();
		    	break;
		    case clsMainScreen::eAddNewClient:
				system("cls"); 
				_ShowAddNewClientsScreen();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eDeleteClient:
				system("cls");
				_ShowDeleteClientScreen();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eUpdateClient:
				system("cls");
				_ShowUpdateClientScreen();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eFindClient:
				system("cls");
				_ShowFindClientScreen();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eShowTransactionsMenue:
				system("cls"); 
				_ShowTransactionsMenue();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eManageUsers:
				system("cls");
				_ShowManageUsersMenue();
				_GoBackToMainMenue();
				break;
		    case clsMainScreen::eExit:
				system("cls"); 
				_ShowEndScreen();
				// Login();
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
		cout << setw(37) << left << "" << "[8] Logout.\n";
		cout << setw(37) << left << "" << "============================================\n";

		_PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenueOption());
	}
};

