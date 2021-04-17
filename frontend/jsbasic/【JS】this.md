解析器在调用函数时，每次都会向函数内部传递进一个隐含的参数，这个隐含的参数就是this
- this指向一个对象
- 这个对象我们称为函数执行的上下文对象
- 根据函数调用方式的不同，this会指向不同的对象
	- 以函数形式调用时，this永远都是window
	- 以方法形式调用时，this是调用方法的对象
```javascript
function fun(){
	console.log(this); // [object Window]
}
fun();
var obj = {
	name: "moqi",
	sayName: fun
}
console.log(obj.sayName()); // [object Object]

console.log(obj.sayName== fun); //true
```

```javascript
var name = "全局";
function fun() {
	console.log(name);
}
// 创建两个对象
var obj1 = {
	name: "name1",
	sayName: fun
};
var obj2 = {
	name: "name2",
	sayName: fun
};
fun();
// 希望调用obj1.sayName时可以输出obj名字
obj1.sayName(); // 实际输出为"全局"
```
可以用this来解决这个问题
```javascript
var name = "全局";
function fun() {
	console.log(this.name);
}
// 创建两个对象
var obj1 = {
	name: "name1",
	sayName: fun
};
var obj2 = {
	name: "name2",
	sayName: fun
};
fun();
// 希望调用obj1.sayName时可以输出obj名字
obj1.sayName(); // 输出name1
```
