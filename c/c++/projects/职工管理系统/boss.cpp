#include "boss.h"


Boss::Boss(int id, string name){
    this->id = id;
    this->name = name;
    this->department = 9;
}

void Boss::showInfo(){

    cout << this->id << '\t' << this->name << '\t' << this->getDeptName() << endl;

}

string Boss::getDeptName(){
    return "师父";
}