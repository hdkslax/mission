```javascript
function createStudent(name, gender, studentNumber){
	// 创建一个新对象
	var obj = new Object();
	// 向对象中添加属性
	obj.name = name;
	obj.gender = gender;
	obj.studentNumber = studentNumber;
	// 将对象返回
	return obj;
}
var student1 = createStudent("moqi", "male", 123456789);
console.log(student1);
```
使用工厂方法创建的对象，使用的构造函数都是Object，所以创建的对象都是Object这个类型，导致无法区分出多种不同类型的对象。

