#pragma once
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include "clsString.h"

class clsUser : protected clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _Username;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;

	static clsUser _GetEmptyClientObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector <string> vUser;
		vUser = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4], vUser[5], stoi(vUser[6]));
	}

	static vector <clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUsers.push_back(User);
			}

			MyFile.close();

		}
		return vUsers;
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserRecord;
		UserRecord = User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.Username + Seperator;
		UserRecord += User.Password + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;
	}

	static void _SaveUsersDataToFile(vector <clsUser> vUsers)
	{
		fstream MyFill;
		MyFill.open("Users.txt", ios::out);//overwrite
		string Line = "";

		for (clsUser& U : vUsers)
		{
			if (U.MarkedForDelete() == false) {
				//we only write records that are not marked for delete.  
				Line = _ConvertUserObjectToLine(U);
				MyFill << Line << endl;
			}
		}
	}

	void _Update()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers )
		{
			if (U.Username == Username) {
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	void _AddNewUser()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

public:

	// constractor to dont create empty object
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permission)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_Username = Username;
		_Password = Password;
		_Permissions = Permission;
	}

	// property Get/Set for _Username
	void SetUsername(string Username) {
		_Username = Username;
	}
	string GetUsername() {
		return _Username;
	}
	__declspec(property(get = GetUsername, put = SetUsername)) string Username;

	// property Get/Set for _Password
	void SetPassword(string Password) {
		_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	// property Get/Set for _Permission
	void SetPermission(int Permissions) {
		_Permissions = Permissions;
	}
	int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) string Permissions;

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	static clsUser Find(string Username)
	{
		vector <clsUser> vClients;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);
				if (User.Username == Username)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	static clsUser Find(string Username, string Password)
	{
		vector <clsUser> vClients;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLineToUserObject(Line);
				if (Username == User.Username && Password == User.Password)
				{
					MyFile.close();
					return User;
				}
			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	static bool IsUserExist(string Username)
	{
		clsUser User = Find(Username);
		return (!User.IsEmpty());
	}

	enSaveResults Save() {
		switch (_Mode)
		{
		case clsUser::EmptyMode:
		{
			if (IsEmpty())
				return enSaveResults::svFaildEmptyObject;
		}
		case clsUser::UpdateMode:
		{
			_Update();
		    return enSaveResults::svSucceeded;
		}
		case clsUser::AddNewMode:
		{
			if (clsUser::IsUserExist(_Username))
			{
				return enSaveResults::svFaildUserExists;
			}
			else
			{
				_AddNewUser();
				//We need to set the mode to update after add new
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			};
		}
		}
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : vUsers)
		{
			if (U.Username == _Username)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
		*this = _GetEmptyClientObject();
		return true;
	}

	static clsUser GetAddNewClientObject(string Username)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", Username, "", 0);
	}

	static vector <clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}
};

