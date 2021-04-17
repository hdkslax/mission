# 【JS】滚轮事件



### onmousewheel

鼠标滚轮滚动事件，会在滚轮滚动时触发。

但火狐不支持该属性，需要用到`DOMMouseScroll`来绑定滚动事件。（注意：该事件需通过`addEventListener()`函数来绑定）

```javascript
// 当滚轮向上滚动时，box1变短
// 当滚轮向下滚动时，box1变长
	var box1 = document.getElementById("box1");
	box1.onmousewheel = function () {
					
	};
	bind(box1,"DOMMouseScroll", function(){

	});
	// 或者用以下写法:
	bind(box1,"DOMMouseScroll", box1.onmousewheel); // 因为 函数已经被赋值给 box1.onmousewheel

// 为addEventListener绑定事件
function bind(obj, enevtStr, callback){
	if (obj.addEventListener){
		obj.addEventListener(evenStr, callback, false);
	} else {
		// 兼容IE8及以下
		obj.attachEvent("on"+evenStr, function(){
			callback.call(obj);
		});
	}
}
```



### 判断鼠标滚轮滚动方向

`event.wheelDelta`可以获取鼠标滚轮滚动方向，不看大小，只看正负

	- 正，向上
	- 负，向下

但火狐不支持该属性，需要用到`event.detail`

```javascript
box1.onmousewheel = function (event) {
	// 判断滚动滚动方向
	if(event.wheelDelta>0 || event.detail < 0){
		// 当滚轮向上滚动时，box1变短
		box1.style.height = box1.clientHeight - 10 + "px";
	} else {
		// 当滚轮向下滚动时，box1变长
		box1.style.height = box1.clientHeight + 10 + "px";
	}
};
```



### 注意

当鼠标滚轮滚动时，若浏览器有滚动条，滚动条会随之滚动。这是浏览器的默认行为，若不希望发生，则可以`return false`来取消。

```javascript
box1.onmousewheel = function (event) {
	// 判断滚动滚动方向
	if(event.wheelDelta>0 || event.detail < 0){
		// 当滚轮向上滚动时，box1变短
		box1.style.height = box1.clientHeight - 10 + "px";
	} else {
		// 当滚轮向下滚动时，box1变长
		box1.style.height = box1.clientHeight + 10 + "px";
	}
	return false;
};
```

但是，使用addEventListener()方法绑定响应函数，取消默认行为时不能使用`return false`，需使用`event.preventDefault()`来取消默认行为。

但IE8及以下不支持`event.preventDefault()`，直接用会报错。

```javascript
box1.onmousewheel = function (event) {
	// 判断滚动滚动方向
	if(event.wheelDelta>0 || event.detail < 0){
		// 当滚轮向上滚动时，box1变短
		box1.style.height = box1.clientHeight - 10 + "px";
	} else {
		// 当滚轮向下滚动时，box1变长
		box1.style.height = box1.clientHeight + 10 + "px";
	}
    // 兼容火狐和IE8
    event.preventDefault && event.preventDefault();
	return false;
};
```



