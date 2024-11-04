#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include <string>
#include "clsString.h"

using namespace std;

class clsCurrency
{
private:
	enum enMode {enEmpty = 0, enUpdate=1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string CurrencyLine, string Seperator = "#//#")
	{
		vector <string> vCurrencyData = clsString::Split(CurrencyLine,Seperator);
		return clsCurrency(enMode::enUpdate, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}

	static vector <clsCurrency> _LoadCurrenciesDataFormFile()
	{
		vector <clsCurrency> vCurrencies;
		fstream MyFill;

		MyFill.open("Currencies.txt", ios::in);
		if (MyFill.is_open())
		{
			string Line;

			while (getline(MyFill, Line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			}
			MyFill.close();
		}
		return vCurrencies;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string DataCurrencie;

		DataCurrencie = Currency._Country + Seperator;
		DataCurrencie += Currency._CurrencyCode + Seperator;
		DataCurrencie += Currency._CurrencyName + Seperator;
		DataCurrencie += to_string(Currency.Rate()) + Seperator;

		return DataCurrencie;
	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies)
	{
		fstream MyFill;
		MyFill.open("Currencies.txt", ios::out);

		if (MyFill.is_open())
		{
			string DataLine;
			for(clsCurrency& C : vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFill << DataLine << endl;
			}
			MyFill.close();
		}
	}

	void _Update()
	{
		vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFormFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == _CurrencyCode)
			{
				C = *this; 
				break;
			}
		}
		_SaveCurrenciesDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::enEmpty, "", "", "", 0);
	}

	

public:

	// constractor for class clsCurrency
	clsCurrency(enMode Mode, string CountryName, string CodeCoin, string NameCoin, float Rate) 
	{
		_Mode = Mode;
		_Country = CountryName;
		_CurrencyCode = CodeCoin;
		_CurrencyName = NameCoin;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return(enMode::enEmpty == _Mode);
	}

	// Read Only For Property _CountryName
	string Country()
	{
		return _Country;
	}

	// Read Only For Property _CodeCoin
	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	// Read Only For Property _NameCoin
	string CurrencyName()
	{
		return _CurrencyName;
	}

	// Read Only For Property _Rate
	float Rate()
	{
		return _Rate;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFill;
		MyFill.open("Currencies.txt", ios::in);//read Mode
	
		if (MyFill.is_open())
		{
			string Line;
			while (getline(MyFill, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFill.close();
					return Currency;
				}
			}
			MyFill.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFill;
		MyFill.open("Currencies.txt", ios::in);//read Mode

		if (MyFill.is_open())
		{
			string Line;
			while (getline(MyFill, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFill.close();
					return Currency;
				}
			}
			MyFill.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C = FindByCode(CurrencyCode);
		return (!C.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFormFile();
	}

	double ConvertToUSD(double Amount)
	{
		return (Amount / Rate());
	}

	double ConvertToAnotherCurrency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (AmountInUSD * Currency2.Rate());
	
	}
};

