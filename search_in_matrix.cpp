/*
in each function (direction and random) , to being sure if the function
is truly working , you trun on the flags info inside the functions.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//=========================
void init(int **,int);
void print(int **,int);
int random(int);
double calculator_dir(int **,int);
double calculator_rand(int **,int);
//=========================

int main(){
	int **matrix1,constant,range;
	cout<<"Enter a constant number for row & column : ";cin>>constant;
	cout<<"Enter repetition number : ";cin>>range;
	//outspread array
	matrix1 = new int*[constant];
	for(int i = 0; i < constant; ++i)
	    matrix1[i] = new int[constant];
	//====================
	double sum_dir=0,sum_rand=0;
	cout<<"\nprocessing ...\n\n";
	for(int i=1;i<=range;i++){
		init(matrix1,constant);
		sum_dir += calculator_dir(matrix1,constant);
	}
	//cout<<"\n---------------------\n";
	for(int i=1;i<=range;i++){
		init(matrix1,constant);
		sum_rand += calculator_rand(matrix1,constant);	
	}
	print(matrix1,constant);
	cout<<"Total tome of direction search in range "<<range<<" is : "<<sum_dir<<" sec";
	cout<<"\nThe average of direction search in range "<<range<<" is : "<<sum_dir/range<<" sec";
	cout<<"\n\nTotal tome of random search in range "<<range<<" is : "<<sum_rand<<" sec";
	cout<<"\nThe average of random search in range "<<range<<" is : "<<sum_rand/range<<" sec";
	cout<<"\n\n =============== Reasilt ==============\n\n";
	if((sum_dir/range)<(sum_rand/range))
		cout<<"In this try, Direction search was faster !!";
	else cout<<"In this try, Random search was faster !!";
	
   	return 0;
}
//=============================
int random(int constant){
	int random;
	random = rand() % constant + 0;
	
	return random;
}
//============================
void init(int** mat,int constant){
	
  	int x = random(constant);
  	int y = random(constant);
	for(int i=0;i<constant;i++){
		for(int j=0;j<constant;j++){
			mat[i][j]=0;
			if(i==x && j==y){
				mat[i][j]=1;
			}
		}
	}	
		
}
//=============================

void print(int** mat,int constant){
	int x,y;
	cout<<"\n\n======= Last matrix in range ========\n\n";
	cout<<"The matrix is : "<<constant<<"*"<<constant<<endl<<endl;
	if(constant<=40){
	for(int i=0;i<constant;i++){
		for(int j=0;j<constant;j++){
			cout<<mat[i][j]<<" ";
		}                      
			
		cout<<endl;
	}
}
	else{
		cout<<"\n Too much for printing ...\n";
}

	cout<<"\n===============================\n\n";	
}
//=================================
double calculator_rand(int **mat,int constant){

	int x,y,x_again,y_again,flag; 
	
	clock_t t;
	t = clock();
	while(true){	
	x = random(constant);
	y = random(constant);
				
	if(mat[x][y]==1){
			flag =1;
			break;					
		}
	else continue;
}
	
   	t = clock() - t;
   	double time = ((double)t)/CLOCKS_PER_SEC;
   	
	/*if(flag == 1)
		cout<<"Random finding status : True\n";
	else 
		cout<<"Random finding status : False\n";*/	   	
   	return time;
}
//=================================
double calculator_dir(int **mat,int constant){
	int flag=0;
	clock_t t;
	t = clock();
	
	for(int i=0;i<constant;i++){
		for(int j=0;j<constant;j++){
			if(mat[i][j]==1){
				flag=1;
				break;
			}
		}
	}			
   	t = clock() - t;
   	double time = ((double)t)/CLOCKS_PER_SEC;
   	
	/*if(flag == 1)
		cout<<"Direct finding status : True\n";
	else 
		cout<<"Direct finding status : False\n";*/ 	
   	
   	return time;
}
