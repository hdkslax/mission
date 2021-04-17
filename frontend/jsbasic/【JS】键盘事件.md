# 【JS】键盘事件

键盘事件一般都会绑定给可以获取焦点的对象或者是`document`

焦点：比如`input`的输入框，点进去有光标闪烁的时候，就是获取焦点的时候。

### onkeydown

- 按键被按下
- 对于`onkeydown`来说若一直按着某个键不松手，则事件会一直被触发
- 当onkeydown连续触发时，第一次和第二次之间会间隔稍微长一点，其他的会非常快。
  - 这种设计是为了防止误操作的发生。

```javascript
document.onkeydown = function(){};
```

### onkeyup

- 按键被松开

```javascript
document.onkeyup = function(){};
```



### 哪个按键被按下了？

`event`中有个属性`keyCode`，可以判断哪个按键被按下。

用Unicode来判断

```javascript
document.onkeydown = function(event){
    // 判断y是否被按下
    if(event.keyCode === 89){ // 89是y的Unicode编码
		console.log("y被按下了");
    }
};
```

判断两个按键是否同时被按下

不能用`event.keyCode === 89 && event.keyCode === 17`来判断，因为同一个值不可能同时等于两个值。

###### altKey, ctrlKey, shiftKey

- 用来判断相应的键是否被按下
- 按下，返回`true`
- 否则，返回`false`



### 小游戏：控制一个小盒子的上下左右移动

Unicode：

37 - 左

38 - 上

39 - 右

40 - 下

```javascript
var box1 = document.getElementById("box1");
document.onkeydown = function(event){
	switch (event.keyCode){
		case 37:
			box1.style.left = box1.offsetLeft - 100 + "px";
			break;
		case 38:
			box1.style.top = box1.offsetTop - 100 + "px";
			break;
		case 39:
			box1.style.left = box1.offsetLeft + 100 + "px";
			break;
		case 40:
			box1.style.top = box1.offsetTop + 100 + "px";
			break;
}
```



### event.key

现在`keyCode`已经被弃用（虽然实测还是可以用啦），但`event`中的`key`属性，比`keyCode`好用太多！

`key`的输出类型为string字符串（再也不用去查Unicode啦）

```javascript
document.onkeydown = function(event){
    var speed = 10;
    if(event.ctrlKey){
        speed = 100;
    }
   	switch (event.key){
      case "ArrowLeft":
         box1.style.left = box1.offsetLeft - speed + "px";
         break;
      case "ArrowUp":
         box1.style.top = box1.offsetTop - speed + "px";
         break;
      case "ArrowRight":
         box1.style.left = box1.offsetLeft + speed + "px";
         break;
      case "ArrowDown":
         box1.style.top = box1.offsetTop + speed + "px";
         break;
}
```

这种写法有个小问题，第一次按下按键的时候，会卡顿一下（技能后摇）。

#### 用setInterval()和clearInterval()解决后摇问题

```javascript
var speed = 10;
// 创建一个变量方向
var dir = 0;

//开启一个定时器，来控制div的移动
setInterval(function(){
    switch (event.key){
      case "ArrowLeft":
         box1.style.left = box1.offsetLeft - speed + "px";
         break;
      case "ArrowUp":
         box1.style.top = box1.offsetTop - speed + "px";
         break;
      case "ArrowRight":
         box1.style.left = box1.offsetLeft + speed + "px";
         break;
      case "ArrowDown":
         box1.style.top = box1.offsetTop + speed + "px";
         break;
}, 30);
document.onkeydown = function(event){
    //使dir改变方向
    dir = event.key;
   	if(event.ctrlKey){
   		speed = 500;
	} else {
        speed = 100;
    }
};
// 当按键松开时，div不再移动
document.onkeyup = function(){
    // 设置方向为0
    dir = 0;
};
```

