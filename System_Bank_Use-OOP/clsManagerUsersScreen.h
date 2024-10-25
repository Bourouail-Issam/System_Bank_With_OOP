#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include <iomanip>


class clsManageUsersScreen :protected clsScreen
{

private:

	static enum _enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4,
		eFindUser = 5, eMainMenue = 6
	};

	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manager Users menue...";
		system("pause>0");
		ShowManagerUsers();

	}

	static short _ReadManageUsersMenueOption()
	{
		cout  << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,6, "Enter Number between 1 to 6 : ");
		return Choice;
	}

    static void _ShowListUsersScreen()
    {
       // cout << "\nList Users Screen Will Be Here.\n";
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        // cout << "\nAdd New User Screen Will Be Here.\n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }

	static void _PerformManageUsersMenueOption(_enManageUsersMenueOptions UserManagerMenueOption)
    {
        switch (UserManagerMenueOption)
        {
            case _enManageUsersMenueOptions::eListUsers:
                {
                    system("cls");
                    _ShowListUsersScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }
            case _enManageUsersMenueOptions::eAddNewUser:
                {
                    system("cls");
                    _ShowAddNewUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }
            case _enManageUsersMenueOptions::eDeleteUser:
                {
                    system("cls");
                    _ShowDeleteUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }
            case _enManageUsersMenueOptions::eUpdateUser:
                {
                    system("cls");
                    _ShowUpdateUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }
            case _enManageUsersMenueOptions::eFindUser:
                {
                    system("cls");
                    _ShowFindUserScreen();
                    _GoBackToManageUsersMenue();
                    break;
                }
            case _enManageUsersMenueOptions::eMainMenue:
                {
                //do nothing here the main screen will handle it :-) ;
                }
            }
            
    }

public:
	static void ShowManagerUsers() 
	{
        system("cls");
		_DrawScreenHeader("\t Manager Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManager Users Memue Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUsersMenueOption((_enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}

};

