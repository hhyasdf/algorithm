#### 动态规划 ####

动态规划是一种很重要的算法设计思想，通常用来解决最优解问题。我们可以把它看成一种详尽的搜索，通常这种搜索效率是很差的（指数级别的时间复杂度），我们需要野蛮地找到所有可能的解。但在动态规划中，最重要的是，我们需要**重用我们已经算出的子问题的解**来加速算法（多项式级别的复杂度）。通常这是通过一个备忘录（一般是数组或字典）来实现的。而子问题，则是我们最后解决目标问题的依据。此时算法的复杂度变成了需要解决的子问题的个数。

动态规划问题的**自顶向下解法**通常从目标问题出发，采用**递归+全局备忘录**的方式解决。通常这样会产生额外的函数调用开销，也为解决方案的输出造成了一些困惑，更重要的是某些OJ平台通不过。。。。所以是比较次的dp方法。

**自底向上的解决方法**，通常从最基本的子问题出发，不断上溯解决上一级的子问题，最终解决目标问题。不使用递归的函数调用，而是使用多层循环。（通常循环体中的代码与递归加备忘录函数体中的部分代码类似，只不过其中递归调用函数本身求解子问题变成了在备忘录中查找子问题的解，这意味着需要之前已经解决了该子问题，也就是需要**将规模较小的子问题先解决再解决规模较大的子问题**）这也类似于描述了所有子问题加目标问题的有向无环图的拓扑排序（问题之间的依赖关系为边的反向），然后我们所做的就是**从左到右按照拓扑排序出顺序求解子问题**。自底向上的动态规划还有个好处就是可以节约空间，当你确定某个子问题的解之后不会再被用到，就可以删除掉它。

动态规划中还有一个重要的点是所谓的最优子问题结构。（私以为这个名字起得很蠢）我们实际上需要描述的是，假设所有**规模略小的*相同问题***（并不是一次到最小规模，也许只是subquestion[n-1]这种，比如说最短路径问题）已经被解决，我们该如何解决目标问题（这往往需要我们利用一些问题的性质，往往也是设计时比较麻烦的地方）；而我们需要的就是用来（使用规模略小的相同问题的解）解决目标问题的所有方案中，最优的那一个。最麻烦的就是如何定义子问题，以用来解决目标问题。

我们同样以**最短路径问题**为例，求源点到某一点的最短路径；这个问题的特殊性质是，*从源点到某一点的路径的所有子路径一定是对应两点的最短路径* ，这意味着我们的目标问题可以变为求解：*从源点到为目标点入度的任一点的最短路径加上从该点到目标点的边的权重* 的所有可能情况中的最小值。（但这个问题*可以导致我们陷入无限循环*，因为子问题可能依赖目标问题，比如说目标点是其相邻节点的入度的另一端点，而某一子问题需要求解源点到该相邻节点的最短路径，此时子问题的依赖关系不再是一个有向无环图，而是有环的。此时我们可以为子问题增加某些限制以破坏该环，比如说限制到达目标点的路径上边的个数；这不会影响我们的正常求解，因为我们仍然可以将所有子问题求出）

有一些tips来定义子问题：

对于**序列**或**字符串** （大多数问题都可以转化为序列和字符串），我们可以使用序列（字符串）的**后缀**的性质来定义子问题（类似于 $subquestion([x:]) = max\{whatever_1 + subquestion([y_1:]), ... ,whatever_i + subquestion([y_i:]), ...\}$，其中 $y_i > x$ ，$whatevet_i$ 通过直接求解其它部分得到）；

但有时后缀没什么用，我们可以考虑**前缀**，（类似于 $subquestion([:x]) = max\{whatever_1 + subquestion([:y_1]), ... ,whatever_i + subquestion([:y_i]), ...\}$，其中 $y_i < x$），$whatevet_i$ 通过直接求解其它部分得到；

如果前缀和后缀都没用的话，我们考虑**子串**，即 x[i:j]，考虑子序列的算法复杂度要高些，我们需要求出所有子序列（不管需不需要用），每个规模的求解最优子序列组合的复杂度为 O($n$)，子序列个数为 O($n^2$)，总复杂度为 O($n^3$)。

