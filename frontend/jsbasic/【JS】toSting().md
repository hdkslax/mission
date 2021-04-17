```javascript
console.log(student1);// "[object Object]"
```
当我们直接在页面中打印一个对象时，事件上是输出对象的toString()方法的返回值

（但谷歌浏览器打印出的是Object的内容）

若希望在输出时不输出[object Object]，可以为对象添加一个toString()方法
