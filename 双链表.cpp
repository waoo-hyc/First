#include<stdio.h>
#include<stdlib.h>
struct Node  //结点 
{
	int data;
	struct Node*next;
	struct Node*front; 
};
struct Node*createNode(int data) //创建结点 
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next =newNode->front= NULL;
	return newNode;
};
struct Node*creathead()//头指针 
{
struct Node*head = (struct Node*)malloc(sizeof(struct Node));
head->next=head->front=NULL;
head->data=0;	
return head;
}
void CreateLA(struct Node*head,int data)//表头插入 
{
	struct Node* newNode=createNode(data);
	struct Node*nodee=head;
    newNode->next=nodee->next;
    newNode->front=nodee;
	nodee->next=newNode; 
} 
void CreateLB(struct Node*head,int data)//表尾插入 
{
	struct Node* newNode=createNode(data);
	struct Node*nodee=head;
	while(nodee->next)
	{
		nodee=nodee->next;
	}
	nodee->next=newNode;
	newNode->front=nodee;
}
void printfl(struct Node*head)//从前往后输出链表 
{
	struct Node*pMove=head->next;
	while(pMove)
	{
		printf(" -->%d",pMove->data);
		pMove=pMove->next;
	} 
}
/*void Reversr(struct Node*head)//双向链表的反转 
{
	struct Node*pMove=head;
	struct Node*dMove=head;
	while(pMove->next)
	{
		pMove=pMove->next;
	} 
	struct Node*rMove=pMove->front;
	head->next=pMove;
	pMove->front=head;
	while(rMove->next)
	{
		pMove->next=rMove;
		rMove->front=pMove;
		pMove=rMove;
		rMove=rMove->front;
	}
}*/
/*void Reversal(struct Node*head)//反转
	struct Node*q,*p,*pr;
	p=head->next;
	q=NULL;
	while(p)
	{
		pr=p->next;
		p->next=q;
		q=p;
		p=pr;
	}
	head->next=q;
}*/
int main()
{
	struct Node*head=creathead();
	CreateLB(head,3);
	CreateLB(head,2);
	CreateLB(head,1);
	printfl(head);
	 
	
}
