#pragma once
#include <iostream>
#include <string>
using namespace std;

class Base
{
    public:
        Base();
        Base(const string &n);
        Base(const Base& other);
        virtual ~Base();

        virtual void print_info() = 0;
        virtual void change_info() = 0;
        virtual void save(ostream&) = 0;
        virtual void load(istream&) = 0;
};
