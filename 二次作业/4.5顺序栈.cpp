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
Status initStack(SqStack *s,int sizes)//初始化栈
{
	s->elem=(ElemType*)malloc(sizes*sizeof(ElemType));
	s->top=0;
	s->size=sizes;
	return SUCCESS;
} 
Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->top==0) 
	return SUCCESS;
	else
	return ERROR;
}
Status pushStack(SqStack *s,ElemType data)//入栈
{
	if((s->top)>(s->size))
	return ERROR;
	else 
	 s->elem[s->top++]=data;
	 return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)//出栈
{
	if(isEmptyStack(s)==SUCCESS) 
	return ERROR;
	else
	{
		*data=s->elem[--s->top];
		return SUCCESS; 
	}
}
Status stackLength(SqStack *s,int *length)//检测栈长度
{
	*length=s->top;
	return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	*e=s->elem[s->top-1];
	return SUCCESS;
}
Status destroyStack(SqStack *s)//销毁栈
{
	ElemType a;
	while(isEmptyStack(s)!=SUCCESS)
   {
	    free(&s->elem[s->top-1]);
		popStack(s,&a);
   }
   printf("銷毀成功"); 
   return SUCCESS;
} 
void Print(SqStack *s)//输出元素 
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
	printf("输入你入栈的个数"); 
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		printf("输入入栈元素%d:",i+1);
		scanf("%d",&data);
		pushStack(&s,data);
	}
	/*pushStack(&s,1);          //----- 测试------ 
	pushStack(&s,3);
	pushStack(&s,4);
	Print(&s);*/
	//getTopStack(&s,&e);
	//printf("输出栈订元素：");
	//printf("%d",e);
	//popStack(&s,&data);
	//Print(&s);
	
	//destroyStack(&s);
	printf("输出栈所有元素：");
	Print(&s);
	printf("输入你出栈的个数"); 
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		popStack(&s,&data); 
	}
	printf("输出栈所有元素：");
	Print(&s);
	stackLength(&s,&length);
	printf("输出栈的长度:%d\n",length);
	getTopStack(&s,&e);
	printf("输出栈顶元素：");
	printf("%d",e);
	return 0;
}

