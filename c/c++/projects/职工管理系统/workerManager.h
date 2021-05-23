#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
using namespace std;
#define FILENAME "empFile.txt"


class WorkerManager{
public:

	//构造函数
	WorkerManager();

    void Show_Menu();

    void exit_system();

	void add_emp();
	
	void save();

	int get_empnum();//获取职工人数

	void init_emp(); //初始化职工

	void show_emp(); //显示职工

	void del_emp(); //删除职工

	void mod_emp(); //修改职工

	void find_emp(); //查询员工

	void sort_emp(); //排序员工

	void clean_file(); //清空文件

	int isExist(int id); // 判断职工是否存在，存在返回index，不存在返回-1



	//析构函数
	~WorkerManager();

	int empNum;
	Worker ** EmpArray;
	bool fileIsEmpty;


};