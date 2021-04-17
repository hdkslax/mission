对象的属性值可以是任何函数类型，也可以是个函数：
```javascript
var obj = new Object();
obj.name = "MoQi";
obj.sayName = function(){
	console.log(obj.sayName);
}
```
函数可以称为对象的属性：
 - 若一个函数作为一个对象的属性保存，则这个函数是这个对象的方法。
 - 调用该函数就是调用对象的方法(method)。
 - 只是名称上的区别，和函数没有本质的区别
