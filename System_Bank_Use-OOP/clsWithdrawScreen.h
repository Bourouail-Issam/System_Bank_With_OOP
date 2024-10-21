#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFirstName     : " << Client.FirstName;
		cout << "\nLastName      : " << Client.LastName;
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nEmail         : " << Client.Email;
		cout << "\nPhone         : " << Client.Phone;
		cout << "\nAccountNumber : " << Client.AccountNumber;
		cout << "\nPinCode       : " << Client.PinCode;
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}

public:
	
	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");
		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter withdraw amount : ";
		double Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\nAre you sure you want to perfrom this transaction? y/n : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot Withdraw, Insuffecient Balance\n";
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\nUour Balance is : " << Client.AccountNumber;
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

