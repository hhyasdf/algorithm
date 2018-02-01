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

由于二叉搜索树的查找和插入操作的最差时间复杂度取决于树的高度（即从根节点到一叶子节点的最长路径），而树的高度可能为n，所以最坏时间复杂度为 O($n$)，此时树中的每层都只有一个节点。插入操作如下：

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
		else if parent.value > target:
			position = parent.left
		else:
			return NULL               //该值已存在
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

*******************

为了解决由于不平衡的树造成的效率低下的影响，**平衡树**（balanced tree）被开发出来以保证BST的效率。平衡树中，任何节点的两个子树的高度最大差别为1（每棵平衡树的高度不一定是 $\log{n +1}$ ，即不一定是一棵完全二叉树，其最少节点数目满足以下规律：$N_0=0,N_1=1,N_2=2; N_h=N_{h−1}+N_{h−2}+1$ 其中 $h$ 为树的高度，完全二叉树的定义见 documents/heap/heap.md ）几乎所有平衡树的操作都基于 O(1) 的**旋转**操作，通过旋转操作可以使树趋于平衡。旋转操作不会违背BST的性质。（旋转的时候注意要将旋转的两个节点的所有儿子画出来，如果没有左儿子或右儿子，用NIL节点代替，不然很容易搞错）

旋转操作如图：![./Tree_rotation.png](Tree_rotation.png)

```
//N为旋转后变为父元素的节点（转轴），在途中分别为P（右旋）和Q（左旋），N.parent指向父节点
//T为节点所属二叉树，T.root.parent指向NIL
left_rotation(T, N):
	if N != T.root:           //如果N是根节点，那么什么都不做
		parent = N.parent
		grandparent = parent.parent
		if grandparent != NIL:
			if grandparent.left == parent:
				grandparent.left = N
			else:
				grandparent.right = N
		else:
			T.root = N        //如果parent是根节点那么要重设根节点
		N.parent = grandparent
		parent.parent = N
		parent.right = N.left
		if N.left != NIL:     // !
			N.left.parent = parent   
		N.left = parent

//右旋与左旋类似
right_rotation(T, N):
	if N != T.root:
		parent = N.parent
		grandparent = parent.parent
		if grandparent != NIL:
			if grandparent.left == parent:
				grandparent.left = N
			else:
				grandparent.right = N
		else:
			T.root = N
		N.parent = grandparent
		parent.parent = N
		parent.left = N.right
		if N.right != NIL:
			N.right.parent = parent
		N.right = parent
```

通常我们采用旋转操作来使子树的高度减1（我们把PABCQ视为一棵子树，假设此时以P节点为根的子树高度等于以C节点为根的子树高度加2），但我们需要注意到，如果需要右旋时（如图），B节点代表的子树高度如果等于A节点代表的子树高度加1，此时右旋后仍不平衡，我们需要先左旋P和B节点，再右旋B和Q节点（double rotation），左旋时情况类似。

每种平衡树的搜索方式和普通BST相同，我们只关注它们的 insert 和 delete 操作。

##### AVL #####

AVL树是最先发现的自平衡查找树，在AVL树中任何节点的两个子树的高度最大差别为1，也被称为高度平衡树。AVL树的每个节点中都保存了该节点在树中的高度（height，即从该节点到其子树中一叶子节点的最长路径），我们可以很简单地得到：每个节点（node）的高度等于以其为根节点的树的高度并等于两儿子节点的高度的最大值加1（ node.height = max{ node.left.height, node.right.height } + 1 ）。根据这个公式，为了方便计算，我们将NIL节点的 height 记为 -1（ NIL.height=-1 ）。

根据AVL树的定义可得，|node.left.height - node.right.height|必须满足 <= 1。

在AVL树的 insert 操作中，和之前的 BST_insert 一样，我们首先找到合适的位置并插入一个新的节点，然后更新每个需要更新的节点的 height。通过每个节点的 height，如果插入后树不再是平衡的，我们找到第一个不平衡的节点进行一些旋转使其重新平衡（平衡之后不平衡节点往上的节点都是平衡的，**旋转消除了插入节点后不平衡子树的根节点上方节点高度的变化**）。并且旋转之后只需要更新旋转操作的两个节点的高度。

插入节点时分为4种情况（左、右的double rotation和一次旋转），四种情况对应的旋转方法是不同的，复杂度为 O($\lg{n}$)

```
//T为要查找的二叉树，每个节点存储了一个value和左右子节点的信息left和right，没有子节点的话相应值为NIL
//target为要插入的目标值，NIL的height为-1
AVL_insert(T, target):
	node = BST_insert(T, target)       //假设BST_insert返回插入的节点，插入节点的height为0
	parent = node.parent
	while parent != NIL:			   //沿node向上查找不平衡的树的根节点
		if parent.left.height-parent.right.height == 2:  
			if node.right.height-node.left.height == 1:  //double rotation
				left_rotation(node.right)                //旋转之后node.right成为父元素
				update the height of node and node.right
				right_rotation(parent.left)
				update the height of parent and parent.parent  //parent.left成为父元素
			else:
				right_rotation(node)
				update the height of node and parent
			break                                       // !
		else if parent.left.height-parent.right.height == -2:
			if node.right.height-node.left.height == -1: //double rotation
				right_rotation(node.left)
				update the height of node and node.left
				left_rotation(parent.right)
				update the height of parent and parent.parent  //parent.right成为父元素
			else:
				left_rotation(node)
				update the height of node and parent
			break                                       // !
		parent.height = max(parent.left.height, parent.right.height)+1
		node = parent
		parent = parent.parent
```

从AVL树中删除，同样先与在普通BST中一样删除节点，然后修正平衡，删除的情况中没有double rotation，复杂度也为 O($\lg{n}$)：

```
AVL_delete(T, target):
	node = BST_search(T, target)
	parent = BST_delete(T, node)        //假设返回的是实际被delete（对高度有影响）的节点的父节点
	while parent != NIL                 //沿父节点向上查找不平衡的树的根节点
		parent.height = max(parent.left.height, parent.right.height)+1
		if parent.left.height-parent.right.height == 2:
			right_rotation(parent.left)
			update the height of parent and parent.parent
			break                                       // !
		else if parent.left.height-parent.right.height == -2:
			left_rotation(parent.right)
			update the height of parent and parent.parent
			break                                       // !
		parent = parent.parent
```

##### 红黑树 #####

