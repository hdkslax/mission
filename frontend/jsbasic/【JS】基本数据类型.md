# 基本数据类型
### String 

任意字符串

### Number

任意数值

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

true / false

### Null 空值

Null类型的值只有一个，就是null

`null`这个值专门用来表示一个空对象

`typeof null` 返回object

### Undefined 未定义

当声明一个变量，但并不给变量赋值时，就是`undefined`. 


# 引用数据类型
### Object 

任意对象

```js
var obj = {}
```

<a href = "【JS】对象.md"> 【JS】对象 </a>

### Function

一种特别的对象，可以执行

```js
function test() {
    var a = 3;
}
```

### Array

一种特别的对象（数值下标，内部数据有序）

普通对象内部无序，但对象内部有序。

```js
var arr = [3, 'abc'];
arr[1];
```



### 检查类型

`typeof variableName`; 

- 返回数据类型的字符串表达
- 可以判断：undefined, 数值, 字符串, 布尔值, function
- 不能判断：null与object, object与array

`instanceof`

- 用来判断具体类型

```js
var b1 = {
    b2: [1, "abc", console.log],
    b3: function () {
        console.log("b3");
    }
}

console.log(b1 instanceof Object, b1 instanceof Array); // true false
console.log(b1.b2 instanceof Array, b1.b2 instanceof Object); // true true
console.log(b1.b3 instanceof Function, b1.b3 instanceof Object); // true true
```



`===` 可以判断 undefined 和 null

```js
var a;
console.log(a); // undefined
console.log(typeof a); // "undefined"
console.log((typeof a)==="undefined"); // true
console.log(a===undefined); // true
```



### 实例

- 实例：实力对象
- 类型：类型对象

```js
function Person(name, age) { // 构造函数，类型
    this.name = name;
    this.age = age;
}

var p = new Person("tom", 12); // 根据类型创建的实例对象
Person("tom", 12); // 语法上合法，原则上说不可以
```



### undefined 和 null 的区别？

- undefined - 定义未赋值
- null - 定义赋值了，但值为null

```js
var a;
console.log(a); // undefined
a = null;
console.log(a); // null
```



### 什么时候给变量赋值为null？

- 对象值未知时

  ```js
  var obj = null; // 初始赋值，将要赋值为对象
  ```

- 最后释放内存空间

  ```js
  b = null; // 让b指向的对象称为垃圾对象（被垃圾回收器回收）
  ```



### 严格区分变量类型与数据类型

- 数据的类型
  - 基本类型
  - 对象类型
- 变量的类型 - 变量内存值的类型
  - 基本类型 - 保存的就是基本类型的数据
  - 引用类型 - 保存的是地址值

```js
var c = {};
// 等号右边是对象
// c保存的是地址值，指向右边对象
typeof c; // 'function'
// typeof找到c之后，再去找它指向的地址，然后才知道是个'function'
```

