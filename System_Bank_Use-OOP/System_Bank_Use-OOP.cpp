// System_Bank_Use-OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsCurrency.h"

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
   return 0;
}

