#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen :protected clsScreen
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

public:

	static void ShowDeleteClientScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tDelete Client Screen");

        string AccoutNumber = "";
        cout << "Please Enter Client Accout Number : ";
        AccoutNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccoutNumber))
        {
            cout << "Accout Number is not found, Choose another one : ";
            AccoutNumber = clsInputValidate::ReadString();
        }

        clsBankClient DeleteClient = clsBankClient::Find(AccoutNumber);
        _PrintClient(DeleteClient);

        char Answer = 'n';
        cout << "\nAre you sure you want to delete this client n/y? : ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (DeleteClient.Delete())
            {
                cout << "\nClient Deleted Successfully :)\n";
                _PrintClient(DeleteClient);
            }
            else
            {
                cout << "\nError Client was not Deleted\n";
            }
        }
	}
};

