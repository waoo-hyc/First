#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;
Status initLStack(LinkStack *s)//初始化栈
{
	s->top=(LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if(!s->top)
	return ERROR;
	s->count=0;
	s->top=NULL;
	return SUCCESS;
} 
Status isEmptyLStack(LinkStack *s)//判断栈是否为空 
{
	if(s->count==0)
	return SUCCESS;
	else
	return ERROR;
} 
Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	LinkStackPtr a=(LinkStackPtr)malloc(sizeof(StackNode));
	a->data=data;
	a->next=s->top;
	s->top=a;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//出栈 
{
	LinkStackPtr Non;
	if(isEmptyLStack(s))
	return ERROR;
	else
	{
		Non=s->top;
		*data=s->top->data;
		s->top=s->top->next;
		free(Non);
		s->count--;
		return SUCCESS;
	}
}
Status LStackLength(LinkStack *s,int *length)//判断栈的长度 
{
	*length=s->count-1;
	return SUCCESS;
}
 Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
 {
 	if(isEmptyLStack(s))
 	return ERROR;
 	else
 	*e=s->top->data;
 }
 Status Print(LinkStack *s)//输出栈元素 
 {
 	LinkStackPtr tool;
	 tool=s->top;
	 while(tool->next)
	 {
	 	printf("%3d",tool->data);
	 	tool=tool->next;
	 } 
	 printf("\n");
	 return SUCCESS; 
 }
 Status destroyLStack(LinkStack *s)//销毁栈
 {
 	ElemType data;
 	while(isEmptyLStack(s)!=SUCCESS)
 	{
 		data=popLStack(s,&data);
 		s->top=s->top->next;
 		s->count--;
 	}
 	printf("销毁成功"); 
 	return SUCCESS;
 } 
Status clearLStack(LinkStack *s)//清空栈
 {
 	LinkStackPtr a=s->top;
 	while(a->next)
 	{
 		a->data=0;
 		a=a->next;
 	}
 	return SUCCESS;
 }
 int main()
 {
 	LinkStack s;
 	int len,e,logo,data;
 	//if(initLStack(&s)==true)
 	/*for(int i=0;i<logo;i++)
 	{
 		pushLStack(&s,i); 
 	}*/
 	printf("想要多少个元素？请输入:");
 	scanf("%d",&logo);
 	for(int i=0;i<logo;i++)
 	{
 		printf("输入入栈元素%d:",i+1);
 		scanf("%d",&data);
 		pushLStack(&s,data);
 		
 	}
 	printf("輸出元素");
	Print(&s);
	printf("輸出栈长度");
	LStackLength(&s,&len);
	printf("%d",len);
	//destroyLStack(&s);
	printf("\n");
	printf("輸出头元素");
	getTopLStack(&s,&e);
	 printf("%d",e);
	 printf("\n");
	 printf("清空元素并重新输出\n");
	 clearLStack(&s);
	 Print(&s);
	 printf("\n");
	 printf("销毁栈；");
     destroyLStack(&s); 
	 printf("\n");
	 printf("再次輸出元素");
	Print(&s);
	return 0; 
 }
