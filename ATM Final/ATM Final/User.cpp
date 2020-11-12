#include "User.h"

//Class User
string User::getID() {
	return _strID;
}
string User::getPIN() {
	return _strPIN;
}
void User::setID(string ID) {
	this->_strID = ID;
}
void User::setPIN(string PIN) {
	this->_strPIN = PIN;
}

void User::lock() {
	_bStatus = true;
}
void User::unlock() {
	_bStatus = 0;
}

bool User::compare(vector<User>arrUser) {
	for (int i = 0; i < arrUser.size(); i++)
		if (arrUser[i].getID() == _strID && arrUser[i].getPIN() == _strPIN && _bStatus == false) return true;
	return false;
}


//Class ListUser
void ListUser::readFile() {
	User user;
	bool isID = true;
	ifstream  file;
	file.open("TheTu.txt");
	while (!file.eof()) {
		string temp;
		if (isID) {
			getline(file, temp);
			user.setID(temp);
		}
		else {
			getline(file, temp);
			user.setPIN(temp);
			_arrUser.push_back(user);
		}
		isID = !isID;
	}
	file.close();
}
void ListUser::writeFile() {
	ofstream file;
	file.open("TheTu.txt");
	for (int i = 0; i < _arrUser.size(); i++) {
		file << _arrUser[i].getID() << endl << _arrUser[i].getPIN();
		if (i < _arrUser.size() - 1) file << endl;
	}
	file.close();
}

void ListUser::lockUser(string ID) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) _arrUser[i].lock();
	}
}
void ListUser::unlockUser(string ID) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) _arrUser[i].unlock();
	}
}
void ListUser::deleteUser(string ID) {
	int count;
	for (int i = 0; i < _arrUser.size(); i++)
		if (ID == _arrUser[i].getID()) count = i;
	_arrUser.erase(_arrUser.begin() + count);
}
void ListUser::addUser(User user) {
	_arrUser.push_back(user);
}

bool ListUser::search(string ID) {
	for (int i = 0; i < _arrUser.size(); i++)
		if (_arrUser[i].getID() == ID) return true;
	return false;
}
void ListUser::changePIN(string ID, string PIN) {
	for (int i = 0; i < _arrUser.size(); i++) {
		if (_arrUser[i].getID() == ID) _arrUser[i].setPIN(PIN);
	}
}
bool ListUser::checkPIN(string ID, string PIN) {
	for (int i = 0; i < _arrUser.size(); i++)
		if (_arrUser[i].getID() == ID && _arrUser[i].getPIN() == PIN) return true;
	return false;
}

void ListUser::viewListUser() {
	for (int i = 0; i < _arrUser.size(); i++) {
		cout << "	ID: " << _arrUser[i].getID() << endl;
		cout << "	PIN: " << _arrUser[i].getPIN() << endl;
	}
}
vector<User> ListUser::getListUser() {
	return _arrUser;
}


//Class InfoUser
void InfoUser::setID(string ID) {
	_strID = ID;
}
void InfoUser::setName(string name) {
	_strName = name;
}
void InfoUser::setTypeCurrency(string typeCurrency) {
	_strTypeCurrency = typeCurrency;
}
void InfoUser::setSurplus(string surplus) {
	_strSurplus = surplus;
}

string InfoUser::getID() {
	return _strID;
}
string InfoUser::getName() {
	return _strName;
}
string InfoUser::getSurplus() {
	return _strSurplus;
}
string InfoUser::getTypeCurrency() {
	return _strTypeCurrency;
}


//Class ListInfoUser
void ListInfoUser::readFile(ListUser arrUser) {
	for (int i = 0; i < arrUser.getListUser().size(); i++) {
		InfoUser infoUser;
		int count = 1;
		string temp, path;
		path = (arrUser.getListUser())[i].getID() + ".txt";
		ifstream  file;
		file.open(path);

		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				infoUser.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				infoUser.setName(temp);
			}

			if (count == 3) {
				getline(file, temp);
				infoUser.setSurplus(temp);
			}

			if (count == 4) {
				getline(file, temp);
				infoUser.setTypeCurrency(temp);
				_arrInfoUser.push_back(infoUser);
				count = 0;
			}
			count++;
		}
		file.close();

	}
}
void ListInfoUser::wrtieFile() {
	ofstream file;
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		file.open(_arrInfoUser[i].getID() + ".txt");
		file << _arrInfoUser[i].getID() << endl << _arrInfoUser[i].getName() << endl << _arrInfoUser[i].getSurplus() << endl << _arrInfoUser[i].getTypeCurrency();
		if (i < _arrInfoUser.size() - 1) file << endl;
	}
	file.close();
}
void ListInfoUser::wrtieFile2(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (ID == _arrInfoUser[i].getID()) {
			ofstream file;
			file.open(ID + ".txt");
			file << _arrInfoUser[i].getID() << endl << _arrInfoUser[i].getName() << endl << _arrInfoUser[i].getSurplus() << endl << _arrInfoUser[i].getTypeCurrency();
			if (i < _arrInfoUser.size() - 1) file << endl;
			file.close();
			break;
		}
	}
}

