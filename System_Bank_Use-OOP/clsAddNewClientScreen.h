#pragma once
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

class clsAddNewClientScreen :protected clsScreen
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

	static void ShowAddNewClientScreen()
	{
        _DrawScreenHeader("\t Add New Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::svFaildEmptyObject:
        {
            cout << "\nError accout was not saved because it's empty";
            break;
        }
        case clsBankClient::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::svFaildAccountNumberExists:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }

	}
};

