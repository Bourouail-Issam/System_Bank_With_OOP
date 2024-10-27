#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUsersScreen :protected clsScreen
{
private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "Do you want to give Full Aceess ? y/n : ";
		cin >> Answer;

		if ('y' == Answer || 'Y' == Answer)
		{
			return clsUser::enPermissions::eAll;
		}

		cout << "\nDo you want to give access to : \n";

		cout << "\nShow Client List? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}


		cout << "\nManage Users? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter LastName : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "Enter Permissions : ";
		User.Permissions = _ReadPermissionsToSet();
	}


public:

	static void ShowUpadteUsersScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "UserName is not found, Choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser UpdateUser = clsUser::Find(UserName);
		_PrintUser(UpdateUser);

		char Answer = 'n';
		cout << "\nAre you sure you want to Update this User n/y? : ";
		cin >> Answer;

		if ('y' == Answer || 'Y' == Answer)
		{
			cout << "\nUpDate User Info : ";
			cout << "\n--------------------\n";

			_ReadUserInfo(UpdateUser);
			clsUser::enSaveResults SaveResult;
			SaveResult = UpdateUser.Save();

			switch (SaveResult)
			{
			case clsUser::svFaildEmptyObject:
			{
				cout << "\nError User was not saved because it's empty\n";
				break;
			}
			case clsUser::svSucceeded:
			{
				cout << "\nUser Updated Successfuly :-)\n";
				_PrintUser(UpdateUser);
				break;
			}
			}
		}
	}
};

