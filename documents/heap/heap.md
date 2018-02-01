#### 堆 ####

堆作为数据结构通常用来实现最大、最小优先队列，对应叫做最小堆（根节点最小）或最大堆（根节点最大）。常见的堆有二叉堆、斐波那契堆等。

堆的定义如下：n个元素的序列 {$k_{1},k_{2}...,k_{i},…,k_{n}$} 当且仅当满足下关系时，称之为堆（注意这里下标是从1开始的）：

​	$(k_{i} <= k_{2i},k_{i} <= k_{2i+1})$ 或者 $(k_{i} >= k_{2i},k_{i} >= k_{2i+1}), (i = 1,2,3,4...n/2)$ 

堆是堆排序的逻辑数据结构。一般用**数组**实现。（注意堆的定义）堆的逻辑结构就是一棵 **完全二叉树**，类比于树，$k_{i}$ 的左子节点为 $k_{2i}$，右子节点为 $k_{2i+1}$，父节点为 $k_{i/2}$，其中 $k_1$ 为根节点。（注意是地板除）

堆应该支持以下的基本操作:

- build：建立一个空堆
- insert：向堆中插入一个新元素
- update：将新元素提升使其符合堆的性质
- get：获取当前堆顶元素的值
- delete：删除堆顶元素
- heapify：使只有堆顶元素不满足堆的性质的堆再次成为堆

其中 update 操作和 heapify 时间复杂度为 O($\lg{n}$) 、build 操作的时间复杂度为 O($n$) （注意从叶子向上的每一层的每个节点的 heapify 操作中比较次数线性增长，而节点数目指数减少，总工作量收敛于 O($n$)） 。每次 insert 之后均要 update，每次 delete 之后均要 heapify。堆的操作时间复杂度取决于树的高度（最坏情况是一直沿着最左边向下）。

```
//A是存储堆的数组，i是要提升的元素的索引，假设是最大堆
update(A, i):
	index = i+1
	parent_i = index/2
	while index > 1:
		if A[index-1] > A[parent_i-1]:
			swap(A[index-1], A[parent_i-1])
			index = parent_i
			parent_i = index/2
		else:
			break

//i为某个堆的根节点索引，假设左右子树都满足（最大）堆的性质，节点被删除之后置为 -INFINATY
//length为要维护的堆大小
heapify(A, i, length):
	index = i+1
	while 2*index <= length:     //堆是完全二叉树，如果一个节点没有左儿子，那么它肯定是叶子节点
		left_child = A[2*index-1]
		right_child = 2*index+1 > length ? -INFINATY:A[2*index]
		
		if A[index-1] < left_child and left_child >= right_child:
			swap(A[index-1], A[2*index-1])
			index = 2*index
		else if A[index-1] < right_child and right_child > left_child:
			swap(A[index-1], A[2*index])
			index = 2*index+1
		else: 
			break

//将A数组建立为一个heap，时间复杂度为 O(n)
build_heap(A):
	for i = A.length/2-1 to 0:     //A[n/2-1:n-1]为所有叶子节点
		heapify(A, i, A-i+1)
```

> PS：完全二叉树：若设二叉树的深度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。对于满二叉树，国内国外定义不同。国内：一个二叉树，如果每一个层的结点数都达到最大值，则这个二叉树就是满二叉树（图形形态上看是一个三角形）；国外：如果一棵二叉树的结点要么是叶子，要么这个结点有两个孩子结点，这样的树就是满二叉树（full binary tree），可以不是一个三角形。完全二叉树和满二叉树（国内）都是平衡的。

