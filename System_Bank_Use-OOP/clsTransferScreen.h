#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsTransferScreen :protected clsScreen
{
private:

	static string _ReadAccountNumber(string client)
	{
		string AccountNumber;

		cout << "\nPlease Enter Account Number to transfer " << client << " : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\nEnter Transfer Amount ? : ";
	    Amount = clsInputValidate::ReadDblNumber();

		while ( SourceClient.AccountBalance < Amount)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name     : " << Client.FullName();
		cout << "\nAccountNumber : " << Client.AccountNumber;
		cout << "\nBalance       : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen");
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		while (SourceClient.AccountNumber == DestinationClient.AccountNumber)
		{
			cout << "\nYou Cant Tansfer Money To Yourself.\n";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		}
		_PrintClient(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount,DestinationClient)) 
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

