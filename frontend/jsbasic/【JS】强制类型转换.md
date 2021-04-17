#### 其他类型 -> String

###### 调用被转换数据类型的toString()方法

```
var a = 123;
a.toString();
```

该方法不会影响原变量，但会返回String类型

想要将原变量转换类型：

```
var a = 123;
a = a.toString();
```

`null`, `undefined` 没有`toString()`方法，调用会报错

###### String() 函数

```
var a = 123;
a = String(a);
```

`null` `undefined` 可以用



#### 其他类型 -> Number

###### Number() 函数

纯数字字符串：

```
var a = "123";
a = Number(a); 
console.log(typeof a); // number
```

非纯数字字符串：

```
var a = "123abc";
a = Number(a); 
console.log(typeof a); // NaN
```

​	解决方法：调用`parseInt()`函数将a转换为Number，`parseFloat()`提取有效小数

​	注：此方法只能将字符串开头几位数字提取出来，遇到非数字制度则停

​	注：若对非String使用`parseInt()`, 则会先转为String，再操作

```
var a = "123px";
a = parseInt(a); 
console.log(typeof a); // number
console.log(a); // 123
```

空字符串 、空格：

```
var a = "";
a = Number(a); 
console.log(typeof a); // 0
```

Boolean -> 数字：

```
true -> 1
false -> 0
```

null -> 数字：0

undefined -> 数字：NaN

### 其他类型 -> Boolean

###### Boolean() 函数

数字 -> Boolean：除了`0` 和 `NaN`, 都是`true`

```
var a = 123;
a = Boolean(a);
```

String -> Boolean: 除了空串，都是`true`

null, undefined -> false

object -> true
