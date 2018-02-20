#### 二叉树的遍历 ####

树的遍历是对树的一种最基本的运算，所谓遍历二叉树，就是按一定的规则和顺序走遍二叉树的所有结点，使每一个结点都被访问一次，而且只被访问一次。由于二叉树是非线性结构，二叉树的遍历本质上是将二叉树的各个节点转换成一个线性序列来表示。

设L、D、R分别表示遍历左子树、访问根结点和遍历右子树， 则对一棵二叉树的遍历（根据*访问根节点的顺序的不同*）有三种情况：**DLR（先序遍历）**，**LDR（中序遍历）**，**LRD （后序遍历）**。这三种遍历方式也叫作**深度优先遍历** 。

还有一种情况为 **层序遍历**，即按照层次访问，通常用队列来保存遍历需要的信息，也叫作**广度优先遍历**。

由于从给定的某个节点出发，有多个可以前往的下一个节点（树不是线性数据结构），所以在顺序计算（即非并行计算）的情况下，只能推迟对某些节点的访问——即以某种方式保存起来以便稍后再访问。遍历是一个递归的过程，对于每个子树都需要采用同样的遍历方式遍历下去。常见的做法是采用栈（LIFO）或队列（FIFO）迭代地遍历，关键在于什么时候访问根节点。也可以使用递归的方式遍历。

我们二叉树存储的算数表达式为例子来表示先序、中序和后序的区别。二叉树存储的算数表达式中，数字总为算数符号的儿子节点，优先级底的符号为优先级高的算数符号的父节点（括号所代表的树一定是其他树的子树）。（手写前缀后缀形式算数表达式的技巧）

（感觉只要满足两种情况的话其他情况都会满足：1、所有节点只有右儿子或没有儿子  2、所有节点只有左儿子或没有儿子）在深度优先遍历的三种方式中，我们使用只需要**一个辅助栈**的迭代算法来遍历二叉树，并且**都通过不断地向左遍历所有节点并将其压入栈中来构造栈中的数据**，通过简单的递归思想，因为一次遍历中最后被压入栈的节点的左儿子一定为NIL，并且我们**只能通过栈进行向上回溯**，可以很简单地得到，这样构造完毕之后的**栈顶节点总是隐含有其左子树已被访问完毕的信息**。

##### 先序遍历 #####

先序遍历对应二叉树存储的算数表达式的前缀形式：4\*5+6\*7 -> +\*45\*67 。

递归方式，对于二叉树的中每个节点都先访问其本身，再访问其左儿子（如果存在的话），然后对其右儿子进行访问（如果存在的话）。：

```
//operation表示要进行的操作, node为要遍历的（子）树的根节点
pre_order_traversal(node, operation):
	operation(node)
	if node.left != NIL:
		pre_order_traversal(node.left, operation)
	if node.right != NIL:
		pre_order_traversal(node.right, operation)
```

迭代方式，**对于每个节点，如果节点不为NIL，先访问其本身，将其右儿子入栈，并用左儿子继续循环，如果节点为NIL且stack非空，表示已经到达本次需要访问的最左端节点，则进行出栈操作，访问得到的节点并使用该得到的节点继续循环，如果节点为NIL且stack为空。则结束循环**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
pre_order_traversal(root_node, opetation):
	node = root_node
	while node != NIL or !stack.empty:  //第一个传进来的node为NIL则什么都不做
		if node == NIL:                 //第一次循环node肯定不为NIL，node为NIL则stack肯定非空
			node = stack.pop()          //栈顶节点的左子树和该节点都已被访问过
			node = node.right
		else:
			operation(node)
			stack.push(node)            //使用栈来保存访问需要的路径信息，node不为NIL才会入栈
			node = node.left
