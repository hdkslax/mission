@[TOC](目录)
# 事件对象
- 当事件的响应函数被触发时，浏览器每次都会将一个事件对象作为实参传递响应函数。
- 在事件对象中封装了当前事件相关的一切信息，比如：鼠标的坐标、键盘哪个按键被按下、鼠标滚轮滚动方向，等等。
```javascript
areaDiv.onmousemove = function(event){
		// 这里的event就是事件对象
};
```
注意：在IE8及以下的浏览器中，是将时间对象作为window对象的属性来保存的
```javascript
var x = window.event.clientX;
var y = window.event.clientY;
```
兼容两者：
```javascript
if (!event) {
	event = window.event
}
```
或者
```javascript
event = event || window.event;
```
### onmousemove
- 该事件将会在鼠标在元素中移动时触发

### clientX、clientY
clientX - 可以获取鼠标指针的水平坐标
clientY - 可以获取鼠标指针的垂直坐标
clientX和clientY总是相对于可见窗口
```javascript
var areaDiv = document.getElementById("areaDiv");
	var showMsg = document.getElementById("showMsg");
	areaDiv.onmousemove = function(event){
		var x = event.clientX;
		var y = event.clientY;
		showMsg.innerHTML = "x = "+x+" ,y = " + y;
	};
```
### pageX、pageY
pageX和pageY是相对于页面的坐标

### 获取滚动条滚动距离
scrollTop属性
浏览器认为滚动条是html的
```javascript
var scrollTop = document.documentElement.scrollTop;
```

