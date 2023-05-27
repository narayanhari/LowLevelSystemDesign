#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class BasePizza{
    public:
        virtual int cost() =0;
    private:
};

class Margrita : public BasePizza{
    public:
        int cost(){
            return 100;
        }
};

class VegDelight : public BasePizza{
    public:
        int cost(){
            return 150;
        }
};

class FarmHouse : public BasePizza{
    public:
        int cost(){
            return 250;
        }
};
