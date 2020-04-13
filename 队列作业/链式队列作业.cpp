#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 10
typedef struct node
{
    int data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];	
LQueue *CreateQueue()//c���� 
{
LQueue* q=(LQueue*)malloc(sizeof(LQueue));
q->front=NULL;
q->rear=NULL;
q->length=0;	
return q;
}
Status IsEmptyLQueue(const LQueue *Q)//�鿴�Ƿ�Ϊ�� 
{
	if(Q->length==0) return TRUE;
	else return FALSE;
}
Status EnLQueue(LQueue *Q, int data)//��� 
{
	Node *node;
	node=(Node*)malloc(sizeof(Node));
    node->data=data;
    node->next=NULL;
    if(IsEmptyLQueue(Q))
    {
    	Q->front=Q->rear=node;
    	Q->length++;
    }
    else
    {
    	Q->rear->next=node;
    	Q->rear=node;
    	Q->length++;
    }
    return TRUE;
}
void ClearLQueue(LQueue *Q)//���
{
	Node*node=Q->front;
	while(!node) 
	{
		printf("�޷����"); 
	}
	while(node)
	{
		node->data=0; 
		node=node->next;
	}
	printf("��ճɹ�\n");
}
Status TraverseLQueue(const LQueue *Q)//����
{
	Node*node=Q->front;
	while(!node) 
	{
		printf("�޷���ӡ"); 
		 return FALSE;
	}
	printf("����Ԫ��Ϊ��");
	while(node)
	{
		printf("%d ",node->data);
		node=node->next;
	}
	printf("\n");
	return TRUE;
} 
Status DeLQueue(LQueue *Q)//����
{
	Node *node=Q->front;
	while(!node->next) 
	{
		printf("�޷�����"); 
		 return FALSE;
	}
	Q->front=node->next;
	Q->length--; 
	free(node);
	return TRUE;
} 
int GetHeadLQueue(LQueue *Q)//�鿴ͷԪ�� 
{
	return Q->front->data;
}
int LengthLQueue(LQueue *Q)//�鿴����
{
	return Q->length;
} 
void DestoryLQueue(LQueue *Q)//�ݻٶ���
{
	Node *node;
	while(IsEmptyLQueue(Q))  
	{
		printf("����Ϊ�գ��޷��ݻ�");
		return;
	}
	while(Q->front)
	{
		node=Q->front;
		Q->front=node->next;
		free(node);
	} 
	printf("�ݻٳɹ�");
} 
int main()
{
	/*int i;
	LQueue *Q=InitLQueue();
	EnLQueue(Q, 2);
	EnLQueue(Q, 3);
	EnLQueue(Q, 3);
	EnLQueue(Q, 3);
	EnLQueue(Q, 3);
	i=LengthLQueue(Q);
	printf("%d",i);
	printf("\n");
	TraverseLQueue(Q);
	DeLQueue(Q);
	TraverseLQueue(Q);
	ClearLQueue(Q);
	TraverseLQueue(Q);*/
	 int i,j,k,n,a,e;
    LQueue *Q; 
	Q=CreateQueue(); 
    printf("Ҫ������ٸ�����"); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	printf("data��");
		scanf("%d",&a);
    	EnLQueue(Q,a);
    }
    TraverseLQueue(Q);
    printf("\n");
    printf("�����ٸ�����"); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	 DeLQueue(Q); 
    }
    TraverseLQueue(Q);
    printf("\n");
    printf("��ն��У�\n"); 
    ClearLQueue(Q); 
    TraverseLQueue(Q);
    e=LengthLQueue(Q);
    printf("���ȣ�");
    printf("%d\n",e);
    printf("�ݻٶ��У�\n");
	DestoryLQueue(Q); 
	return 0;
}

