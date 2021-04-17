# 函数
 - 函数也是个对象。
 - 函数中可以封装一些功能（代码），在需要是可以执行这些功能（代码）
 - 使用typeof检查一个函数对象时，会返回function
 
# 创建一个函数对象
### 1. 将要封装的代码以字符串的形式传递给构造函数
（在实际开发中很少使用构造函数来创建函数对象）
```
var fun = new Function("console.log('Hello');");
```
- 封装在函数中的代码不会立即执行
- 函数中的代码会在函数调用时执行
- 调用函数 语法：函数对象()
- 当调用函数时，函数中封装的代码会按照顺序执行
```
fun();
```
### 2. 使用函数声明来创建函数
语法：
```
function 函数名([形参1，形参2， ... , 形参N]){
	语句 ...
}
```
```
function fun2(){
	console.log("hello");
}
```
### 3. 使用函数表达式来创建函数
匿名函数
语法： 
```
var fun3 = function() {
	console.log(“test”);
};
```
创建了一个匿名函数，并将匿名函数的对象赋值给一个变量`fun3`
调用：
```
fun3();
```

# 参数
```
function sum(a,b) {
	console.log(a+b);
}

//调用
sum(1,2);
```
形参：在函数定义时
实参：在函数调用时

注意：
 - 在函数函数时，解析器不会检查实参的数据类型
 	- 所以要注意，是否有可能会接收到非法的参数，若有可能则需要对参数进行类型的检查。
 - 在调用函数时，解析器不会检查实参的数量
 	- 多余实参不会被赋值
 	- 少了会出错，没有对应实参的形参将会被赋值undefined
 - 实参可以是任意数据类型

#### 实参可以是任意类型
实参可以是任意类型，也可以是一个对象
 - 当参数过多时，可以将参数封装到一个对象中，然后通过对象传递
 - 参数也可以是函数
 	```javascript
 	var o = "Hello";
 	function sayHello(o){
		console.log(o);
	}
 	function fun(a) {
 		console.log("a = " + a);
 	}
 	fun(sayHello);
 	```
 	输出结果为：
 	```javascript
	a = function sayHello(o){
				console.log(o);
			}
	```
	这里还可以这么写：
	```javascript
 	function sayHello(o){
		a(“Hello”)
	}
 	function fun(a) {
 		console.log("a = " + a);
 	}
 	fun(sayHello);
 	```
 	此处调用a()和调用sayHello()是一样的

### 返回值可以是任意数据类型
也可以是对象

### 在函数内部可以声明/创建函数
```
funciton fun3(){
	function fun4(){
		alert(“This is fun4”);
	}
}
```
