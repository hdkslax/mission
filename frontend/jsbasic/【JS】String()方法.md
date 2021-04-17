在底层，字符串是以字符数组的形式保存的。
比如：
```javascript
var str = "Hello";
```
在底层是这样的：
```javascript
["H","e","l","l","o"]
```
所以很多属性和方法和Array一样
#### length 属性
- 获取字符串长度
```javascript
console.log("Hello".length); // 5
```
#### charAt()
- 返回指定位置的字符
- 根据索引获取指定字符
```javascript
var str = "Hello";
var result = str.charAt(0);
console.log(result); // H
```
或
```javascript
var str = "Hello";
var result = str[0];
console.log(result); // H
```
#### charCodeAt()
- 获取指定位置字符的字符编码（Unicode编码）
```javascript
var str = "Hello";
var result = str.charCodeAt(0);
console.log(result); // 72
```
#### fromCharCode(某字符的Unicode编码)
```javascript
var result = String.fromCharCode(72);//此处为十进制数，若是16进制，可用0X加在数字前面
console.log(result); // H
```
#### concat()
- 连接两个或多个字符串
- 作用和 + 一样
```javascript
var str = "Hello";
var result = str.concat(" World", "!");
console.log(result); // Hello World!
```
#### indexOf()
- 检索一个字符串中是否含有指定内容
- 若有，则返回该字符第一次出现索引
- 若无，则返回-1
- 第二个参数可有可无，为查找的起始index
```javascript
var str = "Hello";
var result = str.indexOf("l");
var result2 = str.indexOf("l", 3);
console.log(result); // 2
console.log(result2); // 3
```
#### lastIndexOf()
- 用法和indexOf一样
- 不同的是该方法返回字符最后一次出现的index
- 还是从前往后找！
#### slice(start,end)
- 可以从字符串中截取指定的内容
- 不会影响原字符串
- 参数
	start - 开始位置索引（包括）
	end - 结束位置索引（不包括）
	若省略第二个参数，则截取到最后
	也可以传递负数作为参数，负数的话从后边开始计算index
```javascript
var str = "Hello";
var result = str.slice(1,3);
console.log(result); // el
```
#### substring(start,end)
- 截取字符串，和`slice()`相似
- 参数
	start - 开始位置索引（包括）
	end - 结束位置索引（不包括）
- 不同的是如果传递了一个负数，则默认是0
- 会自动调整参数的位置，若end<start，则自动换位
#### substr(start,length)
- ES中没有定义，但大部分浏览器都支持

#### split()
- 可以将一个字符串拆分为一个数组
- 若传递一个空串，则将每个字符都拆分成数组中的一个元素

```javascript
var str = "abc,def,ghi";
var result = str.split(",");
console.log(result); //["abc", "def", "ghi"]
```
#### toUpperCase()
- 将一个字符串转换为大写并返回
- 不会影响原字符串
#### toLowerCase()
- 将一个字符串转换为小写并返回
- 不会影响原字符串

