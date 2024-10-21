#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

class clsTotalBalancesScreen :protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << left << setw(20)
			<< Client.AccountNumber;
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(15) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t  Balances List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client (s).";
		
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << ""
			 << "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw(25) << left << ""
			 << "| " << left << setw(15)<< "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(25) << left << ""
			 << "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;


		if (vClients.size() == 0)
		{
			cout << clsUtil::Tabs(4) << "No Clients Available In The System!";
		}
		else
		{
			for (clsBankClient C : vClients)
			{
				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}
			cout << setw(25) << left << ""
				<< "\n\t_______________________________________________________";
			cout << "________________________________________________\n" << endl;

			double TotalBalances = clsBankClient::GetTotalBalances();
			cout << setw(8) << left << "" <<clsUtil::Tabs(7) <<"     Totale Balances is : " 
				 << TotalBalances;

			cout << "\n" << setw(8) << left << ""
				 << clsUtil::Tabs(4)<< "  ( " << clsUtil::NumberToText(TotalBalances)
				<< " )" << endl;
		}


	}
};

