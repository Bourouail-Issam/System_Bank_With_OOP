#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsMainScreen.h"

class clsLoginScreen :protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFaild = false;
		string Username, Password;
		do
		{
			if (LoginFaild)
			{
				cout << "\nInvlaid Username/Password!\n\n";
			}

			cout << "Enter Username? : ";
			Username = clsInputValidate::ReadString();

			cout << "Enter Password? : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		clsMainScreen::ShowMainMenue();
	}
public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		_Login();
	}
};

