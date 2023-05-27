#include<iostream>
#include "pizza.h"

using namespace std;

class Toppings : public BasePizza{
};

class MushroomTop : public Toppings{
    public:
        MushroomTop(BasePizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            return pizza->cost()+10;
        }

    private:
        BasePizza* pizza;
};

class ExtraCheeseTop : public Toppings{
    public:
        ExtraCheeseTop(BasePizza* pizza){
            this->pizza = pizza;
        }
        int cost(){
            return pizza->cost()+15;
        }

    private:
        BasePizza* pizza;
};
