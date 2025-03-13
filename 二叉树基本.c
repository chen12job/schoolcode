#include <stdio.h>
#include <stdlib.h>
// 定义二叉树节点的结构
typedef struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
}bitree;
// 创建新的二叉树节点
struct TreeNode *createNode(char data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// 销毁二叉树
void destroyTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
// 先序遍历
void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
//先序遍历非递归
/*void preorderTraverse1(bitree* t) {
	stack s;  
	s.top = -1;
	bitree* p = t;
	while (p != NULL || s.top != -1) {
		if (p) {
			printf("%c", p->data);   //访问节点
			s.data[++(s.top)] = p;  //入栈
			p = p->lchild;          
		}
		else {
			p = s.data[(s.top)--];  //出栈
			p = p->rchild;
		}
	}
}*/
// 中序遍历
void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}
//中序遍历非递归算法
/*void inorder(bitree *t) {
	stack s;
	s.top = -1;
	bitree* p = t;
	while (p != NULL || s.top != -1) {
		if (p) {
			s.data[++(s.top)] = p;  //入栈
			p = p->lchild;
		}
		else {
			p = s.data[(s.top)--];  //代表出栈
			printf("%c", p->data);  //访问节点
			p = p->rchild;
		}
	}
}*/
// 后序遍历
void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}
// 层次遍历
void levelOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    struct TreeNode *queue[100]; // 用数组模拟队列
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        struct TreeNode *current = queue[front++];
        printf("%c ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}
// 用括号表示法输出二叉树
void printParenthetical(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root->data);
    if (root->left != NULL || root->right != NULL)
    {
        printf("(");
        printParenthetical(root->left);
        printf(",");
        printParenthetical(root->right);
        printf(")");
    }
}
int main()
{
    // 函数的示例用法
    struct TreeNode *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    printf("先序遍历: ");
    preorderTraversal(root);
    printf("\n");
    printf("中序遍历: ");
    inorderTraversal(root);
    printf("\n");
    printf("后序遍历: ");
    postorderTraversal(root);
    printf("\n");
    printf("层次遍历: ");
    levelOrderTraversal(root);
    printf("\n");
    printf("括号表示法: ");
    printParenthetical(root);
    printf("\n");
    destroyTree(root); // 释放分配的内存
    return 0;
}
