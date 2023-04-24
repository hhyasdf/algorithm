#### 二叉树的遍历 ####

树的遍历是对树的一种最基本的运算，所谓遍历二叉树，就是按一定的规则和顺序走遍二叉树的所有结点，使每一个结点都被访问一次，而且只被访问一次。由于二叉树是非线性结构，二叉树的遍历本质上是将二叉树的各个节点转换成一个线性序列来表示。

由于从给定的某个节点出发，有多个可以前往的下一个节点（树不是线性数据结构），所以在顺序计算（即非并行计算）的情况下，只能推迟对某些节点的访问——即以某种方式保存起来以便稍后再访问。

设L、D、R分别表示遍历左子树、访问根结点和遍历右子树， 则对一棵二叉树的遍历（根据*访问根节点的顺序的不同*）有三种情况：**DLR（先序遍历）**，**LDR（中序遍历）**，**LRD （后序遍历）**。这三种遍历方式也叫作**深度优先遍历** ，通常用**栈**实现。

还有一种情况为 **层序遍历**，即由上到下逐层进行遍历，通常用队列来保存遍历需要的信息，也叫作**广度优先遍历**。

我们以二叉树存储的算数表达式为例子来表示先序、中序和后序的区别。**在存储了一个合法算数表达式的二叉树中，数字一定都是叶子节点（叶子节点也一定都是数字），给表达式中的所有子表达式加上不影响计算效果的括号，括号所代表的树一定是其他树的子树**。（手写前缀后缀形式算数表达式的技巧：“加括号”）

在深度优先遍历的三种方式中，我们只需要使用**一个辅助栈**的迭代算法来遍历二叉树，并且**都通过不断地向左遍历所有节点并将其压入栈中来构造栈中的数据**，通过简单的递归思想，因为一次遍历中最后被压入栈的节点的左儿子一定为NIL，并且我们**只能通过栈进行向上回溯**，可以很简单地得到，这样构造完毕之后的**栈顶节点总是隐含有其左子树已被访问完毕的信息**。

> 两种特殊情况需要考虑：1、所有节点只有右儿子或没有儿子  2、所有节点只有左儿子或没有儿子

##### 先序遍历 #####

先序遍历对应二叉树存储的算数表达式的前缀形式：4\*5+6\*7 -> +\*45\*67 。

递归方式，对于二叉树的中每个节点都先访问其本身，再访问其左儿子（如果存在的话），然后对其右儿子进行访问（如果存在的话）：

```
//operation表示要进行的操作, node为要遍历的（子）树的根节点
pre_order_traversal(node, operation):
	operation(node)           //先处理根节点
	if node.left != NIL:
		pre_order_traversal(node.left, operation)
	if node.right != NIL:
		pre_order_traversal(node.right, operation)
```

迭代方式，**”对于每个节点，如果节点不为NIL，先访问其本身，将其本身入栈，并用左儿子继续循环，如果节点为NIL且stack非空，表示已经到达本次需要访问的最左端节点，则进行出栈操作，访问得到的节点的右儿子并使用该得到的节点继续循环；如果节点为NIL且stack为空。则结束循环“**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
pre_order_traversal(root_node, opetation):
	node = root_node
	while node != NIL or !stack.empty:  //每次都往最左找，如果已经处理完当前最左节点并且栈也空了，就结束
		if node != NIL:
      operation(node)
			stack.push(node)                //使用栈来保存访问已经访问过的路径信息
			node = node.left
		else:
			node = stack.pop()              //栈顶节点的左子树和该节点都已被“操作”过，下一步从右儿子开始访问
			node = node.right
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