void ListInfoUser::takeMoney(string ID, string& s) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			while (true) {
				cout << "	Moi Ban Nhap So Tien Can Rut: ";
				cin >> s;
				if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) {
					cout << "	Rut Tien Thanh Cong" << endl << endl;
					_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) - stoi(s)));
					break;
				}
				else cout << "	Rut Tien That Bai" << endl;
			}
		}
	}
}
void ListInfoUser::transferMoney(string ID, string s, string ID2) {
	int t = 0;
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) {
				_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) - stoi(s)));
			}
			else t = 1;
		}
	}
	if (t == 0) {
		for (int i = 0; i < _arrInfoUser.size(); i++) {
			if (_arrInfoUser[i].getID() == ID2) {
				_arrInfoUser[i].setSurplus(to_string(stoi(_arrInfoUser[i].getSurplus()) + stoi(s)));
			}
		}
	}
}
bool ListInfoUser::checkMoney(string ID, string s) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) {
			if (stoi(_arrInfoUser[i].getSurplus()) - stoi(s) >= stoi(s) && stoi(_arrInfoUser[i].getSurplus()) >= 50000) return true;
		}
	}
	return false;
}
void ListInfoUser::viewInfoUser(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (ID == _arrInfoUser[i].getID()) {
			cout << "	Id: " << _arrInfoUser[i].getID() << endl;
			cout << "	Ten Tai Khoan: " << _arrInfoUser[i].getName() << endl;
			cout << "	So Du: " << _arrInfoUser[i].getSurplus() << endl;
			cout << "	Loai Tien Te: " << _arrInfoUser[i].getTypeCurrency() << endl << endl << endl;
			break;
		}
	}
}
bool ListInfoUser::check(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++)
		if (_arrInfoUser[i].getID() == ID) return true;
	return false;
}

InfoUser ListInfoUser::getInfoUser(string ID) {
	for (int i = 0; i < _arrInfoUser.size(); i++) {
		if (_arrInfoUser[i].getID() == ID) return _arrInfoUser[i];
	}
}


//Class History
string History::getID() {
	return _strID;
}
string History::getTime() {
	return _strTime;
}
string History::getTypeTransfer() {
	return  _strTypeTransfer;
}
string History::getMoneyTransfer() {
	return _strMoneyTransfer;
}

void History::setID(string ID) {
	_strID = ID;
}
void History::setTypeTransfer(string typeTransfer) {
	_strTypeTransfer = typeTransfer;
}
void History::setMoneyTransfer(string moneyTransfer) {
	_strMoneyTransfer = moneyTransfer;
}
void History::setTime(string time) {
	_strTime = time;
}

void History::viewHistory() {
	cout << "	ID: " << _strID << endl;
	cout << "	Loai Giao Dich: " << _strTypeTransfer << endl;
	cout << "	So Tien Giao Dich: " << _strMoneyTransfer << endl;
	cout << "	Thoi Gian: " << time << endl << endl;
}


//Class ListHistory
void ListHistory::readFile(ListUser arrUser) {
	for (int i = 0; i < arrUser.getListUser().size(); i++) {
		History history;
		int count = 1;
		string temp, path;
		path = "LichSu" + (arrUser.getListUser())[i].getID() + ".txt";
		ifstream  file;
		file.open(path);
		while (!file.eof()) {
			if (count == 1) {
				getline(file, temp);
				history.setID(temp);
			}

			if (count == 2) {
				getline(file, temp);
				history.setTypeTransfer(temp);
			}
			if (count == 3) {
				getline(file, temp);
				history.setMoneyTransfer(temp);
			}
			if (count == 4) {
				getline(file, temp);
				history.setTime(temp);
				_arrHistory.push_back(history);
				count = 0;
			}
			count++;
		}
		file.close();
	}
}
void ListHistory::writeFile(string ID) {
	string path = "LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == ID) {
			file << _arrHistory[i].getID() << endl << _arrHistory[i].getTypeTransfer() << endl << _arrHistory[i].getMoneyTransfer() << endl << _arrHistory[i].getTime();
			if (i < _arrHistory.size() - 1) file << endl;
		}
	}
	file.close();
}
void ListHistory::writeFile2(string ID, string h) {
	string path = "LichSu" + ID + ".txt";
	ofstream file;
	file.open(path);
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == h || _arrHistory[i].getID() == ID) {
			file << _arrHistory[i].getID() << endl << _arrHistory[i].getTypeTransfer() << endl << _arrHistory[i].getMoneyTransfer() << endl << _arrHistory[i].getTime();
			if (i < _arrHistory.size() - 1) file << endl;

		}
	}
	file.close();
}

void ListHistory::add(History history) {
	_arrHistory.push_back(history);
}
void ListHistory::showHistory(string ID) {
	for (int i = 0; i < _arrHistory.size(); i++) {
		if (_arrHistory[i].getID() == ID) _arrHistory[i].viewHistory();
	}
}


