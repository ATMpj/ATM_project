#pragma once
#include<iostream> 
#include<string>
#include<fstream>
#include<sstream>
#include<ctime>
#include<vector>
#include<stdlib.h>
#include <conio.h>
#include "LinkedList.h"

using namespace std;

class Account
{
	string _strID;
	string _strPIN;
	string _strAccountName;
	long long _lSurplus;
	string _strTypeCurrency;
	bool _bStatus;

	string pathCardDefault = "ATM_data\\TheTu.txt";
	string pathIDDefault = "ATM_data\\ID\\";
	string pathHistoryDefault = "ATM_data\\LichSuGD\\LichSu";
public:
	void set_strID(string);
	void set_strPIN(string);
	void set_strAccountName(string);
	void set_lSurplus(long long);
	void set_strTypeCurrency(string);
	void set_bStatus(bool);

	string get_strID();
	string get_strPIN();
	string get_strAccountName();
	long long get_lSurplus();
	string get_strTypeCurrency();
	bool get_bStatus();

	Account();
	Account(const Account&);
	~Account();

	vector<string> _vctID;
	vector<string> _vctCard;
	vector<string> _vctHistory;


	void loginAccount();
	void loginWhenPINWrong();

	void readID();
	void writeID();
	void readCard();
	void writeCard();
	void readHistory();
	void writeHistory(long long);
	void transfers();

	bool isLogin();
	bool isBlock();
	void blockUser();

	void showInfomation();
	void updateMoney(long long);
	void historyDeal();
	void withDrawal();
	void changePIN();

	void run();
};

class Admin : public Account
{

public:
	void unBlockUser();
	void removeAccout();
};

class Login
{
	int _iChoose;
public:
	void setChoose();
	int getChoose();

	void optionChoose();
	void menuAdmin();
	void menuUser();

	void userLogin();
};