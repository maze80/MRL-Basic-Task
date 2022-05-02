#include <iostream>
using namespace std;

void finder (int [],int,int);
void sorter (int [],int);

int main(){
	
	const int size = 10;
	int a[size]={4,25,40,8,66,5,3,1,7,10};
	int key;
	cout<<"Enter key value : ";
	cin>>key;
	
	sorter(a,size);
	for(int i=0;i<size;i++)
	cout<<"a["<<i<<"] = "<<a[i]<<endl;
	cout<<"=============================="<<endl;
	
	finder(a,size,key);
	return 0;
}

void sorter(int a[],int size){
	int arrey;
	for(int j=0;j<size-1;j++){
		for(int i=0;i<size-1;i++){
		if(a[i]>a[i+1]){
		arrey=a[i];
		a[i]=a[1+i];
		a[i+1]=arrey;
			}
		}
	}
}

void finder(int a[],int size,int key){
	
	int range=size/2;
		
		if(key>a[range]){
			for(int j=range;j<size;j++){
				if(key==a[j])
				cout<<"key "<<key<<" is : "<<"a["<<j<<"]"<<endl;
				continue;
				}
			}
		if(key<a[range]){
			for(int i=range;i>=0;i--){
				if(key==a[i])
				cout<<"key "<<key<<" is : "<<"a["<<i<<"]"<<endl;
				continue;
			}
		}
		else if(key==a[range]){
		cout<<"key "<<key<<" is : "<<"a["<<range<<"]";
	}
}
