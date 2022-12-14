#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
//#include<chrono> 
using namespace std;

void C(vector<double> &randnuma,int MAX){
	double min=0.0,max=100000.0000000000;
	for(int i=0;i<MAX;i++){
		double j=(double)(max-min)*rand()/(RAND_MAX+1.0);
		randnuma.push_back(j);
	}
/*	cout<<"�Ƨǫe";
	cout<<"double:  ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
  cout<<endl;*/
}
void C(vector<float>&randnuma,int MAX){
	float min=0.0f,max=10000.0f;
	for(int i=0;i<MAX;i++){
		randnuma.push_back((float)(max-min)*rand()/(RAND_MAX+1.0));
	}
/*	 cout<<"float: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
 
}
void C(vector<long> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		randnuma.push_back((long)rand());
	}
 /*   cout<<"long: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl*/
 
}
void C(vector<int> &randnuma,int MAX){
	for(int i=0;i<MAX;i++){
		randnuma.push_back(rand());
	}
 /*   cout<<"int: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/

}
void C(vector<string>  &randnuma,int MAX){
	for(int i=0;i<MAX;i++){	
		string str="aaaaaa";
		for(int k=0;k<6;k++){
			str[k]+=rand()%26;
		}
		randnuma.push_back(str);
	}
 /*  cout<<"string: ";
	for(int i=0;i<MAX;i++)
		cout<<randnuma[i]<<" ";
    cout<<endl;*/
    
}

