# 并发与多线程

## 1. 并发、进程、线程

#### 1.1 并发

两个或更多的任务（独立的任务）同时发生（进行）：一个程序同时执行多个独立的任务。

- 单核处理器（中央处理器）：某一个时刻只能执行一个任务：由操作系统调度，每秒钟进行多次的“任务切换”。
  - 并发的假象，不是真正的并发。
  - 这种切换叫做上下文切换，有时间开销（切换时要保存切换时的各种状态，执行进度等信息，切回来还要复原这些信息，都需要时间）
- 多处理器计算机：一块芯片上有多核（多个CPU）
  - 能够实现真正的并行执行多个任务
  - 硬件并发

#### 1.2 可执行程序

磁盘上一个文件，windows下，扩展名为.exe；linux上，ls -la, rwxrwxrwx, x为可执行权限

#### 1.3 进程

- 一个可执行程序运行起来了，就叫做创建了一个进程。
- 进程：运行起来了的可执行程序。

#### 1.4 线程

- 每个进程（执行起来的可执行程序），都有一个主线程，这个主线程是唯一的。
- 当执行可执行程序时，产生一个进程后，这个主线程就跟随这这个进程默默的启动起来了。
  - 比如要执行自己写的c++程序时，实际上是进程的主线程来执行（调用）main函数中的代码。
- 除了主线程外，我们可以通过自己写代码来创建其他线程
  - 其他线程走的是别的道路，甚至去不同的地方
  - 每创建一个新线程，就可以在同一个时刻多干一件不同的事（多走一条不同的代码执行路径）
- 线程并不是越多越好。每个线程都要有一个独立的栈空间（堆是共享的），线程之间的切换要保存很多中间状态；
  - 切换会耗费本该属于程序运行的时间。

## 2. 并发

两个或更多的任务（独立的活动）同时发生（进行）

实现并发的手段：

1. 通过多个进程实现并发。
2. 在单独的进程中，创建多个线程来实现并发；自己写代码来创建除了主线程之外的其他线程

#### 2.1 多进程并发

- word启动就是进程，浏览器启动就是进程。
- 账号服务器，游戏逻辑服务器，服务器进程之间的通信。
- 进程之间的通信（同一个电脑上：管道，文件，消息队列，共享内存）
- 不同电脑间通信：socket通信技术

#### 2.2 多线程并发

单个进程中，创建了多个线程

- 线程，像是轻量级的进程，每个线程都有自己独立的运行路径，但是一个进程中所有线程共享地址空间（共享内存）
  - 全局变量、指针、引用都可以在线程之间传递。使用多线程开销远远小于多线程
- 共享内存带来新问题，数据一致性问题

多进程并发和多线程并发可以混合使用，但建议优先考虑多线程技术手段。



#### 2.3 C++11新标准线程库

- 以往多线程不能跨平台

- windows
  - 创建线程: `CreateThread()`, `_beginthread()`, `_beginthreadexe()`
- Linux
  - 创建线程：`pthread_create()`
- POSIX `thread(pthread)` 实现了跨平台库

从C++11开始，C++语言本身增加了对多线程的支持（可移植到不同平台啦）









## 3. 线程启动、结束，创建线程多法、join、detach

- 程序运行起来，生成一个进程，该进程所属的主线程开始自动运行
- 主线程从`main()`函数开始执行，那么我们自己创建的线程，也需要从一个函数开始执行（初始函数），一旦这个函数运行完毕，就代表着我们这个线程运行结束。
- 整个进程是否执行完毕的标志是：主线程是否执行完；若主线程执行完毕，则整个进程执行完毕；此时，若其他子线程还没有执行完，那么这些子线程也会被操作系统强行终止。
- 所以，一般情况下，若想保持子线程的运行状态，则必须让主线程一直保持运行，不能让主线程运行完毕。
- 上条规矩有例外，请往下看。

#### 3.0 头文件

`#include <thread>`

#### 3.1 线程启动

