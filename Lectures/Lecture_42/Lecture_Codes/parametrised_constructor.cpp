#include<iostream>
using namespace std;

class Hero {

    private:
    int health;

    public:
    char level;

    Hero() {
        cout<<"Constructor Called"<<endl;
    }

    Hero(int health) {
        this->health = health;
    }
    /// if name of parameters is different then easy no need to use this keyford 
    Hero(int health, char level) {   ///--- Hero(int h,char l){
        this->level = level;                      // level=l;                                          
        this->health = health;                    // health=h;
    }                                        // }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHelth(int h) {
        health = h;
    }

    void setLevel(char l) {
        level = l;
    }

    void print() {
        cout<<"level : "<<level<<endl;
        cout<<"health : "<<health<<endl;
    }
};

int main() {

    // static allocation
    Hero h1(10);
    h1.print();

    // dynamically allocation
    Hero *h2 = new Hero(32);
    h2->print();

    Hero *h3 = new Hero(25, 'A');
    h3->print();

    return 0;
}
