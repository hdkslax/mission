Math和其他对象不同，不是构造函数，是一个工具类。
封装了数学运算相关的属性和方法。

## 属性
都是常量，固定数值。
<a href="https://www.w3school.com.cn/jsref/jsref_obj_math.asp"> 直接查文档就完事啦！</a>

## 方法
#### abs()
绝对值
#### ceil()
- 向上取整
- 注意负数
```javascript
console.log(Math.ceil(-1.5)); // -1
```
#### floor()
- 向下取整
- 注意负数
```javascript
console.log(Math.floor(-1.5)); // -2
```
#### round()
- 四舍五入取整
- 注意负数
```javascript
console.log(Math.round(-1.5)); // -1
```
#### random()
- 生成0-1之间的随机数
- 不会出现0和1
```javascript
console.log(Math.random()); 
```
- 生成0-10之间的随机数
```javascript
console.log(Math.round(Math.random()*10));
```
- 生成0-n之间的随机数
```javascript
console.log(Math.round(Math.random()*n));
```
- 生成1-n之间的随机数
```javascript
console.log(Math.round(Math.random()*(n-1)+1));
```
- 生成m-n之间的随机数
```javascript
console.log(Math.round(Math.random()*(n-m)+m));
```

#### max()、min()
- 获取多个数的最大值、最小值
- 不能比较数组，会返回NaN
```javascript
var max = Math.max(10,20,30);
```
