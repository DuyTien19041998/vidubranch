#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<" nhap n :";
	cin>>n;
	int dem =0;
	while( n>0){
		n=n/10;
		dem++;
	}
	cout<<" so chu so cua n :"<<dem<<endl;
	return 0;

}

