#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsUtil.h"

class clsListUsersScreen : protected clsScreen
{
	
private:

	static void _PrintUserRecorde(clsUser User)
	{
		cout << setw(8) << left << "" 
			 << "| " << left << setw(12) << User.UserName;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}
public:
	static void ShowUsersList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();
		string Title = "\t Manager Users Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Users(s).";

		_DrawScreenHeader(Title,SubTitle);
		cout << setw(8) << left << "" 
			 << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" 
			 << "| " << left << setw(12) << "UserName";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << clsUtil::Tabs(5) << "No Users Available In the System!";
		}
		else
		{
			for (clsUser & U : vUsers) {
				_PrintUserRecorde(U);
				cout << endl;
			}
		}

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;
	}
};

