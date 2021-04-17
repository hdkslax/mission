语法：
```javascript
for (var 变量 in 对象){
	
}
```

```javascript
var student = {
	name: "sn",
	gender: "male",
	studentNumebr: "123456789"
};

for (var n in student){
	console.log("test");
}
```
for ... in 语句，对象中有几个属性，循环体就执行几次。
每次执行时，会将对象中的一个属性的名字赋值给变量。

所以可以这样输出对象的属性名：
```javascript
for (var n in student) {
	console.log("属性名:" + n);
	console.log("属性值:" + student[n]);
}
```
注意：此处这样写是错的，因为student对象里不包含属性名为n的属性：
```javascript
for (var n in student) {
	console.log(student.n);
}
```
