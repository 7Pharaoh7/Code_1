#pragma once
#include "base.h"

class Vilain: public Base 
{
    private:
        string name;
        string weapon;
        string crime;
        string place;
        string* skills;
        int size;
        int capacity;
    public:
        Vilain();
        Vilain(string& n, string& w, string& c, string& p, string skill);
        Vilain(const Vilain& other);
        ~Vilain();

        void set_name(string n);
        void set_weapon(string w);
        void set_crime(string c);
        void set_place(string p);
        void set_skills();

        string get_name();
        string get_weapon();
        string get_crime();
        string get_place();
        string get_skills();

        void print_info() override;
        void change_info() override;
        void save(ostream&) override;
        void load(istream&) override;

        void add_skill(const string& skill);
        void resize();
        void clear_skills();
    
};