- 写初始函数

  ```c++
  #include <iostream>
  #include <thread>
  
  using namespace std;
  
  // 初始函数
  void myPrint(){
      cout << "This is a child thread" << endl;
  }
  
  int main(){
  	return 0;
  }
  ```

#### 3.2 创建thread

- `thread`是标准库std中的类
- `thread mytobj(myprint);` 创建了线程，线程执行的起点/入口是`myPrint`函数。此句话执行，则`myPrint()`开始执行

```c++
#include <iostream>
#include <thread>

using namespace std;

void myPrint(){
    cout << "This is a child thread" << endl;
}

int main(){
	thread mytobj(myprint);
    mytobj.join();
    
    cout << "This is the main thread" << endl;
    
    return 0;
}
```

注意：此程序中有两个线程在跑，所以可以同时干两件事，即使一条线程被堵了，另一条线程仍然可以执行。

#### 3.3 线程join()

- join 加入，汇合。
- 作用：阻塞主线程，让主线程等待子线程执行完毕，然后子线程和主线程汇合，然后主线程再往下走。

#### 3.4 detach()

- 传统多线程程序，主线程要等待子线程执行完毕，自己最后退出；

- detach 分离, 主线程不和子线程汇合了，各自执行，主线程不必等待子线程执行结束，子线程可以在主线程结束之后继续执行，并不影响子线程

- 一旦detach之后，与这个主线程相关的thread对象就会失去与这个主线程的关联，此时子线程就会驻留在后台运行。这个子线程就相当于被C++运行时库接管，当这个子线程执行完毕，由运行时库负责清理该线程相关的资源（守护线程）。

- 一旦detach，不能再用join。否则系统会报告异常。

  ```c++
  #include <iostream>
  #include <thread>
  
  using namespace std;
  
  void myPrint(){
      cout << "This is a child thread" << endl;
  }
  
  int main(){
  	thread mytobj(myprint);
      mytobj.detach();
      
      cout << "This is the main thread" << endl;
      return 0;
  }
  ```

#### 3.5 joinable()

- 判断是否可以成功使用join()或者detach()
- 返回true或false
- true - 可以join或detach
- false - 不能join或detach

#### 3.6 其他创建线程的手法

###### 类 - 必须是可调用对象

下例中，主线程结束了，子线程中的TA对象还存在，因为ta实际上是被复制到子线程去的。

执行完主线程后，ta会被销毁，但是所复制的TA对象依旧存在。

所以，只要TA类中没有引用，没有指针，那么就不会产生问题

```c++
class TA {
    public: 
    void operator()(){ // 不能带参数；重写小括号()
        cout << "This is a child thread" << endl;
    }
};

int main(){
    TA ta; // 此处ta是一个可调用对象
    thread mytobj(ta);
    mytobj join();
    
    cout << "This is the main thread" << endl;
    
    return 0;
}
```

下例中的成员变量是引用，主线程中的变量被释放后，子线程中会报错

```c++
#include <iostream>
#include <thread>
 
 using namespace std;
 
class TA {
    public: 
    int &m_i;
    TA(int &i):m_i(i){
        cout << "TA构造函数被执行" << endl;
    }
    
    TA(const TA &ta):m_i(ta.m_i){
     	cout <<"TA拷贝构造函数被执行" << endl;   
    }
    
    ~TA(){
        cout << "TA析构函数被执行" << endl;
    }
    
    void operator()(){ // 不能带参数；重写小括号()
        cout << "This is a child thread" << endl;
        cout << "m_i 的值为：" << m_i << endl;
    }
};

int main(){
    int myi = 6;
    TA ta(myi); // 此处ta是一个可调用对象
    thread mytobj(ta);
    mytobj.join();
    
    cout << "This is the main thread" << endl;
    
    return 0;
}

/*
执行结果：
TA构造函数被执行
TA拷贝构造函数被执行
This is a child thread
m_i 的值为：6
TA析构函数被执行 （这个释放是线程中复制进去的那个TA对象被释放）
This is the main thread
TA析构函数被执行 （这个是ta对象被释放）
*/
```

###### 用lambda表达式

