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

ostream& operator <<(ostream& os, const Message& Message_Vector_Class)
{
	os << Message_Vector_Class._message;
	os << ' ';
	os << Message_Vector_Class._sender;
	os << ' ';
	os << Message_Vector_Class._recipient;
	return os;
}

fstream& operator >>(fstream& is, Message& Message_Vector_Class)
{
	is >> Message_Vector_Class._message;
	is >> Message_Vector_Class._sender;
	is >> Message_Vector_Class._recipient;
	return is;
}
