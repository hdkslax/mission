confirm()用于弹出一个带有确认和取消按钮的提示框
需要一个字符串作为参数，该字符串将会作为提示文字显示出来
- 确定 = true
- 取消 = false
```javascript
if (confirm("确认删除"+tr.getElementsByTagName("td")[0].innerHTML+"吗？")){
	tr.parentNode.removeChild(tr);
}
```
