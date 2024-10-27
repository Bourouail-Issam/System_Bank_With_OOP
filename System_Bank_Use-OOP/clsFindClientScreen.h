#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsFindClientScreen : protected clsScreen
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

    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }
        _DrawScreenHeader("\tFind Client Screen");

        string AccoutNumber = "";
        cout << "Please Enter Client Accout Number : ";
        AccoutNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccoutNumber))
        {
            cout << "Accout Number is not found, Choose another one : ";
            AccoutNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccoutNumber);
        
        if(!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient not Found :-(\n";
        }
        _PrintClient(Client);
    }

};

