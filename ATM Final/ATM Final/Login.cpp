#include "Login.h"


void Login::inputMyChoose() {
	cin >> _cChoose;
}
char Login::getChoose() {
	return _cChoose;
}
void Login::optionChoose()
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, 14);
	cout << endl << endl;
	cout << "\n\n\t\t\t\tChon Loai Tai Khoan Dang Nhap:	\n\n" << endl;
	cout << "\t\t\t\t1.Dang Nhap Tai Khoan Admin" << endl;
	cout << "\t\t\t\t2.Dang Nhap Tai Khoan User\n\n\n\n";
	cout << "\t\t\t\tNhap Lua Chon Cua Ban: ";
	inputMyChoose();
}

void Login::menuAdmin()
{
	cout << "\n\n\n\n\t\t\t* * * * * * * * * * MENU * * * * * * * * * *" << endl << endl;
	cout << "\t\t\t\t1. Xem danh sach tai khoan" << endl;
	cout << "\t\t\t\t2. Them tai khoan" << endl;
	cout << "\t\t\t\t3. Xoa tai khoan" << endl;
	cout << "\t\t\t\t4. Mo khoa tai khoan" << endl;
	cout << "\t\t\t\t5. Thoat" << endl << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}
void Login::menuUser()
{
	system("cls");
	cout << "\n\n\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << "\t\t\t\t1. Xem thong tin tai khoan" << endl;
	cout << "\t\t\t\t2. Rut tien" << endl;
	cout << "\t\t\t\t3. Chuyen tien" << endl;
	cout << "\t\t\t\t4. Xem noi dung giao dich" << endl;
	cout << "\t\t\t\t5. Doi ma PIN" << endl;
	cout << "\t\t\t\t6. Thoat" << endl << endl;
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
}

void Login::loginAdmin()
{
	FeatureAdmin feature;

	while (true) {

		feature.input();

		if (feature.checkLogin())
		{
			cout << "\t\t\t\tDang Nhap Thanh Cong" << endl << endl;
			system("cls");
			while (true) {
				menuAdmin();
				cout << endl << "\t\t\t\tMoi Ban Nhap Lua Chon: ";
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
					//system("cls");
					feature.chooseThree();
					break;

				case '4':
					//system("cls");
					feature.chooseFour();
					break;

				case '5':
					system("cls");
					feature.chooseFive();
					break;

				default:
					system("cls");
					cout << endl << "\n\t\t\t\tNhap sai vui long nhap lai" << endl;
					break;
				}
			}
		}
		else cout << "\n\n\t\t\t\tDang Nhap That Bai" << endl << endl;
	}
}
void Login::userLogin() {
	FeatureUser feature;

	while (true) {
		feature.input();
		if (feature.checkLogin()) {
			cout << "\t\t\t\tDang Nhap Thanh Cong" << endl << endl;
			menuUser();

			while (true) {
				cout << "\t\t\t\tMoi Ban Nhap Lua Chon: ";
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
		else cout << "\t\t\t\tDANG NHAP THAT BAI" << endl << endl;
		feature.lockUser();
	}
}