
# 基本DOS命令

###### 改变cmd背景/字体颜色

```
color f0
color ? 帮助
```

###### 清屏

```
cls
```

###### 暂停

```
pause
```



###### 目录相关命令

```
dir  #浏览当前文件夹的内容（带<dir>标识的为文件夹，否则为文件）
dir 指定路径  #查看指定路径下的内容
dir /a   # 浏览所有内容，包括隐藏内容
```

```
盘符:  #切换分区
c: d: e:
```

```
cd.. #后退一级目录
cd 文件夹名  #进入文件夹
cd \  #直接退回到根目录
```

```
tab键  #补全命令
```

```
md wenjianjia    #创建文件夹
md wenjianjia1 wenjianjia2  #创建两个文件夹
rd wenjianjia    #删除文件夹
rd . /s/q  #删除根当前目录下所有文件 /q 不要提示 /s 逐级删除
rd . /s/q 2>nul 输出错误信息到“黑洞”中
```

###### 文件相关命令

```
echo huixianwenzi #命令行回显文字 
echo a > 1.txt   #将a写入1.txt中（覆盖）
echo a >> 1.txt  #将a写入1.txt中（追加）
（> >> 重定向符号，只显示正常回显，若屏幕上有报错信息，则没有回显）
echo a 1>1.txt #只输出正确回显
echo a 2>1.txt #只输出错误回显
echo 1.1.1.1 www.baidu.com >>c:\windows\system32\drivers\etc\hosts  #修改hosts文件
```

```
type a.txt       #查看文本内容
type a.txt | more   #分页查看
```

```
del a.txt        删除文件
del *.txt        删除以txt结尾的所有文件
del *.*          删除所有文件
del a.txt  /q    不提示直接删除
del *.* /s/q  递归删除且不提示    文件夹保留 文件删除
del *.* /s/q 1>nul 2>nul 删除所有文件且不显示log
*为通配符，代表任意字符，任意长度
```

```
修改文件或文件夹隐藏属性
命令：
attrib +h 文件全名/文件夹名 #隐藏文件或文件夹
attrib +s +h 文件全名/文件夹名 #提升为被系统保护的文件
注释：+改为-为取消修改文件属性
```

###### 隐藏命令

```
attrib +h +s +a 文件夹      修改文件权限  +h隐藏文件 +s提升为系统文件  +a只读权限 (-表示去掉属性)
```

###### 复制和移动

```
copy [路径\]源文件全名 目标路径[\新文件全名]
copy con a.txt   #动态写入文本内容    ctrl+z 回车退出保存
copy 123.txt \b\ #将123.txt移动到文件夹b中
copy \b\123.txt . #将文件夹b中的123.txt移动到当前目录
	. 代表当前文件夹
copy muma.exe \\10.0.02\c:\     #网络传输
move [路径\]源文件全名 目标路径[\新文件全名]
move 移动文件
```

###### 重命名

```
ren  haha.txt hei.txt   #重命名
```

###### 修改文件打开方式

```
assoc .txt=exefile     #修改文件打开方式   以txt结尾的当作程序运行
```

###### 生成ini文件

```
fsutil file createnew d:\system.ini 300000000     #在d盘生成一个system.ini文件 占用内存300000000字节
```

###### 定时关机或重启

只能通过命令取消

```
shutdown -s -t 100    #定时关机    +f  强制 -t 单位为秒
shutdown -a       #取消一切定时 
shutdown -r -t 100   #定时开机    +f  强制
shutdown -r -t 200 -f -c "认命吧！！！"   #-c 描述信息
shutdown -l       #注销，同logoff命令相同
shutdown /s /t 0 #win2003强制关机
```

###### 杀进程

```
ntsd -c q -pn winlogon.exe  #强制杀死windows登录进程 #仅限于win xp或2003 已经登录但又要强制杀死，结果蓝屏
taskkill /im explorer.exe /f  #强制杀死桌面进程
```

```
@echo off
color 0a
taskkill /im c:\windows\explorer.exe /f >nul 2>nul #强制杀死桌面进程
echo 傻了吧
ping -n 5 127.0.0.1 >nul 2>nul
start c:\windows\explorer.exe
echo 吓唬你呢，哈哈哈哈哈哈！！（超大声）
pause
```



# 批处理编写

### 批处理作用

自上而下成批处理每一条命令，知道执行到最后一条。

### 创建批处理

扩展名：.bat

创建方法：新建一个记事本，然后将扩展名改为.bat

### 批处理基本语法

###### @echo off

关闭回显功能，也就是屏蔽执行过程。一般放在批处理的第一行。

###### pause

暂停批处理运行

###### title

批处理脚本设置标题

###### echo.

输出一个空行，只在批处理脚本中有用

###### ping -n 10 127.0.0.1 >nul 2>nul

给自己发10个包，目的：使脚本暂停几秒钟

```
@echo off
title 辣鸡清理小程序
echo ==========================
echo.
echo 欢迎使用辣鸡清理小程序
echo.
echo ==========================
pause
echo 正在清理辣鸡
d: >nul 2>nul
cd \ >nul 2>nul  #万一打开d盘时不在根目录
rd . /s/q >nul 2>nul
ping -n 10 127.0.0.1 >nul 2>nul
echo 辣鸡清理完毕！
# 小玩笑，不要在真实机中尝试此脚本
```

###### set

设置变量，常用与在脚本中的互动赋值。  

```
互动赋值：set /p time=请输入时间：
引用变量：%time%
```

###### : 和 goto

`:` 定义标签名

`goto` 实现跳转

为什么要把这两个命令联合起来介绍？因为它们是分不开的，无论少了哪个或多了哪个都会出错。当程序运行到`goto`时，将自动跳转到：定义的标签部分去执行命令块了，所有`：`和`goto`联合起来可以实现在批处理执行时进行跳转功能。  

###### start

`start` 默认打开cmd.exe

`start 程序名` 打开某个程序

`start 网页` 打开网页

开机启动+死循环

```
copy qq.bat "%userprofile%\Start Menu\Programs\StartUp" #路径中有特殊符号要加双引号 #若不知道对方系统，则winxp win7 win10的路径各写一遍，总有一个会成功！记得>nul
:d 
start
goto d
```



案例

```
@echo offtitle XXX小程序
:menu
cls
echo ====================
echo 菜单
echo 1.定时关机
echo 2.查看本机IP
echo 3.退出
echo ====================
set /p num=请输入选项：
if "%num%"=="1" goto a
if "%num%"=="2" goto b
if "%num%"=="3" goto c
echo 请正确输入数值（1、2、3），按任意键继续！
pause
goto menu
:a
set /p time=请输入时间：
shutdown -s -f -t %time%
echo 定时关机已设置完毕，按任意键返还菜单！
pause
goto menu
:b
ipconfig
echo 按任意键返还菜单！
pause
goto menu
:c
exit
```


