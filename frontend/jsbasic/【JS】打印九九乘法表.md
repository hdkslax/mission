```
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title></title>
		<!--JS代表放script标签中-->
		<script type="text/javascript">
			for (var i=1; i < 10; i++){
				for (var j=1; j<=i; j++){
					document.write("<span>" + j + "*" + i + "=" + i*j + "</span>");
				}
				document.write("</br>");
			}
		</script>
		<style>
			span {
				display: inline-block;
				width: 80px;
			}
		</style>
	</head>
	<body>
		
	</body>
</html>

```

![在这里插入图片描述](img\打印九九乘法表.png)