```

##### 中序遍历 #####

中序遍历对应算数表达式的中缀表达式，也就是正常的算数表达式形式：4\*5+6\*7 。

递归形式，对于二叉树中的每一个节点，先访问其左儿子（如果存在的话），再访问其本身，然后对右儿子进行访问（如果存在的话）：

```
//operation表示要进行的操作, node为要遍历的（子）树的根节点
in_order_traversal(node, operation):
	if node.left != NIL:
		in_order_traversal(node, operation)
	operation(node, operation)
	if node.right != NIL:
		in_order_traversal(node, operation)
```

迭代形式，**对于每个节点，如果节点不为NIL，先将其本身入栈，再使用左儿子继续循环，如果节点为NIL且stack非空，表示已经到达本次需要访问的最左端节点，则进行出栈操作，访问出栈得到的节点，该节点的右儿子继续循环。如果节点为NIL且stack为空，则结束循环**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
in_order_traversal(root_node, operation):
	node = root_node
	while node != NIL or !stack.empty:  //第一个传进来的node为NIL则什么都不做
		if node == NIL:                 //第一次循环node肯定不为NIL，node为NIL则stack肯定非空
        	node = stack.pop()          //栈顶节点的左子树已被访问过
			operation(node) 
            node = node.right          
		else:
			stack.push(node)
			node = node.left
```

##### 后序遍历 #####

先序遍历对应二叉树存储的算数表达式的后缀形式：4\*5+6\*7 -> 45\*67*+ 。

递归形式，对于二叉树中的每一个节点，先访问其左儿子（如果存在的话），再访问其右儿子（如果存在的话），然后对其本身进行访问：

```
post_order_traversal(node, operation):
	if node.left != NIL:
		post_order_traversal(node, operation)
	if node.right != NIL:
		post_order_traversal(node, operation)
	operation(node, operation)
```

迭代形式，麻烦的是子树的根节点只能在其左子树和右子树都被访问过之后才能从栈中压出，虽然我们将栈顶节点视为其左子树已经被访问过的节点，但因为我们不知道其右子树是否被访问过，而且我们只能通过栈来回溯，所以需要标记什么时候栈中节点的右子树被访问过了。我们**将某节点的右儿子保存在栈中该节点的上方，如果该节点的右子树已经被访问过了，就将该节点的右儿子位置的节点置为NIL** ，并且因为向左遍历到NIL和右子树已经访问完毕这两种情况不好区分，我们需要加一个循环来进行向左遍历：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
post_order_traversal(root_node, operation):
	node = root_node
    while node != NIL or !stack.empty:
    	while node != NIL:           //一直向左，把沿途的节点及其右儿子保存在栈里，外循环用来回溯
   			stack.push(node)
   			stack.push(node.right)            
   			node = node.left
   		node = stack.pop()           //如果右儿子的位置为NIL代表右子树已经访问过
        if node == NIL:              //如果右子树已经被访问完，又因为栈顶的节点左子树已经被访问过
        	operation(stack.pop())
        	node = NIL               //该子树的节点已全部被访问过，向上回溯
        else:                        //node对应的右子树还没有访问过
        	stack.push(NIL)          //下个循环访问node为根的右子树
```

> PS：以上三种遍历算法的递归方式中，注意 stack.push(node) 和 node=node.left 两个操作总是紧接着的。前序和中序遍历极为相似。

##### 层序遍历 #####

与上面三种遍历方式不同，层序遍历又叫做广度优先遍历，先访问离根节点近的节点。我们使用**队列**来实现该操作。**从根节点开始，我们将上层的每个非NIL节点从左到右保存在队列中，并在下一层的遍历中逐个将其从队列中压出并访问其非NIL左右儿子**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
layer_traversal(root_node, operation):
	node = root_node
    while node != NIL or !queue.empty:     //第一个传进来的node为NIL则什么都不做
		if !queue.empty:
    		node = queue.pop()
    		if node.left != NIL:
    			operation(node.left)
    			queue.push(node.left)
    		if node.right != NIL:
    			operation(node.right)
    			queue.push(node.right)
    		node = NIL
    	else:                              //队列为空node肯定不为NIL
    		operation(node)
    		queue.push(node)
```

