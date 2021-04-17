# 【JS】BOM

### BOM

- 浏览器对象模型
- BOM可以使我们通过JS访问浏览器
- 在BOM中为我们提供了一组对象，用来完成对浏览器的操作

#### BOM对象

- Window - 整个浏览器的窗口，同时也是网页中的全局对象
- Navigator - 当前浏览器的信息，通过该对象可以来识别不同的浏览器
- Location - 当前浏览器的地址栏信息，通过Location可以获取地址栏信息，或者操作跳转界面
- History - 浏览器的历史记录，可以通过对象来操作浏览器的历史记录。
  - 由于隐私原因，该对象不能获取到具体的历史记录，只能操纵浏览器向前或向后翻页。
  - 该操作只在当次访问时有效。
- Screen - 用户的屏幕信息，通过该对象可以获取到用户显示器的相关信息。

这些BOM对象在浏览器中都是作为window对象的属性来保存的，可以通过window对象来使用，也可以直接使用。

### Navigator

- 当前浏览器的信息，通过该对象可以来识别不同的浏览器
- 由于历史原因，Navigator独享中国的大部分属性已经不能帮我们识别浏览器了
- 一般我们只会使用`userAgent`来判断浏览器信息
  - `useAgent`是一个字符串，这个字符串中包含有用来描述浏览器信息的内容

##### appName

`Netscape` - 火狐、Ghrome、IE

`Microsoft Internet Explorer` - IE8,9,10

##### useAgent

火狐 - `Mozilla/5.0 (Windows NT 10.0; WOW64; rv:50.0) Gecko/20100101 Firefox/50.0`

Chrome - `Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36`

Edge - `Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.90 Safari/537.36 Edg/89.0.774.54`

IE11 - 已经将微软和IE相关的标识全部去除，基本已经无法通过`userAgent`来识别IE11。课通过一些浏览器中特有的对象，来判断浏览器的信息，比如：`currentStyle`，`attachEvent`，但无法直接通过`ActiveXObject`来判断IE11，可用`"ActiveXObject" in window`来判断

```javascript
var ua = navigator.userAgent
console.log(navigator.userAgent);
if(/firefox/i.test(ua)){
	alert("火狐");
}else if(/chrome/i.test(ua)) {
	alert("Chrome");
}else if(/msie/i.test(ua)){
	alert("IE");
}else if ("ActiveXObject" in window){
	alert("IE11");
}
```



### History

- 用来操作浏览器向前向后翻页
- `history.length` - 获取当前访问链接的数量
- `history.back()` - 回退到上一个页面，作用和浏览器的回退按钮一样
- `history.forward()` - 跳转到下一个页面，作用和浏览器的前进按钮一样
- `history.go()` - 跳转到指定页面，需要一个整数作为参数
  - 1 - 向前跳转1个页面
  - 2 - 向前跳转2个页面
  - -1 - 向后跳转1个页面

### Location

- 该对象中封装了浏览器地址栏的信息

  ```javascript
  // 若直接打印location，则可以获取到地址栏的信息（当前页面完整路径）
  alert(location);//http://localhost:63342/%E5%89%8D%E7%AB%AF%E7%BB%83%E4%B9%A0/JS01.html?_ijt=63qfct0br9u02sr56s18kfpaui
  ```

- 修改location

  - 绝对路径/相对路径都可以
  - 会生成相应的历史记录

  ```javascript
  location = "http://www.baidu.com";
  ```

- `assign()` - 跳转到其他页面，作用和直接修改location一样

  ```javascript
  location.assign("http://www.baidu.com");
  ```

- `reload()` - 重新加载当前页面，作用和刷新按钮一样

  - 刷新页面后，`input`文本框中的内容还在，ctrl+f5可强制清空缓存刷新
  - 在`reload()`方法中传入参数`true`，也可强制清空缓存刷新

- `replace()` - 可以使用新的页面替换当前页面，调用完毕也会跳转页面

  - 不会生成历史记录

  ```javascript
  location.replace("http://www.baidu.com");
  ```

  





