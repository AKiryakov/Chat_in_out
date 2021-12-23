#pragma once
#include <string>
#include <fstream>

using namespace std;

class User
{
public:
	User() = default; // конструктор по умолчанию
	~User() = default; // деструктор

	User(const string& login_user, const string& name_user, const string& password_user) : _login(login_user), _name(name_user), _password(password_user){} // конструктор с параметрами

	void setUserLogin(const string& login);
	string &getUserLogin();
	void setUserName(const string& name);
	string &getUserName();
	void setUserPassword(const string& password);
	string &getUserPassword();

	friend fstream& operator >>(fstream& is, User& Users_Vector_Class);
	friend ostream& operator <<(ostream& os, const User& Users_Vector_Class);

private:
	string _login; // переменная с логином
	string _name; // переменная с именем
	string _password; // переменная с паролем
};
