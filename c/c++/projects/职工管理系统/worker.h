#pragma once
#include <iostream>

using namespace std;

class Worker{
    public:

    // 显示个人信息
    virtual void showInfo() = 0;

    // 获取岗位名称
    virtual string getDeptName() = 0;


    int id;
    string name;
    int department;

};