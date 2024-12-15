#include "hero.h"

Hero::Hero() : name(""), weapon(""), skills(nullptr), size(0), capacity(0) {
    cout << "Hero: Конструктор без параметров\n";
}

Hero::Hero(string& n, string& w, string skill) 
    : name(n), weapon(w), size(0), capacity(1) {
    skills = new string[capacity];
    add_skill(skill);
    cout << "Hero: Конструктор с параметрами\n";
}

Hero::Hero(const Hero& other) 
    : name(other.name), weapon(other.weapon), size(other.size), capacity(other.capacity) {
    skills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        skills[i] = other.skills[i];
    }
    cout << "Hero: Конструктор копирования\n";
}

Hero::~Hero() {
    delete[] skills;
    cout << "Hero: Деструктор\n";
}

void Hero::set_name(string n) {
    name = n;
}

void Hero::set_weapon(string w) {
    weapon = w;
}

void Hero::set_skills() {
    int num_skills;
    cout << "Введите количество навыков: ";
    cin >> num_skills;
    cin.ignore(); 

    clear_skills();

    for (int i = 0; i < num_skills; ++i) {
        string skill;
        cout << "Введите навык №" << (i + 1) << ": ";
        getline(cin, skill);
        add_skill(skill);
    }
}

string Hero::get_name() {
    return name;
}

string Hero::get_weapon() {
    return weapon;
}

string Hero::get_skills() {
    string allSkills;
    for (int i = 0; i < size; ++i) {
        allSkills += skills[i];
        if (i < size - 1) {
            allSkills += ", ";
        }
    }
    return allSkills;
}

void Hero::print_info() {
    cout << "Герой\n" << "Имя: " << name << "\n"
         << "Оружие: " << weapon << "\n"
         << "Навыки: " << get_skills() << endl;
}

void Hero::change_info() {
    int choice;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1. Имя" << endl;
    cout << "2. Оружие" << endl;
    cout << "3. Навык" << endl;
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
            string newWeapon;
            cout << "Введите новое оружие: ";
            getline(cin, newWeapon);
            set_weapon(newWeapon);
            cout << "Оружие изменено." << endl;
            break;
        }
        case 3: {
            cout << "Введите новые навыки:" << endl;
            set_skills(); 
            cout << "Навыки изменены." << endl;
            break;
        }
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
}

void Hero::save(ostream& out) {
    out << "Hero\n";
    out << name << '\n' << weapon << '\n';
    for (int i = 0; i < size; ++i) {
        out << skills[i];
        if (i < size - 1) {
            out << ',';
        }
    }
    out << '\n'; 
}


void Hero::load(istream& in) {
    getline(in, name); 
    getline(in, weapon);
    string skills_line;
    getline(in, skills_line);  
    clear_skills(); 
    int new_size = 1;
    for (char c : skills_line) {
        if (c == ',') {
            new_size++;
        }
    }
    skills = new string[new_size];
    size = new_size;
    int start = 0;
    int index = 0;
    for (int i = 0; i <= skills_line.length(); ++i) {
        if (skills_line[i] == ',' || skills_line[i] == '\0') {
            skills[index++] = skills_line.substr(start, i - start);
            start = i + 1;
        }
    }
    if (start < skills_line.length()) {
        skills[index] = skills_line.substr(start);
    }
}


void Hero::add_skill(const string& skill) {
    if (size >= capacity) {
        resize();
    }
    skills[size++] = skill;
}

void Hero::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    string* newSkills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        newSkills[i] = skills[i];
    }
    delete[] skills;
    skills = newSkills;
}

void Hero::clear_skills() {
    delete[] skills;
    skills = nullptr;
    size = 0;
    capacity = 0;
}
