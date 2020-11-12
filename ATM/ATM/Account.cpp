#pragma warning(disable : 4996)
#include "Account.h"

using namespace std;

void Account::set_strID(string id)
{
	_strID = id;

}
void Account::set_strPIN(string pin)
{
	_strPIN = pin;
}
void Account::set_strAccountName(string accountname)
{
	_strAccountName = accountname;
}
void Account::set_lSurplus(long long surpuls)
{
	_lSurplus = surpuls;
}
void Account::set_strTypeCurrency(string type)
{
	_strTypeCurrency = type;
}
void Account::set_bStatus(bool status)
{
	_bStatus = status;
}

string Account::get_strID() { return _strID; }
string Account::get_strPIN() { return _strPIN; }
string Account::get_strAccountName() { return _strAccountName; }
long long Account::get_lSurplus() { return _lSurplus; }
string Account::get_strTypeCurrency() { return _strTypeCurrency; }
bool Account::get_bStatus() { return _bStatus; }

Account::Account()
{
	this->_strID = "";
	this->_strPIN = "";
	this->_strAccountName = "";
	this->_lSurplus = 0;
	this->_strTypeCurrency = "VND";
	this->_bStatus = true;
}
Account::Account(const Account& u)
{
	this->_strID = u._strID;
	this->_strPIN = u._strPIN;
	this->_strAccountName = u._strAccountName;
	this->_lSurplus = u._lSurplus;
	this->_strTypeCurrency = u._strTypeCurrency;
	this->_bStatus = u._bStatus;
}
Account::~Account() {}

void Account::loginAccount()
{
	char c;
	cout << "ID:";
	cin >> _strID;
	cout << "PIN:";
	c = _getch();
	while (c != 13)
	{
		_strPIN.push_back(c);
		cout << "*";
		c = _getch();
	}
}
void Account::loginWhenPINWrong() {
	_strPIN = "";
	cout << "ID: " << _strID << endl;
	cout << "PIN: ";
	char c = _getch();
	while (c != 13) {
		_strPIN.push_back(c);
		cout << "*"; //][; [] ]
			c = _getch();
	}
}

void Account::readID()
{
	string path = pathIDDefault + _strID + ".txt";
	fstream fileID(path);
	while (!fileID.eof()) {
		string tmp;
		getline(fileID, tmp);
		if (tmp != "") {
			_vctID.push_back(tmp);
		}

	}
	fileID.close();
}
void Account::writeID() {
	string path = pathIDDefault + _strID + ".txt";
	ofstream fileID(path, ofstream::trunc);
	for (int i = 0; i < _vctID.size(); i++) {
		fileID << _vctID[i];
		if (i < _vctID.size() - 1) fileID << endl;
	}
	fileID.close();
}
void Account::readCard() {
	fstream fileCard(pathCardDefault);

	while (!fileCard.eof()) {
		string tmp;
		fileCard >> tmp;
		if (tmp != "") {
			_vctCard.push_back(tmp);
		}

	}

	fileCard.close();
}
void Account::writeCard() {
	ofstream fileCard(pathCardDefault, ofstream::trunc);
	for (int i = 0; i < _vctCard.size(); i++) {
		fileCard << _vctCard[i];
		if (i < _vctCard.size() - 1) fileCard << endl;
	}
	fileCard.close();
}
void Account::readHistory() {
	string path = pathHistoryDefault + _strID + ".txt";
	ifstream fileHistory(path);

	while (!fileHistory.eof()) {
		string tmp;
		getline(fileHistory, tmp);
		if (tmp != "") {
			_vctHistory.push_back(tmp);
		}
	}

}
void Account::writeHistory(long long Money) {
	time_t t = time(0);
	tm* now = localtime(&t);
	fstream fileHistory;
	string path = pathHistoryDefault + _strID + ".txt";
	fileHistory.open(path, ios::app);

	//ghi vào file LichSu
	fileHistory << endl << _strID << endl << "Rut tien " << endl << Money << endl << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << " " << now->tm_mday << '/' << (now->tm_mon + 1) << '/' << (now->tm_year + 1900);
	fileHistory.close();
}

