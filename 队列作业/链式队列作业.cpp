#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 10
typedef struct node
{
    int data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];	
LQueue *CreateQueue()//c创建 
{
LQueue* q=(LQueue*)malloc(sizeof(LQueue));
q->front=NULL;
q->rear=NULL;
q->length=0;	
return q;
}
Status IsEmptyLQueue(const LQueue *Q)//查看是否为空 
{
	if(Q->length==0) return TRUE;
	else return FALSE;
}
Status EnLQueue(LQueue *Q, int data)//入队 
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
void ClearLQueue(LQueue *Q)//清空
{
	Node*node=Q->front;
	while(!node) 
	{
		printf("无法清空"); 
	}
	while(node)
	{
		node->data=0; 
		node=node->next;
	}
	printf("清空成功\n");
}
Status TraverseLQueue(const LQueue *Q)//遍历
{
	Node*node=Q->front;
	while(!node) 
	{
		printf("无法打印"); 
		 return FALSE;
	}
	printf("队列元素为：");
	while(node)
	{
		printf("%d ",node->data);
		node=node->next;
	}
	printf("\n");
	return TRUE;
} 
Status DeLQueue(LQueue *Q)//出队
{
	Node *node=Q->front;
	while(!node->next) 
	{
		printf("无法出队"); 
		 return FALSE;
	}
	Q->front=node->next;
	Q->length--; 
	free(node);
	return TRUE;
} 
int GetHeadLQueue(LQueue *Q)//查看头元素 
{
	return Q->front->data;
}
int LengthLQueue(LQueue *Q)//查看长度
{
	return Q->length;
} 
void DestoryLQueue(LQueue *Q)//摧毁队列
{
	Node *node;
	while(IsEmptyLQueue(Q))  
	{
		printf("队列为空，无法摧毁");
		return;
	}
	while(Q->front)
	{
		node=Q->front;
		Q->front=node->next;
		free(node);
	} 
	printf("摧毁成功");
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
    printf("要插入多少个数："); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	printf("data：");
		scanf("%d",&a);
    	EnLQueue(Q,a);
    }
    TraverseLQueue(Q);
    printf("\n");
    printf("出多少个数："); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	 DeLQueue(Q); 
    }
    TraverseLQueue(Q);
    printf("\n");
    printf("清空队列：\n"); 
    ClearLQueue(Q); 
    TraverseLQueue(Q);
    e=LengthLQueue(Q);
    printf("长度：");
    printf("%d\n",e);
    printf("摧毁队列：\n");
	DestoryLQueue(Q); 
	return 0;
}

