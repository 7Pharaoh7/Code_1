#include "keeper.h"
#include "hero.h"
#include "vilain.h"
#include "monster.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

void display_menu() {
    cout << "\nМеню:\n";
    cout << "1. Добавить объект в контейнер\n";
    cout << "2. Вставить объект в контейнер по индексу\n";
    cout << "3. Удалить объект из контейнера\n";
    cout << "4. Изменить информацию об объекте\n";
    cout << "5. Перегруженный оператор !\n";
    cout << "6. Перегруженный оператор --\n";
    cout << "7. Вывести информацию обо всех объектах\n";
    cout << "8. Сохранить контейнер в файл\n";
    cout << "9. Загрузить контейнер из файла\n";
    cout << "0. Выход\n";
    cout << "Выберите действие: ";
}

int main() {
    Keeper keeper;
    int choice, index;

    while (true) {
        display_menu();
        if (!(cin >> choice)) {
            cout << "Ошибка: Введите корректное число.\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        cin.ignore();

        switch (choice) {
            case 1: {
                try {
                    cout << "Какой объект вы хотите добавить?\n";
                    cout << "1 - Герой\n2 - Злодей\n3 - Монстр\n";
                    int obj_choice;
                    if (!(cin >> obj_choice)) {
                        throw runtime_error("Ошибка: Введено некорректное значение при выборе объекта.");
                    }
                    if (obj_choice < 1 || obj_choice > 3) {
                        throw out_of_range("Ошибка: Выбран несуществующий тип объекта.");
                    }
                    cin.ignore();

                    Base* new_object = nullptr;
                    switch (obj_choice) {
                        case 1: {
                            string name, weapon, skill;
                            cout << "Введите имя героя: ";
                            getline(cin, name);
                            cout << "Введите оружие героя: ";
                            getline(cin, weapon);
                            cout << "Введите навыки героя: ";
                            getline(cin, skill);
                            new_object = new Hero(name, weapon, skill);
                            break;
                        }
                        case 2: {
                            string name, weapon, crime, place, skill;
                            cout << "Введите имя злодея: ";
                            getline(cin, name);
                            cout << "Введите оружие злодея: ";
                            getline(cin, weapon);
                            cout << "Введите преступление злодея: ";
                            getline(cin, crime);
                            cout << "Введите место действия злодея: ";
                            getline(cin, place);
                            cout << "Введите навыки злодея: ";
                            getline(cin, skill);
                            new_object = new Vilain(name, weapon, crime, place, skill);
                            break;
                        }
                        case 3: {
                            string name, description;
                            cout << "Введите имя монстра: ";
                            getline(cin, name);
                            cout << "Введите описание монстра: ";
                            getline(cin, description);
                            new_object = new Monster(name, description);
                            break;
                        }
                    }
                    index = keeper.get_count();
                    keeper.add(new_object, index);
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 2: {
                try {
                    cout << "Какой объект вы хотите добавить?\n";
                    cout << "1 - Герой\n2 - Злодей\n3 - Монстр\n";
                    int obj_choice;
                    if (!(cin >> obj_choice)) {
                        throw runtime_error("Ошибка: Введено некорректное значение при выборе объекта.");
                    }
                    if (obj_choice < 1 || obj_choice > 3) {
                        throw out_of_range("Ошибка: Выбран несуществующий тип объекта.");
                    }
                    cin.ignore();

                    Base* new_object = nullptr;
                    switch (obj_choice) {
                        case 1: {
                            string name, weapon, skill;
                            cout << "Введите имя героя: ";
                            getline(cin, name);
                            cout << "Введите оружие героя: ";
                            getline(cin, weapon);
                            cout << "Введите навыки героя: ";
                            getline(cin, skill);
                            new_object = new Hero(name, weapon, skill);
                            break;
                        }
                        case 2: {
                            string name, weapon, crime, place, skill;
                            cout << "Введите имя злодея: ";
                            getline(cin, name);
                            cout << "Введите оружие злодея: ";
                            getline(cin, weapon);
                            cout << "Введите преступление злодея: ";
                            getline(cin, crime);
                            cout << "Введите место действия злодея: ";
                            getline(cin, place);
                            cout << "Введите навыки злодея: ";
                            getline(cin, skill);
                            new_object = new Vilain(name, weapon, crime, place, skill);
                            break;
                        }
                        case 3: {
                            string name, description;
                            cout << "Введите имя монстра: ";
                            getline(cin, name);
                            cout << "Введите описание монстра: ";
                            getline(cin, description);
                            new_object = new Monster(name, description);
                            break;
                        }
                    }
                    cout << "Введите индекс для вставки\n";
                    if (!(cin >> index)) {
                        throw runtime_error("Ошибка: Введено некорректное значение индекса.");
                    }
                    if (index < 1 || index > keeper.get_count() + 1) {
                        throw out_of_range("Ошибка: Индекс выходит за границы контейнера.");
                    }
                    cin.ignore();
                    keeper.add(new_object, index - 1);
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 3: {
                try {
                    cout << "Введите индекс объекта для удаления: ";
                    if (!(cin >> index)) {
                        throw runtime_error("Ошибка: Введено некорректное значение индекса.");
                    }
                    if (index < 1 || index > keeper.get_count()) {
                        throw out_of_range("Ошибка: Индекс выходит за границы контейнера.");
                    }
                    keeper.delete_element(index - 1);
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 4: {
                try {
                    cout << "Введите индекс объекта для изменения: ";
                    if (!(cin >> index)) {
                        throw runtime_error("Ошибка: Введено некорректное значение индекса.");
                    }
                    if (index < 1 || index > keeper.get_count()) {
                        throw out_of_range("Ошибка: Индекс выходит за границы контейнера.");
                    }
                    keeper.edit_element(index - 1);
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 5: {
                try {
                    !keeper;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 6: {
                try {
                    keeper--;
                } catch (const exception& e) {
                    cerr << e.what() << endl;
                }
                break;
            }

            case 7: {
                keeper.display_keeper();
                break;
            }

            case 8: {
                try {
                    keeper.save("2.csv");
                    cout << "Контейнер сохранен в файл.\n";
                } catch (const runtime_error& e) {
                    cerr << "Ошибка при сохранении файла: " << e.what() << endl;
                }
                break;
            }

            case 9: {
                try {
                    keeper.load("1.csv");
                    cout << "Контейнер загружен из файла.\n";
                } catch (const runtime_error& e) {
                    cerr << "Ошибка при загрузке файла: " << e.what() << endl;
                }
                break;
            }

            case 0:
                cout << "Выход из программы.\n";
                return 0;

            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }
}
