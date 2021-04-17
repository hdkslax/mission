## C语言

```srand()``` 设置种子

```rand()```

###### 范围

```[0,RAND_MAX)``` 

###### 生成随机数

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    int a = rand();
    printf("%d\n", a);
    return 0;
}
```

###### 生成一定范围内的随机数

```c
int a = rand() % 10;    //产生0~9的随机数，注意10会被整除
int a = rand() % 50 + 10;    //产生10~60的随机数
```



## C++

```srand()``` 设置种子 - 当用户未设定随机数种子时，系统默认的随机数种子为1

```rand()``` 

###### 范围

```[0,RAND_MAX)``` 

###### 生成随机数

```cpp
#include <iostream>
#include <cstdlib> // Header file needed to use srand and rand
using namespace std;
int main()
{
    unsigned seed;  // Random generator seed
    // Get a nseed" value from the user
    cout << "Enter a seed value: ";
    cin >> seed;
    // Set the random generator seed before calling rand()
    srand(seed);
    //Now generate and print three random numbers
    cout << rand() << " ";
    cout << rand() << " ";
    cout << rand() << endl;
    return 0;
}
```

###### 生成一定范围内的随机数

```cpp
// number = rand() % max + 1;
dice = rand() % 6 + 1; // 生成1~6的随机数

// number = (rand()%(maxValue - minValue +1)) + minValue;
number = rand() % (18 - 10 + 1) + 10; // 生成10~18的随机数
```



## Java

```import java.util.Random```

| 方法                    | 说明                                                         |
| ----------------------- | ------------------------------------------------------------ |
| boolean nextBoolean()   | 生成一个随机的 boolean 值，生成 true 和 false 的值概率相等   |
| double nextDouble()     | 生成一个随机的 double 值，数值介于 [0,1.0)，含 0 而不包含 1.0 |
| int nextlnt()           | 生成一个随机的 int 值，该值介于 int 的区间，也就是 -231~231-1。如果 需要生成指定区间的 int 值，则需要进行一定的数学变换 |
| int nextlnt(int n)      | 生成一个随机的 int 值，该值介于 [0,n)，包含 0 而不包含 n。如果想生成 指定区间的 int 值，也需要进行一定的数学变换 |
| void setSeed(long seed) | 重新设置 Random 对象中的种子数。设置完种子数以后的 Random 对象 和相同种子数使用 new 关键字创建出的 Random 对象相同 |
| long nextLong()         | 返回一个随机长整型数字                                       |
| boolean nextBoolean()   | 返回一个随机布尔型值                                         |
| float nextFloat()       | 返回一个随机浮点型数字                                       |
| double nextDouble()     | 返回一个随机双精度值                                         |

###### 生成随机数

```java
import java.util.Random;
public class Test {
    public static void main(String[] args) {
        Random r = new Random();
        double d1 = r.nextDouble(); // 生成[0.0,1.0)区间的小数
        int i1 = r.nextInt(10); // 生成[0,10)区间的整数
        }
    }
}
```

###### 生成一定范围的随机数

```java
import java.util.Random;
public class Test {
    public static void main(String[] args) {
        Random r = new Random();
        double d1 = r.nextDouble() * 6; // 生成[0.0,6.0)区间的小数
        int i2 = r.nextInt(18) - 3; // 生成[-3,15)区间的整数
    }
}
```



## Python

```import random```

```random.random()```



###### random.random()

用来随机生成一个0到1之间的浮点数，包括零。

```python
import random

r = random.random() # 0.15790797219589303
```

###### randint(a, b)

用来生成[a,b]之间的随意整数，包括两个边界值。

```python
import random

random.randint(1,6) # 1
```

###### random.uniform(a,b)

用来生成[a,b]之间的随意浮点数，包括两个边界值。

```python
import random

random.uniform(1,6) # 5.497873150216069
```

###### random.choice(seq)

从一个非空序列选出随机一个元素。seq泛指list，tuple，字符串等

```python
import random

List = [1,2,3,4,5,6]
random.choice(List) # 1
```

###### randrange(start, stop[, step = 1])

这个就是random和range函数的合二为一了。但注意，range用法有变。

```python
import random

random.randrange(1,6) # 3
```

###### random.shuffle(x[,random])

正如函数名所表示的意思，shuffle，洗牌，将一个列表中的元素打乱。

```python
import random

List = [1,2,3,4,5,6]
random.shuffle(List)
print(List) #[2, 1, 6, 4, 5, 3]
```

###### random.sample(sequence,k)

sample，样品，从有序列表中选k个作为一个片段返回。

```python
import random

List = [1,2,3,4,5,6]
random.sample(List,3) # [4, 6, 3]
```

###### random.seed ( [x] )

x:改变随机数生成器的种子seed。如果你不了解其原理，你不必特别去设定seed，Python会帮你选择seed。使用同一个种子，每次生成的随机数序列都是相同的。

```python
import random

random.seed(10)
print("Random number with seed 10: ", random.random())
 # Random number with seed 10:  0.5714025946899135

random.seed(10)
print("Random number with seed 10: ", random.random())
# Random number with seed 10:  0.5714025946899135

random.seed(10)
print("Random number with seed 10: ", random.random())
# Random number with seed 10:  0.5714025946899135
```