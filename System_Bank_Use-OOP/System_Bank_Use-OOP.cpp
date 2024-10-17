// System_Bank_Use-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include <iostream>

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

int main()
{
	//clsPerson Person1("Issam", "Bourouail", "issam@gmail.com", "0625423126");
	//Person1.Print();

	////Test clsBankClient
 //   clsBankClient Client1 = clsBankClient::Find("A101");
 //   if (!Client1.IsEmpty())
 //      cout << "\nClient Found :-)\n";
 //   else
 //      cout << "\nClient Was not Found :-(\n";
 // 
 //   Client1.Print();

 //   clsBankClient Client2 = clsBankClient::Find("A101", "1234");
 //   if (!Client2.IsEmpty())
 //      cout << "\nClient Found :-)\n";
 //   else
 //      cout << "\nClient Was not Found :-(\n";
 //   
 //   Client2.Print();

 //   cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");

 //   UpDateClient();

    AddNewClient();
	return 0;

}

