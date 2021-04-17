@[TOC](文章目录)
### 对象.事件 = 函数
使用`对象.事件 = 函数`的形式绑定响应函数
 	- 只能同时为一个元素的一个事件绑定一个响应函数
 	- 不能绑定多个，如果绑定了多个，则后边会覆盖掉前边的。

### addEventListener()
通过`addEventListener()`方法也可以为元素绑定响应函数
参数：
	 -  事件的字符串，不要on
	 - 回调函数，当事件触发时，该函数被调用
	 - 是否在捕获阶段触发事件，需要一个Boolean值，一般都传false
	 - 不支持IE8及以下
```javascript
btn01.addEventListener("click", function(){
	alert(1);
},false);
btn01.addEventListener("click", function(){
	alert(2);
},false);
btn01.addEventListener("click", function(){
	alert(3);
},false);
// 顺序： 1 2 3
```
IE8及以下，用`attachEvent()`
参数
	- 事件的字符串，要on
	- 回调函数
这个方法也可以同时为一个书剑绑定多个处理函数，不同的是它是后绑定的函数先执行，执行顺序和`addEventListener()`相反。
```javascript
btn01.attachEvent("onclick",function(){
	alert(1);
});
btn01.attachEvent("onclick",function(){
	alert(2);
});
btn01.attachEvent("onclick",function(){
	alert(3);
});
// 顺序：3 2 1
```

**兼容写法**
`addEventListener()`中的this，是绑定事件的对象
`attachEvent()`中的this，是window
需要统一两个方法的this

参数：
	- obj 要绑定事件的对象
	- eventStr 事件的字符串
	- callback 回调函数
```javascript
function bind(obj, eventStr, callback){
	if(obj.addEventListener){
		//大部分浏览器兼容的方式
		obj.addEventListener(eventStr, callback, false);
	}else{
		//IE8及以下
		obj.attachEvent("on"+eventStr, function(){ //因为IE8-中this是window，需要this指向obj而不是window，所以这里不能直接调用callback，callback一般是浏览器自己调用，为了拿回调用权限，我们写一个匿名函数给浏览器去调用，这样callback的权限回到了我们自己手里
			// 在匿名函数中调用回调函数
			callback.call(obj);
		});
	}
}
```
