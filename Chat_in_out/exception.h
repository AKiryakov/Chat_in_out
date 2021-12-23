#pragma once
using namespace std;


class Bad_range : public exception // создаем класс ошибок, наследуясь от встроенного класса exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: bad range array"; // отображается на экране при получении исключения
	}
};