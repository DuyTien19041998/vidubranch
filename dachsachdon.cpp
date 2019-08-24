#include<iostream>
#include<conio.h>
using namespace std;
struct NUT
{
	int data;
	NUT*link;
};
typedef NUT* tro;

void first_Insert (int x, tro &first){ // chan dau
// ham bo sung mot NUT chua gia tri x vao dau danh sach
	tro p = new(NUT);
	p->data = x;
	p->link =first;//1
	first =p;//2
}
void last_Insert (int x, tro &first){ // chan dau
// ham bo sung mot NUT chua gia tri x vao dau danh sach
	tro p = new(NUT);
	p->data = x;
	p->link = NULL;
	if(first == NULL) first =p;
	else
	{
		tro q= first;
		while ( q->link) q=q->link;
		q->link =p;
	}
}
void NhapDS(tro &first){
	first =NULL;
	char ch;
	int x;
	do{
		cout<<endl<<" nhap x ="; cin>>x;
		 last_Insert ( x, first);// last or first
		 cout<<" nhap <ESC> de ket thuc nhap!";
		 ch = getch();
	}
	while (ch!=27);
}
void Xem( tro &first)
{
	tro p = first;
	cout<<endl;
	while(p){
		cout<<p->data<<"  ";
		p=p->link;
	}
}
int Sum( tro first)// tinh tong
{
	int s=0;
	tro p = first;
	while(p!=NULL){
		s+=p->data;
		p=p->link;
	}
	return s;
}

int SumDeQuy( tro first)
{
	if( first ==NULL) return 0;
	else return first->data + SumDeQuy(first->link);
}

void Sort( tro &first)
{
	/* for(i=1; i<n;i++)
	for(j=i+1;j<n;j++)
	if(a[i] >a[j]) swap(a[i],a[j]);
	*/
	tro p = first, q;
	while(p){
		q = p->link;
		while(q){
			if(p->data > q->data) swap (p->data , q->data);
			q=q->link;
		}
		p=p->link;
	}
}

void Insert(int x, tro q, tro &first)
{
	tro p = new(NUT);
	p->data = x;
	p->link = q->link;
	q->link =p;
}

void first_del(tro &first)
{
	tro p = first;
	first = p->link;
	delete(p);
}
//void last_del( tro &first)
//{
//	tro p =first,q;
//	if(first->link==NUll) first= NULL; 
//	else 
//	{
//		//b1: dinh vi p den cuoi dnah sach 
//		// 		q : dung truoc p
//		while(p->link)
//		 {
//		 	q =p;
//		 	p=p->link;
//		 }
//		 // b2: cat nut p khoa danh sach
//		 q->link=NULL;
//	} 
//	// xoa p
//	delete(p); 
//}
void del(tro q, tro &first)
{
	// xoa nut dung sau nuts q
	//b	 : dinh vi den nut can xoa p
	tro p = q->link;
	// b2: tach p khoa danh sach
	q->link = p ->link;
	//b3: xoa
	delete(p);
}
int main(){
	 tro first;
	 NhapDS(first);
	 Xem(first);
//	 cout<<endl<<" tong ="<<Sum(first);
//	 cout<<endl<<" tong de quy ="<<SumDeQuy(first);
//	 Sort(first);
//	 Xem(first);
//	tro q = first->link->link;
//	 Insert(1000,q,first);//q =first->link
//	 Xem(first);
//	 first_del(first);	
//	  Xem(first);
//	last_del(first);	
//	Xem(first);
    del(first->link,first);
    Xem(first);
	return 0;
}
