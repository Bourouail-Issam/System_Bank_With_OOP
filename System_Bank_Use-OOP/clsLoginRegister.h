#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsLoginRegister
{
private:

	string _Date;
	string _CurrentUserName;
	string _Password;
	short  _Permission;

	static string _ConvertLoginRegisterObjectToLine(clsLoginRegister UserRegister, string Seperator = "#//#")
	{
		string UserRecord;
		UserRecord += UserRegister._Date + Seperator;
		UserRecord += UserRegister._CurrentUserName + Seperator;
		UserRecord += UserRegister._Password + Seperator;
		UserRecord += to_string(UserRegister._Permission);

		return UserRecord;
	}
	static void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

public:


	clsLoginRegister()
	{
		_Date = clsDate::DateToString(clsDate()) + "  -  " + clsDate::GetSystemTime();
		_Password = CurrentUser.Password;
		_CurrentUserName  = CurrentUser.UserName;
		_Permission = CurrentUser.Permissions;
	}

	//// Property Get/Set For _Date
	//string GetDate()
	//{
	//	return _Date;
	//}
	//void SetDate(string Date)
	//{
	//	_Date = Date;
	//}
	//__declspec(property(get = GetDate, put = SetDate)) string Date;

	//// Property Get/Set For _Time
	//string GetTime()
	//{
	//	return _Time;
	//}
	//void SetTime(string Time)
	//{
	//	_Time = Time;
	//}
	//__declspec(property(get = GetTime, put = SetTime)) string Time;

	//// Property Get/Set For _CurrentUser
	//string GetCurrentUserName()
	//{
	//	return _CurrentUserName;
	//}
	//void SetCurrentUserName(string CurrentUserName)
	//{
	//	_CurrentUserName = CurrentUserName;
	//}
	//__declspec(property(get = GetCurrentUserName, put = SetCurrentUserName)) string CurrentUserName;

	// Property Get/Set For _Permission
	//short GetPermission()
	//{
	//	return _Permission;
	//}
	//void SetDate(string Permission)
	//{
	//	_Date = Date;
	//}
	//__declspec(property(get = GetPermission, put = SetPermission)) short Permission;

	void SaveLoginUserInfo()
	{
		_AddDataLineToFile(_ConvertLoginRegisterObjectToLine(*this));
	}
};

