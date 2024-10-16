#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

		vector<string> vClientData;

		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	// constractor
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AcountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AcountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}

	//check mode is empty
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	// Read Only Propertie for _AccountNumber
	string GetAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = GetAccountNumber)) string AccountNumber;

	// Property Get/Set for _PinCode
	string GetPinCode() {
		return _PinCode;
	}
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	// Property Get/Set for _AccountBalance
	float GetAccountBalance() {
		return _AccountBalance;
	}
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\Client Card:";
		cout << "\n___________________\n";
		cout << "\nFirstName     : " << FirstName;
		cout << "\nLastName      : " << LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << Email;
		cout << "\nPhone         : " << Phone;
		cout << "\nAccountNumber : " << _AccountNumber;
		cout << "\nPinCode       : " << _PinCode;
		cout << "\nBalance       : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient clinet1 = clsBankClient::Find(AccountNumber);
		return (!clinet1.IsEmpty());
	}

};

 