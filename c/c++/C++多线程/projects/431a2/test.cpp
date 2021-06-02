#include <iostream>
#include <ctime>
#include <vector>
#include <thread>
#include <atomic>
 
using namespace std;
 


int main(){
    
    auto mylamthread = [] {
        cout << "This is a child thread" << endl;
    };

    thread mytobj(mylamthread);
    mytobj.join();
    
    cout << "This is the main thread" << endl;
    
    return 0;
}