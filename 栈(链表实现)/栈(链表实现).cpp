#include <stdio.h>
#include<stdlib.h>
//存在问题，top不能定义为全局，否则循环查找会改top   
int size = 0;
struct ListNode* top;
/* 链表节点结构体 */
typedef struct ListNode {
    int index;
    int val;               // 节点值
    struct ListNode* next; // 指向下一节点的指针
}SqListNode;

/* 构造函数 */
SqListNode* newListNode(int val) {
   
    SqListNode* node;
    node = (SqListNode*)malloc(sizeof(SqListNode));
    node->val = val;
    node->next = NULL;
    return node;
};

void initStack(int val) {
    top  =  newListNode(val); //为全局变量top赋予你给的初值
    size++;
}


void push(int val) {  
    if (top == 0) {
        top = newListNode(val);
        size++;
        return;
    }
    SqListNode* n = top;         //原来的top指向的节点  
    top = newListNode(val); 
    top->index = n->index + 1;//将top指向新添加的节点
    top->next = n ; 
    size++;
}

SqListNode* getByindex(int index) {
    SqListNode* n = top;         //将top的值赋给形参，便于后续的循环查找
    while (n->index != index) {  
        n = n->next;
        if (n==NULL) {
            return NULL;
        }
    }
    return top;
}

void printMyList() {
    for (ListNode* n = top; n != NULL; n = n->next) { //注意顺序，这个是在循环一次结束后才n= n->next 
        if (n->next == NULL) { //表明下一个是最初的top了，应该改变打印格式
            printf("%d\n", n->val);
            break;
        }
        printf("%d->", n->val);
    }
};


int main() {
   initStack(9);
    push(2);
    push(3);
    push(3);
    printMyList();
 
}