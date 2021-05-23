#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;


int main(int argc, char const *argv[])
{

    WorkerManager wm;

    int choice = 0;
    

    while(true){
        wm.Show_Menu();
        cout << "请输入您的选择：";
        cin >> choice;

        switch(choice){
            case 0://退出系统
                wm.exit_system();
                break;
            case 1://增加职工
                wm.add_emp();
                break;
            case 2://显示职工
                wm.show_emp();
                break;
            case 3://删除职工
                wm.del_emp();
                break;
            case 4://修改职工
                wm.mod_emp();
                break;
            case 5://查找职工
                wm.find_emp();
                break;
            case 6://排序职工
                wm.sort_emp();
                break;
            case 7://清空文档
                wm.clean_file();
                break;
            default:
                system("reset");
        }
    }


    return 0;
}
