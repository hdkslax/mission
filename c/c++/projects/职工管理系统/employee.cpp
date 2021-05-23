#include "employee.h"

Employee::Employee(int id, string name){
    this->id = id;
    this->name = name;
    this->department = 2;

}
    // 显示个人信息
void Employee::showInfo(){
    cout << this->id << '\t' << this->name << '\t' << this->getDeptName() << endl;
}

    // 获取岗位名称
string Employee::getDeptName(){
    return "学徒";

}