#pragma once
#include "base.h"

class Monster: public Base 
{
    private:
        string name;
        string description;
    public:
        Monster();
        Monster(string& n, string& d);
        Monster(const Monster& other);
        ~Monster();

        void set_name(string n);
        void set_description(string d);

        string get_name();
        string get_description();

        void print_info() override;
        void change_info() override;
        void save(ostream&) override;
        void load(istream&) override;

};
