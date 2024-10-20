#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "Enter FirstName : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "Enter LastName : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "Enter Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "Enter Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "Enter PineCode : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "Enter Accout Balance : ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\Client Card:";
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
     
    static void ShowUpdateClientScreen()
    {
        _DrawScreenHeader("\tUpdate Client Screen");

        string AccoutNumber = "";
        cout << "Please Enter Client Accout Number : ";
        AccoutNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccoutNumber))
        {
            cout << "Accout Number is not found, Choose another one : ";
            AccoutNumber = clsInputValidate::ReadString();
        }

        clsBankClient Updateclient = clsBankClient::Find(AccoutNumber);
        _PrintClient(Updateclient);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if ('y' == Answer || 'Y' == Answer)
        {
            cout << "\nUpDate Client Info : ";
            cout << "\n--------------------\n";

            _ReadClientInfo(Updateclient);

            clsBankClient::enSaveResults SaveResult;
            SaveResult = Updateclient.Save();

            switch (SaveResult)
            {
            case clsBankClient::svSucceeded:
                cout << "\nAccount Updated Successfuly :-)\n";
                _PrintClient(Updateclient);
                break;

            case clsBankClient::svFaildEmptyObject:
                cout << "\nError account was not saved because it's empty\n";
                break;
            }
        }
    }
};

