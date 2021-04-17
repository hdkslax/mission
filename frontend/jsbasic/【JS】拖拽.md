@[TOC](目录)

# 拖拽元素
### 拖拽的流程
1. 当鼠标在被拖拽元素上按下时，开始拖拽 `onmousedown`
2. 当鼠标移动时被拖拽元素跟随鼠标移动 `onmousemove`
3. 当鼠标松开时，被拖拽元素固定在当前位置 `onmouseup

```javascript
var box1 = document.getElementById("box1");
	box1.onmousedown = function (event) {
		//为document绑定一个跟随鼠标事件 onmousemove
		// 鼠标按下时，所处在box1中的位置：
		// 鼠标.clentX - 元素.offsetLeft
		// 鼠标.clentY - 元素.offsetTop
		var oLeft = event.clientY - box1.offsetLeft;
		var oTop = event.clientY - box1.offsetTop;
		document.onmousemove = function(event){
			//当鼠标移动时，被拖拽元素跟随鼠标移动 onmousemove
			var left = event.clientX - oLeft;
			var top = event.clientY - oTop;
			//修改box1的位置
			box1.style.left = left + "px";
			box1.style.top = top + "px";
		};
		// 当拖拽一个网页中的内容时，浏览器会默认去搜索引擎中搜索内容
		// 此时会导致拖拽功能异常，这是浏览器的默认行为
		// 若不希望发生此行为，则return false取消此默认行为
		return false;
	};

//为box1绑定一个鼠标松开事件的话当鼠标经过其他元素，up事件就不会触发了
//应该为document绑定鼠标松开事件
document.onmouseup = function(){
	//当鼠标松开时，被拖拽元素固定在当前位置 onmouseup
	document.onmousemove = null;
};
```

### IE8
IE8 中`return false`无法取消拖拽功能异常，需要使用`setCapture()`。

在`onmousedown`中，调用`setCapture()`
 - 当调用一个元素的setCapture()方法以后，这个元素将会把之后所有的鼠标按下相关事件捕获到自己身上
 - `setCapture()` 只有IE支持，但是在火狐中调用不会报错，而chrome会报错
```javascript
if(box1.setCapture){
	box1.setCapture();
}
```
或者可以这么写：
```javascript
box1.setCapture && box1.setCapture();
```

记得在onmouseup中取消！
```javascript
// 当鼠标松开时，取消对事件的捕获
box1.releaseCapture && box1.releaseCapture();
```

