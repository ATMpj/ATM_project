
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
	file.open("ATM_data\\Admin.txt");
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

	cout << "\n\n\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << "\t\t\t*             DANG NHAP ADMIN               *" << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << endl;

	_arrAdmin.readFile();
}

void FeatureAdmin::input() {
	cout << "\t\t\t\tUser: ";
	cin >> _strUser;
	_admin.setUser(_strUser);

	cout << "\t\t\t\tPIN: ";
	cin >> _strPin;
	_admin.setPass(_strPin);
}
bool FeatureAdmin::checkLogin() {
	return _admin.compare(_arrAdmin.getListAdmin());
}

void FeatureAdmin::chooseOne() {
	cout << "\t\t\t\t\tDanh Sach Tai Khoan\n\n\n" << endl;

	ListUser arrUser;
	arrUser.readFile();
	arrUser.viewListUser();
}
void FeatureAdmin::chooseTwo() {
	ListUser arrUSer;
	arrUSer.readFile();

	cout << "\t\t\t\tNhap ID Muon Them: ";

	string newID;
	cin >> newID;

	if (arrUSer.search(newID) == false) {

		User newUser;
		newUser.setID(newID);
		newUser.setPIN("1111");
		arrUSer.addUser(newUser);
		arrUSer.writeFile();
		cout << "\t\t\t\tThem Tai Khoan Thanh Cong";
	}
	else cout << "\t\t\t\tTai Khoan Da Ton Tai";
}
void FeatureAdmin::chooseThree() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "\t\t\t\tNhap ID Muon Xoa: ";
	string ID;
	cin >> ID;

	if (arrUser.search(ID)) {
		arrUser.deleteUser(ID);
		arrUser.writeFile();
		cout << "\t\t\t\tXoa Tai Khoan Thanh Cong" << endl;
	}
	else cout << "\t\t\t\tTai Khoan Khong Ton Tai" << endl;
}
void FeatureAdmin::chooseFour() {
	ListUser arrUser;
	arrUser.readFile();

	cout << "\t\t\t\tNhap ID Muon Mo Khoa:";
	string ID;
	cin >> ID;

	if (arrUser.search(ID))
	{
		cout << "\t\t\t\tMo Khoa Thanh Cong";
		arrUser.unlockUser(ID);
		arrUser.writeFile();
	}
	else cout << "\t\t\t\tTai Khoan Khong Ton Tai";
}
void FeatureAdmin::chooseFive() {
	cout << "\t\t\t\tThoat Thanh Cong";
	exit(0);
}
