// System_Bank_Use-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"clsPerson.h"
#include"clsBankClient.h"
#include <iostream>

int main()
{
	clsPerson Person1("Issam", "Bourouail", "issam@gmail.com", "0625423126");
	Person1.Print();

	//Test clsBankClient
    clsBankClient Client1 = clsBankClient::Find("A101");
    if (!Client1.IsEmpty())
       cout << "\nClient Found :-)\n";
    else
       cout << "\nClient Was not Found :-(\n";
  
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A101", "1234");
    if (!Client2.IsEmpty())
       cout << "\nClient Found :-)\n";
    else
       cout << "\nClient Was not Found :-(\n";
    
    Client2.Print();


    cout << "\nIs Client Exist? " << clsBankClient::IsClientExist("A101");
	return 0;

}

