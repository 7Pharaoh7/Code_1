#include "monster.h"

Monster::Monster() : name(""), description("") {cout << "Monster: Конструктор без параметров\n";}

Monster::Monster(string& n, string& d) : name(n), description(d) {cout << "Monster: Конструктор с параметрами\n";}

Monster::Monster(const Monster& other) : name(other.name), description(other.description) {cout << "Monster: Конструктор копирования\n";}

Monster::~Monster() {cout << "Monster: Деструктор\n";}

void Monster::set_name(string n) {
    name = n;
}

void Monster::set_description(string d) {
    description = d;
}

string Monster::get_name() {
    return name;
}

string Monster::get_description() {
    return description;
}

void Monster::print_info() {
    cout << "Монстр\n"<< "Имя: " << name << "\n"
         << "Описание: " << description << endl;
}

void Monster::change_info() {
    int choice;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1. Имя" << endl;
    cout << "2. Описание" << endl;
    cout << "Введите номер: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1: {
            string newName;
            cout << "Введите новое имя: ";
            getline(cin, newName);
            set_name(newName);
            cout << "Имя изменено." << endl;
            break;
        }
        case 2: {
            string newDescription;
            cout << "Введите новое описание: ";
            getline(cin, newDescription);
            set_description(newDescription);
            cout << "Описание изменено." << endl;
            break;
        }
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
}

void Monster::save(ostream& out) {
    out << "Monster\n";
    out << name << '\n' << description << '\n';
}

void Monster::load(istream& in) {
    getline(in, name);
    getline(in, description);
}
