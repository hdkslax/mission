## Date对象
Date对象表示时间
#### 创建一个Date对象
- 若直接使用构造函数创建一个Date对象，则会封装为当前代码执行时间
```javascript
var d = new Date(); // Sat Mar 13 2021 11:06:58 GMT-0800 (北美太平洋标准时间)
```
#### 创建一个指定时间的对象
需要在构造函数中传递一个表示时间的字符串作为参数
```javascript
var d = new Date("03/12/2021 11:10:30"); // Fri Mar 12 2021 11:10:30 GMT-0800 (北美太平洋标准时间)
```
## Date 方法
#### getDate()
- 获取当前Date对象的日期
- 只获取“日”
```javascript
var d = new Date("03/12/2021 11:10:30");
var date = d.getDate(); 
console.log(date);// 12
```
#### getDay();
- 获取当前Date对象是周几
- 返回一个0-6的值
- 周日是0
```javascript
var d = new Date("03/12/2021 11:10:30");
var date = d.getDay();
console.log(date); // 5
```

#### getMonth()
- 获取当前Date对象的月份
- 返回一个0-11的值
- 一月是0
```javascript
var d = new Date("03/12/2021 11:10:30");
var date = d.getMonth();
console.log(date); // 2
```

#### getFullYear()
- 获取当前Date对象的年份
```javascript
var d = new Date("03/12/2021 11:10:30");
var date = d.getFullYear();
console.log(date); // 2021
```
#### getHours()
- 0~23
#### getMinutes()
- 0~59
#### getSeconds()
- 0~59
#### getMilloseconds()
- 0~999
### getTime()
- 返回格林威治标准时间的1970年1月1日至今的毫秒数
- 时间戳
- 计算机底层在保存时间时都是时间戳
- 不同时区获取的时间戳一样，实际使用中，记得考虑时区
```javascript
var d = new Date("03/12/2021 11:10:30");
var date = d.getTime();
console.log(date); // 2021
```
###### 利用时间戳测试代码性能
```javascript
var start = Date.now();
执行语句...
var end = Date.now();
console.log("执行了"+ (end-start) + "毫秒");
```
