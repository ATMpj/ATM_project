#pragma once
#include "User.h"
#include "Admin.h"

class Login
{
private:
	char _cChoose;
public:

	void input();
	char getChoose();
	void optionChoose();

	void menuAdmin();
	void menuUser();

	void loginAdmin();
	void userLogin();
};