对于 $m$ 个**矩阵的乘法问题**，不同的处理顺序（即加上不同方案的任意个括号）会导致不同的处理效率。我们需要得到最优的矩阵乘法效率。此时我们可以将所有矩阵看成一个序列。只考虑前缀和后缀对该问题具有局限性。所以我们考虑*子序列*。对于一个子序列 A[i:j]，我们假设规模比其小的子问题（求解矩阵的代价）已经被解决并保存在 $P[][]$ 数组中（第一维表示子序列的起始位置，第二维表示序列的长度），那么我们可以得出 $P[i][j] = min\{P[i][1] + P[i+1][j-1], ..., P[i][k]+P[i+k][j-k], ... \}$ 

然后可以通过自底向上或自顶向下解决该问题。这样空间复杂度为 O($n^2$)。

对于**编辑距离（edit distance）问题**来说，我们既可以使用前缀也可以使用后缀来构造子问题。编辑距离指的是，提供给我们两个字符串x和y，我们可以**采用insert、delete和replace操作来修改其中某一个字符串的每一个字符使两字符串相同**，每个操作都要付出一定的代价，所有可能的操作组合的***最小总代价***就是我们要求的编辑距离（也可以作为文本相似度的相反意义）。如果我们用后缀来构造子问题：

对于字符串x、y，我们使用 $M[][]$ 来保存子问题的计算结果。$M[i][j]$ 表示后缀 $x[i:]$ 与 $y[j:]$ 的编辑距离。对于一个后缀，假设我们修改字符串x来使其与y相同（反正是对称的），我们现在要求 $M[i][j]$ ，我们假设规模比其小的子问题已经被求解了，那么意味着我们现在要求怎样修改 $x[i]$ 来使 $x[i:]$ 等于 $y[j:]$ 的代价最小（因为每次只能操作一个字符，并且编辑距离是*最小*的总操作代价，那么加上已经求出的编辑距离就是可能的编辑距离）。有三种可能性（要注意规模比其小的编辑距离已经被求解了，分别为 $M[i+1][j]$ 、$M[i][j+1]$ 和 $M[i+1][j+1]$）：

1. 将 $x[i]$ replace为 $y[j]$
2. 将 $x[i]$ delete
3. 将 $y[j]$ insert到 $x[i]$ 前面

此时，如果 $x[i]$ 等于 $y[j]$ ，$M[i][j]$ 等于 $M[i+1][j+1]$ ，否则：

$M[i][j] = min\{cost\_of_\_repalce + M[i+1][j+1],cost\_of_\_delete + M[i+1][j],cost\_of_\_insert + M[i][j+1]\}$

然后可以用自底向上的方法来求解问题，注意循环的方向（双层，都是索引从大到小，先求规模小的），可以画出矩阵来判断方向。最后 $M[0][0]$ 即为所求解。算法复杂度为 O($|x||y|$)，这是最优的文本距离求解复杂度。

**最长公共子序列(Longest Common Subsequence,lcs)问题** 和编辑距离一样，也可以用来判断字符串之间的相似度。公共子序列不需要是连续的，只需要在两字符串中都出现，并且其中的字符先后顺序相同即可（比如说 sdfgsflfag 与 lalsdkfla 的最长公共子序列为 sdfla）。（注意，我们最后求得的是最长公共子序列的长度）

对于最长公共子序列问题，我们需要得出最长公共子序列的性质（下面简称为 LCS）：令X=<$x_1,x_2,...,x_m$> 和 Y=<$y_1,y_2,...,y_n$>为两个序列，Z=<$z_1,z_2,...,z_k$>为 X 和 Y 的任意LCS。

1. 如果 $x_m = y_n$ ，那么  $z_k=x_m = y_n$ 且 $Z_{k-1}$ 为 $X_{m-1}$ 和 $Y_{n-1}$ 的一个LCS。
2. 如果 $x_m \neq y_n$ ，$z_k \neq x_m$ ，那么 $Z_{k}$ 为 $X_{m-1}$ 和 $Y$ 的一个LCS。
3. 如果 $x_m \neq y_n$ ，$z_k \neq y_n$ ，那么 $Z_{k}$ 为 $X$ 和 $Y_{n-1}$ 的一个LCS。

