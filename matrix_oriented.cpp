#include <iostream>
using namespace std;

class matrix{
	private:
		float **mat,**tmp,determinant;
		int size;
	public:
		void init();
		void printer(int);
		void generate_tmp();
		void delete_tmp();
		void operator +(const matrix &);
		void operator -(const matrix &);
		void operator *(const matrix &);
		void diag();
		void inverse2();
		void inverse3();
};
//===========================
void matrix :: init(){
	int random,number;
	cout<<"Enter the size of matrix row & column : ";cin>>size;cout<<endl;
	
	mat = new float*[size];
	for(int i = 0; i < size; i++)
	    mat[i] = new float[size];	  

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<"Matrix1 "<<"["<<i<<"]"<<"["<<j<<"] : ";cin>>number;
			mat[i][j] = number;
		}
	}
	cout<<endl;
}
//=================================
void matrix :: generate_tmp(){
	tmp = new float*[size];
	for(int i = 0; i < size; i++)
	    tmp[i] = new float[size];	
}
//=================================
void matrix :: delete_tmp(){
	delete []tmp;
}
//=================================
void matrix :: printer(int number){
	if(number==1){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++)
				cout<<"  "<<mat[i][j]<<" ";		
			cout<<endl;
		}
	}
	else{
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++)
				cout<<"  "<<tmp[i][j]<<" ";		
			cout<<endl;
		}
	}
	
}
//=================================
void matrix :: operator +(const matrix &mat2){

	generate_tmp();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			tmp[i][j] = mat[i][j] + mat2.mat[i][j];		
		}
	}	
	printer(0);
	delete_tmp();
}
//=================================
void matrix :: operator -(const matrix &mat2){
	
	generate_tmp();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			tmp[i][j] = mat[i][j] - mat2.mat[i][j];		
		}
	}	
	printer(0);
	delete_tmp();
}
//=================================
void matrix :: operator *(const matrix &mat2){
	
	generate_tmp();
	for(int i = 0; i < size; i++){
    	for( int j = 0; j < size; j++){
    		tmp[i][j]=0;
        	for(int z = 0; z < size; z++)
            	tmp[i][j] += mat[i][z] * mat2.mat[z][j];
    	}
	}
	printer(0);
	delete_tmp();	
}
//===============================
void matrix :: diag (){
	if(size==3)
		inverse3();
	else if(size==2)
		inverse2();
	else cout<<"\nThe matrix is out of range to reverse !!\n";
}
//===============================
void matrix :: inverse3 (){
	generate_tmp();
	// matrix kehad :
	tmp[0][0] = (mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2]);
	tmp[1][0] = (mat[0][1]*mat[2][2])-(mat[2][1]*mat[0][2]);
	tmp[2][0] = (mat[0][1]*mat[1][2])-(mat[1][1]*mat[0][2]);
	tmp[0][1] = (mat[1][0]*mat[2][2])-(mat[2][0]*mat[1][2]);
	tmp[1][1] = (mat[0][0]*mat[2][2])-(mat[2][0]*mat[0][2]);
	tmp[2][1] = (mat[0][0]*mat[1][2])-(mat[1][0]*mat[0][2]);
	tmp[0][2] = (mat[1][0]*mat[2][1])-(mat[2][0]*mat[1][1]);
	tmp[1][2] = (mat[0][0]*mat[2][1])-(mat[2][0]*mat[0][1]);
	tmp[2][2] = (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]);
	
	//matrix hamsaz :
	tmp[0][1] *= -1;
	tmp[1][0] *= -1;
	tmp[1][2] *= -1;
	tmp[2][1] *= -1;

	// matrix elhaghi :

	int tmp2;		

	tmp2 = tmp[0][1];
	tmp[0][1] = tmp[1][0];
	tmp[1][0] = tmp2;
	
	tmp2 = tmp[0][2];
	tmp[0][2] = tmp[2][0];
	tmp[2][0] = tmp2;
	
	tmp2 = tmp[1][2];
	tmp[1][2] = tmp[2][1];
	tmp[2][1] = tmp2;

	// Determinant matrix base :

	determinant = (
	(mat[0][0]*(mat[1][1]*mat[2][2] - mat[2][1]*mat[1][2]))-
	(mat[0][1]*(mat[1][0]*mat[2][2] - mat[1][2]*mat[2][0]))+
	(mat[0][2]*(mat[1][0]*mat[2][1] - mat[2][0]*mat[1][1]))
	);
	
	// matrix reverse :
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			tmp[i][j] *= (1/determinant);
		}
		
	printer(0);
	delete []tmp;
}
//===============================
void matrix :: inverse2(){
	generate_tmp();
	// creating matrix with specific formula:
	tmp[0][0] = mat[1][1];
	tmp[0][1] = -mat[0][1];
	tmp[1][0] = -mat[1][0];
	tmp[1][1] = mat[0][0];

	//determinant basic matrix
	determinant = ((mat[0][0]*mat[1][1])-(mat[0][1]*mat[1][0]));

	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++){
			tmp[i][j] *= (1/determinant);
		}
			
	printer(0);
	//delete []tmp;
}
//===============================
int main(){
	matrix matrix1,matrix2;
	int method;
	cout<<".:: Initializing a mount for 2 matrix ::.\n\n";
	
	matrix1.init();
	matrix1.printer(1);
	cout<<endl;
	matrix2.init();
	matrix2.printer(1);
	
	cout<<"\n=====================================\n";
	while(true){
		cout<<"\nchoose a method or press 0 to exit : \n";
		cout<<"\n1 = matrix (+)\n";
		cout<<"\n2 = matrix (-)\n";
		cout<<"\n3 = matrix (*)\n";
		cout<<"\n4 = matrix inverser\n";
		cout<<"\n0 = Exit\n";
		cin>>method;
		if(method==0)
			return 0;
		else{
			switch(method){
					case 1 : {
						cout<<"\n=========== Matrix1 + Matrix 2 ============\n\n";
						matrix1 + matrix2;
						cout<<"\n==========================================\n\n";
						break;
					}
					case 2 : {
						cout<<"\n=========== Matrix1 - Matrix 2 ============\n\n";
						matrix1 - matrix2;
						cout<<"\n==========================================\n\n";
						break;
					}
					case 3 : {
						cout<<"\n=========== Matrix1 * Matrix 2 ============\n\n";
						matrix1 * matrix2;
						cout<<"\n==========================================\n\n";
						break;
					}
					case 4 : {
						cout<<"\n============ Matrix Inversed =============\n\n";
						matrix1.diag();
						cout<<endl;
						matrix2.diag();
						cout<<"\n==========================================\n\n";
						break;
					}
					default : break;
				}
			}
		}
		
}
