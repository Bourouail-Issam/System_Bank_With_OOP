#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:

	static enum _enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,
		eShowMainMenue = 4
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		short Choice = 0;
		Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4? ");
		return Choice;
	};

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();

	};

	static void _ShowDepositScreen()
	{
	  // cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
	};

	static void _ShowWithdrawScreen()
	{
		// cout << "\n Withdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithDrawScreen();
	};

	static void _ShowTotalBalancesScreen()
	{
		cout << "\n Balances Screen will be here.\n";
	};

	static void _PerfromTranactionsMenueOption(_enTransactionsMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		    case clsTransactionsScreen::eDeposit:
		    {
		    	system("cls");
		    	_ShowDepositScreen();
		    	_GoBackToTransactionsMenue();
		    	break;
		    }
		    case clsTransactionsScreen::eWithdraw:
		    {
		    	system("cls");
		    	_ShowWithdrawScreen();
		    	_GoBackToTransactionsMenue();
		    	break;
		    }
		    case clsTransactionsScreen::eShowTotalBalance:
		    {
		    	system("cls");
		    	_ShowTotalBalancesScreen();
		    	_GoBackToTransactionsMenue();
		    	break;
		    }
		    case clsTransactionsScreen::eShowMainMenue:
		    {
				//do nothing here the main screen will handle it :-) ;
		    }
		}
	};

public:

	static void ShowTransactionsMenue()
	{
		system("cls");
		_DrawScreenHeader("\t  Transaction Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromTranactionsMenueOption((_enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

};

