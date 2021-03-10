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

//0-�˳����� 
Status Displist(sqlist &L)
{
	delete []L.elem;
	L.length=0;
	cout<<"ллʹ�ã����˳�����";
	return ok;
}

//1-���Ԫ�� 
void output(sqlist &L)
{
	int i;
	for(i=0;i<L.length;i++)
	cout<<L.elem[i]<<" ";
}

//2-ɾ��Ԫ�� 
Status Delete(sqlist &L) 
{
	int i,j;
	cout<<"ɾ��Ԫ�ص����Ϊ:";
	cin>>i;
	if((i<1)||(i>L.length))
	{
		cout<<"������Ų��Ϸ�"; 
	    return error;
	}
	for(j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
		--L.length;
		cout<<"ִ�гɹ�";
		return ok;
}

//3-����Ԫ��
Status findlist1(sqlist &L)
{
	int i,e;
	cout<<"���������Ԫ�����:";
	cin>>i;
	if((i<1)||(i>L.length))
	{
		cout<<"������Ų��Ϸ�"; 
	    return error;
	}
	e=L.elem[i-1];
	printf("��%d��Ԫ��Ϊ:%d",i,e);
	return ok;
} 
//4-����Ԫ����� 
Status findlist2(sqlist &L)
{
	int e,i;
	cout<<"��Ҫ���ҵ�Ԫ��Ϊ��";
	cin>>e;
	for(i=0;i<L.length;i++)
	if(L.elem[i]==e)
	printf("Ԫ��%dΪ��%d��Ԫ��",e,i+1);
	return ok;
} 

//5-����Ԫ��
Status cutin(sqlist &L)
{
	int i,e,j;
	cout<<"���������λ�úͲ���Ԫ��:";
	cin>>i>>e;
	if((i<1)||(i>L.length+1))
	{
		cout<<"������Ų��Ϸ�"; 
	    return error;
	}
	if(L.length==maxsize)
	{
		cout<<"�洢�ռ�����";
		return error;
	}
	for(j=L.length-1;j>=i-1;j--)
	L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	++L.length;
	cout<<"ִ�гɹ�";
	return ok;
} 

//6-ɾ������Ԫ��
Status deletesome(sqlist &L)
{
	int i=0,x,y;  
    int j=0;  
    cout<<"������ɾ����Χ:";
    cin>>x>>y;
    while(i<L.length)  
    {  
        if(L.elem[i]>=x && L.elem[i]<=y)  
            j++;  
        else  
            L.elem[i-j]=L.elem[i];  
        i++;  
    }  
    L.length-=j; 
    cout<<"ִ�гɹ�";
    return ok;
}

//7-��ֵ������
Status Simplist(sqlist &L)
{
	Elemtype *p,*q,*r;
	q=L.elem;
	r=L.elem+L.length-1;
	for(q=L.elem;q<L.elem+L.length;q++)
	{
		for(r=L.elem+L.length-1;r>q;--r)
	     if(*q==*r)
	     {
	     	p=r;
	     	for(++p;p<=L.elem+L.length-1;++p)
	     	*(p-1)=*p;
	     	--L.length;
	     }
	}
	cout<<"ִ�гɹ�";
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
	
	int s;
	cout<<endl;
	cout<<"��ʾ��"<<endl; 
	cout<<"0-�����˳�;1-���Ԫ��;2-ɾ��Ԫ��;3-����Ԫ��;"<<endl;
	cout<<"4-����Ԫ�����;5-����Ԫ��;6-ɾ������Ԫ��;7-��ֵ������;"<<endl;
	do
	{
		cout<<endl;
 	    cout<<"�������������"; 
	    cin>>s;
	    //�жϲ�����ʽ 
	    if(s==0)
	    {
	    	Displist(L);
	    	cout<<endl;
	    }
	    
	    if(s==1)
	    {
	    	output(L);
	    	cout<<endl;
	    }
	    
	    if(s==2)
	    {
	    	Delete(L);
	    	cout<<endl;
	    }
	    
	    if(s==3)
	    {
	    	findlist1(L);
	    	cout<<endl;
	    }
	    
	    if(s==4)
	    {
	    	findlist2(L);
	    	cout<<endl;
	    }
		
		if(s==5)
		{
			cutin(L);
			cout<<endl;
		}
		  
		if(s==6)
		{
		    deletesome(L);
			cout<<endl;
		}  
		
		if(s==7)
		{
			Simplist(L);
			cout<<endl;
		}
		
	}while(s!=0);
	
	return 0;
}

