#include<stdio.h>
#define SORT_H_INCLUDED

void MergeArray(int *a,int begin,int mid,int end,int *temp)//¹é²¢£¨£©ºÏ 
{
	int i=begin;
	int j=mid+1,k=0;
	while(i<=mid&&j<=end)
	{
		if(a[i]<a[j])
		temp[k++]=a[i++];
		else
		temp[k++]=a[j++];
		
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
void MergeSort(int *a,int begin,int end,int *temp)
{

	while(begin<end)
	{
		int mid=(begin+end)/2;
		MergeSort(a,begin,mid,temp);
		MergeSort(a,mid+1,end,temp);
		MergeArray(a,begin,mid,end,temp);
	}
} 
int main()
{
	int a[8]={4,6,2,9,10,7,8,15},temp[8];
	MergeSort(a,0,7,temp);
	for(int i=0;i<7;i++)
	{
		printf("%d ",a[i]);
	}
	
}
