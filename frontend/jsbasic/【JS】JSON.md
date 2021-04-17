# 【JS】JSON

- JS中的对象只有JS自己认识，其他语言都不认识。
- 一般各种语言的对象其他语言都不认识。
- JSON就是一个特殊格式的字符串，这个字符串可以被人以的语言所识别，并且可以转换为任意语言中的对象。

#### JSON 

- JavaScript Object Notation JS对象表示法
- JSON和JS对象的格式一样，只不过JSON字符串中的属性名必须加双引号，不能不加，也不能换成单引号。

```javascript
var obj = '{"name":"墨祈", "age":18, "gender":"男"}';
```

#### JSON分类

- 对象 {}
- 数组 []

```javascript
var obj = '{"name":"墨祈", "age":18, "gender":"男"}'; // 对象
var arr = '[1,2,3,"hello", true]'; // 数组
```

#### JSON中允许的值：

- 字符串
- 数值
- 布尔值
- null
- 对象
- 数组
- 函数不行，只能在js中用

#### 将JSON字符串转换为JS中的对象

- 在JS中，为我们提供了一个工具类，就叫JSON
- 这个对象可以帮助我们将一个JSON转换为JS对象，也可以将一个JS对象转换为JSON
  - json -> js对象：`JSON.parse()`
  - js对象 -> json:`JSON.stringify()`

```javascript
var json = '{"name":"墨祈", "age":18, "gender":"男"}';

// json -> js对象
var o = JSON.parse(json);
//js对象 -> json
var str = JSON.stringify(o);
```

#### 注意

- JSON这个对象在IE7及以下的浏览器中不支持，所以在这些浏览器中调用会报错。

- 兼容IE7：

  - `eval()` 

    - 这个函数可以用来执行一段字符串形式的JS代码，并将执行结果返回。
    - 若此函数执行的字符串中含有`{}`,它会将`{}`当成代码块
    - 若不希望将其当做代码块解析，则需要将字符串用`()`括起来

    ```javascript
    var str = '({"name":"墨祈", "age":18, "gender":"男"})';
    var obj = eval(str);
    ```

    或者

    ```javascript
    var str = '{"name":"墨祈", "age":18, "gender":"男"}';
    var obj = eval("("+str+")");
    ```

    * 这个函数的功能很强大，可以直接执行一个字符串中的js代码，但是再开发中尽量不要使用
      * 执行性能较差，慢
      * 具有安全隐患
    * 若需兼容IE7及以下的JSON操作，则可以引入一个外部的js文件来处理