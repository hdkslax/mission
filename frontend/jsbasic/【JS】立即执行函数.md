# 立即执行函数
函数定义完，立即被调用。
 - 立即执行函数，旺旺只会执行一次

直接在script标签中写这样的匿名函数会报错：
```javascript
function(){
	alert("...");
}
```
写成这样才不会报错：
```javascript
var fun = function(){
	alert("...");
}
```
或者这样
```javascript
(function(){
	alert("...");
})
```
