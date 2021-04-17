# 【JS】类的操作

目的：一行代码，同时修改多个样式。

可以通过修改元素的class属性来间接修改样式。

定义一个函数，用来向一个元素中添加指定的class属性值。

- 参数：
  - obj - 要添加class属性的元素
  - cn - 要添加的class值

``` javascript
// 向一个元素obj中添加指定的class属性值cn
function addClass(obj,cn){
    if(!hasClass(box, cn)){
        obj.className += " "+cn;
    }
}

// 判断一个元素obj中是否含有指定的class属性值cn。若有，返回true;若无，返回false
function hasClass(obj,cn){
    var reg = new RegExp("\\b" + cn + "\\b");
    return reg.test(obj.className);
}

// 删除一个元素中指定的Class
function removeClass(obj, cn){
    var reg = new RegExp("\\b" + cn + "\\b");
    //删除class
    obj.className = obj.className.replace(reg, ""); 
}

// 切换一个类: 若元素具有该类，则删除; 若没有，则添加
function toggleClass(obj, cn){
    if(hasClass(obj,cn)){
        removeClass(obj,cn);
    }else{
        addClass(obj,cn);
    }
}
```

