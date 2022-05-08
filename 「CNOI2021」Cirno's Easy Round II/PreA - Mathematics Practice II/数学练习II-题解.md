#### Mathematics Practice II 题解

**Tags** : 计数 / 组合数学

由于 $|\texttt{S}|\not\in \texttt{S}, |\texttt{T}|\not\in \texttt{T}$，所以 $|\texttt{S}|\in \texttt{T},|\texttt{T}|\in \texttt{S}$。

所以将其他元素任意分配到两个集合，$|\texttt{S}|,|\texttt{T}|$ 有唯一放置方案。

所以，当 $n$ 为奇数时，答案为 $2^{n-2}$。

当 $n$ 为偶数时，可能出现 $|\texttt{S}|=|\texttt{T}|$ 的情况，答案为 $2^{n-2}-{n-2\choose{(n-2)/2}}$。