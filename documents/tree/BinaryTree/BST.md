#### 二叉搜索树 #### 

二叉搜索树是一棵物理上的二叉树，需要一些额外的字节来维护每个节点的左右孩子的信息（至少两个指针，还可以维护父节点的信息）。二叉查找树（英语：Binary Search Tree），也称二叉搜索树、有序二叉树（英语：ordered binary tree），排序二叉树（英语：sorted binary tree），是指一棵空树或者具有下列性质的二叉树：

- 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
- 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
- 任意节点的左、右子树也分别为二叉查找树；
- **没有键值相等的节点**。

二叉搜索树对于查找和插入操作都具有较好的时间复杂度。当我们在有序数组上查找时，最快的方法是使用二分查找，它的复杂度是 O($\lg{n}$) ，而插入操作需要把每个大于或小于目标元素的元素向后移动，这导致了 O($n$) 的时间复杂度。而当我们在有序链表上操作时，我们虽然有 O(1) 的插入代价，但我们无法进行二分查找，因此查找的复杂度为 O($n$) 。而对于二叉树，无论查找和插入操作的时间复杂度都是 O($\lg{n}$)，所以对于需要经常使用查找和插入操作的场景下，二叉搜索树是一个不错的选择。

二叉树的查找算法，平均时间复杂度为 O($\lg{n}$)（准确来讲应该是O($\lg{h}$)，其中 $h$ 为树的高度）：

```
//T为要查找的二叉树，每个节点存储了一个value和左右子节点的信息left和right，没有子节点的话相应值为NIL
//target为要查找的目标值
BST_search(T, target):
	position = T.root
	while position != NIL:
		if position.value < target:
			position = position.right
		else if position.value > target:
			position = position.left
		else:
			break
	return position	
```

由于二叉搜索树的查找和插入操作的最差时间复杂度取决于树的高度，而树的高度可能为n，所以最坏时间复杂度为 O($n$)，此时树中的每个节点都只有左儿子（或都只有右儿子）或没有儿子。插入操作如下：

```
//T为要查找的二叉树，每个节点存储了一个value和左右子节点的信息left和right，没有子节点的话相应值为NIL
//target为要插入的目标值
BST_insert(T, target):
	parent = T.root
	position = parent
	while position != NIL:            //每个插入都会成为二叉树的叶子节点!!
		parent = positon
		if parent.value < target:
			position = parent.right
		else:
			position = parent.left
	if parent.left == position:
		parent.left = new node(target, NIL, NIL)
	else:
		parent.right = new node(target, NIL, NIL)
```

删除操作如下：

```
//T为要查找的二叉树，每个节点存储了一个value和左右子节点的信息left和right，没有子节点的话相应值为NIL
//node为要删除的节点
//有两种方法，一种是使左子树的最右节点成为新的node，另一种方法是使右子树的最左节点成为新的node
//两者分别对应中序遍历的前驱和后继
//这里采用第一种
BST_delete(T, node):
	if node.right == NIL and node.left == NIL:
		delete node        //如果为叶子节点就直接删除，删除之后父节点对应要指向NIL
	else if node.right == NIL:
		node = node.left   //如果没有右儿子，就直接将左儿子的值赋给node，删除左儿子
		delete node.left
	else if node.left == NIL:
		node = node.right  //如果没有左儿子，就直接将右儿子的值赋给node，删除右儿子
		delete node.right
	else:
		right_n = node.left
		p = node
		while right_n.right != NIL:      //找到左子树的最右节点
			p = right_n
			right_n = right_n.right
		node.value = right_n.value
		if p == node:                    //左子树最右节点就是node的左儿子
			p.left = right_n.left
		else:
			p.right = right_n.left
		delete right_n
```

删除操作的复杂度也为 O($\lg{n}$)。

我们可以在每个节点中维护更多的信息来达到其他的需求（比如说以该节点为根的BST子树的节点数目），它们仅仅增加了 insert 和 delete 时间复杂度中的常数系数。