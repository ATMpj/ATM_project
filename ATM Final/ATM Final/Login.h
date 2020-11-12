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

	void MenuAdmin();
	void MenuUser();

	void loginAdmin();
	void userLogin();
};