#include<stdio.h>
#include<stdlib.h>
struct Node  //��� 
{
	int data;
	struct Node*next;
	struct Node*front; 
};
struct Node*createNode(int data) //������� 
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next =newNode->front= NULL;
	return newNode;
};
struct Node*creathead()//ͷָ�� 
{
struct Node*head = (struct Node*)malloc(sizeof(struct Node));
head->next=head->front=NULL;
head->data=0;	
return head;
}
void CreateLA(struct Node*head,int data)//��ͷ���� 
{
	struct Node* newNode=createNode(data);
	struct Node*nodee=head;
    newNode->next=nodee->next;
    newNode->front=nodee;
	nodee->next=newNode; 
} 
void CreateLB(struct Node*head,int data)//��β���� 
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
void printfl(struct Node*head)//��ǰ����������� 
{
	struct Node*pMove=head->next;
	while(pMove)
	{
		printf(" -->%d",pMove->data);
		pMove=pMove->next;
	} 
}
/*void Reversr(struct Node*head)//˫������ķ�ת 
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
/*void Reversal(struct Node*head)//��ת
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
