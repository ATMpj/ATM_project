#include "Login.h"


void Login::input() {
	cin >> _cChoose;
}
char Login::getChoose() {
	return _cChoose;
}
void Login::optionChoose()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 12);
	cout << endl << endl;
	cout << "\tChon Loai Tai Khoan Dang Nhap:	" << endl;
	cout << "\t1.Dang Nhap Tai Khoan Admin" << endl;
	cout << "\t2.Dang Nhap Tai Khoan User" << endl << endl << endl;
	cout << "\tNhap Lua Chon Cua Ban: ";
	input();
}

void Login::MenuAdmin()
{
	cout << "* * * * * * * * * * MENU * * * * * * * * * *" << endl << endl;
	cout << "\t1. Xem danh sach tai khoan" << endl;
	cout << "\t2. Them tai khoan" << endl;
	cout << "\t3. Xoa tai khoan" << endl;
	cout << "\t4. Mo khoa tai khoan" << endl;
	cout << "\t5. Thoat" << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}
void Login::MenuUser()
{
	system("cls");
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << "	1. Xem thong tin tai khoan" << endl;
	cout << "	2. Rut tien" << endl;
	cout << "	3. Chuyen tien" << endl;
	cout << "	4. Xem noi dung giao dich" << endl;
	cout << "	5. Doi ma PIN" << endl;
	cout << "	6. Thoat" << endl << endl;
	cout << "* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

void Login::loginAdmin()
{
	FeatureAdmin feature;

	while (true) {

		feature.input();

		if (feature.checkLogin())
		{
			cout << "	Dang Nhap Thanh Cong" << endl << endl;
			system("cls");
			while (true) {
				MenuAdmin();
				cout << endl << "	Moi Ban Nhap Lua Chon: ";
				char choose;
				cin >> choose;

				switch (choose)
				{
				case '1':
					system("cls");
					feature.chooseOne();
					break;

				case '2':
					system("cls");
					feature.chooseTwo();
					break;

				case '3':
					system("cls");
					feature.chooseThree();
					break;

				case '4':
					system("cls");
					feature.chooseFour();
					break;

				case '5':
					system("cls");
					feature.chooseFive();
					break;

				default:
					system("cls");
					cout << endl << "Nhap sai vui long nhap lai" << endl;
					break;
				}
			}
		}
		else cout << "	Dang Nhap That Bai" << endl << endl;
	}
}
void Login::userLogin() {
	FeatureUser feature;

	while (true) {
		feature.input();
		if (feature.checkLogin()) {
			cout << "	Dang Nhap Thanh Cong" << endl << endl;
			MenuUser();

			while (true) {
				cout << "	Moi Ban Nhap Lua Chon: ";
				int choose;
				cin >> choose;

				switch (choose)
				{
				case 1:
					feature.chooseOne();
					break;

				case 2:
					feature.chooseTwo();
					break;

				case 3:
					feature.chooseThree();
					break;

				case 4:
					feature.chooseFour();
					break;

				case 5:
					feature.chooseFive();
					break;

				case 6:
					feature.chooseSix();
					break;

				default:
					break;
				}
			}
			break;
		}
		else cout << "	DANG NHAP THAT BAI" << endl << endl;
		feature.lockUser();
	}
}