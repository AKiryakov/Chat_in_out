#include <string>
#include <fstream>
#include "user.h"
using namespace std;

string &User::getUserLogin()
{
	return _login;
}

void User::setUserLogin(const string& login)
{
	_login = login;
}

string &User::getUserName()
{
	return _name;
}

void User::setUserName(const string& name)
{
	_name = name;
}

string &User::getUserPassword()
{
	return _password;
}

void User::setUserPassword(const string& password)
{
	_password = password;
}

ostream& operator <<(ostream& os, const User& Users_Vector_Class)
{
	os << Users_Vector_Class._login;
	os << ' ';
	os << Users_Vector_Class._name;
	os << ' ';
	os << Users_Vector_Class._password;
	return os;
}

fstream& operator >>(fstream& is, User& Users_Vector_Class)
{
	is >> Users_Vector_Class._login;
	is >> Users_Vector_Class._name;
	is >> Users_Vector_Class._password;
	return is;
}
