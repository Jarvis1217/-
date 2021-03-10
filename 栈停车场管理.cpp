#include<iostream>
#include<iomanip>
using	namespace	std;

#define	OK	1
#define	ERROR	0

typedef	int	Status;
typedef	int	ElemType;
typedef	struct	StackNode
{
	ElemType	data;
	struct	StackNode	*next;
}StackNode,*LinkStack;

Status   Push(LinkStack	&S,ElemType	id);
Status	Pop(LinkStack	&S,ElemType	&r);
Status	GoOut(LinkStack	&S,ElemType	ID);
Status	Print(LinkStack	S);

int	main()
{
	LinkStack	S;
	S=NULL;
	int	z,id,ID;
	do{
		cout<<setw(35)<<"ͣ��������"<<endl;
		cout<<"���������1�����2���뿪��3�����ͣ������0���˳��������ƺ�"<<endl;
		cin>>z;
		switch(z){
			case	1:
				cout<<"�����뵽����������ƺţ�"<<endl;
				cin>>id;
				Push(S,id);
				break;
			case	2:
				cout<<"�����뼴���뿪���������ƺţ�";
				cin>>ID;
				GoOut(S,ID);
				cout<<"�ó��뿪��ͣ����ʣ�೵��Ϊ��"<<endl;
				Print(S);
				break;
			case	3:
				if(S==NULL){
					cout<<"��ǰͣ����Ϊ��"<<endl;
					break;
				}
				cout<<"��ǰͣ����������ϢΪ��"<<endl;
				Print(S);
				break;
			 case	0:
			 	cout<<"�˳�����ϵͳ"<<endl;
			 	break;
		};
	}while(z!=0);
	delete	[]S->next;
	return	0;
	 
}
Status	Push(LinkStack	&S,ElemType	id){
	LinkStack	p;
	p=new	StackNode;
	p->data=id;
	p->next=S;
	S=p;
	return	OK;
}
Status	Pop(LinkStack	&S,ElemType	&r)
{
	LinkStack	p;
	if(S==NULL){
		cout<<"ͣ����Ϊ��"<<endl;
		return	ERROR;
	}
	r=S->data;
	p=S;
	S=S->next;
	delete	p;
	return	OK;
}
Status	GoOut(LinkStack	&S,ElemType	ID)
{
	LinkStack	p;
	p=NULL;	
	int	e,t;
	while(S->data!=ID)
	{
		Pop(S,e);
		Push(p,e);
	}
	Pop(S,e);
	while(p)
	{
		Pop(p,t);
		Push(S,t);
	}
	return	OK;
}
Status	Print(LinkStack	S)
{
	int	e,q,i=1;
	LinkStack	p;
	LinkStack	z;
	p=NULL;
	z=S;
	while(z!=NULL)
	{
		Pop(z,e);
		Push(p,e);
	}
	while(p!=NULL){
		Pop(p,q);
		Push(z,q);
		cout<<"���ƺţ�"<<q<<" λ�ú�"<<i<<endl;
		i++;
	}
	return	OK;
}
