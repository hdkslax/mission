// 通讯录管理系统

#include <iostream>

using namespace std;

#define MAX 1000


// 联系人结构体
struct Person
{
    string m_Name;
    int m_Gender;
    int m_Age;
    string m_Phone;
};

// 通讯录结构体
struct msgManagement
{
    Person personArray[MAX];
    int m_Size; // 通讯录中当前记录条目个数
};

void showMenu(){

    cout << "1. 添加联系人" << endl;

    cout << "2. 显示联系人" << endl;

    cout << "3. 删除联系人" << endl;

    cout << "4. 查找联系人" << endl;

    cout << "5. 修改联系人" << endl;

    cout << "6. 清空联系人" << endl;

    cout << "0. 退出通讯录" << endl;

    cout << "请选择: ";

}

// 1. 添加联系人
void addPerson(msgManagement *abs){
    if(abs->m_Size == MAX){
        cout << "通讯录已满，无法添加" << endl;
        return;
    }else{
        // 添加具体联系人
        string name;
        cout << "请输入姓名：";
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        int gender;
        cout << "请输入性别(1.男，2.女)：";
        
        while(1){
            cin >> gender;
            if (gender==1 || gender==2){
                abs->personArray[abs->m_Size].m_Gender = gender;
                break;
            } else {
                cout << "请输入合法数字(1.男，2.女)：";
            }
        }

        int age;
        cout << "请输入年龄：";
        
        while (cin >> age){
            if(age>-1 && age < 150){
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            } else {
                cout << "请输入合法数字：";
            }
        }

        string phone;
        cout << "请输入电话：";
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // 更新通讯录人数
        abs->m_Size++;

        system("reset"); // linux下的清屏操作
        // system("cls"); // windows下的清屏操作

    }
}

// 2. 显示联系人
void showPerson(msgManagement *abs){
    //若通讯录中人数为0，则显示为空
    //若不为0，显示记录信息
    if(abs->m_Size==0){
        cout << "当前记录为空" << endl;
    } else {
        cout << "姓名" << '\t'
             << "性别" << '\t'
             << "年龄" << '\t'
             << "电话" << endl;
        for (int i=0; i<abs->m_Size; i++){
            cout << abs->personArray[i].m_Name << '\t'
                 << abs->personArray[i].m_Gender << '\t'
                 << abs->personArray[i].m_Age << '\t'
                 << abs->personArray[i].m_Phone << endl;
        }
        
    }

    cout << "任意键返回菜单" << endl;
    getchar();getchar();
    system("reset");
}

// 3.1 检测联系人是否存在
int isExist(msgManagement *abs, string name){
    for (int i=0; i<abs->m_Size; i++){
        if (abs->personArray[i].m_Name == name){
            return i;
        }
    }
    return -1;
}

// 3. 删除联系人
void deletePerson(msgManagement *abs){
    string name;
    cout << "请输入要删除的联系人姓名：";
    cin >> name;
    int index = isExist(abs,name);
    if(index==-1){
        cout << "查无此人" << endl;
    } else {
        for(int i=index; i<abs->m_Size; i++){
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }

    cout << "任意键返回菜单" << endl;
    getchar();getchar();
    system("reset");
}

// 4. 查找联系人
void findPerson(msgManagement *abs){
    string name;
    cout << "请输入您要查找的联系人: ";
    cin >> name;

    int index = isExist(abs, name);

    if (index==-1){
        cout << "查无此人" << endl;
    } else {
        cout << "姓名: " << abs->personArray[index].m_Name << '\t'
             << "性别: " << abs->personArray[index].m_Gender << '\t'
             << "年龄: " << abs->personArray[index].m_Age << '\t'
             << "电话: " << abs->personArray[index].m_Phone << endl;
    }

    cout << "任意键返回菜单" << endl;
    getchar();getchar();
    system("reset");
}

// 5. 修改联系人
void modifyPerson(msgManagement *abs){
    string name;
    cout << "请输入要修改的联系人姓名：";
    cin >> name;

    int index = isExist(abs, name);
    if (index==-1) cout << "查无此人" << endl;
    else {
        string name;
        cout << "请输入姓名：";
        cin >> name;
        abs->personArray[index].m_Name = name;

        int gender;
        cout << "请输入性别(1.男，2.女)：";
        
        while(cin >> gender){
            if (gender==1 || gender==2){
                abs->personArray[index].m_Gender = gender;
                break;
            } else {
                cout << "请输入合法数字(1.男，2.女)：";
            }
        }

        int age;
        cout << "请输入年龄：";
        
        while (cin >> age){
            if(age>-1 && age < 150){
                abs->personArray[index].m_Age = age;
                break;
            } else {
                cout << "请输入合法数字：";
            }
        }

        string phone;
        cout << "请输入电话：";
        cin >> phone;
        abs->personArray[index].m_Phone = phone;
        
        cout << "任意键返回菜单" << endl;
        getchar();getchar();
        system("reset");

    }
}

// 6. 清空联系人
void clearPerson(msgManagement *abs){
    cout << "是否真的要清空？(1-是，2-否)：";
    int clear;
    cin >> clear;
    if (clear==1){
        abs->m_Size = 0;
        cout << "通讯录已清空" << endl;
    }
    
    // 按任意键清屏
    cout << "任意键返回菜单" << endl;
    getchar();getchar();
    system("reset");
}

int main(int argc, char const *argv[])

{

    // 创建通讯录结构体变量
    msgManagement abs;

    cout << abs.m_Size << endl;

    //创建用户选择输入的变量
    int select = 0;

    while(1){
        // 菜单调用
        showMenu();

        cin >> select;

        // 0 - exit, others - loop
        switch (select){

        case 1:
            // 1. 添加联系人
            addPerson(&abs); //利用地址传递，可以修改实参
            break;
        case 2:
            // 2. 显示联系人
            showPerson(&abs); 
            break;

        case 3:
            // 3. 删除联系人
            deletePerson(&abs);
            break;
        case 4:
            // 4. 查找联系人
            findPerson(&abs);
            break;
        case 5:
            // 5. 修改联系人
            modifyPerson(&abs);
            break;
        case 6:
            // 6. 清空联系人
            clearPerson(&abs);
            break;
        case 0:
            // 0. 退出通讯录
            cout << "Thanks for using our software! See you soon!" << endl;
            return 0;
            break;

        default:

            break;

        }



    }

    return 0;

}

