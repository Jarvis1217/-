#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
const int MAXSIZE=100;
typedef char TElemType;
typedef int  Status;
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree SElemType;

typedef struct sequencestack{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

typedef struct{
	SElemType *base;
	int front;
	int rear;
}SqQueue;

void CreateBiTree(BiTree &t,char *ch);
Status InitStack(SqStack &S);
Status Push(SqStack &S,SElemType e);
Status Pop(SqStack &S,SElemType &e);
SElemType GetTop(SqStack S);
void DispBTNode(BiTree t);
BiTNode *FindNode(BiTree t,TElemType x);
void parent(BiTree t,BiTree t1,TElemType x);
void PreOrder(BiTree t);
void InOrder(BiTree t);
void PostOrder(BiTree t);
int CountLeaf(BiTree t);
int Depth(BiTree t);
void Doub(BiTree t);
int simi(BiTree t1,BiTree t2);
void findx(BiTree t);
int Findx(BiTree t);
void destroy(BiTree t);
void PrintTree(BiTree T,int nLayer);
void change(BiTree &t);
void doubleb(BiTree t);
void cOrder(BiTree t);
int NumLevel(BiTree t, int k); 
int plevel(BiTree t, int level);
void printlevel(BiTree t);

int main()
{
	int choice,h,e,d,f,k,level;char c[MAXSIZE],a[MAXSIZE];TElemType x;
	BiTree T,Ta,Tb,Tc;
	cout<<"�����������ŷ���ʾ������\n";
	cin>>c;
	CreateBiTree(Ta,c);
		cout<<"  �������Ļ�������\n";
		cout<<"      1.���ű�ʾ�����"<<"2.������״���\n"; 
		cout<<"      3.����˫��"<<"4.���Һ���\n";
		cout<<"      5.�������"<<"6.�������"<<"7.�������\n";
		cout<<"      8.ͳ��Ҷ�ӽڵ����"<<"9.���˫��֧���\n";
		cout<<"      10.�����"<<"11.�ж��������Ƿ����\n";
		cout<<"      12.�������Һ���"<<"13.˫�����\n";
		cout<<"      14.����α���"<<"15.�������\n";
		cout<<"      16.ͳ��Сд��ĸ������"<<"17.����·��\n";
		cout<<"      18.���Ҷ�ӵ�����·��"<<"19.������\n";
		cout<<"      20.���k��Ľ�����\n";
		cout<<"      0.�˳�(���ٶ�����)\n";
	do{ 
		cin>>choice;
		switch(choice)
		{
			case 0:destroy(Ta);cout<<"Bye!"<<endl;break;
			case 1:DispBTNode(Ta);cout<<endl;break;
			case 2:cout<<"������״���������Ϊ��\n";PrintTree(Ta,0);break;
			case 3:cout<<"������Ҫ���ҵĽ���ֵ\n";cin>>x;
			       Tb=FindNode(Ta,x);parent(Ta,Tb,x);break;
			case 4:cout<<"������Ҫ���ҵĽ���ֵ\n";cin>>x;
			       Tc=FindNode(Ta,x);cout<<x<<"������Ϊ��"<<Tc->lchild->data<<endl;
				   cout<<x<<"���Һ���Ϊ��"<<Tc->rchild->data<<endl;break;
			case 5:PreOrder(Ta);cout<<endl;break;
			case 6:InOrder(Ta);cout<<endl;break;
			case 7:PostOrder(Ta);cout<<endl;break;
			case 8:e=CountLeaf(Ta);cout<<"�������е�Ҷ�ӽ�����Ϊ��"<<e;cout<<endl;
			break;
			case 9:Doub(Ta);cout<<endl;
			break;
			case 10:h=Depth(Ta);cout<<"�����������Ϊ��"<<h;cout<<endl;
			break;
			case 11:cout<<"������ڶ�������\n";cin>>a;CreateBiTree(T,a);d=simi(Ta,T);
			        if(d) cout<<"���\n";
					else cout<<"�����\n";cout<<endl;
					break;
			case 12:change(Ta);cout<<"�������Һ��Ӻ�Ķ�����Ϊ��\n";PrintTree(Ta,0);cout<<endl;
			break;
			case 13:cout<<"ԭ������Ϊ��\n";PrintTree(Ta,0);cout<<"˫������Ľ��Ϊ:\n";doubleb(Ta);cout<<endl;break;
			case 14:
			cout<<"����α����Ľ��Ϊ��"<<endl;
			printlevel(Ta);
			cout<<endl;
			break;
			case 15:break;
			case 16:cout<<"ԭ������Ϊ��\n";PrintTree(Ta,0);f=Findx(Ta);cout<<"Сд��ĸ������Ϊ��"<<f<<endl;break;
			case 17:break;
			case 18:break;
			case 19:break;
			case 20:
			cout<<"������Ҫ���ҽڵ�����Ĳ���k��";
			cin>>k;
			cout<<"�ò��� "<<NumLevel(Ta, k)<<"���ڵ�"<<endl;break;
			default:
			printf("������0~20֮������֣�\n"); 

		}
	}
	while(choice!=0);
	
	
	return 0;
}
int plevel(BiTree t, int level) 
{  
    if (!t || level < 0)  
        return 0;  
    if (level== 0 ) 
	{  
        cout << t->data << " ";  
        return 1;  
    }  
    return plevel(t->lchild, level - 1) + plevel(t->rchild, level - 1);  
}

void printlevel(BiTree t) 
{  
    int i = 0;   
    for (i = 0; ; i++) 
	{  
        if (!plevel(t, i))  
            break;  
    }  
    cout << endl;  
}  
int NumLevel(BiTree t, int k)  
{  
    if(t == NULL || k < 1)  
        return 0;  
    if(k == 1)  
        return 1;  
    int numLeft = NumLevel(t->lchild, k-1);  
    int numRight = NumLevel(t->rchild, k-1); 
    return (numLeft + numRight);  
}  
void doubleb(BiTree t)
{
	if(t)
	{
		cout<<t->data;
	    doubleb(t->lchild);
	    cout<<t->data;
	    doubleb(t->rchild);
	}
}
void change(BiTree &t)
{
	BiTree t1;
	if(t==NULL) return ;
	change(t->lchild);
	change(t->rchild);
		t1=t->lchild;
		t->lchild=t->rchild;
		t->rchild=t1;
}
void PrintTree(BiTree T,int nLayer) 
{
    int i;
	 if(T==NULL) return;
	 PrintTree(T->rchild,nLayer+3);
	 for(i=0;i<nLayer;i++)
	  cout<<' ';
	 cout<<T->data;
	 if(T->lchild&&T->rchild)
	   cout<<'<';
	 else if(T->lchild==NULL&&T->rchild!=NULL)
	   cout<<'/';
	 else if(T->lchild!=NULL&&T->rchild==NULL)
	   cout<<'\\';
	 else 
	   cout<<'-';
	 cout<<endl;
	 PrintTree(T->lchild,nLayer+3);
}
void destroy(BiTree t)
{
	if(t!=NULL)
	{
	 BiTree p;
	 destroy(t->lchild);
	 destroy(t->rchild);
	 p=t;
	 delete p;
	}	
}
int Findx(BiTree t)
{
	if(t==NULL) return 0;
	if(t->data>='a'&&t->data<='z')
	  return Findx(t->lchild)+Findx(t->rchild)+1;
}
int simi(BiTree t1,BiTree t2)
{
	int like1,like2;
	if(t1==NULL&&t2==NULL)  return 1;
	else if(t1==NULL||t2==NULL)  return 0;
	else
	{
		like1=simi(t1->lchild,t2->lchild);
		like2=simi(t1->rchild,t2->rchild);
		return (like1&like2);
	}
}
void Doub(BiTree t)
{
	if(t!=NULL)
	{
	if(t->lchild&&t->rchild)
	 cout<<t->data<<' ';
	Doub(t->lchild);
	Doub(t->rchild);
    }
}
int Depth(BiTree t)
{
	int m,n;
	if(t==NULL)  return 0;
	else{
		m=Depth(t->lchild);
		n=Depth(t->rchild);
		if(m>n)   return (m+1);
		else return (n+1);
	}
}
int CountLeaf(BiTree t)
{
	int num;
	if(t==NULL)  num=0;
	else if(t->lchild==NULL&&t->rchild==NULL)
	     num=1;
	else
	     num=CountLeaf(t->lchild)+CountLeaf(t->rchild);
	return num;
}
void CreateBiTree(BiTree &t,char *ch)
{
	BiTNode *p=NULL;   int k,j=0;
	char c; SqStack s; SElemType x;
	t=NULL; c=ch[j];  InitStack(s);
	while(c!='\0') 
	{
		switch(c)
		{
			case '(':  Push(s,p);k=1;break;
			case ')':  Pop(s,x);break;
			case ',':  k=2;break;
			default :
				p=new BiTNode;
				p->data=c;
				p->lchild=NULL;
				p->rchild=NULL;
				if(t==NULL)
				   t=p;
				else
				{
					switch(k)
					{
						case 1:x=GetTop(s);x->lchild=p;break;
						case 2:x=GetTop(s);x->rchild=p;break;
					}
				}
		}
		j++;c=ch[j];
	}
}
void PreOrder(BiTree t)
{
	if(t)
	{
		cout<<t->data;
		PreOrder(t->lchild);
		PreOrder(t->rchild);
	}
}
void InOrder(BiTree t)
{
	if(t)
	{
		InOrder(t->lchild);
		cout<<t->data;
		InOrder(t->rchild);
	}
}
void PostOrder(BiTree t)
{
	if(t)
	{
		InOrder(t->lchild);
		InOrder(t->rchild);
		cout<<t->data;
	}
}
void DispBTNode(BiTree t)
{
	if(t!=NULL)
	{
		cout<<t->data;
		if(t->lchild!=NULL||t->rchild!=NULL)
		{
			cout<<'(';
			DispBTNode(t->lchild);
			if(t->rchild!=NULL)
			   cout<<',';
			DispBTNode(t->rchild);
			cout<<')';
		}
	}
}
void parent(BiTree t,BiTree t1,TElemType x)
{
	if(t->lchild||t->rchild)
	{
	 if(t->lchild==t1||t->rchild==t1)
	  cout<<x<<"��˫��Ϊ��"<<t->data<<endl;
	 else 
	  {
	   parent(t->lchild,t1,x);
       parent(t->rchild,t1,x);
      }
    }
}
BiTNode *FindNode(BiTree t,TElemType x)
{
	BiTNode *p;
	if(t==NULL)
	   return NULL;
	else if(t->data==x)
	    return t;
	    else 
	    {
	    	p=FindNode(t->lchild,x);
	    	if(p!=NULL)
	    	    return p;
	    	    else return FindNode(t->rchild,x);
	    }
}
Status InitStack(SqStack &S)
{
	S.base=new SElemType[MAXSIZE];
	if(!S.base)  exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return OK;
}
Status Push(SqStack &S,SElemType e)
{
	if(S.top-S.base==S.stacksize)  return ERROR;
	*S.top++=e;
	return OK;
}
Status Pop(SqStack &S,SElemType &e)
{
	if(S.top==S.base)  return ERROR;
	e=*--S.top;
	return OK;
}
SElemType GetTop(SqStack S)
{
	if(S.top!=S.base)
	   return *(S.top-1);
} 
