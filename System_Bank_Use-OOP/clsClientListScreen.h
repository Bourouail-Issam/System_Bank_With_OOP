#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include "clsUser.h"

class clsClientListScreen :protected clsScreen
{
private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) 
			 << Client.AccountNumber;
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(18) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowClientList()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";
		
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" 
			 << "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) 
			 << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(18) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";

		cout << setw(8) << left << "" 
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
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;
	}
};

