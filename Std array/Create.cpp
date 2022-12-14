#include<array> 
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

//#include<chrono> 
using namespace std;

void C(array<double,500000> &randnuma,int MAX){
	double min=0.0,max=100000.0000000000;
	for(int i=0;i<MAX;i++){
		randnuma.at(i)=(double)(max-min)*rand()/(RAND_MAX+1.0);
	}

/*	cout<<"�Ƨǫe";
	cout<<"double:  ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
  cout<<endl;*/ 
}
void C(array<float,500000>&randnuma,int MAX){
	float min=0.0f,max=10000.0f;
	for(int i=0;i<MAX;i++){
		randnuma.at(i)=(float)(max-min)*rand()/(RAND_MAX+1.0);
	}
 /*  cout<<"float: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
 
}
void C(array<long,500000> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		randnuma.at(i)=(long)rand();
	}
/*    cout<<"long: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;
 */ 
}
void C(array<int,500000> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		randnuma.at(i)=rand();
	}
/*    cout<<"int: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;
*/
}
void C( array<string,500000> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		string str="aaaaaa";
		for(int k=0;k<6;k++){
			str[k]+=rand()%26;
		}
		randnuma.at(i)=str;
	}
  /* cout<<"string: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
    
}

