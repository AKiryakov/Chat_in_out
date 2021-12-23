#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "user.h"
#include "message.h"
#include "exception.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<User> Users_Vector_Class; // создаем вектор пользователей класса User
    vector<Message> Message_Vector_Class; // создаем вектор сообщений класса Message
    string user_login, user_name, user_password, user_confirm_password, current_message, current_reciption_name, flag_response;// имя текущего пользователя, пароль, подтверждение, текст сообщения, имя получателя сообщения, переменная для определения кому отвечать
    int num, j; // переменные для меню и цикла
    bool authorization, name_free, sent_nosuccessfully, finish_program = true; // для логики факта авторизации, свободного имени в чате, факта отправки сообщения, завершения программы
    while (finish_program) //бесконечный цикл пока finish_program = true 
    {
        cout << "выберете действие:" << endl;// основное меню
        cout << "1. Регистрация пользователя" << endl;
        cout << "2. Авторизация пользователя и работа в чате" << endl;
        cout << "Для выхода из программы нажмите любую другую кнопку" << endl << endl;
        cin >> num;
        cin.ignore();
        switch (num) // выбор действий через оператор switch
        {
        case 1:
            cout << "Введите ваш логин" << endl;
            getline(cin, user_login);
            if (Users_Vector_Class.size() == 0) // если пользователь первый, то не проверяем на уникальность
            {
                cout << "Введите Ваше имя" << endl;
                getline(cin, user_name);
                cout << "Придумайте Ваш пароль" << endl;
                getline(cin, user_password);
                cout << "Повторите пароль еще раз" << endl;
                getline(cin, user_confirm_password);

                if (user_password == user_confirm_password) // если пароли совпадают
                {
                    Users_Vector_Class.push_back(User(user_login, user_name, user_password)); // добавляем новый объект User в вектор
                    cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                }
                else
                {
                    cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl; // если пароли не совпадают выводим сообщение
                }
            }
            else // если в векторе User есть хотя бы одна запись, проверяем следующих пользователей на уникальность
            {
                name_free = true;
                for (int i = 0; i < Users_Vector_Class.size(); ++i) // просматриваем все зарегистрированные логины
                {
                    if (user_login == Users_Vector_Class[i].getUserLogin()) // если находим
                    {
                        name_free = false; // выставляем name_free = false
                        break;
                    }
                }

                if (name_free) // если имя совободно, то приступаем к вводу имени и пароля
                {
                    cout << "Введите Ваше имя" << endl;
                    getline(cin, user_name);
                    cout << "Придумайте Ваш пароль" << endl;
                    getline(cin, user_password);
                    cout << "Повторите пароль еще раз" << endl;
                    getline(cin, user_confirm_password);
                    if (user_password == user_confirm_password) // если пароли совпадают
                    {
                        Users_Vector_Class.push_back(User(user_login, user_name, user_password)); // добавляем новый объект User в вектор
                        cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                        break;
                    }
                    else
                    {
                        cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                    }
                }
                else
                {
                    cout << "Логин уже используется, придумайте другой" << endl << endl;
                }
            }
            break;
        case 2:
            if (Users_Vector_Class.size() < 2) // если в векторе имен меньше 2 зарегистрированных пользователей, то в чат не пускаем
            {
                cout << "В чате зарегистрировано недостаточно пользователей для общения" << endl << endl;
                break;
            }
            // авторизация
            cout << "Введите Ваш логин:" << endl;
            getline(cin, user_login);
            cout << "Введите Ваш пароль:" << endl;
            getline(cin, user_password);

            authorization = false;
            for (int i = 0; i < Users_Vector_Class.size(); ++i) // перебираем введенные имя и пароль в векторах
            {
                if (user_login == Users_Vector_Class[i].getUserLogin() && user_password == Users_Vector_Class[i].getUserPassword()) // если нашли соответствие авторизация прошла
                {
                    cout << "Добро пожаловать " << Users_Vector_Class[i].getUserName() << endl << endl;
                    authorization = true; //если имя и пароль верные, переменная authorization = true
                    break;
                }
            }
            if (!authorization)
            {
                cout << "Ошибка логина пользователя или пароля" << endl << endl;
            }
            while (authorization) // если авторизация прошла, показываем меню
            {
                cout << "выберете действие:" << endl;// основное меню
                cout << "1. Отправить сообщение всем пользователям" << endl;
                cout << "2. Отправить личное сообщение" << endl;
                cout << "3. Получить сообщение" << endl; // 
                cout << "Для выхода в предыдущее меню нажмите любую другую цифру, для выхода из программы любую букву" << endl << endl;
                cin >> num;
                cin.ignore();
                switch (num) // выбор действий через оператор switch
                {
                case 1: // отправка сообщений всем пользователям
                    cout << "введите сообщение" << endl;
                    getline(cin, current_message);
                    current_message = "сообщение всем от " + user_login + ": " + current_message;
                    for (int i = 0; i < Users_Vector_Class.size(); ++i) // перебираем вектор User
                    {
                        if (user_login != Users_Vector_Class[i].getUserLogin()) // для рассылки всем, кроме случая равенства имени текущего пользователя и пользователя из вектора User (чтобы не отправлять сообщение самому себе)
                        {
                            Message_Vector_Class.push_back(Message(user_login, Users_Vector_Class[i].getUserLogin(), current_message));// отправляем сообщение
                        }
                    }
                    cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;
                    break;

                case 2:
                    // отправка сообщения конкретному пользователю
                    sent_nosuccessfully = true; // значение переменной будет истина, пока пользователь не введет правильно имя получателя
                    cout << "Сейчас в чате зарегистрированы:" << endl; // отображаем список зарегистрированных пользователей
                    for (int i = 0; i < Users_Vector_Class.size(); ++i) // Отображаем на экран список зарегистрированных пользователей
                    {
                        cout << Users_Vector_Class[i].getUserLogin() << "; ";
                    }
                    while (sent_nosuccessfully) // бесконечный цикл, пока не введем точное имя получателя
                    {
                        cout << endl << "кому отправляем сообщение?" << endl;
                        getline(cin, current_reciption_name);

                        for (int i = 0; i < Users_Vector_Class.size(); ++i) // перебираем введенное имя среди зарегистрированных пользователей
                        {
                            if (current_reciption_name == Users_Vector_Class[i].getUserLogin()) // если находим, просим ввести текст сообщения
                            {
                                cout << "введите сообщение" << endl;
                                getline(cin, current_message);
                                current_message = "Вам сообщение от " + user_login + ": " + current_message;
                                Message_Vector_Class.push_back(Message(user_login, current_reciption_name, current_message));// отправляем сообщение
                                cout << "Ваше сообщение отправлено" << endl << endl;
                                sent_nosuccessfully = false; // устанавливаем флаг в положение "сообщение отправлено"
                            }
                        }
                        if (sent_nosuccessfully) // если имя получателя в списке не нашли, сообщаем об этом
                        {
                            cout << "пользователь с именем " << current_reciption_name << " в чате не зарегистрирован" << endl << endl;
                        }
                    }
                    break;

                case 3: // получаем сообщения
                    j = Message_Vector_Class.size();
                    try
                    {
                        for (int i = 0; i < j; ++i)
                        {
                            if (user_login == Message_Vector_Class[i].getRecipient()) // если находим свое имя в векторе Message в поле получатель, 
                            {
                                cout << Message_Vector_Class[i].getMessage() << endl; // выводим на экран сообщение
                                cout << "Для ответа пользователю '" << Message_Vector_Class[i].getSender() << "' лично нажмите 'л', для ответа в общий чат нажмите 'в', для получения остальных сообщений - любую кнопку" << endl; // предлагаем ответить лично или всем
                                cin >> flag_response; // вводим с клавиатуры, если:
                                if (flag_response == "л") // "л" - отпраляем личный ответ
                                {
                                    cin.ignore();
                                    cout << "введите текст сообщения:" << endl;
                                    getline(cin, current_message);
                                    current_message = "Вам сообщение от " + user_login + ": " + current_message;
                                    Message_Vector_Class.push_back(Message(user_login, Message_Vector_Class[i].getSender(), current_message)); // отправляем сообщение
                                    cout << "Ваше сообщение отправлено" << endl << endl;
                                }
                                if (flag_response == "в") // если "в" - то отвечаем всем
                                {
                                    cin.ignore();
                                    cout << "введите текст сообщения:" << endl;
                                    getline(cin, current_message);
                                    current_message = "сообщение всем от " + user_login + ": " + current_message;

                                    for (int k = 0; k < Users_Vector_Class.size(); ++k) //отправляем всем сообщение аналогично, как ранее
                                    {
                                        if (user_login != Users_Vector_Class[k].getUserLogin())
                                        {
                                            Message_Vector_Class.push_back(Message(user_login, Users_Vector_Class[k].getUserLogin(), current_message));// отправляем сообщение
                                        }
                                    }
                                    cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;
                                }
                                Message_Vector_Class.erase(Message_Vector_Class.begin() + i); // удаляем из вектора Message объект с прочитанным сообщением
                                --j; // длина векторов стала меньше на 1, соответственно уменьшаем на 1 количество проходов
                                --i; // удалено текущее значения в векторе Message, значит с этим же индексом хранится уже новое сообщение, оно проверяется на следующем проходе
                            }
                        }
                    }

                    catch (exception& error) // отработка пойманных исключений
                    {
                        cout << error.what();
                    }

                    cout << "Входящих сообщений нет" << endl << endl;
                    break;

                default:
                    if ((num > 3) || (num < 1)) // условие выхода в предыдущее меню
                    {
                        authorization = false;
                    }
                    break;
                }
            }
            break;

        default:
            if ((num > 2) || (num < 1)) // условие выхода из программы
            {
                finish_program = false;
            }
            break;
        }
    }
    return 0;
}