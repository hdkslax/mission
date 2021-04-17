在调用函数时，浏览器每次都会传递进两个隐含的参数
 1. 函数的上下文对象
 2. 封装实参的对象arguments
 	- arguments是一个类数组对象，可通过索引来操作数据，可获得长度
 	- 在调用函数时，所传递的实参都会封装到arguemnts中保存
 	- arguments.length可以用来获取实参的长度
 	- 即使不定义形参，也可以通过arguments来使用实参
 		- argument[0] 表示第一个实参
 	- `callee`属性 - 对应当前正在执行的函数对象
 ```javascript
 function fun() {
 	console.log(arguemnts instanceof Array); // false
 	console.log(Array.isArray(arguments)); // false
 	console.log(arguments.length); // 1
 	console.log(arguments[0]); // Hello
 	console.log(arguments.callee); // 会打印出整个fun函数
 }
 fun("Hello");
 ```
 

