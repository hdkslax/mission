# 为什么用对象
若使用基本数据类型的数据，所创建的变量都是独立的，不能成为一个整体。
对象属于一种复合数据类型，在对象中可以保存多个不同的数据类型的属性。

# 对象的分类
### 1. 内建对象
由ES标准中定义的对象，在任何ES的实现中都可以使用
例： Math, String, Number, Boolean, Function, Object ...

### 2. 宿主对象
由JS的运行环境提供的对象，目前来讲主要指由浏览器提供的对象
例： BOM (浏览器对象模型) - console
		DOM (文本对象模型) - document
### 3. 自定义对象
由开发人员自己创建的对象


# 创建对象
使用`new`关键字调用的函数，是构造函数constructor
	- 构造函数是专门用来创建对象的函数
```javascript
var obj = new Object();
```
使用`typeof`检查一个对象时，会返回object
 - 检测`null`时，也会返回object，不过那是错误返回，object是正常返回

# 向对象中添加属性
语法：对象.属性名 = 属性值；
```
obj.name = "墨祈";
```
# 读取对象中属性
语法：对象.属性名
```
console.log(obj.name);
```
若读取对象中没有的属性，不会报错而是返回`undefined`

# 修改对象的属性值
语法：对象.属性名 = 新值

# 删除对象的属性
语法：delete 对象.属性名
```
delete obj.name;
```
# 检查对象中是否含有指定属性 - in运算符
有 - 返回true
无 - 返回false
语法：“属性名” in 对象
```
console.log("name" in obj);
```
