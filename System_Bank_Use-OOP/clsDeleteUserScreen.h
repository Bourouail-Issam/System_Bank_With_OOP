#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


class clsDeleteUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________\n";
        cout << "\nFirstName     : " << User.FirstName;
        cout << "\nLastName      : " << User.LastName;
        cout << "\nFull Name     : " << User.FullName();
        cout << "\nEmail         : " << User.Email;
        cout << "\nPhone         : " << User.Phone;
        cout << "\nUser Name     : " << User.UserName;
        cout << "\nPassword      : " << User.Password;
        cout << "\nPermissions   : " << User.Permissions;
        cout << "\n___________________\n";
    }
public:

	static void ShowDeleteUserScreen()
	{
        _DrawScreenHeader("/t  Delete User Screen");

        string UserName = "";
        cout << "Please Enter UserName : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "Accout Number is not found, Choose another one : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser DeleteUser = clsUser::Find(UserName);
        _PrintUser(DeleteUser);

        char Answer = 'n';
        cout << "\nAre you sure you want to delete this User n/y? : ";
        cin >> Answer;

        if ('y' == Answer || 'Y' == Answer)
        {
            if (DeleteUser.Delete())
            {
                cout << "\nClient Deleted Successfully :)\n";
                _PrintUser(DeleteUser);
            }
            else
            {
                cout << "\nError Client was not Deleted\n";
            }

        }
	}
};

