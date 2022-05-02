#include <iostream>
#include <stdlib.h>
using namespace std;
//====================
class sorter{
	public:
		int index,tmp,*array,size;
	public:
		void initialize();
		void printer();
		void bubble_sort();
		void selection_sort();
		void insertion_sort();
		void quick_sort(int *,int,int);	
		int divider(int *,int,int);	
		void merge_sort(int *,int,int);
		void merger(int *,int,int,int);
		void swap(int *,int *);
		sorter();
		sorter(int,int,int *,int);
		sorter(const sorter &);
		~sorter();
};
//================================
void sorter :: initialize(){
	int number,random;
	cout<<"Enter the size of array : ";cin>>size;
	cout<<"Enter the range of numbers : ";cin>>number;
	array = new int[size];

	for(int i=0;i<size;i++){
		random = rand() % number + 0;
		array[i] = random;
	}
	cout<<"\n=========== Random Array ===========\n\n";
	for(int i=0;i<size;i++) cout<<array[i]<<" ";
	cout<<"\n\n====================================\n";
}
//==============================
void sorter :: printer(){
	int status;
	cout<<"1:ascending sort\n2:decending sort\n";cin>>status;cout<<endl;
	switch(status){
		case 1:{
			for(int i=0 ;i<size;i++)
				cout<<array[i]<<"  ";
			break;
		}
		case 2 : {
			for(int j=size-1 ;j>=0;j--)
				cout<<array[j]<<"  ";
			break;
		}
		default : cout<<"wrong key ...";
	}

}
//==============================



//======================================
int sorter :: divider(int *array,int begin,int end){
    int anchorpoint=begin;
    int anchor=array[end];
    for(int i=begin;i<end;i++)
    {
        if(array[i]<anchor)
        {
            swap(&array[anchorpoint],&array[i]);
            anchorpoint++;
        }
    }
    swap(&array[anchorpoint],&array[end]);
    return anchorpoint;
}
//=============================
void sorter :: quick_sort(int *array,int begin,int end){
    if(begin >= end)
        return;
    int anchorpoint=divider(array,begin,end);
    quick_sort(array,begin,anchorpoint-1);
    quick_sort(array,anchorpoint+1,end);
}

//==============================
void sorter :: merger(int *array, int left_side, int middle, int right_side){
  
  int n1 = middle - left_side + 1;
  int n2 = right_side - middle;

  int left_array[n1], right_array[n2];

  for (int i = 0; i < n1; i++)
    left_array[i] = array[left_side + i];
  for (int j = 0; j < n2; j++)
    right_array[j] = array[middle + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = left_side;

  while (i < n1 && j < n2) {
    if (left_array[i] <= right_array[j]) {
      array[k] = left_array[i];
      i++;
    } else {
      array[k] = right_array[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = left_array[i];
    i++;
    k++;
  }
  while (j < n2) {
    array[k] = right_array[j];
    j++;
    k++;
  }
}
//===================================
void sorter :: merge_sort(int *array, int begin, int end) {
  if (begin < end) {
    int middle = begin + (end - begin) / 2;

    merge_sort(array, begin, middle);
    merge_sort(array, middle + 1, end);
    merger(array, begin, middle, end);
  }
}
//===================================
void sorter :: bubble_sort(){
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1;j++)
			if(array[j]>array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}
//====================================
void sorter :: swap(int *min_array, int *array) { 
    tmp = *min_array; 
    *min_array = *array; 
    *array = tmp; 
} 
//===================================
void sorter :: selection_sort(){
	for(int i=0;i<size;i++){
		index = i;
		for(int j=i+1;j<size;j++)
			if(array[j]<array[index])
			index = j;
		swap(&array[index], &array[i]);
	}
}
//=======================================
void sorter :: insertion_sort(){
    for (int i = 1; i < size; i++){
        tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }
}
//=============================
sorter :: sorter(){
	index = 0;
	tmp = 0;
	array = 0;
	size = 0;
}
sorter :: sorter(int inx,int tp,int *arr,int sz){
	index = inx;
	tmp = tp;
	array = arr;
	size = sz;
}
sorter :: sorter(const sorter &sample){
	index = sample.index;
	tmp = sample.tmp;
	array = sample.array;
	size = sample.size;
}
sorter :: ~sorter(){};
//=========================

main(){

	sorter sample;
	sample.initialize();
	int p_number;
	cout<<"\nchoose one parameter : \n";
	while(true){
		cout<<"\n1 = Bublle sort\n";
		cout<<"\n2 = Selection sort\n";
		cout<<"\n3 = Insertion sort\n";
		cout<<"\n4 = Quick sort\n";
		cout<<"\n5 = Merge sort\n\n";
		cin>>p_number;
		if(p_number==1 || p_number==2 || p_number==3 || p_number==4 || p_number==5) break;
		else {cout<<"\nTry another number !!\n";continue;}
	}
	
	if(p_number == 1){
		cout<<"\n========== Bublle sort ==========\n";
		sample.bubble_sort();
	}
	else if(p_number == 2){
		cout<<"\n========== Selection sort ==========\n";
		sample.selection_sort();
	}
	else if(p_number == 3){
		cout<<"\n========== Insertion sort ==========\n";
		sample.insertion_sort();
	}
	else if(p_number == 4){
		cout<<"\n========== Quick sort ==========\n";
		sample.quick_sort(sample.array,0,sample.size-1);		
	}
	else{
		cout<<"\n========== Merge sort ==========\n";
		sample.merge_sort(sample.array,0,sample.size-1);		
	}

	sample.printer();
		
	return 0;
}