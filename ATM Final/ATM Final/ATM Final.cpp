#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Login.h"

using namespace std;

void runProgram() {
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
			cout << endl << "Nhap sai, Vui long nhap lai" << endl; 
		}
	}
}

int main()
{
	runProgram();
	system("pause");
	return 0;
}