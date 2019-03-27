## 有关printf的一个问题



```c
int main() {
    int a = 1048577; // 2^20 + 1
    size_t b = 4096; // 2^12
    long long asize = a * (long long) b;
    printf("%d %d\n", sizeof(size_t), sizeof(long long));
    printf("%d %lld\n", (size_t)asize, asize);
    printf("%lld %lld\n", (size_t)asize, asize);
    return 0;
}
```

输出如图：

![1551342383977](有关printf的一个问题.assets/1551342383977.png)



问题在于：为什么左边的输出占位符会影响右边的输出？

> 这里有答案：
>
> https://blog.csdn.net/u011497904/article/details/42454483

> **原因在于**printf后边的变量以栈的方式存储，而%f、%lld等转换说明符的操作方式是从栈中读取该符号对应数据类型的字节数，并不关心后边对应的数据类型具体是什么！

>  ![img](有关printf的一个问题.assets/20150106102048152.jpg)
>
> *其中，上面是栈底，n4先入栈，n1最后入栈；*
>
> *输出先输出第一个%ld，读取的是float n1(4字节)；*
>
> *接下来的两个%ld读取n2的前一半和后一半；*
>
> *最后一个%ld读取的是n3*



现在具体分析我们的例子：

```c
int main() {
    int a = 1048577; // 2^20 + 1
    size_t b = 4096; // 2^12
    long long asize = a * (long long) b;
    printf("%d %d\n", sizeof(size_t), sizeof(long long));
    printf("%d %lld\n", (size_t)asize, asize);
    printf("%lld %lld\n", (size_t)asize, asize); // 主要分析这一句
    return 0;
}
```

首先，参数从右往左入栈，64位的asize在栈底，32位的asize在栈顶。

**第一个占位符 %lld 代表着64位整数的占位符**，所以printf会按照从栈顶到栈底的顺序取8个字节。

这八个字节分别是32位的asize的四个字节，以及64位的asize的前四个字节。

由 asize 在内存中表示为 00 10 00 00 01 00 00 00 （小端模式）

得出printf会取 00 10 00 00 00 10 00 00

用小端模式来解释的话，这一串字节的表示0x0000 1000 0000 1000

![1551343593662](有关printf的一个问题.assets/1551343593662.png)

也就是 17592186048512 的十六进制。

**接下来第二个 %lld 则取栈内所剩的 asize 的后四个字节，再加上栈底之外的 4 个字节。在这里，引发了栈底溢出。**



#### 结论：

在 printf 函数中，对不同类型的数据采用正确的占位符是非常重要的，否则将会影响到所有数据的输出。