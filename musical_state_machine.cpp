/*
musical state machine is based on windows and linux operation !!

to use in windows :
	include windows.h and try to use beep() method.
to use in linux :
	just try to use beeps() method which is exist in program's functions.
	
*/

#include <iostream>
#include <stdlib.h>
//#include <windows.h>
#include <time.h>
using namespace std;
//==================
void beeps(int);
void single_beep();
void random_beep();
void decussate_beep();
void status(int);
//==================

int main(){
	system("Color 70");
	int option;
	cout<<" .:: Welcome to the musical state machine ::.\n";
	status(0);
	
	cout<<"\nChoose a method or press 0 to close program : ";
	while(true){
		cout<<"\n1 = Single beep\n";
		cout<<"2 = Random beep\n";
		cout<<"3 = Decussate beep\n";
		cin>>option;
		switch(option){
				case 1: single_beep();break;
				case 2: random_beep();break;
				case 3: decussate_beep();break;
				}		
		if(option == 0)
			break;
		else{
		cout<<"\nTry another key or press 0 to exit !!\n";
		continue;
	}
	}
	
	return 0;
}
//==========================================
void status(int num){
	cout<<"\n================ Status ==================\n";
	cout<<"|";cout<<" section 1 |  ";cout<<"section 2  | ";cout<<"  section 3  |\n";
	cout<<"|";cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"|";if(num==1){cout<<"  Active";cout<<"   |\t";cout<<"\t  |\t";cout<<"\t |\n";cout<<"|";}
	if(num==2){cout<<"\t    |   Active    |";cout<<"\t\t |\n";cout<<"|";}
	if(num==3){cout<<"\t    |  \t\t  |    Active";cout<<"\t |\n";cout<<"|";}
	cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"|";cout<<"-----------|-----";cout<<"--------|--------";cout<<"------|\n";
	cout<<"|";cout<<" section 4 |  ";cout<<"section 5  | ";cout<<"  section 6  |\n";
	cout<<"|";cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"|";if(num==4){cout<<"  Active";cout<<"   |\t";cout<<"\t  |\t";cout<<"\t |\n";cout<<"|";}
	if(num==5){cout<<"\t    |   Active    |";cout<<"\t\t |\n";cout<<"|";}
	if(num==6){cout<<"\t    |  \t\t  |    Active";cout<<"\t |\n";cout<<"|";}
	cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"|";cout<<"-----------|-----";cout<<"--------|--------";cout<<"------|\n";
	cout<<"|";cout<<" section 7 |  ";cout<<"section 8  | ";cout<<"  section 9  |\n";
	cout<<"|";cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"|";if(num==7){cout<<"  Active";cout<<"   |\t";cout<<"\t  |\t";cout<<"\t |\n";cout<<"|";}
	if(num==8){cout<<"\t    |   Active    |";cout<<"\t\t |\n";cout<<"|";}
	if(num==9){cout<<"\t    |  \t\t  |    Active";cout<<"\t |\n";cout<<"|";}
	cout<<"\t    |\t";cout<<"\t  |\t";cout<<"\t |\n";
	cout<<"==========================================\n";
}
//==========================================
void single_beep(){
	int sec,bp;
	while(true){
		cout<<"\nchoose a section or press 0 to back to the menu : \n\n";
		cout<<"1:section1 \t 2:section2 \t 3:section3\n";
		cout<<"4:section4 \t 5:section5 \t 6:section6\n";
		cout<<"7:section7 \t 8:section8 \t 9:section9\n";
		cin>>sec;
		//==============
		if(sec==1){
			status(1);
			while(true){
			cout<<"now press 1 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 1){
					//Beep(100,1000);
					beeps(1);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				} 				
		}
	}
	//==============
		if(sec==2){
			status(2);
			while(true){
			cout<<"now press 2 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 2){
					//Beep(200,1000);
					beeps(2);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				} 
			}
		}
		//================
		if(sec==3){
			status(3);
			while(true){
			cout<<"now press 3 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 3){
					//Beep(300,1000);
					beeps(3);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}
		
	//=============	
		if(sec==4){
			status(4);
			while(true){
			cout<<"now press 4 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 4){
					//Beep(400,1000);
					beeps(4);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}		
//=========================
		if(sec==5){
			status(5);
			while(true){
			cout<<"now press 5 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 5){
					//Beep(500,1000);
					beeps(5);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}		
//==================
		if(sec==6){
			status(6);
			while(true){
			cout<<"now press 6 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 6){
					//Beep(600,1000);
					beeps(6);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}		
//======================
		if(sec==7){
			status(7);
			while(true){
			cout<<"now press 7 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 7){
					//Beep(700,1000);
					beeps(7);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}
//=========================
		if(sec==8){
			status(8);
			while(true){
			cout<<"now press 8 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 8){
					//Beep(800,1000);
					beeps(8);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}
//======================
		if(sec==9){
			status(9);
			while(true){
			cout<<"now press 9 to make beep or 0 to back to the menu : ";cin>>bp;
				if(bp == 9){
					//Beep(900,1000);
					beeps(9);
					continue;
				}
				else if(bp == 0)
					break;
				else{
					cout<<"\nTry another key or press 0 to back to menu !!\n";
					continue;
				}
			} 
		}		
		else if(sec == 0)
			break;
		else{
			//cout<<"\nwrong key!!\n";
			continue;
		}		
}
}
//==========================================
void random_beep(){
	int range,random;
	cout<<"Enter duration range : ";cin>>range;
	for(int i=1;i<=range;i++){
		srand(time(NULL));
		random = rand() % 9 + 1;
		cout<<"Section "<<random<<" is active : "<<random*100<<" db\n";
		//Beep(random*100,1000);
		beeps(random);
		
	}
}
//==========================================
void decussate_beep(){
	cout<<"\nDecussate beep noise : \n";
	for(int i=1;i<=9;i++){
		cout<<"Section "<<i<<" is active : "<<i*100<<" db\n";
		//Beep(i*100,1000);
		beeps(i);
	}
	for(int i=9;i>=1;i--){
		cout<<"Section "<<i<<" is active : "<<i*100<<" db\n";
		//Beep(i*100,1000);
		beeps(i);
	}
}
void beeps(int number){
	switch(number){
		case 1 : system("(speaker-test > /dev/null 2>&1 -t sine -f 100)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 2 : system("(speaker-test > /dev/null 2>&1 -t sine -f 200)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 3 : system("(speaker-test > /dev/null 2>&1 -t sine -f 300)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 4 : system("(speaker-test > /dev/null 2>&1 -t sine -f 400)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 5 : system("(speaker-test > /dev/null 2>&1 -t sine -f 500)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 6 : system("(speaker-test > /dev/null 2>&1 -t sine -f 600)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 7 : system("(speaker-test > /dev/null 2>&1 -t sine -f 700)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 8 : system("(speaker-test > /dev/null 2>&1 -t sine -f 800)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		case 9 : system("(speaker-test > /dev/null 2>&1 -t sine -f 900)& pid=$!; sleep 1.0s; kill -9 $pid > /dev/null 2>&1");break;
		default : break;
	}

}
