## 数组
数组也是一个对象。
和普通对象功能类似，也是用来存储一些值得
不同的是，普通对象是使用字符串作为属性名的，而数组是使用数字来作为索引元素的。
数组的存储性能比普通对象要好，在开发中经常使用数组来存储一些数据
### 索引 index
- 从0开始的整数

### 创建数组对象
```javascript
var arr = new Array();
console.log(typeof arr); // object
```
使用typeof检查一个数组时，会返回object

### 向数组中添加元素
语法：数组[索引] = 值
```javascript
arr[0] = 10;
arr[1] = 33;
console.log(arr); // 10,33
```
### 读取数组中的元素
```javascript
console.log(arr[1]); // 33
```
超过数组范围的索引，不会报错，返回`undefined`

### 获取数组长度
可以使用`length`属性来获取数组的长度（元素的个数）
	语法：数组.length

对于连续的数组，使用length可以获取数组的长度（元素的个数）
对于非连续的数组，使用length会获取到数组的最大索引+1
	- 尽量不要创建非连续的数组（占用空间）
###### 修改length
- 若修改的length大于原长度，则多出的部分会空出来
- 若修改的length小于原长度，则多余的元素会被删除
	```javascript
	arr.length = 10;
	console.log(arr); // 10,33,,,,,,,,,	
	```
###### 向数组的最后一个位置添加元素
```javascript
arr[arr.length] = 70;
arr[arr.length] = 80;
```
## 数组字面量

### 使用字面量来创建数组
语法：[]
```javascript
var arr = [];
console.log(typeof arr); //object
```
使用字面量来创建数组时，可以在创建时就指定数组中的元素
```javascript
var arr = [1,2,3,4];
```
使用构造函数创建数组时，也可以同时添加元素，将要添加的元素作为构造函数的参数传递
元素之间用逗号隔开
```javascript
var arr2 = new Array(10,20,30);
```
注意：
创建一个数组，数组中只有一个元素10
```javascript
arr = [10]; // "10"
arr2 = new Array(10); // ",,,,,,,,," 创建了一个长度为10的数组
```
###### 数组中可以放函数
```javascript
arr = [function(){alert(1);}, function(){alert(2);}];
// 调用
arr[0]();
```
## 数组的3个属性
1. constructor
2. length
3. prototype
## 数组的11个方法
#### 1. push()
- 向数组末尾添加一个或多个元素，并返回数组的新的长度
- 可以将要添加的元素作为方法的参数传递
```javascript
arr.push("123","456","789");
```
#### 2. pop()
- 该方法可以删除数组最后一个元素
- 并返回被删除的元素
```javascript
var result = arr.pop()
```

#### 3. unshift()
- 向数组开头添加一个或多个元素，并返回新的数组长度
- 向开头插入元素后，其他芫荽索引会依次调整
```javascript
arr.unshift("123","456","789");
```
![在这里插入图片描述](img\数组Array1.png)


#### 4. shift()
- 删除数组第一个元素
- 并将被删除的元素返回
```javascript
var result = arr.shift()
```

#### 5. forEach(function)
一般使用for循环遍历数组
JS中还提供了一个方法`forEach`，用来遍历数组（此方法IE8或以下不支持）
 - `forEach`方法需要一个函数作为参数
 - 像这种函数，由我们创建，但不由我们调用的（浏览器调用），称为回调函数
 - 数组中有几个元素，函数就会执行几次
 - 每次执行时，浏览器会将遍历到的元素以实参的形式传递进来
 	- 第一个参数 - 当前正在遍历的元素
 	- 第二个参数 - 当前正在遍历的元素的索引
 	- 第三个参数 - 当前正在遍历的数组
```javascript
arr.forEach(function (value,index,arrObj){
	console.log(value,index,arrObj);
});
```

#### 6. slice(start,end)
- 从数组中提取指定元素
- 该方法不会改变原数组，而是封装到新数组中返回
- 参数：
	start - 截取开始的位置索引，包含开始索引
	end - 截取结束的位置索引，不包含结束索引 (可省略不写，意为直到最后)
- 索引可以传递一个负值，若传递一个负值，则从后往前计算
	- -1 倒数第一个
	- -2 倒数第二个
	- ...
```javascript
var arr = [1, 2, 3, 4, 5];
var result = arr.slice(1,2); // 2 
```

#### 7. splice(start,count,newValue,newValue,...)
- 删除数组中的指定元素
- 会影响到原数组，会将指定元素从原数组中删除，并将被删除的元素作为返回值返回
- 参数
	start - 开始的索引
	count - 删除的数量
	newValue - 被传递进来的新元素，会自动插入到开始位置索引之前（也就是被删除元素所在的位置）

```javascript
var arr = [1, 2, 3, 4, 5];
var result = arr.splice(0,2);
console.log(result); // 1,2
console.log(arr); // 3,4,5
```
插入元素：
```javascript
var arr = [1, 2, 3, 4, 5];
var result = arr.splice(1,0,66,77,88);
console.log(arr); // 1, 66, 77, 88, 2, 3, 4, 5
```
数组去重：
```javascript
var arr = [1, 2, 3, 4, 5, 5, 2];
for (var i=0;i<arr.length;i++){
	for (var j=i+1;j<arr.length;j++){
		if(arr[i]==arr[j]){
			// 相等则出现重复元素，删除j对应的元素
			arr.splice(j,1);
			// 当删除了当前j所在的元素后，后边的元素会自动补位，
			// 此时将不会再比较这个元素，需要在比较一次j所在位置的元素
			j--;
		}
	}
}
console.log(arr);
```

#### 8. concat()
- 连接两个或多个数组，并将新的数组返回
- 不会对原数组产生影响

```javascript
var result = arr.concat(arr2,arr3);
console.log(result);
```
#### 9. join()
- 将数组转换为字符串
- 不会对原数组产生影响，而是将转换后的字符串作为结果返回
- 在`join()`中可以指定一个字符串作为参数，这个字符串将会成为数组中元素的连接符
```javascript
arr.join();
```
#### 10. reverse()
- 反转数组
- 该方法会直接修改原数组
```javascript
arr.reverse();
```
#### 11. sort()
- 对数组元素按Unicode编码顺序排序
- 会影响原数组
- 即使对于纯数字的数组，使用`sort()`排序时，也会按照Unicode编码来排序，所以对数字会出错。
```javascript
var arr = [11, 2, 3, 4, 5];
arr.sort(); // 11, 2, 3, 4, 5, 错误
```
- 可以自己指定排序规则
	- 回调函数中需要定义两个形参，
	- 浏览器将会分别使用数组中的元素作为实参去调用回调函数
	- 使用哪个元素不确定，但肯定是在数组中，a一定在b前边
- 浏览器会根据回调函数的返回值来决定元素的顺序
	- 若返回大于0的值，则元素会交换位置
	- 若返回小于0的值，则元素位置不变
	- 若返回0，则两元素相等
```javascript
var arr = [11, 2, 3, 4, 5];
arr.sort(function(a,b){
	// 升序
	if(a>b){
		return 1;
	} else if (a<b) {
		return -1;
	} else {
		return 0;
	}
}); 
```
```javascript
var arr = [11, 2, 3, 4, 5];
arr.sort(function(a,b){
	// 升序
	return a-b;
}); 
```
## 数组的遍历
基本形式：
```javascript
for (var i=0; i<arr.length; i++) {
	console.log(arr[i];
}
```

