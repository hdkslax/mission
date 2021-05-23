// 普通员工文件

#pragma once
#include <iostream>
#include "worker.h"
using namespace std;

class Manager : public Worker{
    public:

    Manager(int id, string name);
    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};