#include<iostream>
#include "toppings.h"

using namespace std;

int main(){

    BasePizza* marg1 = new Margrita();
    cout<<marg1->cost()<<endl;

    BasePizza* marg2 = new MushroomTop(marg1);
    BasePizza* marg3 = new ExtraCheeseTop(marg2);
    cout<<marg2->cost()<<endl;
    cout<<marg3->cost()<<endl;


    return 0;
}
