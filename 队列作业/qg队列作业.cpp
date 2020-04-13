#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 10
typedef struct Aqueue
{
    int data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
AQueue *CreateAQueue()//�������� 
{
	AQueue *Q=(AQueue*)malloc(sizeof(AQueue));
	Q->length=0;
	Q->front=0;
	Q->rear=0;
} 
void InitAQueue(AQueue *Q)//��ʼ������ 
{
  Q->front=0;
  Q->rear=0;	
}
void DestoryAQueue(AQueue *Q)//���ٶ���
{
	if(Q!=NULL)
	{
		free(Q);
	}
	printf("�ݻٳɹ�"); 
}
Status IsEmptyAQueue(const AQueue *Q)//�ж϶����Ƿ�Ϊ�� 
{
	if(Q->front==Q->rear)  return TRUE;
	else 
	return FALSE;
}
Status IsFullAQueue(const AQueue *Q)//�ж϶����Ƿ����� 
{
	if((Q->rear+1)%MAXQUEUE==Q->front)  return TRUE;
	else 
	return FALSE;
}
Status GetHeadAQueue(AQueue *Q, int *e)//��ȡ��ͷԪ�� 
{
   if(IsEmptyAQueue(Q))	return FALSE;
   else 
   {
   
   *e=Q->data[Q->front];
   return TRUE;
   }
} 
int LengthAQueue(AQueue *Q) //��ȡ���г��� 
{
	return Q->length; 
} 
Status EnAQueue(AQueue *Q, int data)//��Ӳ��� 
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
Status DeAQueue(AQueue *Q)//���Ӳ��� 
{
	if(IsEmptyAQueue(Q)) return FALSE;
	else
	{
		Q->front=(Q->front+1)%MAXQUEUE;
		Q->length--;
		return TRUE; 
	}
}
Status TraverseAQueue(const AQueue *Q)//�������� 
{
	int front=Q->front;
	int rear=Q->rear;
	printf("���У�");
	while(front!=rear)
	{
		printf("%d  ",Q->data[front]);
		front=(front+1)%MAXQUEUE;
	} 
	return TRUE;
} 
Status ClearAQueue(AQueue *Q)//��ն��� 
{
	int front=Q->front;
	int rear=Q->rear;
		while(front!=rear)
	{
		Q->data[front]=0;
		front=(front+1)%MAXQUEUE;
	} 
	printf("��ճɹ�:\n"); 
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
    printf("Ҫ������ٸ�����"); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	printf("data��");
		scanf("%d",&a);
    	EnAQueue(Q,a);
    }
    TraverseAQueue(Q);
    printf("\n");
    printf("�����ٸ�����"); 
	scanf("%d",&n); 
    for(i=0;i<n;i++)
    {
    	 DeAQueue(Q); 
    }
    TraverseAQueue(Q);
    printf("\n");
    printf("��ն��У�\n"); 
    ClearAQueue(Q); 
    TraverseAQueue(Q);
    e=LengthAQueue(Q);
    printf("���ȣ�");
    printf("%d\n",e);
    printf("�ݻٶ��У�\n");
	DestoryAQueue(Q); 
	return 0;
}
