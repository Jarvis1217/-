#include <iostream>
using namespace std;

#define maxsize 100
#define ok 1
#define error 0
#define overflow -2

typedef int Elemtype;
typedef int Status;
//����˳��� 
typedef struct list
{
	Elemtype *elem;
	int length;
}sqlist;
//��ʼ��˳��� 
Status initList(sqlist &L)
{
	L.elem=new Elemtype[maxsize];
	if(!L.elem)
	exit(overflow);
	L.length=0;
	return ok;
}
//����˳��� 
Status Creatlist(sqlist &L,Elemtype a[], int n)
{
	int i;
	for(i=0;i<n;i++)
	L.elem[i]=a[i];
	L.length=n;
	return ok;
}
//ð������
Status Bubblesort(sqlist &L)
{
	int i,j,t,q;
	for(i=1;i<L.length;i++)
	{
		for(j=0;j<L.length-1;j++)
		
		{
			if(L.elem[j]>L.elem[j+1])
			{
				t=L.elem[j+1];
				L.elem[j+1]=L.elem[j];
				L.elem[j]=t;
			}
		}
	}
	cout<<"�������Ϊ��";
	for(q=0;q<L.length;q++)
	cout<<L.elem[q]<<' ';
	return ok;
} 
//��ճ�˳��� 
Status Displist(sqlist &L)
{
	delete []L.elem;
	L.length=0;
	return ok;
}

int main()
{
	sqlist L;
	initList(L);
	int n,i;
	cout<<"����Ԫ�صĸ���Ϊ��";
	cin>>n;
	Elemtype a[maxsize];
	cout<<"������Ԫ��:";
	for(i=0;i<n;i++)
		cin>>a[i];
	Creatlist(L,a,n);
	//ð������ 
	Bubblesort(L);
	
	Displist(L);
	
    return 0;
} 
