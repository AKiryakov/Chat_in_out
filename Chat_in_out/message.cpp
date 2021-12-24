#include <string>
#include "message.h"
using namespace std;

string Message::getMessage() const
{
	return _message;
}

void Message::setMessage(const string& message)
{
	_message = message;
}

string Message::getSender() const
{
	return _sender;
}

void Message::setSender(const string& sender)
{
	_sender = sender;
}

string Message::getRecipient() const
{
	return _recipient;
}

void Message::setRecipient(const string& recipient)
{
	_recipient = recipient;
}

ostream& operator <<(ostream& os, const Message& m)
{
	os << m._message << endl;
	//os << ' ';
	os << m._sender;
	os << ' ';
	os << m._recipient;
	return os;
}

fstream& operator >>(fstream& is, Message& m)
{
	getline(is, m._message);
	is >> m._sender;
	is >> m._recipient;
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return is;
}
