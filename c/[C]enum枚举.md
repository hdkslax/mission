# [C]enum枚举

没有显式说明的情况下，enum类型中第一个枚举值为0，第二个为1，以此类推。

若只指定了部分枚举的值，那么未指定的值将依着最后一个指定值向后递增。

```c
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB 的值为 2，MAR 的值为 3，依此类推 */
```

