#include "Header.h"

int _stateMenu;
void Menu() {

    cout << "Main menu:\n\n"

        << "1. Ввести информацию;\n"
        << "2. Вывести информацию;\n"
        << "3. Изменить информацию;\n"
        << "4. Удалить информацию;\n"
        << "5. Добавить информацию;\n"
        << "6. Сохранить информацию;\n"
        << "0. Выйти.\n\n"

        << ">>> ";  cin >> _stateMenu;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    DataInitialization();

    Menu();

    int _actions;
    string fileName;

    while (_stateMenu != 0) {

        switch (_stateMenu)
        {
        case 1:
            system("cls");

            cout << "Ввести информацию вручную(1) или из файла(2)? \n\n>>> ";
            cin >> _actions;

            system("cls");

            if (_actions == 1) {
                DataEntry();
            }
            else if (_actions == 2) {
                cout << "Введите название файла: ";
                cin >> fileName;
                DataReading(fileName);
            }
            else {
                cout << "Неверный ответ.";
            }
            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        case 2:
            system("cls");

            Print();

            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        case 3:
            system("cls");

            Print();
            DataChange();

            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        case 4:
            system("cls");

            Print();
            DeleteData();

            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        case 5:
            system("cls");

            AddData();

            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        case 6:
            system("cls");

            cout << "Введите название файла: ";
            cin >> fileName;

            SaveData(fileName);

            system("pause");
            system("cls");
            Menu();
            break;
            ///////////////////////////////////////////////
        default:
            cout << "Неправильно выбран пункт меню" << endl;
            
            break;
        }
    }

    system("cls");
    if (DataCleaning())
        cout << "Данные очищены.\n";
    else
        cout << "Данные не очищены.\n";

    cout << "Завершение программы.\n";
    system("pause>>void");

    return 0;
}