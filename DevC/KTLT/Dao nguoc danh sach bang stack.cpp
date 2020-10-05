#include <stdio.h>
#include <conio.h>
#include <stack>
using namespace std;

//  Khai bao cau truc du lieu danh sach lien ket cac so nguyen

struct Node
{
	int data;
	struct Node*next;
};
typedef struct Node node;

struct List
{
	node*Head;
	node*Tail;
};
typedef struct List list;

//  Khoi tao
void Init(list &l)
{
	l.Head = l.Tail = NULL;
}

// 3. Tao node 
node*GetNode(int x) 		// x la du lieu dua vao data
{
	node*p = new node;

	if(p == NULL)
	{
		return NULL;
	}
	p->data = x; 
	p ->next = NULL; 
	return p;
}


void AddHead(list &l,node *p) 		// them dau`
{
	if(l.Head == NULL) 
	{
		l.Head = l.Tail = p;
	}
	else
	{
		p->next = l.Head; 
		l.Head = p; 
	}
}

void AddTail(list &l,node *p) 		//them cuoi
{
	if(l.Head == NULL) 
	{
		l.Head = l.Tail = p;
	}
	else
	{
		l.Tail->next = p; 
		l.Tail = p;
	}
}

void Sort(list &l)
{	
	for(node *p = l.Head; p != l.Tail; p = p ->next)
	{
		for(node *q = p ->next; q != NULL; q = q ->next)
		{
			if(p->data > q->data)
			{
				int temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

void InPut(list &l, int n)
{	
	printf("nhap n:	");scanf("%d",&n);
	Init(l); 
	for(int i = 1; i <= n; i++)
	{
		int x;
		printf("\nnhap data: ");scanf("%d", &x);

		node*p = GetNode(x); 
		AddTail(l, p); 
	}	
}

void OutPut(list l)
{	printf("\n");
	for(node *p = l.Head; p != NULL; p = p->next)
	{
		printf("%d\t",p->data);
	}
}

void DaoDSbangStack(list &l){
	node*p =l.Head;
	stack<node*> sta;
	while(p!=NULL)
	{
		sta.push(p);
		p=p->next;
	}
	node*t=sta.top();
	l.Head=t;
	sta.pop();
	while(!sta.empty())
	{
	t->next=sta.top();
	t=t->next;
	sta.pop();
	}
	t->next=NULL;
}

int main(){
	int n,x;
	list l;
	InPut(l,n);
	OutPut(l);
	DaoDSbangStack(l);
	OutPut(l);
}