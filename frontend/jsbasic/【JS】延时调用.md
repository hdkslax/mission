# 【JS】延时调用

### 延时调用 setTimeout()

- 延时调用一个函数，函数不马上执行，而是隔一段时间以后再执行，而且只会执行一次。
- 当一个定时调用只需要执行一次时，延时调用和定时调用实际上是可以互相代替的。

```javascript
var timer = setTimeout(function(){
    console.log(" ");
}, 3000);
```

- 使用`clearTimeout()`来关闭一个延时调用

```javascript
clearTimeout(timer);
```



