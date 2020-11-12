
#include "Admin.h"

string Admin::getUser() {
	return _strUser;
}
string Admin::getPass() {
	return _strPass;
}

void Admin::setUser(string user) {
	_strUser = user;
}
void Admin::setPass(string pass) {
	_strPass = pass;
}
bool Admin::compare(vector<Admin> List) {
	for (int i = 0; i < List.size(); i++)
		if (List[i].getUser() == _strUser && List[i].getPass() == _strPass) return true;
	return false;
}


//Class ListAdmin
void ListAdmin::readFile() {
	Admin admin;
	bool isUser = true;
	ifstream  file;
	file.open("Admin.txt");
	while (!file.eof()) {
		string temp;
		if (isUser) {
			getline(file, temp);
			admin.setUser(temp);
		}
		else {
			getline(file, temp);
			admin.setPass(temp);
			_arrAdmin.push_back(admin);
		}
		isUser = !isUser;
	}
	file.close();
}
vector<Admin> ListAdmin::getListAdmin() {
	return _arrAdmin;
}


//Class FeatureAdmin
FeatureAdmin::FeatureAdmin() {
	system("cls");

	cout << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "*             DANG NHAP ADMIN               *" << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;

	_arrAdmin.readFile();
}

void FeatureAdmin::input() {
	cout << "	User: ";
	cin >> _strUser;
	_admin.setUser(_strUser);

	cout << "	PIN: ";
	cin >> _strPin;
	_admin.setPass(_strPin);
}
bool FeatureAdmin::checkLogin() {
	return _admin.compare(_arrAdmin.getListAdmin());
}

void FeatureAdmin::chooseOne() {
	cout << "	Danh Sach Tai Khoan" << endl;

	ListUser arrUser;
	arrUser.readFile();
	arrUser.viewListUser();
}
void FeatureAdmin::chooseTwo() {
	ListUser arrUSer;
	arrUSer.readFile();

	cout << "	Nhap ID Muon Them: ";

	string newID;
	cin >> newID;

	if (arrUSer.search(newID) == false) {

		User newUser;
		newUser.setID(newID);
		newUser.setPIN("123456");
		arrUSer.addUser(newUser);
		arrUSer.writeFile();
		cout << "	Them Tai Khoan Thanh Cong";
	}
	else cout << "	Tai Khoan Da Ton Tai";
}
void FeatureAdmin::chooseThree() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "	Nhap ID Muon Xoa: ";
	string ID;
	cin >> ID;

	if (arrUser.search(ID)) {
		arrUser.deleteUser(ID);
		arrUser.writeFile();
		cout << "	Xoa Tai Khoan Thanh Cong" << endl;
	}
	else cout << "	Tai Khoan Khong Ton Tai" << endl;
}
void FeatureAdmin::chooseFour() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "	Nhap ID Muon Mo Khoa:";
	string ID;
	cin >> ID;

	if (arrUser.search(ID))
	{
		cout << "	Mo Khoa Thanh Cong";
		arrUser.unlockUser(ID);
	}
	else cout << "	Tai Khoan Khong Ton Tai";
}
void FeatureAdmin::chooseFive() {
	cout << "	Thoat Thanh Cong";
	exit(0);
}
