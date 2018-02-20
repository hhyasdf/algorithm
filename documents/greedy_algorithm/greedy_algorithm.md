#### 贪心算法 #####

贪心法，又称贪心算法、贪婪算法、或称贪婪法，是一种在每一步选择中都采取在**当前状态下最好或最优**（即最有利）的选择，从而希望导致结果是最好或最优的算法。贪心算法在有最优子结构的问题中尤为有效。最优子结构的意思是*局部最优解能决定全局最优解*。简单地说，问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。

贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

贪心法可以解决一些最优化问题，如：求图中的**最小生成树**、求哈夫曼编码等等。

贪心算法的一般思路：

1. 建立数学模型来描述问题。
2. 把求解的问题分成若干个**子问题**。
3. 对每一子问题求解，得到子问题的局部最优解。
4. 把子问题的解局部最优解合成原来解问题的一个解。

实现该算法的过程：从问题的某一初始解出发；while 能朝给定总目标前进一步 do ,求出可行解的一个解元素；最后，由所有解元素组合成问题的一个可行解。
