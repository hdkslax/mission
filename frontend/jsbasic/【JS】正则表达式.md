# 正则表达式基础
### 创建正则表达式
语法：var 变量 = new RegExp("正则表达式","匹配模式");
```javascript
var reg = new RegExp("a"); // reg是一个对象
console.log(reg); // /a/
```

### 正则表达式的test()方法
检查一个字符串是否符合正则表达式的规则，若符合则返回true，否则返回false
- 检测字符串str中是否含有"a"
- 严格区分大小写
```javascript
var reg = new RegExp("a"); // reg是一个对象
console.log(reg); // /a/
var str = "bcabc";
var result = reg.test(str);
console.log(result); //true
```
- 在构造函数中，可以传递一个匹配模式作为第二个参数：
	- i：忽略大小写
	- g：全局匹配模式
```javascript
var reg = new RegExp("a"，"i"); // reg是一个对象
console.log(reg); // /a/
var str = "bcAbc";
var result = reg.test(str);
console.log(result); //true
```

### 使用字面量创建正则表达式
语法：var 变量 = /正则表达式/匹配模式
```javascript
var reg = new RegExp("a","i");
var reg2 = /a/i; // 和上一句一模一样
console.log(reg2.test("abc"));
```
字面量更加简单；
构造函数更加灵活（可以传变量）

- a|b a或b
- [ab] == a|b
- [a-z]  任意小写字母
- [A-Z]  任意小写字母
- [A-z] 任意字母
- [0-9] 任意数字
- [^ ] 除了中括号中的字符是否还有其他字符
创建一个表达式，检查一个字符串中是否有a或b
```javascript
var reg = /a|b/; // | 表示a或b
console.log(reg.test("abc"));
```
创建一个正则表示大检查一个字符串中是否有字母
```javascript
var reg = /[A-z]/; 
console.log(reg.test("abc"));
```
检查一个字符串中是否含有abc或adc或aec
```javascript
var reg = /a[bde]c/; 
console.log(reg.test("abc"));
```
检查除了ab是否还有其他字符
```javascript
var reg = /[^ab]/;
console.log(reg.test("a"));//false 
console.log(reg.test("ab"));//false 
console.log(reg.test("ba"));//false
console.log(reg.test("abc"));//true
```
# 正则表达式语法
#### 量词
- 设置一个内容出现的次数
- 量词只对它前边的一个内容起作用
- {n} 正好出现n次
- {m,n} 出现m~n次
- {m,} 出现m次以上
- `+` 至少一个，相当于 {1,}
- `*` 0个或多个，有没有都行
- `?` 0个或1个，相当于{0,1}
```javascript
var reg1 = /a{3}/; // a连续出现3次
var reg2 = /(ab){3}/; // ab连续出现3次
var reg3 = /ab{1,3}c/; // b出现1-3次
var reg4 = /ab{3,}c/; // b至少连续出现3次
var reg5 = /ab+c/; // b至少出现一次
var reg6 = /ab*c/; //有没有b都行
var reg7 = /ab?c/; //b出现0次或1次
```
检查一个字符串是否以"a"开头，"a"结尾
	- `^`表示开头
	- `$` 表示结尾
	- 若同时使用`^`和`$`，则要求字符串必须完全符合正则表达式
```javascript
var reg1 = /^a/; 
var reg2 = /a$/;
var reg3 = /^a$/;//只有“a”这一个字符串符合
var reg3 = /^a|a$/; //以a开头或以a结尾
```


###### 手机号正则
创建一个正则表达式，检测一个字符串是否是一个合法手机号
 1. 以1开头
 2. 第二位3-9任意数字
 3. 三位以后任意数字9个
```javascript
var phoneReg = /^1[3-9][0-9]{9}$/; 
console.log(phoneReg.test(phoneStr));
```
###### 检查字符串中是否含有 .
- `.` 在正则语法中表示任意字符（除了换行符和结束符）
- 检测字符串中是否含有`.`时，需要转移字符 `\.`
- 注意：使用构造函数时，由于参数是一个字符串，而\是字符串中的转义字符，若要使用\，需要写\\
```javascript
var reg1 = /\./; 
var reg2 = /\\/; 
var reg3 = new RegExp("\\.");
var reg4 = new RegExp("\\\\");
```
- \w	表示字母、数字、下划线
- \W	除了字母、数字、下划线
- \d	任意数字
- \D	除了数字
- \s	空格
- \S	除了空格
- \b	单词边界
- \B	除了单词边界
创建一个正则表达式，检查一个字符串是否含有单词child
```javascript
var reg1 = /child/; // children不算child，直接这样写不行
var reg2 = /\bchild\b/;
```

###### 获取用户输入（当用户输入不当时）
hint: 去掉空格，就是使用“”来替换空格
```javascript
var str = prompt("Username: "); // "        user1       "
str = str.replace(/\s/g, "");
console.log(str); // "user1"
```
hint: 去掉前后空格
```javascript
var str = prompt("Username: "); // "        user1       "
str = str.replace(/^\s*/g, ""); //去开头
str = str.replace(/\s*$/g, ""); //去结尾
console.log(str); // "user1"
```
```javascript
var str = prompt("Username: "); // "        user 1       "
str = str.replace(/^\s*| \s*$/g, ""); 
console.log(str); // "user1"
```
###### 电子邮件的正则 
hello.nihao@abc.com
 任意数字字母下划线 . 任意字母数字下划线 @ 任意数字字母 . 任意字母(2-5位)
\w{3,} (\.\w+)*@[A-z0-9]+(\.\[A-z]{2,5}){1,2}
```javascript
var emailReg = /^\w{3,}(\.\w+)*@[A-z0-9]+(\.\[A-z]{2,5}){1,2}$/;
var email = "abc@abc.com";
console.log(emailReg.test(email));
```
