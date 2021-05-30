#include "workerManager.h"

WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	//1. 文件不存在
	if(!ifs.is_open()){
		cout << "文件不存在" << endl;
		this->empNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. 文件存在，数据为空
	char ch;
	ifs >> ch;
	if(ifs.eof()){
		// 文件为空
		cout << "文件为空" << endl;
		this->empNum = 0;
		this->EmpArray = NULL;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;
	// 3. 文件存在，并且记录着数据
	int num = this->get_empnum();
	this->empNum = num;
	this->EmpArray = new Worker*[this->empNum];
	cout << "这里的大小是：" << sizeof(this->EmpArray) / sizeof(this->EmpArray[0]) << endl;
	
	this->init_emp(); // 将文件中的数据，存到数组中

	for(int i=0; i<this->empNum; i++){
		cout << this->EmpArray[i]->id << "\t" 
			 << this->EmpArray[i]->name << endl;
	}

	ifs.close();

}

void WorkerManager::Show_Menu(){

   	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void WorkerManager::exit_system()
{
	cout << "欢迎下次使用" << endl;
	exit(0);
}

void WorkerManager::add_emp(){
	cout << "请输入添加员工的数量：";
	int addNum = 0;
	cin>> addNum;

	if(addNum>0){
		int newSize = this->empNum + addNum;
		Worker** newSpace = new Worker*[newSize];

		//将原来的数据复制到新空间
		if(this->EmpArray!=NULL){
			for(int i=0; i<this->empNum; i++){
				newSpace[i] = this->EmpArray[i];
			}
		}

		//批量添加新数据
		for(int i=0; i<addNum; i++){
			int id; // 职工编号
			string name; // 职工姓名
			int deptSelect; // 部门选择

			cout << "请输入第" << i+1 << "个新来的编号："; cin >> id;
			cout << "请输入第" << i+1 << "个新来的姓名："; cin >> name;
			cout << "请输入第" << i+1 << "个新来的部门：" << endl;
			cout << "9-师父" << endl; 
			cout << "1-小头头" << endl;
			cout << "2-学徒" << endl;
			cout << ": ";
			cin >> deptSelect;

			Worker * worker = NULL;
			switch (deptSelect){
				case 9:
					worker = new Boss(id, name);
					break;
				case 1: 
					worker = new Manager(id, name);
					break;
				case 2:
					worker = new Employee(id, name);
					break;
				default:
					break;
			}
			newSpace[this->empNum+i] = worker;
		}
		delete[] this->EmpArray;
		this->EmpArray = newSpace;
		this->empNum = newSize;
		this->fileIsEmpty = false;
		this->save();
		cout << "成功添加" << addNum << "个成员" << endl;
		
	}else{
		cout << "输入有误" << endl;
	}

	// 清屏
	system("reset");
}

void WorkerManager::save(){
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for(int i=0; i<this->empNum; i++){
		ofs << this->EmpArray[i]->id << " "
			<< this->EmpArray[i]->name << " "
			<< this->EmpArray[i]->department << endl;
	}

	ofs.close();

}

int WorkerManager::get_empnum(){
	ifstream ifs; 
	ifs.open(FILENAME, ios::in);
	if(!ifs.is_open()){
		cout << "尝试打开文件失败" << endl;
	}

	int id; 
	string name;
	int deptid;


	int num = 0;
	while (ifs>>id && ifs>>name && ifs >> deptid){
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_emp(){
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if(!ifs.is_open()){
		cout << "尝试打开文件失败" << endl;
		exit(0);
	}
	
	int id;
	string name;
	int deptid;
	int index = 0;

	while(ifs>>id && ifs>>name && ifs>>deptid){
		Worker * worker = NULL;
		if(deptid==9){
			worker = new Boss(id, name);
		}else if(deptid == 1){
			worker = new Manager(id, name);
		}else{
			worker = new Employee(id, name);
		}
		worker->showInfo();
		this->EmpArray[index] = worker;
		index++;
	}
	cout << index << endl;
	ifs.close();


}


void WorkerManager::show_emp(){
	if(this->fileIsEmpty){
		cout << "文件不存在或记录为空" << endl;
	}else{
		cout << "The length = " << this->empNum << endl;
		for(int i=0; i<this->empNum; i++){
			this->EmpArray[i]->showInfo();
		}
	}

	getchar();getchar();
	system("reset");
}

void WorkerManager::del_emp(){
	if(this->fileIsEmpty){
		cout << "文件不存在或记录为空" << endl;
	}else{
		cout << "请输入要删除的员工编号：";
		int id;
		cin >> id;

		int index = this->isExist(id);
		if (index == -1) {
			cout << "此员工不存在" << endl;
		}else{
			for(int i = index; i<this->empNum-1; i++){
				this->EmpArray[i] = this->EmpArray[i+1];
			}
			delete this->EmpArray[this->empNum];
			this->empNum--;
			this->save();
		}
	}
	getchar();getchar();
	system("reset");
}

int WorkerManager::isExist(int id){
	int index = -1;
	for(int i=0; i<this->empNum; i++){
		if(this->EmpArray[i]->id == id){
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::mod_emp(){
	if(this->fileIsEmpty){
		cout << "文件不存在或记录为空" << endl;
	}else{
		cout << "请输入要修改的员工编号：";
		int id;
		cin >> id;

		int index = this->isExist(id);
		if(index==-1){
			cout << "此员工不存在" << endl;
		}else{
			delete this->EmpArray[index];
			int newId;
			string newName;
			int newDept;

			cout << "请输入新员工编号：";
			cin >> newId;
			cout << "请输入新姓名：";
			cin >> newName;
			cout << "请输入新员工职位：";
			cin >> newDept;

			Worker *worker = NULL;
			switch(newDept){
				case 9:
				worker = new Boss(newId, newName);
				break;
				
				case 1:
				worker = new Manager(newId, newName);
				break;

				case 2:
				worker = new Employee(newId, newName);
				break;

				default:
				break;
			}

			this->EmpArray[index] = worker;
			cout << "修改成功！" << endl;

			this->save();
		}
	}
	getchar();getchar();
	system("reset");
}

void WorkerManager::find_emp(){
	if(this->fileIsEmpty){
		cout << "文件不存在或记录为空" << endl;
	}else{
		cout << "请选择(1-用id查,2-用姓名查)：";
		int choice;
		cin >> choice;
		switch(choice){
			case 1:
			{
				cout << "请输入查询员工的编号：" << endl;
				int searchId;
				cin >> searchId;

				if(isExist(searchId)==-1){
					cout << "此员工不存在" << endl;
				}else{
					for (int i=0; i<this->empNum; i++){
						if(this->EmpArray[i]->id == searchId){
							this->EmpArray[i]->showInfo();
							return;
						}
					}
					cout << "此员工不存在" << endl;
				}
			}
			break;

			case 2:
			{
				cout << "请输入查询员工的姓名：" << endl;
				string searchName;
				cin >> searchName;
				for (int i=0; i<this->empNum; i++){
					if(this->EmpArray[i]->name == searchName){
						this->EmpArray[i]->showInfo();
						return;
					}
				}
				cout << "此员工不存在" << endl;
			}
		}

	}
		
}

void WorkerManager::sort_emp(){
	if(this->fileIsEmpty){
		cout << "此文件不存在或记录为空" << endl;
		getchar();getchar(); 
		system("reset");
	}else{
		cout << "请选择排序方式(1-升序,2-降序):";
		int choice;
		cin >> choice;

		for (int i=0; i<this->empNum; i++){
			int minormax = i;
			for(int j=i+1; j<this->empNum;j++){
				if(choice==1){
					if(this->EmpArray[minormax]->id > this->EmpArray[j]->id){
						minormax = j;
					}
				}else{
					if(this->EmpArray[minormax]->id < this->EmpArray[j]->id){
						minormax = j;
					}
				}
			}
			if(i != minormax){
				Worker * temp = this->EmpArray[i];
				this->EmpArray[i] = this->EmpArray[minormax];
				this->EmpArray[i] = temp;
			}

			this->save();
			this->show_emp();
			
		}
	}
}

void WorkerManager::clean_file(){
	cout << "确定清空文件？1-确定,2-取消:";
	int choice;
	cin >> choice;

	if (choice == 1){
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建

		ofs.close();

		if(this->EmpArray!=NULL){
			for(int i=0; i<this->empNum; i++){
				delete this->EmpArray[i];
				this->EmpArray[i] = NULL;
			}
			delete[] this->EmpArray;
			this->EmpArray = NULL;
			this->empNum = 0;
			this->fileIsEmpty = true;
		}
		cout << "清空完毕" << endl;
	}

}

WorkerManager::~WorkerManager(){
	if(this->EmpArray != NULL){
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}