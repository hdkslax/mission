@[TOC](DOM查询)
# 获取元素节点
**通过document对象调用**
getElementById() - 通过id属性获取**一个**元素节点对象
getElementByTagName() - 通过标签名获取**一组**元素节点对象
getElementsByName() - 通过name属性获取**一组**元素节点对象

#### 通过id查找元素
```javascript
// 查找#bj节点
var btn01 = document.getElementById("btn01");
btn01.onclick = function(){
	var bj = document.getElementById("bj");
	console.log(bj.innerHTML);
};
```
#### 查找所有li节点
getElementByTagName()返回值是类数组对象，所有查询到的元素都会封装到一组元素节点对象。
即使查询到的数组元素只有一个，也会封装到数组中返回。
```javascript
var btn02 = document.getElementById("btn02");
btn02.onclick = function(){
	var lis = document.getElementByTagName("li");
	console.log(lis); //[object HTMLCollection]
	//遍历lis
	for(var i=0;i<lis.length;i++){
		console.log(lis[i].innerHTML);
	}
};
```

#### 查询name=gender的所有节点
```javascript
var btn03 = document.getElementById("btn03");
btn03.onclick = function(){
	var inputs = document.getElementsByName("gender");
	for(var i=0; i<inputs.length;i++){
		console.log(inputs[i].innerHTML);//返回空值
		console.log(inputs[i].value); //元素.属性名
	} 
};
```
注意：
- innerHTML用于获取元素内部HTML代码的，对于自结束标签，这个属性没有任何意义。
- 若需读取元素节点属性，直接用 元素.属性名
	- 但class属性不能采用这种方式，因为class是JS的保留字。
	- 读取class属性需要使用 元素.className


# 获取元素节点的子节点
**通过具体元素节点调用**
getElementsByTagName() - 方法，返回当前节点的指定标签名后代节点
childNodes - 属性，表示当前节点的所有子节点
firstChild - 属性，表示当前节点的第一个子节点
lastChild - 属性，表示当前节点的最后一个子节点

#### 查找#city下所有li节点
```javascript
var btn04 = document.getElementById("btn04");
btn04.onclick = function(){
	var city = document.getElementById("city");
	var lis = city.getElementsByTagName("li");
	
	for(var i=0; i<inputs.length;i++){
		console.log(lis.innerHTML);
	}
};
```
#### 返回#city的所有子节点
childNodes属性会获取包括文本节点在内的所有节点，根据DOM标准标签间的空白也会当成节点（还包括换行符，就他娘的离谱(╯‵□′)╯︵┻━┻）
注意：在IE8及以下的浏览器中，不会将空白文本当成子节点。

children属性可以获取当前元素的所有子元素
```javascript
var btn05 = document.getElementById("btn05");
btn05.onclick = function(){
	var city = document.getElementById("city");
	var childNodes = city.childNodes;
	console.log(childNodes.length);//只有4个li，确返回9个
	for(var i=0; i<inputs.length;i++){
		console.log(lis.innerHTML);
	}
};
```

#### 返回#phone的第一个子节点
firstChild属性可以获取到当前元素的第一个子节点。
小心空白文本节点(⊙_⊙)

firstElementChild可以获取到当前元素的第一个子元素。
该属性不支持IE8及以下浏览器，若要兼容，尽量不要用。
```javascript
var btn06 = document.getElementById("btn06");
btn06.obclick = function(){
	var phone = document.getElementById("phone");
	var firstPhone = phone.firstChild;//可能会返回空白文本节点
	var fir = phone.firstElementChild;
}
```
# 获取父节点和兄弟节点
**通过具体的节点调用**
parentNode - 属性，表示当前节点的父节点
previousSibling - 属性，表示当前节点的前一个兄弟节点
nextSibling - 属性，表示当前接待你的后一个兄弟节点

#### 获取#bj的父节点
innerText
 - 该属性可以获取到元素内部的文本内容
 - 它和innerHTML类似，不同的是它会自动将HTML标签去除
```javascript
var pn = bj.parentNode;
console.log(pn.innerHTML); 
```
#### 返回id为android的前一个兄弟节点
previousSibling也会获取空白文本节点。
previousElementSibling - 获取前一个兄弟元素，但IE8及以下不支持。
```javascript
var android = document.getElementById("android");
var prevNode = android.previousSibling;
var prevElem = android.previousElementSibling;
```

#### 读取#username的value属性值
文本框的value属性值，就是文本框中填写的内容。
```javascript
var username = getElementById("username");
console.log(username.value);
```
#### 设置#username的value属性值
```javascript
var username = getElementById("username");
username.value = "user1";
```

#### 获取#bj的文本值
```javascript
var bj = document.getElementById("bj");
console.log(bj.innerText);
```
```javascript
var firstChild = bj.firstChild;
console.log(firstChild.nodeValue);
console.log(bj.firstChild.nodeValue);
```
# 获取body标签
```javascript
var body = document.getElementsByTagName("body")[0]; // 因为getElementsByTagName的返回值是类数组
```
此法麻烦。
#### body属性
document中有一个属性叫做body，保存的是body的引用
```javascript
var body = document.body;
```
#### documentElement属性
document中有一个属性叫做documentElement，保存的是html根标签
```javascript
var body = document.documentElement;
```
#### all 属性
获取document中所有元素
```javascript
var all= document.all;
console.log(typeof all); //undefined,但里面确实有东西
```
还有一种方法获取所有元素
```javascript
var all= document.getElementsByTagName("*");
```

# 根据class属性值获取一组元素节点对象
#### getElementsByClassName()
可以根据class属性值获取一组元素节点对象
IE8及以下不支持

#### querySelector()
需要一个选择器的字符串作为参数，可以根据一个CSS选择器来查询一个元素节点对象
支持IE8 ヾ(o´∀｀o)ﾉ 
该方法总会返回一个元素，若有多个元素符合条件，也只会返回第一个
```html
<div class="box1">
		<div></div>
</div>
<script>
	var div = document.querySelector(".box1 div");
</script>
```

#### querySelectorAll(".box1")
该法和querySelector()类似，不同的是它会将符合条件的元素封装到一个数组中返回。
即使符合条件的元素只有一个，也是返回数组。
```html
<body>
	<div class="box1">
		<div></div>
	</div>
	<div class="box1"></div>
	<div class="box1"></div>

</body>
<script>		
var div = document.querySelectorAll(".box1");
console.log(div);	
</script>
```
