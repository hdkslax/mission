# [C]常量

常量表达式在编译时求值，而不在运行时求值。

### long

`long`类型的常量以字母`l`或`L`结尾

```c
long number = 123456789L;
```

### unsigned

无符号常量以字母`u`或`U`结尾

后缀`ul`或`UL`表明是`unsigned long`类型

### 浮点数

- 小数点: `123.4`

- 指数: `le-2`

- 或两者都有

- 没有后缀的浮点数常量为`double`类型
- 后缀`f`或`F`表示`float`类型
- 后缀`l`或`L`表示`long double`类型

#### 整数的进制

- 前缀`0` - 八进制
- 前缀`0x`或`0X` - 十六进制
- 八进制和十六进制的常量可以使用后缀`L`表示`long`类型
- 八进制和十六进制的产钢可以使用后缀`U`表示`unsigned`类型

### 转义字符

- `\ooo`表示任意的字节大小的位模式
  - `ooo`代表1~3个八进制数字
- `\xhh`表示任意的字节大小的十六进制数字
  - `hh`是一个或多个十六进制数字

```c
#define VTAB '\013' // ASCII vertical tab
#define BELL '\007' // ASCII bell character
#define VTAB '\xb'
#define BELL '\x7'
```

###### C语言中全部转义字符

```
\0 空字符null, 值为0的字符
\a 响铃符
\b 回退符
\f 换页符 
\n 换行符 
\r 回车符 
\t 横向制表符 
\v 纵向制表符
\\ 反斜杠
\? 问号
\' 单引号
\" 双引号
\ooo 八进制数
\xhh 十六进制数
```

