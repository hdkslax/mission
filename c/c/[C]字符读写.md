# [C]字符读写

### getchar() / putchar()

语法:

- `char c = getchar();`
- `putchar(c);`

注：在windows下输入EOF需要输入CTRL+Z, Linux/Unix/Mac下要输入EOF需要输入CTRL+D

###### 用法: 复制输入

这段程序的结果就是，你输入什么，它给你输出什么

```c
# include <stdio.h>

int main(){
    int c;
    c = getchar();
    while(c!=EOF){
        putchar(c);
        c = getchar();
    }
}
```

简化版：

```c
# include <stdio.h>

int main(){
    int c;
    while((c = getchar())!=EOF){ // !=比=的优先级高，不加括号的话，先执行getchar()!=EOF，此时c将只有0或1两个值
        putchar(c);
    }
}
```

###### 用法：字符计数

注：这种写法会将EOF也算进去，就是说多算了一个字符，最后应该-1

while的写法：

```c
# include <stdio.h>

int main(){
    long nc = 0;
    while (getchar()!=EOF)
        ++nc;
    printf("%ld\n", nc);
}
```

for的写法：

```c
# include <stdio.h>

int main(){
    double nc;
    for(nc=0; getchar()!=EOF; ++nc)
        ;
    printf("%.0f\n", nc);
}
```



###### 用法：行计数

```c
# include <stdio.h>

int main(){
    int c, nl;
    nl = 0;
    while((c=getchar())!=EOF){
        if(c == '\n')
            ++nl;
    }
    printf("%d\n",nl);
}
```



###### 用法：不同类型字符计数

```c
#include <stdio.h>

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for(i=0;i<10;++i)
        ndigit[i] = 0;
    while ((c=getchar())!=EOF){
        if (c>='0' && c<='9')
            ++ndigit[c-'0'];
        else if (c==' ' || c=='\n' || c=='\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits = ");
    for(i=0;i<10;i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other=%d\n", nwhite, nother);
}
```



###### 用法：输出最长的行

```c
# include <stdio.h>

#define MAXLINE 1000

int getline1(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
    int len; // current line length
    int max; // max length seen so far
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len=getline1(line, MAXLINE))>0){
        if (len>max){
            max = len;
            copy(longest, line);
        }
    }
    if (max>0)
        printf("%s", longest);
    return 0;
}

// return the length of a line
int getline1(char s[], int lim){
    int c, i;
    for (i=0;i<lim-1&&(c=getchar())!=EOF&&c!='\n'; ++i){
        s[i] = c;
    }
    if (c=='\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i;
    i=0;
    while((to[i]=from[i])!='\0')
        ++i;
}
```

