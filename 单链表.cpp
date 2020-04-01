#include<stdio.h>
#include<stdlib.h>
struct Node  //��� 
{
	int data;
	struct Node*next;
};
struct Node*createNode(int data) //������� 
{
	struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
};
struct Node*creathead()//ͷָ�� 
{
struct Node*head = (struct Node*)malloc(sizeof(struct Node));
head->next=NULL;
head->data=0;	
return head;
}
void CreateLA(struct Node*head,int data)//��ͷ���� 
{
	struct Node* newNode=createNode(data);
	struct Node*nodee=head;
    newNode->next=nodee->next;
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
}
void printfl(struct Node*head)//������� 
{
	struct Node*pMove=head->next;
	while(pMove)
	{
		printf("   %d",pMove->data);
		pMove=pMove->next;
	} 
}
void ChaCha(struct Node*head,int data,int size)//���룻 
{
	struct Node*pMove=head->next;
	struct Node* newNode=createNode(data);
	int i=1;
	while(i<size)
	{
		pMove=pMove->next;
		i++;
	}
	newNode->next=pMove->next;
	pMove->next=newNode;
}
void ChuChu(struct Node*head,int size)//ɾ�� 
{
	struct Node*pMove=head->next;
	int i=1;
	if(size==1)
	{
		head->next=pMove->next;
		free(pMove);
	}
	if(size!=1)
	{
	while(i<size-1)
	{
		pMove=pMove->next;
		i++;
	}
    struct Node*chuchu=pMove->next; 
	pMove->next=chuchu->next;
	free(chuchu);}
}
void Reversal(struct Node*head)//��ת 
{
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
}
int main()
{
	struct Node*head=creathead();
	int data,n,m,k;
	printf("������"); 
	scanf("%d",&n);
	printf("��β��������:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		CreateLB(head,data);
	}
	printf("��ͷ������"); 
	scanf("%d",&n);
	printf("��ͷ��������:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		CreateLA(head,data);
	}
	printfl(head);
	printf("\n");
	printf("����ɾ���Ľ����"); 
	scanf("%d",&n);
	printf("\n");
    for(int i=0;i<n;i++)
	{
	
	    printf("����ɾ���Ľ��λ��"); 
		scanf("%d",&m);
		ChuChu(head,m);
		printfl(head);
		printf("\n");
	} 
	printf("��������");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("��������ֵ��λ��"); 
		scanf("%d%d",&m,&k);
		ChaCha(head,m,k);
		printfl(head);
		printf("\n");
	}
	printf("�Ƿ�ת���Ǿ�����1��");
	scanf("%d",&m);
	while(m){
	Reversal(head);
	printf("\n");
	break;
     }
	printfl(head);
    system("pause"); 
	return 0;
} 
