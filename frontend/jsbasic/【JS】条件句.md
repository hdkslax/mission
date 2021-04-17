# if
```
if(条件句){
	语句
} else if (条件句) {
	语句
} else {
	语句
}
```
# switchs
```
switch(条件表达式){
	case 表达式1:
		语句...
		break;
	case 表达式2:
		语句...
		break;
	default:
		语句...
		break;
}	
```
例：
```
switch (parseInt(score/10)){
	case 10:
	case 9:
	case 8:
	case 7:
	case 6:
		console.log(“合格”);
		break;
}
```
