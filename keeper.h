#pragma once
#include "base.h"
#include "hero.h"
#include "vilain.h"
#include "monster.h"
#include <fstream>

struct Element 
{
    Element* next;
    Base* data;
};

class Keeper 
{
    private:
        Element* head;
        Element* tail;
        int count;
    public:
        Keeper();
        Keeper(Element* h, Element* t, int c);
        Keeper(Keeper& other);
        ~Keeper();

        Element* get_head();
        Element* get_tail();
        int get_count(); 
        
        void delete_all();
        void delete_head();
        Keeper& delete_element(int n);
        Keeper& edit_element(int n);
        void add(Base* obj, int n);
        void display_keeper();

        Keeper& operator!();
        Keeper& operator--(int);
        Keeper& operator[](int index);

        void save(const string& filename);
        void load(const string& filename);
};
