#include <iostream>
#include "Login.h"
#include <Windows.h>

using namespace std;

void runProgram();

int main()
{
	runProgram();
	system("pause");
	return 0;
}

void runProgram() {
	//SetConsoleOutputCP(65001); // cho phep co tieng viet
	while (true) {
		Login login;
		login.optionChoose();

		if (login.getChoose() == '1') {
			login.loginAdmin();
			break;
		}

		else if (login.getChoose() == '2') {
			login.userLogin();
			break;
		}
		else {
			system("cls");
			cout << endl << "\t\t\t\tNhap sai, Vui long nhap lai" << endl;
		}
	}
}