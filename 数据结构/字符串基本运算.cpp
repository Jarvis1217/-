#include<iostream>
#include<string.h>
using	namespace	std;

#define	OK	1
#define	ERROR	0
#define	MAXSIZE	255
#define	OVERFLOW	-2

typedef	int		Status;
typedef	char	HElemType;

typedef	struct{
	char	*ch;
	int	length;
}HString;

Status	InitString(HString	&S);
Status	GetSon(HString	S,int	e,int	f);
Status	Delete(HString	&S,int	h,int	i);
Status	StrAssign(HString	&S,char	*chars);
Status	Change(HString	&S1,HString	S2,int	a,int	b); 
Status	BF(HString	S,HString	T,int	pos);

int	main()
{
	HString	S;
	InitString(S); 
	int	z;
	do{
		cout<<endl;
		cout<<"�ַ���������"<<endl;
		cout<<"1-�Ƚ� 2-���� 3-ȡ�ִ� 4-ɾ�� 5-�滻 6-BFģʽƥ�� 7-�˳�"<<endl;
		cout<<"��ѡ���ܣ�";
		cin>>z;
		switch(z){
			case	1:
				HString	S5,S6;
				char	a[100],b[200]; 
				cout<<"�������һ���ַ�����"<<endl;
				scanf("%s",a);
				StrAssign(S5,a);
				cout<<"������ڶ����ַ�����"<<endl;
				scanf("%s",b);
				StrAssign(S6,b);
				if(strcmp(S5.ch,S6.ch)==0)
					cout<<S5.ch<<"��"<<S6.ch<<"����ȵģ�"<<endl;
				else	cout<<S5.ch<<"��"<<S6.ch<<"������ȵģ�"<<endl;
				break;
			case	2:
				HString	S7,S8;
				char	c[100],d[200]; 
				cout<<"�������һ���ַ�����"<<endl;
				scanf("%s",c);
				StrAssign(S7,c);
				cout<<"������ڶ����ַ�����"<<endl;
				scanf("%s",d);
				StrAssign(S8,d);
				cout<<S7.ch<<"��"<<S8.ch<<"���Ӻ�Ľ��Ϊ��";
				strcat(S7.ch,S8.ch);
				cout<<S7.ch<<endl;
				break;
			case	3:
				HString	S1;
				char	e[100];
				cout<<"����������"<<endl;
				scanf("%s",e);
				StrAssign(S1,e);
				cout<<"������Ҫȡ�Ӵ�����ʼλ�ú�:"<<endl;
				int	g,f;
				cin>>g;
				cout<<"������Ҫȡ�Ӵ��ĳ��ȣ�"<<endl;
				cin>>f;
				GetSon(S1,g,f);
				break;
			case	4:
				HString	S2;
				char	p[100];
				cout<<"����������"<<endl;
				scanf("%s",p);
				StrAssign(S2,p);
				cout<<"������Ҫɾ���Ӵ�����ʼλ�ú�:"<<endl;
				int	h,i;
				cin>>h;
				cout<<"������Ҫɾ���Ӵ��ĳ��ȣ�"<<endl;
				cin>>i;
				cout<<"ɾ��"<<S2.ch<<"�ĵ�"<<h<<"���ַ���ʼ����Ϊ"<<i<<"���Ӵ�����Ϊ��";
				Delete(S2,h,i);
				cout<<S2.ch;
				break;
			case	5:
				HString	S3,S4;
				char	q[100];
				int	v,zx;
				cout<<"����������"<<endl;
				scanf("%s",q);
				StrAssign(S3,q);
				cout<<"�������滻����"<<endl;
				char	t[100];
				scanf("%s",t);
				StrAssign(S4,t);
				cout<<"������Ҫ�滻���Ӵ�����ʼλ�úţ�";
				cin>>v;
				cout<<"������Ҫ�滻���Ӵ��ĳ��ȣ�";
				cin>>zx;
				cout<<"��"<<S3.ch<<"�ĵ�"<<v<<"���ַ���ʼ����Ϊ"<<zx<<"���Ӵ���"<<S4.ch<<"�滻��Ľ��Ϊ��"; 
				Change(S3,S4,v,zx);
				cout<<S3.ch;
				cout<<endl;
				break;
			case	6:
				HString	SS,RR;
				int	wz;
				char	QQ[100],rr[100];
				cout<<"����������"<<endl;
				scanf("%s",QQ);
				StrAssign(SS,QQ);
				cout<<"������ģʽ��:"<<endl;
				scanf("%s",rr);
				StrAssign(RR,rr);
				cout<<"��������������ʼƥ��λ�úţ�"<<endl;
				cin>>wz;
				int	gg=BF(SS,RR,wz);
				if(gg!=0)	cout<<RR.ch<<"��"<<SS.ch<<"�ĵ�"<<gg<<"���ַ���ƥ��ɹ�"<<endl;
				else	cout<<"ƥ�䲻�ɹ�"<<endl;
				break;
			
		}
	}while(z!=7);
	return	0;
}
Status	InitString(HString	&S){
	S.ch=new	HElemType[MAXSIZE];
	if(!S.ch)	return	OVERFLOW;
	S.length=0;
	return	OK;
}
Status	GetSon(HString	S,int	e,int	f){
	HString	Q;
	Q.ch=new	char[f];
	int	j=0;
	for(int	i=e-1;i<e-1+f;i++){
		Q.ch[j++]=S.ch[i];
	}
	Q.ch[j]='\0';
	cout<<"��"<<S.ch<<"�ĵ�"<<e<<"���ַ���ʼ����Ϊ"<<f<<"���Ӵ�����Ϊ"<<Q.ch<<endl;
	return	OK;
}
Status	Delete(HString	&S,int	h,int	i){
	int	j;
	int	k=h-1;
	for(j=0;j<i;j++)
	{
		S.ch[k]=S.ch[k+i];
		S.length--;
		k++;
	}
	S.ch[S.length+1]='\0';
	return	OK;
	
}
Status	StrAssign(HString	&S,char	*chars)
{
	int	len,j;
	len=strlen(chars);
	if(!len){
		S.ch=NULL;
		S.length=0;
	}
	else{
		S.ch=new	char[len+1];
		if(!S.ch)	return	OVERFLOW;
		for(j=0;j<len;j++)
			S.ch[j]=chars[j];
			S.length=len;
			S.ch[len]='\0';
	}
	return	OK;
}
Status	Change(HString	&S1,HString	S2,int	a,int	b){
	--b;
	int	i=0,j=b;
	for(;S1.ch[j]!='\0';++j)
	{
		if(S2.ch[i]!='\0')
		{
			S1.ch[j]=S2.ch[i];
			++i;
		}
		else
		{
			break;
		}
	}
	return	OK;
}
Status	BF(HString	S,HString	T,int	pos)
{
	int	i=pos-1,j=0;
	while(i<S.length&&j<T.length){
		if(S.ch[i]==T.ch[j]){
			++i;
			++j;
		}
		else	{
			i=i-j+1;
			j=0;
		}
	}
	if(j==T.length)	return	i-T.length+1;
	else	return	0;
}