然后我们可以用 $M[][]$ 来存储子问题的解，并使用前缀思路（后缀也一样，对称的），其中 $M[i][j]$ 表示 $X_i$ 与 $Y_j$ 的最长公共子序列。（$M[...][0]$ 和 $M[0][...]$ 都为0）如果 $x_i = y_j$ ，$M[i][j] = M[i-1][j-1] + 1$ ；如果 $x_i \neq y_j$，$M[i][j] =max\{ M[i][j-1] ,M[i-1][j] \}$  。

求得的 $M[m][n]$ 即为LCS的最大长度。

**连续子数组的最大和问题** 也是一个经典的动态规划问题。即，输入一个整形数组，数组里有正数也有负数，求所有连续子数组的和的最大值。这个问题我们可以考虑用前缀或后缀的方式来解决。比如说我们考虑前缀的思路解决该问题。假设输入数组为 $A[]$ ，我们用 $N[i]$ 来记录 $A[:i]$ 前缀的*最大后缀子数组和*。我们可以很简单地得到，*数组 $A$ 的最大和连续子数组一定是其某个前缀序列的最大和后缀子数组*。对于 $N[i]$ ，其满足 $N[i] = max \{N[i-1] + A[i], A[i]\}$ ，也就是说：

1. 如果 $N[i-1] > 0$ ， $N[i] = N[i-1] + A[i]$
2. 如果 $N[i-1] <= 0$ ， $N[i] = A[i]$

然后我们可以通过求得 $N$ 数组中的最大元素来得到数组 $A$ 的连续子数组的最大和。（可以在求解 $N[]$ 时维持一个最大值记录）

**最长公共连续子串问题** 与连续子数组的最大和问题类似。给定两个字符串 $s1$ 和 $s2$，求出它们之间最长的相同子字符串的长度。同样，我们用前缀思想来思考这个问题。我们使用一个二维数组 $M[][]$ 来存储子问题的解。$M[i][j]$ 表示前缀 $s1[:i]$ 和 前缀 $s2[:j]$ 的*最长公共后缀长度*。当 $s1[i] = s2[j]$ 时，$M[i][j] = M[i - 1][j - 1] +1 $ ；当 $s1[i] \neq s2[j]$ 时，$M[i][j] = 0$ （此时最长公共后缀显然不存在）。然后我们可以遍历整个 $M[][]$ 数组，其中的最大值即为最长公共连续子串。（可以在求解 $M[][]$ 时维持一个最大值记录，注意，当 $i=0$ 或 $j=0$ 时，$M[i][j] = 0$，要小心初始化问题）

> PS：感觉对于连续子序列的问题都可以将其作为整个字符串某个前缀的一个后缀求解，然后再找这些“后缀”中的最优情况

**背包问题**也可以看做是一个序列来处理，最基本的背包问题叫**01背包问题**，即有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的空间是 $C_i$ ,得到的价值是 $W_i$ ，求解将哪些物品装入背包可使价值总和最大。如果我们将背包问题用前缀思路来思考的话，可以得到，我们假设前 $i$ 件物品放入容量为 $v$ 的背包中得到的最大价值为 $F(i, v)$ ，那么如果我们接下来要放入第 $i + 1$ 个物品时，我们的选择只有两种：放和不放。对于不放的情况，容量不会变化，此时 $F(i+1,v) = F(i,v)$ ；而对于放的情况，容量发生了变化（在实际中体现为我们可能需要从之前放入的 $i$ 件物品中拿出几样来使容量可以放下第 $i+1$ 件物品，而拿出物品的方案肯定要是最优的，这体现为将前 $i$ 件物品放入减少后容量能得到的最优价值，即 $F(i, v-C_i)$）所以此时 $F(i+1, v) = F(i,v-C_i) + W_i$ 。最后我们需要的就是两种情况中的最优解，即 $F(i,v) = max\{F(i-1,v),F(i-1,v-C_i)\}$ 。（*注意矩阵的求解顺序*）

> PS：类似于背包问题，当子问题无法用来描述我们所要解决的问题时，我们需要加入其他的性质（带来了更多子问题）来描述。