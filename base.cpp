#include "base.h"

Base::Base() {cout << "Base: Конструктор без параметров\n";}

Base::Base(const string& n) {cout << "Base: Конструктор с параметрами\n";}

Base::Base(const Base& other) {cout << "Base: Конструктор копирования\n";}

Base::~Base() {cout << "Base: Виртуальный деструктор\n";}
