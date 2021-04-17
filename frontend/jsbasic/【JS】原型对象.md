# 原型 prototype
我们所创建的每一个函数，解析器都会向函数中添加一个属性prototype。
这个属性对应着一个对象，这个对象就是我们多为的原型对象。
![在这里插入图片描述](img\原型对象1.png)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210313074236225.png)
若函数作为普通函数调用，prototype没有任何作用
当函数通过构造函数的形式调用时，它所创建的对象中都会有一个隐含的属性，指向该构造函数的原型对象。
可以通过`__proto__`来访问该属性。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210313080149442.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NDc4MjQyMg==,size_16,color_FFFFFF,t_70)
原型对象就相当于一个公共的区域，所有同一个类的实例都可以访问这个原型对象。
可以将对象中共有的内容，统一设置到原型对象中。

```javascript
// 向MyClass的原型中添加属性a
MyClass.prototype.a = 123;
```
当访问对象的一个属性或方法时，会:
1. 先在对象自身中寻找，若有，则直接使用；若无，则
2. 去原型对象中寻找，找到则直接使用。若无，则
3. 去原型对象的原型中找，直到找到Object的原型。
4. Object对象的原型没有原型，若仍未找到，则返回`undefined`。

所以，构造函数的方法，可以放在原型中
```javascript
Student.prototype.sayName = function(){
					alert(this.name);
				};
```
### in 检查对象中是否有某个属性
使用`in`检查对象中是否有某个属性时，如果对象中没有但是原型中有，也会返回true。

若要检查属性是否在对象本身中，则可使用`hasOwnProperty()`方法，该方法在原型对象prototype中（原型对象也是对象，当然也有`__proto__`）
```javascript
student1.hasOwnProperty();
```
