#include<iostream>
using namespace std;

#define MAXSIZE 100
#define ERROR 0
#define OK 1

typedef int status;
typedef int ElemType;

typedef struct lnode
{
	ElemType date;
	struct lnode *next;
}LNode,*LinkList;

//��ʼ��ͷ�ڵ�
status initList(LinkList &La)
{
	La=new LNode;
	La->next=NULL;
	return OK;
} 

//����������
status CreatList(LinkList &La,ElemType a[],int n)
{
	LNode *s,*r;
	int i;
	r=La;
	for(i=0;i<n;i++)
	{
		s=new LNode;
		s->date=a[i];
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return OK;
} 
//�����˳� 
status destroy(LinkList &La)
{
	LNode *p;
	while(La!=NULL)
	{
		p=La;
		La=La->next;
		delete p;
	}
	return OK;
}
//���Ԫ��
void  output(LinkList La)
{
    LNode *p=La->next;
	if(La->next==NULL)
	cout<<"������Ϊ������";
	while(p!=NULL)
	{
		cout<<p->date<<' ';
		p=p->next;
	}	
} 
//����Ų��� 
status findlist1(LinkList La,int n,int &e)
{
	LNode *p=La->next;
	int j=1;
	while(p&&j<n)
	{
		p=p->next;
		j++;
	}
	if(!p||j>n)
	return ERROR;
	e=p->date;
	return OK;
} 
//��ֵ����
void findlist2(LinkList La,int e)
{
	LNode *q;
	int i=1;
	q=La->next;
	while(q&&q->date!=e)
	{
		q=q->next;
		i++;
	}
	if(q!=NULL)
	  cout<<e<<"Ϊ��"<<i<<"��Ԫ��";
	else
	  cout<<"����Ԫ�ز�����";
} 
//����Ԫ��
status Insertlist(LinkList &La,int e,int i)
{
	LNode *p=La,*s;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next; 
		j++;
	}
	if(p==NULL||j>i+1)
	return ERROR;
	s=new LNode;
	s->date=e;
	s->next=p->next;
	p->next=s;
	return OK;
} 
//ɾ��Ԫ��
void Listdelete(LinkList &La,int i)
{
	LNode *p=La,*q;
	int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if((p->next==NULL)||j>i-1)
	cout<<"ɾ����Ԫ�ز�����";
	q=p->next;
	p->next=q->next;
	delete q;
	cout<<"ִ�гɹ�"; 
} 
//���
void ListLength(LinkList La)
{
	LNode *p=La->next;
	int len=0;
	while(p!=NULL)
	{
		len++;
		p=p->next;
	}
	cout<<"��Ϊ��"<<len;
} 
//������ֵ
int Maxone(LinkList La)
{
	LNode *m=La->next;
	int max;
	max=m->date;
	while(m->next!=NULL)
	{
		m=m->next;
		if(m->date>max)
		max=m->date;
	};
    return max;
} 
//ɾ������Ԫ��
status Deletearea(LinkList &La,int x,int y)
{
	LNode *p=La->next,*q,*m,*n,*d;
	while(p!=NULL)
	{
		if(p->date==x)
		q=p;
		if(p->date==y)
		m=p;
		p=p->next;
	}
	n=q->next;
	q->next=m;
	do
	{
		d=n;
		n=n->next;
		delete d;
	}while(n->date==m->date);
	return OK;
} 
//��յ�����
status ClearList (LinkList &La)
{
	LNode *p,*q;
	p=La->next;
	while(p!=NULL)
	{
		q=p->next;
		delete p;
		p=q;
	}
	La->next=NULL;
	return OK;
}

int main(void)
{
	LinkList La;
	int i,n;
	ElemType a[MAXSIZE];
	initList(La);
	cout<<"������Ԫ�ظ�����";
	cin>>n;
	if(n!=0)
	cout<<"������Ԫ�أ�";
	for(i=0;i<n;i++)
	cin>>a[i];
	CreatList(La,a,n);
	cout<<endl;
	cout<<"��ʾ��"<<endl;
	cout<<"1-���Ԫ�أ�2-����Ų��ң�3-��ֵ���ң�4-����Ԫ�أ�5-ɾ��Ԫ��"<<endl;
	cout<<"6-�������ȣ�7-������ֵ��8-ɾ������Ԫ�أ�9-�������0-�˳�����"<<endl;
	cout<<endl;
	
	int f;
do
{
	cout<<"�������������";
	cin>>f;
	switch(f)
	{
		case 0:                         //�����˳� 
			{
				destroy(La);
				cout<<"ллʹ��"; 
				break;
			}
		case 1:                         //��� 
			{
				output(La);
				cout<<endl;
		        break;
			}
		case 2:                        //����Ų��� 
			{
				int n,e;
				cout<<"���������Ԫ�ص���ţ�";
				cin>>n;
				findlist1(La,n,e);
				cout<<"��"<<n<<"��Ԫ��Ϊ��"<<e; 
				cout<<endl;
		        break;
			}
			case 3:                   //��ֵ���� 
				{
					int e;
					cout<<"��������ҵ�Ԫ�أ�";
					cin>>e;
					findlist2(La,e);
					cout<<endl;
					break;
			    }
			case 4:                    //����Ԫ�� 
				{
					 int e,i;
					 cout<<"���������Ԫ�أ�";
					 cin>>e;
					 cout<<"���������λ�ã�";
					 cin>>i;
					 Insertlist(La,e,i) ;
					 cout<<"ִ�гɹ�";
					 cout<<endl;
					 break;
				}
			case 5:                  //ɾ��Ԫ��
			    {
			    	int i;
			    	cout<<"������ɾ��Ԫ����ţ�";
			    	cin>>i;
			    	Listdelete(La,i);
			    	cout<<endl;
			    	break;
			    }
			case 6:                  //���
			    {
			    	ListLength(La);
			    	cout<<endl;
			    	break;
			    } 
			case 7:                 //������ֵ
			    {
			    	int max;
			    	max=Maxone(La);
			    	cout<<"�������Ԫ��Ϊ��"<<max;
			    	cout<<endl;
			    	break;
			    } 
			    case 8:              //ɾ������Ԫ��
				{
					int x,y;
					cout<<"������ɾ����Χ��";
					cin>>x>>y;
					Deletearea(La,x,y);
					cout<<"ִ�гɹ�";
					cout<<endl;
					break;
				} 
				case 9:               //��յ�����
				{
					ClearList(La);
					cout<<"ִ�гɹ�";
					cout<<endl;
					break;
				} 
			
		default:cout<<"��������";cout<<endl;break;
	}
    cout<<endl;
}while(f!=0);
	
	return 0;
} 
