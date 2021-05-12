## call, apply
- 两个都是函数对象的方法

- 当对函数调用`call()`和`apply()`的时候，都会调用函数执行

- 在调用call和apply时，可以将一个对象指定为第一个参数，此时这个对象将会成为函数执行时的this

```javascript
function fun() {
    alert(this);//object Window
}

var obj = {name:"obj"};
var obj2 = {name:"obj2"};
fun.call(obj.name); // obj
fun.apply(obj2.name); // obj2
```

- call()方法可以将实参在对象之后依次传递
- apply()方法需要将实参封装到一个数组中统一传递

```javascript
function fun(a, b) {
    console.log("a" + a);
    console.log("b" + b);
}
var obj = {name:"obj"};
var obj2 = {name:"obj2"};
fun.call(obj, 2, 3); // a=2,b=3
fun.apply(obj, 2, 3); // 报错，Arguments list has wrong type
fun.apply(obj,[2,3]);
```

- this的情况：
  1. 以函数形式调用时，this永远都是window
  2. 以方法形式调用时，this是调用方法的对象
  3. 以构造函数的形式调用时，this是新创建的那个对象
  4. 用call和apply调用时，this是指定的那个对象



