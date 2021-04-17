## 重要目录

#### “启动”文件夹 - 开机即启动的程序

X:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp*(注：X为Win10系统盘盘符)

#### Windows - 系统安装目录

* System32 - 系统配置文件
  * config/SAM - 存放用户密码

#### PerfLogs - 系统日志文件

## 服务

* 服务是一种应用程序类型，它在后台运行。服务应用程序通常可以在本地和通过网络为用户提供一些功能，例如客户端/服务器应用程序、Web服务器、数据库服务器以及其他基于服务器的应用程序。

#### 打开服务

* 右键我的电脑打开“计算机管理”
* ctrl+r打开运行，输入services.msc回车打开

#### 服务的作用

* 服务决定了计算机的一些功能是否被启用
* 不同的服务器对应的功能不同
* 通过计算机提供的服务可以有效实现资源共享

#### 常见的服务

* web服务
* dns服务 - 为计算机解析域名，解析出来一个IP
* dhcp服务 - 给客户端分发IP地址
* 邮件服务 SMTP
* telnet服务 - 打开即允许远程连接， 一般别开
* ssh服务
* ftp服务 - 上传下载
* smb服务 - 文件共享
  * 若一台计算机共享了某个文件(夹)，通过在“运行”中输入\\对方IP地址，然后需要输入网络密码

## 端口

* 计算机“端口”是英文port的义译，可以认为是计算机与外界通讯交流的出口。
* 端口号：0~65535
* 按端口号可分为3大类：
  * 公认端口(Well Known Ports)；
  * 注册端口(Registered Ports)；
  * 动态和/或私有端口(Dynamic and/or Private Ports)；

#### 端口的作用

* 我们知道，一台拥有IP地址的主机可以提供雨多服务，比如web服务、ftp服务、SMTP服务等，这些服务完全可以通过一个IP地址来实现。那么，主机是怎样区别不同的网络服务呢？显然不是只靠IP地址，因为IP地址与网络服务的关系是一对多的关系。实际上是通过“IP地址+端口号”来区分不同的服务的。
* 需要注意的是，端口并不是一一对应的。比如你的电脑作为客户机访问一台WWW服务器时，WWW服务器使用“80”端口与你的电脑通信，但你的电脑则可能使用“3457”这样的端口。

#### 常见的端口

* HTTP协议代理服务器常用端口号：80/8080/3128/8081/9080
* FTP（文件传输）协议代理服务器常用端口号：21
* Telnet（远程登录）协议代理服务器常用端口：23
* TFTP（Trivial File Transfer Protocol），默认的端口号为69/udp;
* SSH（安全登录）、SCP（文件传输）、端口重定向，默认的端口号为25/tcp(木马Antigen、Email、Password Sender、Haebu Coceda、Shtrilitz Stealth、WinPC、WinSpy都开放这个端口)；
* POP3 Post Office Protocol (E-mail)，默认端口号为110/tcp;
* TOMCAT，默认的端口号为8080；
* WIN2003远程登录，默认端口号为3389；
* Oracle数据库，默认的端口号为1521；
* MS SQL*SERVER数据库server，默认的端口号为1433/tcp 1433/udp;
* QQ，默认的端口号为1080/udp

#### 黑客通过端口可以干什么？

* 信息搜集
* 目标探测
* 服务判断
* 系统判断 - 有些服务只有windows上有，有些只有linux上，通过看开放了哪个端口来判断哪个系统
* 系统角色分析

## 注册表 - 电脑的经络

* 注册表(Registry, 繁体中文版Windows称之为登录档)是Microsoft Windows中的一个重要的数据库，用于存储系统和应用程序的设置信息。
* 早在Windows 3.0推出OLE技术的时候，注册表就已经出现。
* 随后推出的Windows NT是第一个从系统级别广泛使用注册表的操作系统。
* 但是，从Microsoft Windows 95开始，注册表才真正成为Windows用户经常接触的内容，并在其后的操作系统中继续沿用至今。

* 通过改注册表，可以改电脑中的所有东西！！！
* 类似于神经中枢，可以渗透到身体的任何部位。

#### 打开注册表

运行 → regedit

#### 注册表的作用

