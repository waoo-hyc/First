#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 10
typedef struct Aqueue
{
    int data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
AQueue *CreateAQueue()//创建队列 
{
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
	Q->length=0;
	Q->front=0;
	Q->rear=0;
} 
void InitAQueue(AQueue *Q)//初始化队列 
{
  Q->front=0;
  Q->rear=0;	
}
void DestoryAQueue(AQueue *Q)//销毁队列
{
	if(Q!=NULL)
	{
		free(Q);
	}
	printf("摧毁成功"); 
}
Status IsEmptyAQueue(const AQueue *Q)//判断队列是否为空 
{
	if(Q->front==Q->rear)  return TRUE;
	else 
	return FALSE;
}
Status IsFullAQueue(const AQueue *Q)//判断队列是否满了 
{
	if((Q->rear+1)%MAXQUEUE==Q->front)  return TRUE;
	else 
	return FALSE;
}
Status GetHeadAQueue(AQueue *Q, int *e)//获取对头元素 
{
   if(IsEmptyAQueue(Q))	return FALSE;
   else 
   {
   
   *e=Q->data[Q->front];
   return TRUE;
   }
} 
int LengthAQueue(AQueue *Q) //获取队列长度 
{
	return Q->length; 
} 
Status EnAQueue(AQueue *Q, int data)//入队操作 
{
	if(IsFullAQueue(Q)) return FALSE;
	else
	{
		Q->data[Q->rear]=data;
		Q->rear=(Q->rear+1)%MAXQUEUE;
		Q->length++;
		return TRUE; 
	} 
}
Status DeAQueue(AQueue *Q)//出队操作 
{
	if(IsEmptyAQueue(Q)) return FALSE;
	else
	{
		Q->front=(Q->front+1)%MAXQUEUE;
		Q->length--;
		return TRUE; 
	}
}
Status TraverseAQueue(const AQueue *Q)//遍历队列 
{
	int front=Q->front;
	int rear=Q->rear;
	printf("队列：");
	while(front!=rear)
	{
		printf("%d  ",Q->data[front]);
		front=(front+1)%MAXQUEUE;
	} 
	return TRUE;
} 
Status ClearAQueue(AQueue *Q)//清空队列 
{
	int front=Q->front;
	int rear=Q->rear;
		while(front!=rear)
	{
		Q->data[front]=0;
		front=(front+1)%MAXQUEUE;
	} 
	printf("清空成功:\n"); 
	return TRUE;
}
int main()
{
	//int i=0,a=5,b=6,c=7,e=29;
/*	AQueue *Q; 
	Q=CreateAQueue();
	/*int a[10]={1,2,3,4,5,6,7,8,9,10};
	for(i=0;i<10;i++){
		EnAQueue(&Q,**a);
	}
    EnAQueue(Q,2);
    EnAQueue(Q,3);
    EnAQueue(Q,4);
    EnAQueue(Q,5);
    printf("%d ",LengthAQueue(Q));
    //printf("%d",Q->data[Q->front]);
	TraverseAQueue(Q);
    ClearAQueue(Q);
    TraverseAQueue(Q);*/
    int i,j,k,n,a,e;
    AQueue *Q; 
	Q=CreateAQueue();
    printf("要插入多少个数："); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	printf("data：");
		scanf("%d",&a);
    	EnAQueue(Q,a);
    }
    TraverseAQueue(Q);
    printf("\n");
    printf("出多少个数："); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	 DeAQueue(Q); 
    }
    TraverseAQueue(Q);
    printf("\n");
    printf("清空队列：\n"); 
    ClearAQueue(Q); 
    TraverseAQueue(Q);
    e=LengthAQueue(Q);
    printf("长度：");
    printf("%d\n",e);
    printf("摧毁队列：\n");
	DestoryAQueue(Q); 
	return 0;
}
