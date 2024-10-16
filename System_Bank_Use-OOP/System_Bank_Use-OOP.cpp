// System_Bank_Use-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include <iostream>
#include <iomanip>

void ReadClientInfo(clsBankClient& Client)
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

void UpDateClient()
{
    string AccoutNumber;
    cout << "Please Enter Client Accout Number : ";
    AccoutNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccoutNumber))
    {
        cout << "Accout Number is not found, Choose another one : ";
        AccoutNumber = clsInputValidate::ReadString();
    }

    clsBankClient client = clsBankClient::Find(AccoutNumber);
    client.Print();

    cout << "\nUpDate Client Info : ";
    cout << "\n--------------------\n";
    ReadClientInfo(client);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = client.Save();

    switch (SaveResult)
    {
    case clsBankClient::svSucceeded:
        cout << "\nAccount Updated Successfuly :-)\n";
        client.Print();
        break;

    case clsBankClient::svFaildEmptyObject:
        cout << "\nError account was not saved because it's empty\n";
        break;
    }
}

void AddNewClient()
{
    string AccountNumber;
    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

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
        NewClient.Print();
        break;
    }
    case clsBankClient::svFaildAccountNumberExists:
        cout << "\nError account was not saved because account number is used!\n";
        break;
    }

}

void DeleteClient()
{
    string AccoutNumber;
    cout << "Please Enter Client Accout Number : ";
    AccoutNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccoutNumber))
    {
        cout << "Accout Number is not found, Choose another one : ";
        AccoutNumber = clsInputValidate::ReadString();
    }

    clsBankClient client = clsBankClient::Find(AccoutNumber);
    client.Print();

    char Answer = 'n';
    cout << "\nAre you sure you want to delete this client n/y? : ";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        if (client.Delete()) 
        {
            cout << "\nClient Deleted Successfully :)\n";
            client.Print();
        }
        else
        {
            cout << "\nError Client was not Deleted\n";
        }
    }
}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(20) << Client.FullName();
    cout << "| " << left << setw(18) << Client.Phone;
    cout << "| " << left << setw(20) << Client.Email;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowClientsList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    
    cout << clsUtil::Tabs(5) <<"Client List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(18) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;

    if(vClients.size() == 0)
    {
        cout << clsUtil::Tabs(4) << "No Clients Available In The System!";
    }
    else
    {
        for(clsBankClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;
}


void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(40) << Client.FullName();
    cout << "| " << left << setw(12) << Client.AccountBalance;
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << clsUtil::Tabs(5) << "Client List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();


    if (vClients.size() == 0)
    {
        cout << clsUtil::Tabs(4) << "No Clients Available In The System!";
    }
    else
    {
        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }
    }
    cout << "\n_______________________________________________________";
    cout << "________________________________________________\n" << endl;
    cout << clsUtil::Tabs(6) << "    Total Balances = " << TotalBalances << endl;
    cout << clsUtil::Tabs(6) << "    (" << clsUtil::NumberToText(TotalBalances) << ")" << endl;
}

int main()
{
//  clsPerson Person1("Issam", "Bourouail", "issam@gmail.com", "0625423126");
//  Person1.Print();

 // Test clsBankClient
 // clsBankClient Client1 = clsBankClient::Find("A101");
 // if (!Client1.IsEmpty())
 //    cout << "\nClient Found :-)\n";
 // else
 //    cout << "\nClient Was not Found :-(\n";
 //
 // Client1.Print();

 // clsBankClient Client2 = clsBankClient::Find("A101", "1234");
 // if (!Client2.IsEmpty())
 //    cout << "\nClient Found :-)\n";
 // else
 //    cout << "\nClient Was not Found :-(\n";
 // 
 // Client2.Print();

 // cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");

 // UpDateClient();

 // AddNewClient();

 // DeleteClient();

 // ShowClientsList();

    ShowTotalBalances();


    return 0;
}