* 注册表是windows操作系统中的一个核心数据库，其中存放着各种参数，直接控制着windows的启动、硬件驱动程序的装载以及一些windows应用程序的运行，从而在整个系统中起着核心作用。
* 这些作用包括了软、硬件的相关配置和状态信息，比如注册表中保存有应用程序和资源管理器外壳的初始条件、首选项和卸载数据等，联网计算机的整个系统的设置和各种许可，文件扩展名与应用程序的关联，硬件部分的描述、状态和属性，性能记录和其他底层的系统状态信息，以及其他数据等。

#### 注册表结构

1. HKEY_CLASSES_ROOT

   管理文件系统。根据在Windows中安装的应用程序的扩展名，该根键致命其文件类型的名称，相应打开该文件索要调用的程序等等信息。

2. HKEY_CURRENT_USER

   管理系统当前的用户信息。在这个根键中保存了本地计算机中存放的当前登录的用户信息，包括用户登录用户名和暂存的密码。在用户登录Windows 98时，其信息从HKEY_USERS中相应拷贝到HKEY_CURRENT_USER中。

3. HKEY_LOCAL_MACHINE

   管理当前系统硬件配置。在这个根键中保存了本地计算机硬件配置数据，此根键下的子关键字包括SYSTEM.DAT中，用来提供HKEY_LOCAL_MECHINE所需的信息，或者在远程计算机中可访问一组键中。

   这个根键里面许多子键与System.ini文件中设置项类似。

4. HKEY_USERS

   管理系统的用户信息。在这个根键中保存了存放在本地计算机口令列表中的用户标识和密码列表，同时每个用户的预配置信息都存储在HKEY_USERS根键中。HKEY_USERS是远程计算机中访问的根键之一。

5. HKEY_CURRENT_CONFIG

   管理当前用户的系统配置。在这个根键中保存着定义当前用户桌面配置（如显示器等等）的数据，该用户使用过的文档列表（MRU），应用程序配置和其他有关当前用户的Windows 98中文版的安装的信息。

#### 利用注册表防病毒

* 不少计算机系统感染了网络病毒后，可能会在这些注册表中做修改
  * HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce
  * HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
  * HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunServices
* 病毒经常修改的注册表键值
  * IE起始页的修改：HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Main 右半部分窗口中的Start Page就是IE主页地址了
  * Internet选项按钮灰化&失效：HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Control Panel 下的SWORD值“Setting”=dword:1 "links"=dword:1 "SecAddSites" dword: 1 全部改为0后，再将HKEY_USERS\DEFAULT\Software\Policies\Microsoft\Internet Explorer\Control Panel 下的SWORD值 "homepage" 键值改为0，则无法使用“Internet选项”修改IE设置
  * “源文件”项不可用：HKEY_CURRENT_USER\Software\Policies\Microsoft\Internet Explorer\Restrictions的"NoVIewSource"被设置为1了，改为0就可以恢复正常
  * “运行”按钮被取消&失效：HKEY_CURRENT_USER\Software\Microsoft\Windows\Current Version\Policies\Explorer的“NoRun”键值被改为1了，改为0即可恢复
  * “关机”按钮被取消&失效：HKEY_CURRENT_USER\Software\Microsoft\Windows\Current Version\Policies\Explorer的“NoClose”键值被改为1了，改为0即可恢复
  * “注销”按钮被取消&失效：HKEY_CURRENT_USER\Software\Microsoft\Windows\Current Version\Policies\Explorer的“NoLogOff”键值被改为1了，改为0即可恢复
  * 磁盘驱动器被隐藏：HKEY_CURRENT_USER\Software\Microsoft\Windows\Current Version\Policies\Explorer的“NoDrives”键值被改为1了，改为0即可恢复

#### 入侵种常用的注册表

* HKEY_LOCAL_MACHINE\software\hzhost\config\settings\mysqlpass
* HKEY_LOCAL_MACHINE\software\hzhost\config\settings\mssqlpss
* HKEY_LOCAL_MACHINE\software\hzhost\config\Settings\mastersvrpass
* HKEY_LOCAL_MACHINE\SYSTEM\LIWEIWENSOFT\INSTALLFREEADMIN\11
* HKEY_LOCAL_MACHINE\SYSTEM\LIWEIWENSOFT\INSTALLFreeHost\11

