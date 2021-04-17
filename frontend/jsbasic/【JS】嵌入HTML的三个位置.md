### 外部JS引入HTML

将js代码编写到外部js文件中，然后通过`script`标签引入

写到外部文件中可以在不同的页面中引用，也可以利用到浏览器的缓存机制

```html
<head>
	<script type="text/javascript" src="js/script.js"></script>
</head>
```

### 将js代码编写到script标签中

```html
<script type="text/javascript">
	alert("主人，我在script标签中哦");
</script>
```

`script` 标签一旦用于引入外部文件了，就不能在标签内部编写代码了，即使编写了浏览器也会忽略 

### 将js代码编写到HTML标签中

###### 放在HTML标签的onclick属性中，点击后js代码才会执行

```html
<button onclick="alert('讨厌,点我干嘛~')"> 主人点我QVQ </button>
```

###### 放在超链接的href属性中，点击超链接才会执行js代码

```html
<a href="javascript:alert('[笑]讨厌~')"> 主人,我也要~</a>
<a href="javascript:;"></a>
```


