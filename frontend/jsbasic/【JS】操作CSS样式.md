@[TOC](目录)
# 操作CSS内联样式
### 修改样式
语法： 元素.style.样式名 = 样式值
```javascript
box1.style.width = "300px";
```
注意：若CSS的样式名中有-，在JS中不合法，比如：background-color。
需要将这种样式名修改为驼峰命名法，去掉-，并将-后的字母大写。
```javascript
box1.style.backgroundColor = "#bfa";
```

通过`style`属性设置的样式都是内联样式，而内联样式有较高的优先级，所以通过JS修改的样式往往会立即显示。
但若在样式中写了`!important`，则此时样式会有最高的优先级，即使通过JS也不能覆盖该样式，此时将会导致JS修改样式失效。
所以尽量不要为样式添加!important

### 读取样式
语法：元素.style.样式名
```javascript
console.log(box1.style.width);
```
# 获取元素样式
### 获取元素当前显示的样式
###### currentStyle
语法： 元素.currentStyle.样式名
可以用来读取当前元素正在显示的样式
只有IE支持！！

###### getComputedStyle()
在其他浏览器中可以使用`getComputedStyle()`获取元素当前样式。
两个参数:
	- 要获取样式的元素
	- 可以传递一个伪元素，一般都传null
该方法返回一个对象，对象中封装了当前元素对应的样式
 	- 可以通过对象.样式名来读取样式
 	- 若获取到的样式没有设置，则会获取到真实的值，而不是默认值。比如：没有设置width，不会获取到auto，而是一个长度
该方法不支持IE8及以下！！
语法：getComputedStyle(元素, null).样式
```javascript
getComputedStyle(box1,null).backgroundColor; // rgb(187, 255, 170)
```
通过`currentStyle`和`getComputedStyle()`读取到的样式都是只读的，不能修改；
若要修改，只能通过style属性。
###### 自定义函数，用来支持所有浏览器
参数：
	- obj 要获取样式的元素
	- name 要获取的样式名

思路：对象若存在，就是true，不存在即false。可以用来做条件判断。getComputedStyle就是个对象
```javascript
function getStyle(obj,name){
	if(window.getComputedStyle) // 加window将变量变为属性，因为变量不存在会报错
		return getComputedStyle(obj,null)[name];
	else
		obj.currentStyle[name];
}
```
# 其他样式相关属性
#### clientWidth、clientHeight
- 这两个属性可以获取元素的可见宽度和高度
- 这些属性都是不带px的，返回值都是一个数字，可以直接进行计算
- 包括内容区和内边距
- 只读属性，不能修改
- 若有滚动条，减去滚动条的宽度

```javascript
box1.clientWidth;
```

#### offsetWidth、offsetHeight
- 获取元素整个的宽度和高度：内容区+内边距+边框
```javascript
box1.offsetWidth;
```

#### offsetParent
- 可以用来获取当前元素的定位父元素
- 会获取到离当前元素最近的开启了定位的祖先元素
- 开启定位：position值不是static
- 若所有祖先元素都未开启定位，则返回body
```html
<div id="box2" style="position:relative;">
	<div id="box1"></div>
</div>
<script>
	alert(box1.offsetParent);
</script>
```

#### offsetLeft、offsetTop
offsetLeft - 当前元素相对于其定位了的祖先元素的水平偏移量
offsetTop - 当前元素相对于其定位了的祖先元素的垂直偏移量


#### scrollWidth、scrollHeight
scrollWidth - 通过滚动条可见的整个区域的宽度
scrollHeight - 通过滚动条可见的整个区域的高度
当满足scrollHeight - scrollTop == clientHeight时，垂直滚动条滚动到底


