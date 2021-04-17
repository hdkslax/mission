@[TOC]
# 增
#### createElement()
- 可以创建一个元素节点对象
- 需要一个标签名做参数，会根据该标签名创建元素节点对象
- 将创建好的对象作为返回值返回
```javascript
var li = document.createElement("li");
```
#### createTextNode()
- 创建文本节点
- 需要文本内容作为参数，将会根据该文本内容创建文本节点，并将新的节点返回。
```javascript
var newText = document.createTextNode("墨愿");
```
#### appendChild()
- 向一个父节点中添加一个新的子节点
- 语法：父节点.appendChild(子节点);
```javascript
// 添加节点 = 添加文本节点到元素节点 + 添加元素节点到父节点
li.appendChild(newText);
var person = document.getElementById("person");
person.appendChild(li);
```
#### insertBefore()
- 在指定子节点前面插入新的子节点
- 语法：父节点.insertBefore(新节点,旧节点);
```javascript
// 添加墨祈到墨愿前
// 创建新node
var li = document.createElement("li");
var newText = document.createTextNode("墨祈");
li.appendChild(newText);
// 找到父节点，并添加新节点到旧节点之前
var person = document.getElementById("person");
var my = document.getElementById("my");
person.insertBefore(li,my);
```

#### replaceChild()
- 使用指定的子节点替换已有子节点
- 语法：父节点.replaceChild(新节点,旧节点);
```javascript
// 添加墨祈到墨愿前
// 创建新node
var li = document.createElement("li");
var newText = document.createTextNode("墨祈");
li.appendChild(newText);
// 找到父节点，并用新节点替换掉旧节点
var person = document.getElementById("person");
var my = document.getElementById("my");
person.replaceChild(li,my);
```

#### innerHTML
- 优点：省事
- 缺点：动作太大，整个父元素跟着改动
```javascript
//添加新node墨愿
li.appendChild(newText);
var person = document.getElementById("person");
person.innerHTML += "<li>墨愿</li>"
```

#### innerHTML和appendChild()一起用去添加新node
```javascript
//添加新node墨愿
var li = document.createElement("li");
li.innerHTML = "墨愿";
person.appendChild(li);
```

# 删
#### removeChild()
- 删除一个子节点
- 语法：父节点.removeChild(子节点);
```javascript
var person = document.getElementById("person");
var my = document.getElementById("my");
person.removeChild(my);
```
若父节点未知：
```javascript
var my = document.getElementById("my");
my.parentNode.removeChild(my);
```
# 改
#### innerHTML
```javascript
var my = document.getElementById("my");
my.innerHTML = "墨祈";
```
#### innerText
```javascript
var my = document.getElementById("my");
my.innerText = "墨祈";
```