//Class FeatureUser
FeatureUser::FeatureUser() {
	system("cls");
	cout << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*             DANG NHAP USER                *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;
	_arrUser.readFile();
}

void FeatureUser::input() {
	char c;
	cout << "	ID: ";
	cin >> _strID;
	_user.setID(_strID);
	cout << "	PIN: ";
	/*c = _getch();
	while (c != 13)
	{
		_strPIN.push_back(c);
		cout << "*";
		c = _getch();
	}*/
	_user.setPIN(_strPIN);
}
bool FeatureUser::checkLogin() {

	return _user.compare(_arrUser.getListUser());
}
void FeatureUser::lockUser() {
	if (_strIDTemp == _strID) _iDem++;
	if (_iDem == 3) {
		if (_arrUser.search(_strID)) {
			cout << "	Tai Khoan Cua Ban Da Bi Khoa Do Nhap Sai Qua So Lan !!!";
			_arrUser.lockUser(_strID);
			exit(0);
		}
		else _iDem = 1;
	}
	_strIDTemp = _strID;
}

void FeatureUser::chooseOne() {
	cout << endl << "	Thong Tin Tai Khoan: " << endl;
	ListInfoUser arrInfoUser;
	arrInfoUser.readFile(_arrUser);
	arrInfoUser.viewInfoUser(_strID);
}
void FeatureUser::chooseTwo() {
	string h;
	time_t now = time(0);
	char* ch = ctime(&now);
	h = ch;

	string s;
	ListHistory _arrHistory;
	ListInfoUser arrInfoUser;

	_arrHistory.readFile(_arrUser);
	arrInfoUser.readFile(_arrUser);
	InfoUser a = arrInfoUser.getInfoUser(_strID);

	History history;
	history.setID(a.getID());
	history.setTime(h);
	history.setTypeTransfer("Rut Tien");
	arrInfoUser.takeMoney(_strID, s);
	history.setMoneyTransfer(s);

	_arrHistory.add(history);
	_arrHistory.writeFile(_strID);
	arrInfoUser.wrtieFile2(_strID);
}
void FeatureUser::chooseThree() {
	while (true) {
		cout << "	Nhap ID Tai Khoan Can Chuyen: ";
		string IDNeedTransfer;
		cin >> IDNeedTransfer;
		ListInfoUser arrInfoUser;
		arrInfoUser.readFile(_arrUser);
		if (arrInfoUser.check(IDNeedTransfer))
		{
			cout << "	Nhap So Tien Can Chuyen: ";
			string money;
			cin >> money;

			if (arrInfoUser.checkMoney(_strID, money) && IDNeedTransfer != _strID) {
				arrInfoUser.transferMoney(_strID, money, IDNeedTransfer);
				arrInfoUser.wrtieFile2(_strID);
				arrInfoUser.wrtieFile2(IDNeedTransfer);

				string timeTransfer;
				History history;
				ListHistory _arrHistory;
				time_t now = time(0);
				char* ch = ctime(&now);
				timeTransfer = ch;

				_arrHistory.readFile(_arrUser);
				history.setTime(timeTransfer);
				history.setID(_strID);
				history.setTypeTransfer("Da chuyen tien cho: " + arrInfoUser.getInfoUser(IDNeedTransfer).getName() + " voi ID chuyen den la: " + IDNeedTransfer);
				history.setMoneyTransfer(money);
				_arrHistory.add(history);
				_arrHistory.writeFile2(_strID, IDNeedTransfer);
				cout << "	Chuyen Tien Thanh Cong!!!" << endl;
				break;
			}
			else cout << "	So tien chuyen khong phu hop, Vui long nhap lai " << endl;

		}
	}
}
void FeatureUser::chooseFour() {
	ListHistory _arrHistory;
	_arrHistory.readFile(_arrUser);
	_arrHistory.showHistory(_strID);
}
void FeatureUser::chooseFive() {
	ListUser _arrUser;
	_arrUser.readFile();
	cout << "	Doi Ma Pin: " << endl << endl;
	while (true) {
		cout << "	Nhap Ma PIN Hien Tai: ";
		string currentPIN;
		cin >> currentPIN;
		if (_arrUser.checkPIN(_strID, currentPIN)) {
			while (true) {
				string newPIN, newPIN2;
				cout << "	Nhap Ma PIN Moi: ";
				cin >> newPIN;
				cout << "	Xac Nhan Ma PIN Moi: ";
				cin >> newPIN2;
				if (newPIN == newPIN2)
				{
					_arrUser.changePIN(_strID, newPIN);
					_arrUser.writeFile();
					cout << "	Doi Ma Pin Thanh Cong" << endl;
					break;
				}
				else
					cout << "	Xac Nhan Lai Ma Pin Chua Dung" << endl;
			}
			break;
		}
		else cout << "	Ma PIN Hien Tai Khong Dung" << endl;

	}
}
void FeatureUser::chooseSix() {
	cout << "	Thoat Thanh Cong";
	exit(0);
}