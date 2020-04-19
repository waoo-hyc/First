#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SORT_H_INCLUDED
#define random(x)rand()%(x)
#define NUM 100000
#define MAXNUM 1000000
#define KEYBUN 5

void insertSort(int *a,int n)
{
	int j,temp;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
} 
void MergeArray(int *a,int begin,int mid,int end,int *temp)//归并（）合 
{
	int i=begin;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]<a[j])
		{temp[k++]=a[i++];
		}
		else{
		temp[k++]=a[j++];
		}

		
	} 
	while(i<=mid)
	{
		temp[k++]=a[i++];
	}
	while(j<=end)
	{
		temp[k++]=a[j++];
	}
       k=0;
       while(begin<=end)
       {
       	a[begin++]=temp[k++];
       }
}
void MergeSort(int *a,int begin,int end,int *temp)//归并（裂）
{

	if(begin<end)
	{
		int mid=(begin+end)/2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
	}
} 
void QuickSort_Recursion(int *a, int begin, int end)//快排 
{
int i=begin,j=end,temp=a[begin];
while(i>=j)
{
	return;
}
while(i<j){
	while(i<j&&a[j]>a[i])
{
	j--;
}	
if(i<j&&a[j]<a[i])
{
     temp=a[j];
	 a[j]=a[i];
	 a[i]=temp; 
	 i++;
}
while(i<j&&a[i]<a[j])
{
	i++;
}
if(i<j&&a[i]>a[j])
{
	 temp=a[j];
	 a[j]=a[i];
	 a[i]=temp;
	 j--;
}
}
QuickSort_Recursion(a,begin,i-1);
QuickSort_Recursion(a,i+1,end);
}
void QuickSort(int *a,int size)//快排不递归
{
	int i,j,min,temp;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
} 
void Partition(int *a, int begin, int end)//快速排序（枢轴存放）
{
	if(begin>=end)
	{
		return;
	}
	int mid=(begin+end)/2;
	int temp;
	int ha=begin,hb=end;
	if(a[end]<a[begin])
	{
	    temp=a[begin];
		a[begin]=a[end];
		a[end]=temp;	
	} 
	if(a[end]<a[mid])
	{
		 temp=a[mid];
		a[mid]=a[end];
		a[end]=temp;
	}
	if(a[mid]>a[begin])
	{
		temp=a[mid];
		a[mid]=a[begin];
		a[begin]=temp;
	}
	int size=a[begin];
	while(ha<hb)
	{
		while(ha<hb&&a[hb]>=size)
		hb--;
		a[ha]=a[hb];
		while(ha<hb&&a[ha]<=size)
		ha++;
		a[hb]=a[ha];
	}
	a[ha]=size;
	Partition(a,begin,ha);
	Partition(a,ha+1,end);
	
}
void CountSort(int *A, int size , int max)//计数
{
	int *c, *b;
    int i;
    c = (int *)malloc(sizeof(int)*(max+1));
    b = (int *)malloc(sizeof(int)*size); 
    for (i = 0; i <= max; i++)
        c[i] = 0;                      
    for (i = 0; i < size; i++)
        c[A[i]] += 1;                   
    for (i = 1; i <= max; i++)
       c[i] = c[i - 1] + c[i];        
    for (i = size - 1; i >= 0; i--)
    {
        b[c[A[i]] - 1] = A[i];      
        c[A[i]] -= 1;
    }
    for (i = 0; i < size; i++)
        A[i] = b[i];               
    free(c);
    free(b);
	} 
	int GetPos(int num,int pos)//得到第几位上的数 
	{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
	temp *= 10;
	return (num / temp) % 10;
	}
	void RadixCountSort(int *a,int size)//基数排序
	{
		int *radion[10];
		for(int i=0;i<10;i++)
		{
			radion[i]=(int*)malloc(sizeof(int)*(size+1));
			radion[i][0]=0;
		}
		for(int pos=1;pos<=KEYBUN;pos++)
		{
			for(int i=0;i<size;i++)//分配 
			{
				int temp=GetPos(a[i],pos);
				int index=++radion[temp][0];
				radion[temp][index]=a[i];
			}
			for(int i=0,j=0;i<10;i++)//收集 
			{
				for(int k=1;k<=radion[i][0];k++)
				a[j++]=radion[i][k];
				radion[i][0]=0;
			}
		}
	} 
int main()
{
    printf("100k级别时间\n"); 
	int a[NUM];
	int temp[NUM];
	int i;
	clock_t start,end;
	for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
	start=clock();

    RadixCountSort(a,NUM);
    clock_t diff=clock()-start;
    printf("100k计数time:%dms\n",diff);
//--------------------------------------------
for(i=0;i<NUM;i++)
	{
		 a[i]=random(MAXNUM);
	}
	start=clock();

    RadixCountSort(a,NUM);
    diff=clock()-start;
    printf("100k基数time:%dms\n",diff);
//--------------------------------------------
for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
	start=clock();

    insertSort(a,NUM);
    diff=clock()-start;
    printf("插入time:%dms\n",diff);
//--------------------------------------------
	for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
	start=clock();

    Partition(a,0,NUM-1);
    diff=clock()-start;
    printf("快排曲轴time:%dms\n",diff);
//--------------------------------------------
	for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
	start=clock();

    MergeSort(a,0,NUM-1,temp);
    diff=clock()-start;
    printf("归并time:%dms\n",diff);
//--------------------------------------------
  /* for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
    start=clock();
	for(;i<200000;i++)
	{
    insertSort(a,NUM);
	}
    diff=clock()-start;
    printf("插入time:%f ms\n",(double)diff);
//--------------------------------------------
 for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
    start=clock();
	for(;i<100000;i++)
	{
    MergeSort(a,0,NUM-1,temp);
	}
    diff=clock()-start;
    printf("归并time:%f ms\n",(double)diff);
//--------------------------------------------
 for(i=0;i<NUM;i++)
	{
		a[i]=random(MAXNUM);
	}
    start=clock();
	for(;i<100000;i++)
	{
    RadixCountSort(a,NUM); 
	}
    diff=clock()-start;
    printf("基数time:%f ms\n",(double)diff);*/
//--------------------------------------------

	//for(i=0;i<NUM;i++)
//	{
	//printf("%d ",a[i]);
   // }
//	return 0;
}