迭代形式，**”对于每个节点，如果节点不为NIL，先将其本身入栈，再使用左儿子继续循环，如果节点为NIL且stack非空，表示已经到达本次需要访问的最左端节点，则进行出栈操作，处理出栈得到的节点，并使用该节点的右儿子继续循环。如果节点为NIL且stack为空，则结束循环“**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
in_order_traversal(root_node, operation):
	node = root_node
	while node != NIL or !stack.empty:  //每次都往最左找，如果已经处理完当前最左节点并且栈也空了，就结束
		if node != NIL:                   
      stack.push(node)                //使用栈来保存访问已经访问过的路径信息
			node = node.left                
		else:
			node = stack.pop()              //栈顶节点的左子树已被“操作”过，本身和右子树没有被“操作过”，先“操作”本身，下一步操作
			                                //下一步从右儿子开始访问
			operation(node) 
      node = node.right 
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

迭代形式，**“对于每个节点，先进行一个 ‘找对应子树中的最左端节点’ 的过程，这个向最左过程中，依次将路径上的每个节点以及其右儿子入栈，找到最左的NIL节点之后，出栈一个节点（最左的非NIL节点也被入栈了）并使用该节点继续循环。此时出栈的元素一定是某个节点的右儿子并且存在两种情况。如果出栈的元素非NIL，则需要先入栈一个NIL节点再开始下次循环；如果出栈的元素为NIL，则需要再出栈一个节点并直接处理该节点（一定非NIL），然后（以NIL节点）开始下次循环”**

> 麻烦的是子树的根节点只能在其左子树和右子树都被访问过之后才能从栈中压出，之前我们可以将栈顶节点视为其左子树已经被访问过的节点，但因为我们不知道其右子树是否被访问过，而且我们只能通过栈来回溯，所以需要标记什么时候栈中节点的右子树被访问过了。我们将某节点的右儿子保存在栈中该节点的上方，如果该节点的右子树已经被访问过了，就将该节点的右儿子位置的节点置为NIL ，并且因为向左遍历到NIL和右子树已经访问完毕这两种情况不好区分，我们需要加一个循环来进行向左遍历

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
post_order_traversal(root_node, operation):
	node = root_node
    while node != NIL or !stack.empty:
    	while node != NIL:           //每次都先一直向左，把沿途的节点及其右儿子保存在栈里，外循环用来回溯
   			stack.push(node)
   			stack.push(node.right)            
   			node = node.left
   		node = stack.pop()           //如果右儿子的位置为NIL代表右子树已经访问过
        if node == NIL:            //如果右子树已经被访问完，又因为此时栈顶的节点左子树已经被访问过
        	operation(stack.pop())   //该子树的节点已全部被访问过，向上回溯
        else:                      //node对应的右子树还没有访问过
        	stack.push(NIL)          //下个循环访问node为根的右子树
```

##### 层序遍历 #####

与上面三种遍历方式不同，层序遍历又叫做广度优先遍历，先访问离根节点近的节点。我们使用**队列**来实现该操作。**从根节点开始，我们处理节点并将节点的左右非NIL儿子依次入队，并在之后逐个将元素出队并处理（同时继续将元素的左右非NIL儿子依次入队）**：

```
//operation表示要进行的操作, root_node为要遍历的（子）树的根节点
layer_traversal(root_node, operation):
	if root_node == NIL:                   //二叉树为空就啥也不干
	  return
	queue.enqueue(root_node)
  while !queue.empty:                    //先将root节点入队，如果queue中没有元素即结束
    node = queue.dequeue()               //每次都出队一个元素来处理，保证入队的都不是NIL即可
		operation(node)
		if node.left != NIL:
      queue.enqueue(node.left)
    if node.right != NIL:
      queue.enqueue(node.right)
```

> 可以弄两个 queue，这里用 A、B 表示，A 中保存 “下一层将要遍历所有元素” 的信息（初始化为 root 节点），B 中保存 “这次循环要处理的所有元素”，每次循环都将 A 清空转移到 B 中，然后将 B 中元素的非NIL儿子都入队到 A，然后处理 B 中所有元素（并清空），当 A 中为空时结束。这样每次循环都是处理二叉树的 “一层”，保留了层信息。
