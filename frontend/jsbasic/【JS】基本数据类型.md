###### 检查类型

typeof variableName;

# 基本数据类型
### String 字符串



### Number数值

###### 最大最小值

`NUmber.MIN_VALUE` 返回最小的正小数

`Number.MAX_VALUE` JS能表示的数字中的最大值

超过这个最大值，则会返回`Infinity`，表示无穷大

###### Infinity

`a = Infinity` 此处`Infinity` 是字面量

`Infinity`

`-Infinity` 

###### NaN

`NaN` 也是number类型，字面量，Not a Number

二进制无法精确表示1/10，所以各个语言都会报错。

JS的浮点运算可能会得到一个不精确的结果。

###### 十六进制

```
var a = 0x10;
```

###### 八进制

```
var a = 070; // 0开头
```

###### 二进制

```
var a = 0b10; //0b开头
```

注：像`070`这样的数字，有的浏览器当做八进制处理，有的当做十进制处理

解决方法：在`parseInt()`中传递第二个参数，来指定数字的进制

```
var a = 070; 
a = parseInt(a,10); // 十进制
a = parseInt(a,8); // 八进制
```



### Boolean 布尔值



### Null 空值

Null类型的值只有一个，就是null

`null`这个值专门用来表示一个空对象

`typeof null` 返回object

### Undefined 未定义

当声明一个变量，但并不给变量赋值时，就是`undefined`. 


# 引用数据类型
### Object 对象
<a href = "https://blog.csdn.net/weixin_44782422/article/details/114699017"> 【JS】对象 </a>
