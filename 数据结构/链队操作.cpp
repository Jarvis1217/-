#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
typedef int ElemType;

//�������ӽڵ�
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode ,*Queueptr; 

//����ͷβָ�� 
typedef struct
{
    Queueptr front;
    Queueptr rear;
}LinkQueue;

//���ӳ�ʼ�� 
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=new QNode;
    Q.front->next=NULL;
} 

//���ٶ��� 
void DestroyQueue(LinkQueue &Q)
{
    while(Q.front)
    {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}

//����еĳ���
int QueueLength(LinkQueue Q)
{
	QNode *p;
    p = Q.front;
    int count = 0;
    while (p->next!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

//�����
void PrintQueue(LinkQueue Q)
{
	QNode *p;
	p = Q.front;
    while (p->next != NULL)
    {
    	p=p->next;
        cout<<p->data<<' ';
    }
}

//���
void InQueue(LinkQueue &Q,ElemType e)
{ 
    QNode *p;
    p=new QNode;
    p->data = e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
}

//����
void DeleQueue(LinkQueue &Q,ElemType &e) 
{
	QNode *p;
    if(Q.front->next = NULL) 
       cout<<"The Queue is empty";
    p=Q.front->next;
    e = p->data;
    Q.front->next =  p->next;
    if(Q.rear == p) 
        Q.rear = Q.front;
    delete p;
}

int main(void)
{
	LinkQueue Q;
	InitQueue(Q);
	int k;
	cout<<"Tip:"<<endl;
	cout<<"1-in;2-out;3-print;4-getfront"<<endl;
	cout<<"5-getrear;6-length;7-clear;8-exit"<<endl<<endl;
	do
	{
		cout<<"Enter your option:";
		cin>>k;
		switch(k)
		{
			case 1:
				{
					int e;
					cout<<"Enter elem:";
					cin>>e;
					InQueue(Q,e);
					cout<<endl;
					break;
				}
			case 2:
				{
					int e;
					DeleQueue(Q,e);
					cout<<"out elem is:"<<e;
					cout<<endl;
					break;
				}
			case 3:
				{
					cout<<"The Queue is:"<<endl;
					PrintQueue(Q);
					cout<<endl<<endl;
					break;
				}
			case 4:
				{
					cout<<"front of queue:"<<Q.front->next->data;
					cout<<endl<<endl;
					break;
				}
			case 5:
				{
					cout<<"rear of queue:"<<Q.rear->data;
					cout<<endl<<endl;
					break;
				}
			case 6:
				{
					int count;
					count=QueueLength(Q);
					cout<<"length of queue:"<<count;
					cout<<endl<<endl;
					break;
				}
			case 7:
				{
					Q.front=Q.rear;
					cout<<"OK"<<endl<<endl;
					break;
				}
			case 8:
				{
					DestroyQueue(Q);
					cout<<"OK"<<endl<<endl;
					break;
				}
			default:cout<<"wrong input";break;
			cout<<endl;	
		}
	}while(k!=8);
	return 0;
}
