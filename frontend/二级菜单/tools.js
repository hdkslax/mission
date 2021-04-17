// 参数
// 	obj: 要执行的对象
// 	attr: 要执行的样式
//	target: 执行动画的目标位置
//	speed: 移动的速度
// 	callback: 动画执行完毕，调用回调函数
function move(obj, attr, target, speed, callback){
    clearInterval(obj.timer);
    var current = parseInt(getStyle(obj,attr));
    if(current > target){
        speed = -speed;
    }
    obj.timer = setInterval(function(){
        var oldValue = parseInt(getStyle(obj,attr));
        var newValue = oldValue + speed;

        if((speed < 0 && newValue < target) || (speed > 0 && newValue > target)) { // move to left
            newValue = target;
        }

        obj.style[attr] = newValue + "px";

        if (newValue == target) {
            clearInterval(obj.timer);
            callback && callback();
        }
    }, 30);
}

function getStyle(obj,name){
    if(window.getComputedStyle) // 加window将变量变为属性，因为变量不存在会报错
        return getComputedStyle(obj,null)[name];
    else
        obj.currentStyle[name];
}

// 向一个元素obj中添加指定的class属性值cn
function addClass(obj,cn){
    if(!hasClass(obj, cn)){
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