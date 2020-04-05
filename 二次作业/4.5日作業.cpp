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
Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s->top=(LinkStackPtr)malloc(sizeof(LinkStackPtr));
	if(!s->top)
	return ERROR;
	s->count=0;
	s->top=NULL;
	return SUCCESS;
} 
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ�� 
{
	if(s->count==0)
	return SUCCESS;
	else
	return ERROR;
} 
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	LinkStackPtr a=(LinkStackPtr)malloc(sizeof(StackNode));
	a->data=data;
	a->next=s->top;
	s->top=a;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//��ջ 
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
Status LStackLength(LinkStack *s,int *length)//�ж�ջ�ĳ��� 
{
	*length=s->count-1;
	return SUCCESS;
}
 Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
 {
 	if(isEmptyLStack(s))
 	return ERROR;
 	else
 	*e=s->top->data;
 }
 Status Print(LinkStack *s)//���ջԪ�� 
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
 Status destroyLStack(LinkStack *s)//����ջ
 {
 	ElemType data;
 	while(isEmptyLStack(s)!=SUCCESS)
 	{
 		data=popLStack(s,&data);
 		s->top=s->top->next;
 		s->count--;
 	}
 	printf("���ٳɹ�"); 
 	return SUCCESS;
 } 
Status clearLStack(LinkStack *s)//���ջ
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
 	printf("��Ҫ���ٸ�Ԫ�أ�������:");
 	scanf("%d",&logo);
 	for(int i=0;i<logo;i++)
 	{
 		printf("������ջԪ��%d:",i+1);
 		scanf("%d",&data);
 		pushLStack(&s,data);
 		
 	}
 	printf("ݔ��Ԫ��");
	Print(&s);
	printf("ݔ��ջ����");
	LStackLength(&s,&len);
	printf("%d",len);
	//destroyLStack(&s);
	printf("\n");
	printf("ݔ��ͷԪ��");
	getTopLStack(&s,&e);
	 printf("%d",e);
	 printf("\n");
	 printf("���Ԫ�ز��������\n");
	 clearLStack(&s);
	 Print(&s);
	 printf("\n");
	 printf("����ջ��");
     destroyLStack(&s); 
	 printf("\n");
	 printf("�ٴ�ݔ��Ԫ��");
	Print(&s);
	return 0; 
 }
