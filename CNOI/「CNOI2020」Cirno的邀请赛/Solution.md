#                $\ \ \ \ \ \ \ \ $「Cnoi2020」Cirno的邀请赛 $\ \ \ \ \ \ \ \ $ Solution

## A [子弦(Substring)](https://www.luogu.com.cn/problem/P6832)

**Tags : 最优化 / 字符串 / 贪心**

>  求字符串 $\texttt{S}$ 出现次数最多的子串的出现次数。
>
> $|\texttt{S}| \le 10^7，S_x \in [a,z]$。

#### 算法一

枚举子串的左右端点，暴力匹配判断子串的出现次数。

时间复杂度 $O(n^4)$，期望得分 $40$。

#### 算法二

后缀排序，求出后缀数组 $\texttt{height}$ 的最长非 $0$ 子段。

时间复杂度视实现方法 $O(n)$ ~ $O(n\ln n)$  不等，期望得分 $80$。

#### 算法三

定义 $f(\texttt{A})$ 表示 $\texttt{A}$ 在 $\texttt{S}$ 中的出现次数。

若 $\texttt{B}$ 是 $\texttt{A}$ 的子串，则有 $f(\texttt{A})\le f(\texttt{B})$ 恒成立。

所以有贪心： $\texttt{S}$ 出现次数最多的子串一定是单个字母。直接统计 $\texttt{S}$ 的所有字母出现次数求最大值即可。

时间复杂度 $O(n)$，期望得分 $100$。

<div STYLE="page-break-after: always;"></div>

## B [雷雨(Thunderstorm)](https://www.luogu.com.cn/problem/P6833)

**Tags : 最优化 / 图论 / 最短路**

> 求一个 $n\times m$ 的网格图上边缘一点 $\texttt{A}(1,a)$ 到下边缘两点 $\texttt{B}(n,b)$, $\texttt{C}(n,c)$ 的路径并的权值和的最小值。
>
> $n,m \le 1000$，$1\le a,b,c \le m$，$R_{i,j} \le 10^9$。

#### 算法一

针对子任务一。

根据 $a$ 是否在区间 $[b,c]$ 内分类讨论，最优方案分别为 $\texttt{T}$状路径 与 $\texttt{L}$状路径。

期望得分 $10$。

#### 算法二

按题意搜索两条路径，模拟求并集，并取最小值。

视剪枝强力程度，期望得分 $0$ ~ $10$。结合算法一期望得分 $10$ ~ $20$。 

#### 算法三

针对子任务三。

$\texttt{A}$ 到 $\texttt{B}$ 与 $\texttt{C}$ 路径完全重合。所以问题变成了从 $\texttt{A}$ 到 $\texttt{BC}$ 的最短路。

所以使用堆优化的 $\texttt{Dijkstra}$ 或 $\texttt{SPFA}$ 算法即可。

复杂度 $O(mn(\ln n+\ln m))$，期望得分 $10$。结合前述算法可得 $10$ ~ $30$ 分不等。

#### 算法四

发现二叉闪电的形状是最优的，因为如果路径交叉，则环从两个交叉点分成的两段可以只取一段更小的。

所以分别从三点跑一次单源最短路，枚举二叉闪电的分裂点，即可求解最小值。

时间复杂度 $O(nm(\ln n+\ln m))$，期望得分 $100$。

#### 算法五

知道上述结论，但不会低于 $O(n^2)$ 的最短路算法，可以使用 $01\texttt{bfs}$ 通过子任务二。

期望得分 $20$。

<div STYLE="page-break-after: always;"></div>

## C [梦原(Dreamic Plain)](https://www.luogu.com.cn/problem/P6834)

**Tags : 最优化 / 贪心 **& **计数 / 期望 / 树状数组** 

> $n$ 个节点，每个节点向 $[i-k,i-1]$ 随机连边成一棵树。每次可以选择一个连通块权值都减 $1$，求使得全树权值都变成 $0$ 的最小次数的数学期望。
>
> $k \le n \le 10^6$，$a_i \le 10^9$。

#### 算法一

针对子任务一。

枚举树的形态，然后 $\texttt{bfs}$ 搜索全 `1` 连通块数量。

时间复杂度 $O(nk^n)$，期望得分 $10$。

#### 算法二

针对子任务三，树是一条链的情况。