bool Account::isLogin() {
	readCard();

	for (int i = 0; i < _vctCard.size(); i += 2) {
		if (_strID == _vctCard[i] && _strPIN == _vctCard[i + 1]) {
			readID();

			//set dữ liệu từ file vào class
			_strAccountName = _vctID[1];
			_lSurplus = stoi(_vctID[2]);
			_strTypeCurrency = _vctID[3];

			//0 là block, 1 là không block
			if (_vctID[4] == "0") {
				_bStatus = true;
			}
			else {
				_bStatus = false;
			}

			return true;
		}
	}

	return false;
}
bool Account::isBlock() { return _bStatus; }
void Account::blockUser() {
	_vctID[4] = "0";
	writeID();
}
void Account::showInfomation() {
	cout << "\tID: " << _strID << endl;
	cout << "\tTen tai khoan: " << _strAccountName << endl;
	cout << "\tSo Du Tai Khoan: " << _lSurplus << endl;
	cout << "\tLoai Tien Te: " << _strTypeCurrency;
}
void Account::updateMoney(long long Money) {
	_lSurplus = Money;
}
void Account::historyDeal() {
	_vctHistory.clear();
	readHistory();

	for (int i = 0; i < _vctHistory.size(); i = i + 4) {
		cout << "ID giao dich: " << _vctHistory[i] << endl;
		cout << "Loai giao dich: " << _vctHistory[i + 1] << endl;
		cout << "So tien giao dich: " << _vctHistory[i + 2] << endl;
		cout << "Thoi gian giao dich: " << _vctHistory[i + 3] << endl;
		cout << endl;
	}
}
void Account::transfers() {
	string nguoiNhanID;
	cout << "Nhap ID nguoi nhan: " << endl;
	cin >> nguoiNhanID;

}
void Account::withDrawal() {
	long long  tienRut;
	long long tienConLai;

	cout << "Moi quy khach nhap so tien can rut: ";
	cin >> tienRut;

	while (_lSurplus - tienRut <= 50000 || tienRut % 50000 != 0) {
		cout << "So tien rut khong hop le" << endl;
		cout << "Moi quy khach nhap lai!" << endl;
		cout << "Moi quy khach nhap so tien can rut: ";
		cin >> tienRut;
	}

	tienConLai = _lSurplus - tienRut;
	cout << "So du con lai trong tai khoan la: ";
	cout << tienConLai << endl;

	_vctID.clear();
	readID();
	_vctID[2] = to_string(tienConLai); //gán lại số tiền trong file ID
	updateMoney(tienConLai);
	writeHistory(tienRut); //thêm lịch sử giao dịch vào file LichSu
	writeID(); // cập nhập lại số tiền trong file ID
}
void Account::changePIN() {
	int dem = 0;
	_vctCard.clear();
	readCard();
	cout << "Nhap ma PIN hien tai: " << endl;
	string currentPIN;
	cin >> currentPIN;


	for (int i = 0; i < _vctCard.size(); i += 2) {
		while (_strID == _vctCard[i] && currentPIN != _vctCard[i + 1]) {
			if (dem < 3) {
				cout << "Ban da nhap sai ma PIN " << endl;
				cout << "Nhap lai ma PIN hien tai: " << endl;
				cin >> currentPIN;
				dem++;
			}
			else {
				break;
				return;
			}
		}

		if (_strID == _vctCard[i] && currentPIN == _vctCard[i + 1]) {

			cout << "Nhap ma PIN moi: " << endl;
			string newPIN, newPIN2;
			cin >> newPIN;
			cout << "Nhap lai ma PIN moi : " << endl;
			cin >> newPIN2;

			while (newPIN != newPIN2) {
				cout << "Hai ma PIN khong khop" << endl;
				cout << "Nhap ma PIN moi: " << endl;
				cin >> newPIN;
				cout << "Nhap lai ma PIN moi : " << endl;
				cin >> newPIN2;
			}

			if (newPIN == newPIN2) {
				_vctCard[i + 1] = newPIN2; // gán mã PIN đọc được từ file TheTu thành mã PIN mới
				writeCard(); //ghi lại file TheTu
				cout << "Doi ma PIN thanh cong." << endl;
			}
		}

	}
}
/*void Account::run()
{
	int dem = 0;
	string choice = "";
	int num;
	cout << "********************" << endl;
	cout << "*  DANG NHAP USER  *" << endl;
	cout << "********************" << endl;
	loginAccount();
	while (!isLogin()) {
		if (dem < 2) {
			system("cls");
			cout << "********************" << endl;
			cout << "*  DANG NHAP USER  *" << endl;
			cout << "********************" << endl;
			cout << "Sai ma PIN vui long nhap lai: " << endl;
			dem++;
			loginWhenPINWrong();
		}
		else {
			blockUser();
			return;
		}
	}
	if (isLogin() && !isBlock()) {

		do {
			system("cls");
			cout << "*************MENU************" << endl;
			cout << "   1.Xem thong tin tai khoan " << endl;
			cout << "   2.Rut tien " << endl;
			cout << "   3.Chuyen tien " << endl;
			cout << "   4.Xem noi dung giao dich" << endl;
			cout << "   5.Doi ma pin" << endl;
			cout << "   6.Thoat" << endl;
			cout << "******************************" << endl;
			cout << "Vui long chon chuc nang: ";
			cin >> num;

			switch (num) {
			case 1:
				system("cls");
				showInfomation();
				break;

			case 2:
				system("cls");
				withDrawal();
				cout << "Rut tien thanh cong!!!\n";
				break;
			case 3:
				system("cls");

			case 4:
				system("cls");
				historyDeal();
				break;

			case 5:
				system("cls");
				changePIN();
				break;

			case 6:
				return;
				break;
			}
			if (num != 6) {
				cout << endl << "Thuc hien chuc nang khac vui long nhap T hoac t:" << endl;
				cin >> choice;
			}

		} while (choice.compare("t") == 0 || choice.compare("T") == 0);
	}
	else if (isBlock()) {
		system("cls");
		cout << "Tai khoan da bi khoa do dang nhap sai qua 3 lan";
	}
}*/

