@[TOC](DOM)

# DOM
Document Object Model 文档对象模型
- JS中通过DOM来对HTML文档进行操作，只要理解了DOM就可以随心所欲的操作WEB页面。
- 文档：Document 文档表示的是整个HTML网页文档
- 对象：Object 对象表示将网页中的每一个部分都转换为了一个对象。
- 模型：Model 使用模型来表示对象之间的关系，这样方便我们获取对象。

## 模型
![在这里插入图片描述](img\DOM1.png)
## 节点 Node
节点 - 是构成网页的最基本的组成部分，网页中的每一个部分都可以称为是一个节点。比如：html标签、属性、文本、注释、整个文档等都是一个节点。

虽然都是节点，但世界上他们的具体类型不同。比如：标签称为元素节点、属性称为属性节点、文本称为文本节点、文档称为文档节点。

节点的类型不同，属性和方法也不尽相同。

### 四类常用节点
- 文档节点：整个HTML文档
- 元素节点：HTML文档中的HTML标签
- 属性节点：元素的属性
- 文本节点：HTML标签中的文本内容
![在这里插入图片描述](img\DOM2.png)
### 节点的属性
|  |nodeName | NodeType | nodeValue |
|--|--|--|--|
|文档节点  | #document | 9 | null |
|元素节点  | 标签名 | 1 | null |
|属性节点  | 属性名 | 2 | 属性值 |
|文本节点  | #text | 3 | 文本内容 |

### 文档节点
浏览器已经提供了 文档节点 对象，这个对象是window的属性，可以在页面中直接使用，文档节点代表的是整个网页。
```javascript
console.log(document);//打印出整个网页的代码
```
```html
<button id="btn">按钮1</button>
<script type="text/javascript">
	var btn = document.getElementById("btn");
	console.log(btn);//<button id="btn">按钮1</button>
</script>
```
修改按钮文字
```javascript
btn.innerHTML = "This is a Button";
```

## 事件
事件 - 就是文档或浏览器窗口中发生的一些特定的交互瞬间。
- JavaScript与HTML之间的交互是通过事件实现的。
- 对于Web应用来说，有下面这些代表性的事件：
	- 点击某个元素
	- 将鼠标移动至某个元素上方
	- 按下键盘上某个键
	- etc
- 在事件对应的属性中设置一些JS代码，当事件被触发时，这些代码将会执行。
```javascript
<button id="btn" ondblclick="alert('凸(艹皿艹 )')">按钮1</button>
```
上面一行代码的写法叫做结构和行为耦合，不方便维护，不推荐使用。
可以为按钮的对应事件绑定处理函数的形式来响应事件。
```html
<button id="btn">按钮1</button>
		<script type="text/javascript">
			var btn = document.getElementById("btn");
			btn.onclick = function () {
				if(btn.innerText=="按钮1")
					btn.innerText = "按钮2";
				else if(btn.innerText == "按钮2")
					btn.innerText="按钮1";
			};
		</script>
```
