#include "manager.h"


Manager::Manager(int id, string name){
    this->id = id;
    this->name = name;
    this->department = 1;
}

void Manager::showInfo(){

    cout << this->id << '\t' << this->name << '\t' << this->getDeptName() << endl;

}

string Manager::getDeptName(){
    return "师兄";
}