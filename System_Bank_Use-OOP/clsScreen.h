#pragma once
#include <iostream>
#include "clsUtil.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << clsUtil::Tabs(5) << "User : " << CurrentUser.UserName << endl;
        cout << clsUtil::Tabs(5) << clsDate::DateToString(clsDate());
        cout << "\n\n";
    }
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (CurrentUser.CheckAccessPermission(Permission))
        {
            return true;
        }
        else
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }

    }
};

