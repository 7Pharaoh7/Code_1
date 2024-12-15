#include "vilain.h"

Vilain::Vilain() : name(""), weapon(""), crime(""), place(""), skills(nullptr), size(0), capacity(0) {cout << "Vilain: Конструктор без параметров\n";}

Vilain::Vilain(string& n, string& w, string& c, string& p, string skill) 
    : name(n), weapon(w), crime(c), place(p), size(0), capacity(1) {
    skills = new string[capacity];
    add_skill(skill);
    cout << "Vilain: Конструктор с параметрами\n";
}

Vilain::Vilain(const Vilain& other) 
    : name(other.name), weapon(other.weapon), crime(other.crime), place(other.place), size(other.size), capacity(other.capacity) {
    skills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        skills[i] = other.skills[i];
    }
    cout << "Vilain: Конструктор копирования\n";
}

Vilain::~Vilain() {
    delete[] skills;
    cout << "Vilain: Деструктор\n";
}

void Vilain::set_name(string n) {
    name = n;
}

void Vilain::set_weapon(string w) {
    weapon = w;
}

void Vilain::set_crime(string c) {
    crime = c;
}

void Vilain::set_place(string p) {
    place = p;
}

void Vilain::set_skills() {
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
string Vilain::get_name() {
    return name;
}

string Vilain::get_weapon() {
    return weapon;
}

string Vilain::get_crime() {
    return crime;
}

string Vilain::get_place() {
    return place;
}

string Vilain::get_skills() {
    string allSkills;
    for (int i = 0; i < size; ++i) {
        allSkills += skills[i];
        if (i < size - 1) {
            allSkills += ", ";
        }
    }
    return allSkills;
}
void Vilain::print_info() {
    cout << "Злодей\n" << "Имя: " << name << "\n"
         << "Оружие: " << weapon << "\n"
         << "Преступление: " << crime << "\n"
         << "Место: " << place << "\n"
         << "Навыки: " << get_skills() << endl;
}

void Vilain::change_info() {
    int choice;
    cout << "Что вы хотите изменить?" << endl;
    cout << "1. Имя" << endl;
    cout << "2. Оружие" << endl;
    cout << "3. Преступление" << endl;
    cout << "4. Место" << endl;
    cout << "5. Навык" << endl;
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
            string newCrime;
            cout << "Введите новое преступление: ";
            getline(cin, newCrime);
            set_crime(newCrime);
            cout << "Преступление изменено." << endl;
            break;
        }
        case 4: {
            string newPlace;
            cout << "Введите новое место: ";
            getline(cin, newPlace);
            set_place(newPlace);
            cout << "Место изменено." << endl;
            break;
        }
        case 5: {
            string newSkill;
            cout << "Введите новый навык: ";
            set_skills();
            cout << "Навык изменен." << endl;
            break;
        }
        default:
            cout << "Неверный выбор." << endl;
            break;
    }
}

void Vilain::save(ostream& out) {
    out << "Vilain\n";
    out << name << '\n' << weapon << '\n' << crime << '\n' << place << '\n';
    for (int i = 0; i < size; ++i) {
        out << skills[i];
        if (i < size - 1) {
            out << ','; 
        }
    }
    out << '\n'; 
}

void Vilain::load(istream& in) {
    getline(in, name);   
    getline(in, weapon); 
    getline(in, crime); 
    getline(in, place); 
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


void Vilain::add_skill(const string& skill) {
    if (size >= capacity) {
        resize();
    }
    skills[size++] = skill;
}

void Vilain::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    string* newSkills = new string[capacity];
    for (int i = 0; i < size; ++i) {
        newSkills[i] = skills[i];
    }
    delete[] skills;
    skills = newSkills;
}


void Vilain::clear_skills() {
    delete[] skills;
    skills = nullptr;
    size = 0;
    capacity = 0;
}
