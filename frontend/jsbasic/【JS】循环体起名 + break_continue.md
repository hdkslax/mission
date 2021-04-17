震惊！JS里的循环体居然可以起名！
还能用break来控制停止哪个循环体！
```
outer:
for (var i=0; i<5; i++) {
	console.log("外层循环：" + i);
	for (var j=0; j<5; j++) {
		break outer;
		console.log("内层循环：" + j);
	}
}
```
