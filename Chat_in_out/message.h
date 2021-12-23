#pragma once
#include <string>
using namespace std;

class Message
{
public:
	Message() = default; // конструктор по умолчанию
	~Message() = default; // деструктор


	Message (const string& login_user, const string& name_current_reciption, const string& message_current) : _sender(login_user), _recipient(name_current_reciption), _message(message_current) {} // конструктор с параметрами


	void setMessage(const string& message);
	string getMessage() const;

	void setSender(const string& sender);
	string getSender() const;

	void setRecipient(const string& recipient);
	string getRecipient() const;


private:
	string _sender; // логин отправителя
	string _recipient; // логин получателя
	string _message; // текст сообщения
};
