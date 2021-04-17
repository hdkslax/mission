#### splite()
- 将字符串拆分为数组。
- 方法中可以传递一个正则表达式作为参数，这样方法将会根据正则表达式拆分字符串
- 此法即使不指定全局匹配，也会全部拆分
```javascript
var str = "1a2b3c4d5e6f";
var result = str.split(/[A-z]/);
console.log(result);//["1", "2", "3", "4", "5", "6", ""]
```

#### search()
- 搜索字符串中是否含有指定内容
- 若搜索到指定内容，则返回第一次出现的索引
- 若没有搜索到，则返回-1
- 可以接收一个正则表达式作为参数，然后根据正则表达式检索字符串
- 只会查找第一个，即使设置全局匹配也没用
```javascript
var str = "hello abc hehe";
var result = str.search(/a[bef]c/);
console.log(result); //6 - 因为a的index是6
```

#### match()
- 根据正则表达式从一个字符串中将符合条件的内容提取出来
- 默认情况下match()只会找到第一个符合要求的内容，找到以后就停止检索。
- 可以设置正则表达式为全局匹配模式，这样就会匹配到所有的内容
- 可以为一个正则表达式设置多个匹配模式，且顺序无所谓
- 匹配到的内容将会封装到一个数组中返回，即使只查询到一个结果
```javascript
var str = "1a2b3c4d5e6f";
var result = str.match(/[A-z]/);
console.log(result); //a
```
```javascript
var str = "1a2b3c4d5e6f";
var result = str.match(/[A-z]/g);
console.log(result); //["a", "b", "c", "d", "e", "f"]
```
#### replace()
- 将字符串中指定的内容替换为新的内容
- 参数：
	1. 被替换的内容
	2. 新的内容
- 默认只替换第一个
```javascript
var str = "1a2b3c4d5e6f";
var result = str.replace(/[A-z]/g, "@_@");
console.log(result);
```
