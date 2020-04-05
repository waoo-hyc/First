#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#define STACK_H_INCLUDED 100
typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;
Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	s->top=0;
	s->size=sizes;
	return SUCCESS;
} 
Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==0) 
	return SUCCESS;
	else
	return ERROR;
}
Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if((s->top)>(s->size))
	return ERROR;
	else 
	 s->elem[s->top++]=data;
	 return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(isEmptyStack(s)==SUCCESS) 
	return ERROR;
	else
	{
		*data=s->elem[--s->top];
		return SUCCESS; 
	}
}
Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length=s->top;
	return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	*e=s->elem[s->top-1];
	return SUCCESS;
}
Status destroyStack(SqStack *s)//����ջ
{
	ElemType a;
	while(isEmptyStack(s)!=SUCCESS)
   {
	    free(&s->elem[s->top-1]);
		popStack(s,&a);
   }
   printf("�N���ɹ�"); 
   return SUCCESS;
} 
void Print(SqStack *s)//���Ԫ�� 
{
	int k=s->top-1;
	for(int i=k;i>=0;i--)
	{
		printf("%3d",s->elem[i]);
	}
	printf("\n");
}
int main()
{
	SqStack s;
	ElemType data,e;
	int i,j,k;
	int length;
	initStack(&s,STACK_H_INCLUDED);
	printf("��������ջ�ĸ���"); 
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		printf("������ջԪ��%d:",i+1);
		scanf("%d",&data);
		pushStack(&s,data);
	}
	/*pushStack(&s,1);          //----- ����------ 
	pushStack(&s,3);
	pushStack(&s,4);
	Print(&s);*/
	//getTopStack(&s,&e);
	//printf("���ջ��Ԫ�أ�");
	//printf("%d",e);
	//popStack(&s,&data);
	//Print(&s);
	
	//destroyStack(&s);
	printf("���ջ����Ԫ�أ�");
	Print(&s);
	printf("�������ջ�ĸ���"); 
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		popStack(&s,&data); 
	}
	printf("���ջ����Ԫ�أ�");
	Print(&s);
	stackLength(&s,&length);
	printf("���ջ�ĳ���:%d\n",length);
	getTopStack(&s,&e);
	printf("���ջ��Ԫ�أ�");
	printf("%d",e);
	return 0;
}