## 黑客常用的DOS命令

* color 改变cmd颜色

* ping -t -l 65550 ip 死亡之ping（发送大于64K的文件并一直ping就成了死亡之ping）

  * TTL值：跳转路由的数量
    * 低于68：Linux、win7、win8、NT6.0的内核（每经过一个路由 TTL值-1，比如现在是53，就经过了64-53=11个路由）
    * 128：Windows XP、2003
  * -t ：不停的ping指定的计算机，直到按下Ctrl+C中断。
  * -a ：将地址解析为计算机NetBios名。
  * -n ：发送count指定的ECHO数据包数。通过这个命令可以自己定义发送的个数，对衡量网络速度很有帮助。能够测试发送数据包的返回平均时间，及时间的快慢程度。默认值为 4。
  * -l ：发送指定数据量的ECHO数据包。默认为 32 字节；最大值是65500byt。
  * -f ：在数据包中发送“不要分段”标志,数据包就不会被路由上的网关分段。通常你所发送的数据包都会通过路由分段再发送给对方，加上此参数以后路由就不会再分段处理。
  * -i ：将“生存时间”字段设置为TTL指定的值。指定TTL值在对方的系统里停留的时间。同时检查网络运转情况的。
  * -v ：tos 将“服务类型”字段设置为 tos 指定的值。
  * -r ：在“记录路由”字段中记录传出和返回数据包的路由。通常情况下，发送的数据包是通过一系列路由才到达目标地址的，通过此参数可以设定，想探测经过路由的个数。限定能跟踪到9个路由。
  * -s ：指定 count 指定的跃点数的时间戳。与参数-r差不多，但此参数不记录数据包返回所经过的路由，最多只记录4个。
  * -j ：利用 computer-list 指定的计算机列表路由数据包。连续计算机可以被中间网关分隔(路由稀疏源) IP 允许的最大数量为 9。
  * -k ：computer-list 利用 computer-list 指定的计算机列表路由数据包。连续计算机不能被中间网关分隔(路由严格源)IP 允许的最大数量为 9。
  * -w：timeout 指定超时间隔，单位为毫秒。

* ipconfig 查看ip

* ipconfig/release 释放ip

  * Linux：dhclient eth0

* ipconfig/renew 重新获得ip

* systeminfo 查看系统信息

* arp -a 查看

* net view 查看局域网内其他计算机名称

* shutdown -s -t 180 -c "你被黑了，系统马上关机"

  * ```
    -f：强行关闭应用程序
    -m：\\计算机名：控制远程计算机
    -i：显示图形用户界面，但-i必须是Shutdown的第一个选项
    -l：注销当前用户
    -r：关机并重启
    -t：时间：设置关机倒计时
    -c："消息内容"：输入关机对话框中的消息内容（不能超127个字符）
    -a：取消系统关机
    -s：关闭计算机
    ```

  * 180 = 180ms

* dir 查看目录

* cd 切换目录

* start www.google.com 打开网页

* start 123.txt 打开123.txt文件

* copy con c:\123.txt 创建123.txt文件

  * 写东西进123.txt
  * ctrl+z 回车
  * 再次打开 type 123

* md 目录名 创建目录

* rd 123 删除文件夹123

* ren 原文件名 新文件名 重命名文件名

* del 删除文件

* copy 复制文件

* move 移动文件

* tree 树形列出文件夹结构

* telnet 

* net use k:\\192.168.1.1\c$   把192.168.1.1这台电脑的c盘拿过来当做我的k盘

* net use k:\\192.168.1.1\c$/del

* net start 查看开启了那些服务

* net start 服务名 开启服务；(eg. net start telnet, net start schedule)

* net stop 服务名 停止某服务

* net user 用户名 密码 /add建立用户

* net user guest /active:yes 激活guest用户

* net user 查看有那些用户

* net user 账户名 查看账户的属性

* net locaLGroup administrators 用户名 /add 把“用户”添加到管理员中使其具有管理员权限，注意：administrator后加s用复数

* net user guest 12345 用guest用户登录后将密码改为12345

* net password 密码 更改系统登录密码

* net share 查看本地开启的共享

* net share ipc$  开启ipc\$共享

* net share ipc$ /del 删除ipc\$共享

* net share c$ /del 删除C：共享