这就变成经典题 [Noip2013积木大赛](https://www.luogu.com.cn/problem/P1969) / [Noip2018铺设道路](https://www.luogu.com.cn/problem/P5019)。

使用能通过原题的各种方法均可通过这个子任务，期望得分 $10$。

#### 算法三

考虑枚举树的形态，然后将原题的线性做法移植到树上。

原题的线性做法是一种贪心 : 如果 $a_{i+1}>a_i$，则答案加上 $a_{i+1}-a_i$。

对应到树上就是 : 设 $i$ 的父节点是 $f_i$，如果 $a_i>a_{f_i}$ ，则答案加上 $a_i-a_{f_i}$。

时间复杂度 $O(nk^n)$，期望得分 $30$。

#### 算法四

发现答案的贡献均在 $i$ 与 $f_i$ 之间，而 $f_{i} \in [i-k,i-1]$。

所以答案 $E=\sum\limits_{i,j}\big(P(j\rightarrow i)\times \max\{a_i-a_j,0\}\big)$

所以对于每个 $i$ 枚举可能的 $f_i$ 求出贡献即可。

时间复杂度 $O(nk)$，期望得分 $40$。

#### 算法五

由于 $i$ 可行的 $f_i$ 是长度相同连续一段，且答案有可减性，所以可以用树状数组维护值域。

具体地，维护 $[i-k,i-1]$ 中小于某值的 $a_x$ 数量，与小于某值的 $a_x$ 和即可。

时间复杂度 $O(n\ln n)$，期望得分 $100$。

<div STYLE="page-break-after: always;"></div>

## D [线形生物(Linear Creature)](https://www.luogu.com.cn/problem/P6835)

**Tags : 计数 / 期望 / DP**

> 求一条 $n+1$ 个节点的单向链，$m$ 条返祖边组成的图上从 $1$ 号节点随机游走到 $n+1$ 号节点的期望步数。
>
> $n,m \le 10^6$，$1≤v_i≤u_i≤n$。

#### 找规律

三个经典问题，结论分别为:

 - Subtask1 : $2\times n$
 - Subtask2 : $n\times(n+1)$
 - Subtask3 : $2^{n+1}-2$

其中 Subtask3 的结论可以在 [m67大神的博客](http://www.matrix67.com/blog/archives/3638) 上找到。

期望得分 $0$ ~ $30$。

#### 算法一
经典随机游走问题，可以高斯消元，解法见 [[HNOI2013]游走](https://www.luogu.com.cn/problem/P3232)。

时间复杂度 $O(n^3)$，期望得分 $10$。

#### 算法二 

期望DP。

设 $f_i$ 表示线性生物第一次到达 $i$ 号节点的期望步数，所求的答案即是 $f_{n+1}$。

设 $S_i$ 表示返祖图中以 $i$ 号节点开始的边所到的节点的集合。

某次，线形生物从 $i$ 号节点走到 $i+1$ 号节点的概率是 $\frac{1}{|s_i|+1}$，记作 $p$。

令第一次到达 $i+1$ 号节点前，线形生物到达 $i$ 号节点的次数为 $\xi$，$\xi$ 的分布列如下 :

|    $\xi_o$     |  1   |    2     |     3      | $\cdots$ |       i        | $\cdots$ |
| :------------: | :--: | :------: | :--------: | :------: | :------------: | :------: |
| $P(\xi=\xi_0)$ | $p$  | $(1-p)p$ | $(1-p)^2p$ | $\cdots$ | $(1-p)^{i-1}p$ | $\cdots$ |

所以 $E(\xi)=\sum\limits_{i=1}^{\infty}i\times P(\xi=i)=\frac{p}{1-p}\sum\limits_{i=1}^{\infty}i\times(1-p)^i=\frac{p}{1-p}\sum\limits_{i=1}^{\infty}\sum\limits_{j=i}^{\infty}(1-p)^j=\frac{p}{1-p}\sum\limits_{i=1}^{\infty}(1-p)^{i+1}\times\frac{1}{\frac{1}{(1-p)}-1}=\frac{1}{p}=|S_i|+1$

所以第 $i$ 个点期望经过 $|s_i| + 1$ 次，又 $i$ 的出边有 $|S_i| + 1$ 条，所以每条出边期望经历一次。

而对于一条返祖边 $i\rightarrow j\ ( j \le i )$，经历一次后到达 $j$ 号节点，再返回 $i$ 的期望步数为 $f_i-f_j$。

于是有 DP 方程 :
$$
f_1=0
$$

$$
f_{i+1}=f_i+|S_i|+1+\sum\limits_{j \in S_i}(f_i-f_j)
$$

于是直接模拟上式是 $O(n+m)$ 的，期望得分 $100$。

进一步优化到 $O(m)$ 也很容易，这里不再赘述。

#### EXTRA 
用 DP 方程推导 Subtask1,2,3 的结论。

**Subtask1**

因为 $f_i=f_{i-1}+2$，$f_1=0$，所以 $f_{n+1}=2\times n$。

**Subtask2**

$f_{i+1}=f_{i}+2+(f_i-f_{i-1}) \iff (f_{i+1}-f_i)=(f_i-f_{i-1})+2$，

令 $g_i=f_i-f_{i-1}$，所以 $g_i=2(n-1)$，

$f_{n+1}=g_{n+1}+g_{n}+\cdots+g_1=n(n+1)$。

**Subtask3**

$f_i=2f_{i-1}+2$，所以 $f_i+2=2(f_{i-1}+2)$，又 $f_1+2=2$，

所以 $f_{n+1}+2=2^{n+1}$，即 $f_{n+1}=2^{n+1}-2$。
