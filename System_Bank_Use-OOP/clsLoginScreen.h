#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsUser.h"
#include "clsMainScreen.h"

class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		short NumberOfAttempts = 3;

		string Username, Password;
		do
		{

			cout << "Enter Username? : ";
			Username = clsInputValidate::ReadString();

			cout << "Enter Password? : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
			

			if (LoginFaild) {
				--NumberOfAttempts;
				cout << "\n\nInvalid UserName/Password\n";
				cout << "You Have " << NumberOfAttempts << " Trials to Login\n\n";
			}

			if (NumberOfAttempts == 0) {
				cout << "Your are Locked after 3 Faild Trails\n\n";
				return false;
			}
			
		} while (LoginFaild && NumberOfAttempts);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
		return true;
	}
public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}
};

