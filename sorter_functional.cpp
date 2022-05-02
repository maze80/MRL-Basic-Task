#include <iostream>
#include <stdlib.h>
using namespace std;

//=====================
void printer(int *,int);
void swap(int *,int *);
int divider(int *,int,int);
void quick_sort(int *,int,int);
void merge_sort(int *,int,int);
void bubble_sort(int *,int);
void selection_sort(int *,int);
void insertion_sort(int *,int);
void merg_sort();
//=====================

int main(){
	int size,*array,tmp,number,random,method;
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
	cout<<"\nchoose a sort method or press 0 to exit : \n";
	cout<<"\n1:Quick sort\n2:Bubble sort\n3:Selection sort\n4:insertion sort\n5:Merge sort\n0:Exit\n\n";
	while(true){
		cin>>method;
		if(method==0 or method==1 or method==2 or method==3 or method==4 or method==5){
			break;
		}
			
		else{
			cout<<"\nchoose a sort method or press 0 to exit : \n";
			continue;
		}
	}
	switch(method){
		case 1 : {
			cout<<"\n\n=========== Quick sort ===========\n\n";
			int begin = 0 , end = size-1;
			quick_sort(array,begin,end);
			printer(array,size);
			cout<<"\n\n===================================\n\n";
			break;
		}
		case 2 : {
			cout<<"\n\n=========== Bubble sort ===========\n\n";
			bubble_sort(array,size);
			printer(array,size);
			cout<<"\n\n===================================\n\n";
			break;
		}
		case 3 : {
			cout<<"\n\n=========== Selection sort ===========\n\n";
			selection_sort(array,size);
			printer(array,size);
			cout<<"\n\n===================================\n\n";
			break;
		}
		case 4 : {
			cout<<"\n\n=========== Insertion sort ===========\n\n";
			insertion_sort(array,size);
			printer(array,size);
			cout<<"\n\n===================================\n\n";
			break;
		}
		case 5 : {
			cout<<"\n\n=========== Insertion sort ===========\n\n";
			int begin = 0 , end = size-1;
			merge_sort(array,begin,end);
			printer(array,size);
			cout<<"\n\n===================================\n\n";
			break;
		}
	}
	
	
	
	return 0;
}
//==============================
void printer(int *array,int size){
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
//====================================
void swap(int *min_array, int *array) { 
    int tmp = *min_array; 
    *min_array = *array; 
    *array = tmp; 
} 
//======================================
int divider(int *array,int begin,int end){
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
void quick_sort(int *array,int begin,int end){
    if(begin >= end)
        return;
    int anchorpoint=divider(array,begin,end);
    quick_sort(array,begin,anchorpoint-1);
    quick_sort(array,anchorpoint+1,end);
}
//==============================
void bubble_sort(int *array,int size){
	int tmp;
	for(int i=0;i<size-1;i++)
		for(int j=0;j<size-1;j++)
			if(array[j]>array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
}
//==============================
void selection_sort(int *array,int size){
	for(int i=0;i<size;i++){
		int index = i;
		for(int j=i+1;j<size;j++)
			if(array[j]<array[index])
			index = j;
		swap(&array[index], &array[i]);
	}
}
//==============================
void insertion_sort(int *array,int size){
    for (int i = 1; i < size; i++){
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > tmp){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = tmp;
    }
}
//==============================
void merger(int *array, int left_side, int middle, int right_side){
  
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
void merge_sort(int *array, int begin, int end) {
  if (begin < end) {
    int middle = begin + (end - begin) / 2;

    merge_sort(array, begin, middle);
    merge_sort(array, middle + 1, end);
    merger(array, begin, middle, end);
  }
}
//===================================
