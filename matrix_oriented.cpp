#include <iostream>
using namespace std;

class matrix{
	private:
		int **mat1,**mat2,**mat3,**mat9,row,column,tmp;
		float determinant1,determinant2,mat4[3][3],mat5[3][3];
		float determinant3,determinant4,mat7[2][2],mat6[2][2];
	public:
		void initialize();
		void printer();
		void set();
		void inverse2();
		void inverse3();
		void operator +();
		void operator -();
		void operator *();
		matrix();
		matrix(int **,int **,int **,
		int,int,int,float,float,float,float);
		matrix(const matrix &);
		~matrix();
		
};
//================================

void matrix :: initialize(){
	cout<<".:: Initializing a mount for 2 matrix ::.\n\n";
	cout<<"Enter matrix row : ";cin>>row;
	cout<<"Enter matrix column : ";cin>>column;cout<<endl;
	// outspread method:
	mat1 = new int*[row];
	for(int i = 0; i < column; ++i)
	    mat1[i] = new int[column];
	mat2 = new int*[row];
	for(int i = 0; i < column; ++i)
	    mat2[i] = new int[column];
	mat3 = new int*[row];
	for(int i = 0; i < column; ++i)
	    mat3[i] = new int[column];	    
	    
	int number;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<"Matrix1 "<<"["<<i<<"]"<<"["<<j<<"] : ";cin>>number;
			mat1[i][j] = number;
		}
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){
			cout<<"Matrix2 "<<"["<<i<<"]"<<"["<<j<<"] : ";cin>>number;
			mat2[i][j] = number;
		}
	}
}
//===============================
void matrix :: set(){
	if(row == 3 && column == 3)
		inverse3();
	else if(row == 2 && column == 2)
		inverse2();
	else cout<<"Matrix is out of Range to reverse !!";
}
//===============================
void matrix :: inverse3 (){
	// matrix kehad :
	mat4[0][0] = (mat1[1][1]*mat1[2][2])-(mat1[2][1]*mat1[1][2]);
	mat4[1][0] = (mat1[0][1]*mat1[2][2])-(mat1[2][1]*mat1[0][2]);
	mat4[2][0] = (mat1[0][1]*mat1[1][2])-(mat1[1][1]*mat1[0][2]);
	mat4[0][1] = (mat1[1][0]*mat1[2][2])-(mat1[2][0]*mat1[1][2]);
	mat4[1][1] = (mat1[0][0]*mat1[2][2])-(mat1[2][0]*mat1[0][2]);
	mat4[2][1] = (mat1[0][0]*mat1[1][2])-(mat1[1][0]*mat1[0][2]);
	mat4[0][2] = (mat1[1][0]*mat1[2][1])-(mat1[2][0]*mat1[1][1]);
	mat4[1][2] = (mat1[0][0]*mat1[2][1])-(mat1[2][0]*mat1[0][1]);
	mat4[2][2] = (mat1[0][0]*mat1[1][1])-(mat1[1][0]*mat1[0][1]);
	
	mat5[0][0] = (mat2[1][1]*mat2[2][2])-(mat2[2][1]*mat2[1][2]);
	mat5[1][0] = (mat2[0][1]*mat2[2][2])-(mat2[2][1]*mat2[0][2]);
	mat5[2][0] = (mat2[0][1]*mat2[1][2])-(mat2[1][1]*mat2[0][2]);
	mat5[0][1] = (mat2[1][0]*mat2[2][2])-(mat2[2][0]*mat2[1][2]);
	mat5[1][1] = (mat2[0][0]*mat2[2][2])-(mat2[2][0]*mat2[0][2]);
	mat5[2][1] = (mat2[0][0]*mat2[1][2])-(mat2[1][0]*mat2[0][2]);
	mat5[0][2] = (mat2[1][0]*mat2[2][1])-(mat2[2][0]*mat2[1][1]);
	mat5[1][2] = (mat2[0][0]*mat2[2][1])-(mat2[2][0]*mat2[0][1]);
	mat5[2][2] = (mat2[0][0]*mat2[1][1])-(mat2[1][0]*mat2[0][1]);
	//matrix hamsaz :
	mat4[0][1] *= -1;
	mat4[1][0] *= -1;
	mat4[1][2] *= -1;
	mat4[2][1] *= -1;

	mat5[0][1] *= -1;
	mat5[1][0] *= -1;
	mat5[1][2] *= -1;
	mat5[2][1] *= -1;
	// matrix elhaghi :
	tmp = mat4[0][1];
	mat4[0][1] = mat4[1][0];
	mat4[1][0] = tmp;
	
	tmp = mat4[0][2];
	mat4[0][2] = mat4[2][0];
	mat4[2][0] = tmp;
	
	tmp = mat4[1][2];
	mat4[1][2] = mat4[2][1];
	mat4[2][1] = tmp;



	tmp = mat5[0][1];
	mat5[0][1] = mat5[1][0];
	mat5[1][0] = tmp;
	
	tmp = mat5[0][2];
	mat5[0][2] = mat5[2][0];
	mat5[2][0] = tmp;
	
	tmp = mat5[1][2];
	mat5[1][2] = mat5[2][1];
	mat5[2][1] = tmp;	
	// Determinant matrix base :
	determinant1 = (
	(mat1[0][0]*(mat1[1][1]*mat1[2][2] - mat1[2][1]*mat1[1][2]))-
	(mat1[0][1]*(mat1[1][0]*mat1[2][2] - mat1[1][2]*mat1[2][0]))+
	(mat1[0][2]*(mat1[1][0]*mat1[2][1] - mat1[2][0]*mat1[1][1]))
	);

	determinant2 = (
	(mat2[0][0]*(mat1[1][1]*mat2[2][2] - mat2[2][1]*mat2[1][2]))-
	(mat2[0][1]*(mat1[1][0]*mat2[2][2] - mat2[1][2]*mat2[2][0]))+
	(mat2[0][2]*(mat1[1][0]*mat2[2][1] - mat2[2][0]*mat2[1][1]))
	);
	// matrix reverse :
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat4[i][j] *= (1/determinant1);
		}

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat5[i][j] *= (1/determinant2);
		}
	cout<<"\n============== Matrix reversed 3*3 ==============\n\n";		
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat4[i][j]<<" ";		
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat5[i][j]<<" ";		
		cout<<endl;
	}
}
//===============================
void matrix :: inverse2(){
	
	mat6[0][0] = mat1[1][1];
	mat6[0][1] = -mat1[0][1];
	mat6[1][0] = -mat1[1][0];
	mat6[1][1] = mat1[0][0];

	mat7[0][0] = mat2[1][1];
	mat7[0][1] = -mat2[0][1];
	mat7[1][0] = -mat2[1][0];
	mat7[1][1] = mat2[0][0];
	//determinant basic matrix
	determinant3 = ((mat1[0][0]*mat1[1][1])-(mat1[0][1]*mat1[1][0]));
	determinant4 = ((mat2[0][0]*mat2[1][1])-(mat2[0][1]*mat2[1][0]));

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat6[i][j] *= (1/determinant3);
		}	
	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++){
			mat7[i][j] *= (1/determinant4);
		}
	cout<<"\n============== Matrix reversed 2*2 ==============\n\n";		
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat6[i][j]<<" ";		
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat7[i][j]<<" ";		
		cout<<endl;
	}	
}
//===============================
/*void matrix :: identity(){
	cout<<"\n Not possible in this code !! \n";
}*/
//===============================
void matrix :: printer(){
	cout<<"\n\n============ Basic Matrix ============\n\n";
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat1[i][j]<<" ";		
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat2[i][j]<<" ";		
		cout<<endl;
	}
	cout<<"\n======================================\n";
}
//==============================
void matrix :: operator +(){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			mat3[i][j] = mat1[i][j]+mat2[i][j];			
	}	
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat3[i][j]<<" ";		
		cout<<endl;
	}	
}
//==============================
void matrix :: operator -(){
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			mat3[i][j] = mat1[i][j]-mat2[i][j];			
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat3[i][j]<<" ";		
		cout<<endl;
	}	
}
//==============================
void matrix :: operator *(){
	// default mounting for matrix 3:
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			mat3[i][j]=0;		
	}
	// force operation:
	for(int i = 0; i < row; i++){
    	for( int j = 0; j < column; j++){
        	for(int z = 0; z < row; z++)
            	mat3[i][j] += mat1[i][z] * mat2[z][j];
    	}
	}
	// print the result of matrix 3 :
	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++)
			cout<<" "<<mat3[i][j]<<" ";		
		cout<<endl;
	}
}
//==============================
matrix::matrix(){
	mat1 = {0},mat2 = {0},mat3 = {0},row=0,column=0,tmp=0,
	determinant1=0,determinant2=0,determinant3=0,determinant4=0;
}
matrix::matrix(int **m1,int **m2,int **m3,
		int r,int c,int t,float d1,float d2,float d3,float d4){
			mat1=m1,mat2=m2,mat3=m3,row=r,column=c,tmp=t,
			determinant1=d1,determinant2=d2,determinant3=d3,determinant4=d4;				
		}
matrix::matrix(const matrix &m){
			mat1=m.mat1,mat2=m.mat2,mat3=m.mat3,row=m.row,column=m.column,tmp=m.tmp,
			determinant1=m.determinant1,determinant2=m.determinant2,
			determinant3=m.determinant3,determinant4=m.determinant4;
		}
matrix::~matrix(){};
//================================
main(){
	matrix test;
	test.initialize();
	test.printer();
	
	int c_number;
	cout<<"\nchoose one method : \n";
	while(true){
		cout<<"\n1 = matrix (+)\n";
		cout<<"\n2 = matrix (-)\n";
		cout<<"\n3 = matrix (*)\n";
		cout<<"\n4 = matrix inverser\n";
		cin>>c_number;
		if(c_number == 1 || c_number == 2 || c_number == 3|| c_number == 4) break;
		else {cout<<"\nTry another number !!\n";continue;}
	}
	if(c_number == 1)
		+test;
	else if(c_number == 2)
		-test;
	else if(c_number == 3)
		*test;
	else
		test.set();
		
}
