## 构造函数
创建一个构造函数，专门用来创建Student对象的，构造函数就是一个普通的函数，创建方式和普通函数没有区别，不同的是，构造函数习惯上首字母大写。

构造函数和普通函数的区别就是调用方式的不同：
 - 普通函数：直接调用
 - 构造函数：使用`new`关键字来调用
 
 ### 构造函数的执行流程：
	1. 立即创建一个新的对象
	2. 将新建的对象设置为函数中的this，在构造函数中可以使用this来引用新建的对象
	3. 逐行执行函数中的代码
	4. 将新建的对象作为返回值返回

```javascript
function Student(name, gender, studentNumber){
	this.name = name;
	this.gender = gender;
	this.studentNumber = studentNumber;
	this.sayName = function(){
		alert(this.name);
	};
}
var student1 = new Student("MoQi", "Male", 123456789);
```

使用同一个构造函数创建的对象，称为一类对象，也将一个构造函数称为一个类。
通过一个构造函数创建的对象，称为该类的实例。

使用 `instanceof` 可以检查一个对象是否是一个类的实例
	语法：对象 instanceof 构造函数
若是，则返回true；否，则返回false
```javascript
console.log(student1 instanceof Student);
```
所有对象都是Object的实例，所以任何Object做instanceof检查时都会返回true
```javascript
console.log(dog insteaceof Object); // always true
```

### this的情况
1. 当以函数的形式调用时，this是window
2. 当以方法的形式调用时，谁调用方法this就是谁
3. 当以构造函数的形式调用时，this就是新创建的那个对象

## 构造函数的修改
上述代码中，`sayName`方法是在Student类内部创建的，每个实例在创建时都被添加了一个`sayName`的方法。
也就是说所有实例的`sayName`都是唯一的。
这样就导致了构造函数执行一次就会创建一个新的方法。
执行10000次就创建了10000个方法，而这10000个方法都是一样的！
这是完全没有必要的！
可以使所有对象共享同一个方法：
 - 将`sayName`方法在全局作用域中定义，在构造函数中调用
 ```javascript
 function Student(name, gender, studentNumber){
	this.name = name;
	this.gender = gender;
	this.studentNumber = studentNumber;
	this.sayName = fun;
}
// 将sayName方法定义在全局变量中
function fun(){
		alert(this.name);
};
var student1 = new Student("MoQi", "Male", 123456789);
 ```
但这种方法有个问题：
 - 将函数定义在全局作用域，污染了全局作用域的命名空间
 - 将函数定义在全局作用域不安全

解决方法：<a herf="https://blog.csdn.net/weixin_44782422/article/details/114726172">原型对象</a>
