#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");
		string AccountNumber = _ReadAccountNumber();
		

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter Deposit amount : ";
		double Amount = clsInputValidate::ReadDblNumber();
		
		char Answer = 'n';
		cout << "\nAre you sure you want to perfrom this transaction? y/n : ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully\n";
			cout << "\nNew balance is : " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
};

