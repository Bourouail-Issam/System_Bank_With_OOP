#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include <vector>

class clsTransferLogScreen : protected clsScreen
{
private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogLine)
	{
		cout << setw(8) << "| " << setw(30) << left << TransferLogLine.DateTime
			<< "| " << setw(10) << left << TransferLogLine.SourceAccountNumber
			<< "| " << setw(10) << left << TransferLogLine.DestinationAccountNumber
			<< "| " << setw(10) << left << TransferLogLine.Amount
			<< "| " << setw(12) << left << TransferLogLine.srcBalanceAfter
			<< "| " << setw(12) << left << TransferLogLine.destBalanceAfter
			<< "| " << setw(10) << left << TransferLogLine.UserName;
	}
public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogList = clsBankClient::GetTransfersLogList();

		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t   (" + to_string(vTransferLogList.size()) + ") Record(s).";

		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;

		cout << setw(8) << "| " << setw(30) << left << "Date/Time"
			<< "| " << setw(10) << left << "s.Acct"
			<< "| " << setw(10) << left << "d.Acct"
			<< "| " << setw(10) << left << "Amount"
			<< "| " << setw(12) << left << "s.Balance"
			<< "| " << setw(12) << left << "d.Balance"
			<< "| " << setw(10) << left << "User";

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;

		if(vTransferLogList.size()==0)
			cout << "\t\t\t\tNo Transfers Available In the System!";
		else
		{
			for (clsBankClient::stTransferLogRecord& Record : vTransferLogList)
			{
				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}

		}

		cout << setw(8) << left << ""
			<< "\n\t_______________________________________________________";
		cout << "________________________________________________\n" << endl;
	}

};

