#include "keeper.h"

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {cout << "Keeper: Конструктор без параметров\n";}

Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {cout << "Keeper: Конструктор с параметрами\n";}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Keeper: Конструктор копирования\n";
}

Keeper::~Keeper() {
    delete_all();
    cout << "Keeper: Деструктор\n";
}

void Keeper::delete_all() {
    while (head != 0)
        delete_head();
}

void Keeper::delete_head() {
    if (head) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}

void Keeper::display_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "Данных нет" << endl;
        return;
    }
    int i = 0;
    while (temp != 0) {
        cout << i + 1 <<" - ";
        if (temp->data) {
            temp->data->print_info(); 
        } else {
            cout << "Данных нет";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

int Keeper::get_count() {
    return count;
}

Keeper& Keeper::delete_element(int n) {
    if (n < 0 || n >= count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    Element* toDelete = nullptr;

    if (n == 0) { 
        toDelete = head;
        head = head->next;
        if (count == 1) { 
            tail = nullptr;
        }
    } else {
        Element* temp = head;
        for (int i = 0; i < n - 1; i++) { 
            temp = temp->next;
        }
        toDelete = temp->next;
        temp->next = toDelete->next;
        if (toDelete == tail) { 
            tail = temp;
        }
    }

    delete toDelete->data;
    delete toDelete;    
    count--;
    cout << "Объект удален\n";
    return *this;
}


Keeper& Keeper::edit_element(int n) {
    if (n < 0 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    Element* temp = head;
    for (int i = 0; i < n; i++) {
        temp = temp->next;
    }

    if (temp->data) {
        temp->data->change_info(); 
    } else {
        cout << "Данных нет" << endl;
    }

    return *this;
}

Element* Keeper::get_head() {
    return this->head;
}

Element* Keeper::get_tail() {
    return this->tail;
}

void Keeper::save(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save(out);
        current = current->next;
    }
    out.close();
}

void Keeper::load(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Ошибка открытия файла для загрузки!" << endl;
        return;
    }

    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }

        Base* obj = nullptr;

    
        if (marker == "Hero") {
            obj = new Hero();
        } else if (marker == "Monster") {
            obj = new Monster();
        } else if (marker == "Vilain") {
            obj = new Vilain();
        } else {
            cerr << "Неизвестный тип объекта: " << marker << endl;
            continue; 
        }

        if (obj) {
            obj->load(in);
            count = this->get_count();
            this->add(obj, count);
        }
    }

    in.close();
}

void Keeper::add(Base* obj, int index) {
    if (index < 0 || index > count) {
        cerr << "Неверный индекс для добавления элемента\n";
        return;
    }

    Element* newElement = new Element;
    newElement->data = obj;
    newElement->next = nullptr;

    if (index == 0) {
        newElement->next = head;
        head = newElement;
        if (count == 0) {
            tail = head;
        }
    } else {
        Element* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        newElement->next = temp->next;
        temp->next = newElement;
        if (newElement->next == nullptr) {
            tail = newElement;
        }
    }
    count++;
    cout << "Объект добавлен.\n";
}


Keeper& Keeper::operator--(int) {
    delete_element(0);
    return *this;
}

Keeper& Keeper::operator[](int index) {
    if (index < 0 || index >= count) {
        cerr << "Неверный индекс\n";
        return *this;
    }

    Element* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return *this; 
}


Keeper& Keeper::operator!() {
    int index = this->get_count(); 
    this->delete_element(index - 1);
    return *this;
}
