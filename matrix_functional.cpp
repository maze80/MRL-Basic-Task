#include <iostream>
#include <cmath>
using namespace std;
//========================
void init(float **);
void print(float **);
void sum();
void decrement();
void force();
int diag();
void reverser3(float **);
void reverser2(float **);
//========================
float **mat1,**mat2,**mat3,**mat4,determinant;
int row,column,tmp;
//========================
int main(){

	cout<<".:: Initializing a mount for 2 matrix ::.\n\n";
	cout<<"Enter matrix row : ";cin>>row;
	cout<<"Enter matrix column : ";cin>>column;cout<<endl;
	//=============================
	mat1 = new float*[row];
	for(int i = 0; i < 3; ++i)
	    mat1[i] = new float[column];

	mat2 = new float*[row];
	for(int i = 0; i < 3; ++i)
	    mat2[i] = new float[column];

	mat3 = new float*[row];
	for(int i = 0; i < 3; ++i)
	    mat3[i] = new float[column];

	mat4 = new float*[row];
	for(int i = 0; i < 3; ++i)
	    mat4[i] = new float[column];
	//==============================		
	init(mat1);cout<<"\n\n";init(mat2);
	cout<<"\n\n============ Basic Matrix ============\n\n";
	print(mat1);cout<<"\n\n";print(mat2);
	cout<<"\n======================================\n";
	  
	int method;
	cout<<"\nchoose one method : \n";
	while(true){
		cout<<"\n1 = matrix (+)\n";
		cout<<"\n2 = matrix (-)\n";
		cout<<"\n3 = matrix (*)\n";
		cout<<"\n4 = matrix reverser\n";
		cout<<"\n0 = Exit\n\n";
		cin>>method;
		if(method == 1){
			sum();
			cout<<"\n\n======== Matrix1 + Matrix2 ==========\n\n";
			print(mat3);
			cout<<"\n====================================\n\n";
			continue;
		}
		
		else if(method == 2){
			decrement();
			cout<<"\n\n======== Matrix1 - Matrix2 ==========\n\n";
			print(mat3);
			cout<<"\n====================================\n\n";
			continue;		
		}	
		else if(method == 3){
			force();
			cout<<"\n\n======== Matrix1 * Matrix2 ==========\n\n";
			print(mat3);
			cout<<"\n====================================\n\n";
			continue;
		}
		else if(method == 4){
			int status = diag();
			if(status == 3){
				cout<<"\n\n============ Reversed Matrix 3*3 =============\n\n";
				reverser3(mat1);
				print(mat3);
				cout<<endl;
				reverser3(mat2);
				print(mat3);
				cout<<"\n====================================\n\n";
				continue;
			}
			else if(status == 2){
				cout<<"\n\n============ Reversed Matrix 2*2 =============\n\n";
				reverser2(mat1);
				print(mat3);
				cout<<endl;
				reverser2(mat2);
				print(mat3);	
				cout<<"\n====================================\n\n";
				continue;		
			}
			else{
				cout<<"Matrix are out of Range to reversing !!";
				cout<<"\n====================================\n\n";
				continue;
			}
	}
	else if(method == 0){
		break;
		return 0;
	}	
	else {
		cout<<"\nTry another key or press 0 to exit !!\n";continue;
	}
	}
		
}
//==============================
void init(float **mat){
	int number;
		for(int i=0;i<row;i++){
			for(int j=0;j<column;j++){
			cout<<"Matrix "<<"["<<i<<"]"<<"["<<j<<"] : ";cin>>number;
			mat[i][j] = number;
		}
	}
}
//==============================
void print(float **mat){
	
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat[i][j]<<" ";		
		cout<<endl;
	}
}
//==============================
void sum(){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			mat3[i][j] = mat1[i][j]+mat2[i][j];			
	}
}
//==============================
void decrement(){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			mat3[i][j] = mat1[i][j]-mat2[i][j];			
	}	
}
//==============================
void force(){
	for(int i = 0; i < row; i++){
    	for( int j = 0; j < column; j++){
        	for(int z = 0; z < row; z++)
            	mat3[i][j] += mat1[i][z] * mat2[z][j];
    	}
	}
}
//===================================
void reverser3(float **mat){
	// matrix kehad :
	mat3[0][0] = (mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2]);
	mat3[1][0] = (mat[0][1]*mat[2][2])-(mat[2][1]*mat[0][2]);
	mat3[2][0] = (mat[0][1]*mat[1][2])-(mat[1][1]*mat[0][2]);
	mat3[0][1] = (mat[1][0]*mat[2][2])-(mat[2][0]*mat[1][2]);
	mat3[1][1] = (mat[0][0]*mat[2][2])-(mat[2][0]*mat[0][2]);
	mat3[2][1] = (mat[0][0]*mat[1][2])-(mat[1][0]*mat[0][2]);
	mat3[0][2] = (mat[1][0]*mat[2][1])-(mat[2][0]*mat[1][1]);
	mat3[1][2] = (mat[0][0]*mat[2][1])-(mat[2][0]*mat[0][1]);
	mat3[2][2] = (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]);
	//matrix hamsaz :
	mat3[0][1] *= -1;
	mat3[1][0] *= -1;
	mat3[1][2] *= -1;
	mat3[2][1] *= -1;
	// matrix elhaghi :
	tmp = mat3[0][1];
	mat3[0][1] = mat3[1][0];
	mat3[1][0] = tmp;
	
	tmp = mat3[0][2];
	mat3[0][2] = mat3[2][0];
	mat3[2][0] = tmp;
	
	tmp = mat3[1][2];
	mat3[1][2] = mat3[2][1];
	mat3[2][1] = tmp;
	// Determinant matrix base :
	determinant = (
	(mat[0][0]*(mat[1][1]*mat1[2][2] - mat[2][1]*mat[1][2]))-
	(mat[0][1]*(mat[1][0]*mat1[2][2] - mat[1][2]*mat[2][0]))+
	(mat[0][2]*(mat[1][0]*mat1[2][1] - mat[2][0]*mat[1][1]))
	);
	// matrix reverse :
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat3[i][j] *= (1/determinant);
		}
}
//===============================
void reverser2(float **mat){
	// creating matrix with specific formula:
	mat3[0][0] = mat[1][1];
	mat3[0][1] = -mat[0][1];
	mat3[1][0] = -mat[1][0];
	mat3[1][1] = mat[0][0];

	//determinant basic matrix
	determinant = ((mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]));

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat3[i][j] *= (1/determinant);
		}	
}
//==================================
int diag(){
	if(row == 3 && column == 3){
		return 3;
	}		
	else if(row == 2 && column == 2){
		return 2;
	}
	
	else{
		return 0;
	} 
}
//===============================