void Admin::unBlockUser() {
	_vctID[4] = "1";
	writeID();
}





void Login::setChoose() {
	cin >> _iChoose;
}
int Login::getChoose() {
	return _iChoose;
}
void Login::optionChoose(){
	cout << endl << endl;
		cout << "	Chon Loai Tai Khoan Dang Nhap:	" << endl;
		cout << "	1.Dang Nhap Tai Khoan Admin" << endl;
		cout << "	2.Dang Nhap Tai Khoan User" << endl << endl << endl;
		cout << "	Nhap Lua Chon Cua Ban: ";
		setChoose();
}
void Login::menuAdmin(){
	system("cls");
	cout << "* * * * * * * * * * MENU * * * * * * * * * *" << endl << endl;
	cout << "\t1. Xem danh sach tai khoan" << endl;
	cout << "\t2. Them tai khoan" << endl;
	cout << "\t3. Xoa tai khoan" << endl;
	cout << "\t4. Mo khoa tai khoan" << endl;
	cout << "\t5. Thoat" << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}
void Login::menuUser()
{
	system("cls");
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << "\t1. Xem thong tin tai khoan" << endl;
	cout << "\t2. Rut tien" << endl;
	cout << "\t3. Chuyen tien" << endl;
	cout << "\t4. Xem noi dung giao dich" << endl;
	cout << "\t5. Doi ma PIN" << endl;
	cout << "\t6. Thoat" << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}
void Login::userLogin() {
	Account user;
	int dem = 0;
	string choice = "";
	int num;
	cout << "********************" << endl;
	cout << "*  DANG NHAP USER  *" << endl;
	cout << "********************" << endl;
	user.loginAccount();
	while (!user.isLogin()) {
		if (dem < 2) {
			system("cls");
			cout << "********************" << endl;
			cout << "*  DANG NHAP USER  *" << endl;
			cout << "********************" << endl;
			cout << "Sai ma PIN vui long nhap lai: " << endl;
			dem++;
			user.loginWhenPINWrong();
		}
		else {
			user.blockUser();
			return;
		}
	}
	if (user.isLogin() && !user.isBlock()) {

		do {
			system("cls");
			cout << "*************MENU************" << endl;
			cout << "   1.Xem thong tin tai khoan " << endl;
			cout << "   2.Rut tien " << endl;
			cout << "   3.Chuyen tien " << endl;
			cout << "   4.Xem noi dung giao dich" << endl;
			cout << "   5.Doi ma pin" << endl;
			cout << "   6.Thoat" << endl;
			cout << "******************************" << endl;
			cout << "Vui long chon chuc nang: ";
			cin >> num;

			switch (num) {
			case 1:
				system("cls");
				user.showInfomation();
				break;

			case 2:
				system("cls");
				user.withDrawal();
				cout << "Rut tien thanh cong!!!\n";
				break;
			case 3:
				system("cls");

			case 4:
				system("cls");
				user.historyDeal();
				break;

			case 5:
				system("cls");
				user.changePIN();
				break;

			case 6:
				return;
				break;
			}
			if (num != 6) {
				cout << endl << "Thuc hien chuc nang khac vui long nhap T hoac t:" << endl;
				cin >> choice;
			}

		} while (choice.compare("t") == 0 || choice.compare("T") == 0);
	}
	else if (user.isBlock()) {
		system("cls");
		cout << "Tai khoan da bi khoa do dang nhap sai qua 3 lan";
	}
}