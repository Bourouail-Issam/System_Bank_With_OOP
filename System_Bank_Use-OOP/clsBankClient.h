#pragma once
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

		vector<string> vClientData;

		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string Line;
		Line = Client.FirstName + Seperator;
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client.AccountNumber + Seperator;
		Line += Client.PinCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient client = _ConvertLineToClientObject(Line);
				vClients.push_back(client);
			}

			MyFile.close();

		}
		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

		fstream MyFill;
		MyFill.open("Clients.txt", ios::out); //OverWrite Mode

		if (MyFill.is_open())
		{
			string DataLine;
			for (clsBankClient& C : vClients)
			{
				if (C._MarkedForDelete == false )
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFill << DataLine << endl;
				}
			}

			MyFill.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFill;
		MyFill.open("Clients.txt", ios::out | ios::app);

		if (MyFill.is_open())
		{
			MyFill << stDataLine << endl;
			MyFill.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
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

	// Read Only Propertie Get for _AccountNumber
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

	// Read Only Propertie Get for _MarkedForDelete
	bool GetMarkedForDeleted()
	{
		return _MarkedForDelete;
	}
	__declspec(property(get = GetMarkedForDeleted)) bool MarkedForDelete;

	/*
	No UI Related code inside Object
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
	*/
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

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save() {

		switch (_Mode)
		{
		    case clsBankClient::EmptyMode:
		    {
				if (IsEmpty()) {
					return enSaveResults::svFaildEmptyObject;
				}
		    }
		    case clsBankClient::UpdateMode:
		    {
		    	_Update();
		    	return enSaveResults::svSucceeded;
		    }
			case clsBankClient::enMode::AddNewMode:
			{
				//This will add new record to file or database

				if (clsBankClient::IsClientExist(_AccountNumber)) {
					return enSaveResults::svFaildAccountNumberExists;
				}
				else 
				{
					_AddNew();
					//We need to set the mode to update after add new
					_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceeded;
				}
				break;
			}
		    
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients) 
		{
			if(C.AccountNumber == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
		*this = _GetEmptyClientObject(); 

		return true;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances() 
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();
		double TotalBalances = 0;

		for (clsBankClient C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	
	bool Withdraw(double Amount)
	{
		if (AccountBalance>= Amount)
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
		else
		{
			return false;
		}
	}
};

