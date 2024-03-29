#include<iostream>
#include<cstdlib>
#include<ctime> //#include<chrono> 
#include<string>
#include<fstream>
using namespace std;
void C(double*,int);
void C(float* ,int);
void C(long*  ,int);
void C(int*   ,int);
void C(string*,int);

template<class T> //insertion sort
void insertion_sort(T*a,int n){
	for(int i=1;i<n;i++){
		T key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
template<class T>  //bubble sort
void bubble_sort(T*a,int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				T temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
template<class T>//selection sort
void selection_sort(T *a,int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if (a[j]<a[min])
				min=j;
		}
		T temp=a[min]; //swap(a[i],a[min]);
		a[min]=a[i];
		a[i]=temp;
	}
}

// Merge two subarrays L and M into arr
template<class T> 
void merge(T *a, int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  T * L=new T [n1]; 
  T * M=new T [n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i=0, j=0, k=p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
	delete[]L;
	delete[]M;
}

// Divide the array into two subarrays, sort them and merge them
template<class T> 
void merge_sort(T *a, int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    // Merge the sorted subarrays
    merge(a, l, m, r);
  }
}
int main(void){                  
	ofstream file;
	file.open("Carraytime.txt",ios::out); //開啟檔案 
	srand(time(NULL));	
 
	double dr[60];
    float  fr[60];
    long   lr[60];
    int    ir[60];
    string sr[60];
    double*d= new double[500000];
    float *f= new float [500000];
    long  *l= new long  [500000];
    int   *i= new int   [500000];
    string*s= new string[500000];
 	clock_t start ,end,midstart,midend;
    double alltime,time;
    int datesmall[6]={10,20,30,40,50,60};
    int datebig[5]={100000,200000,300000,400000,500000};
    /*
   start=clock();
  cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,50);
		insertion_sort(sr,50);
		}
		end=clock();
		cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<alltime;
 
		midstart=clock();
		cout<<midstart<<endl;
		for(int i=0;i<1000000;i++)
			C(sr,50);
		midend=clock();
		cout<<midend<<endl;
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time<<endl;
		cout<<"  筆double資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;	//cout<<"花費時間"<<alltime-time<<endl;

		//	cout<<"排";
	//	cout<<"double:  ";
	//	for(int i=0;i<10;i++)
		//	cout<<dr[i]<<" ";
 		 //cout<<endl;
*/		
	
 
//insertion_sort
    file<<"insertion_sort執行時間 "<<endl;
    //隨機產生10，20，30，40，50筆資料
    for(int j=0;j<6;j++){

		//double insertionsort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			insertion_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆double資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;	//cout<<"花費時間"<<alltime-time<<endl;

		//float insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			insertion_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆float 資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//lonf insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			insertion_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆long  資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
		//int insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			insertion_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆int   資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//string insertionsort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			insertion_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆string資料insertion_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	}
	
	//隨機產生10萬，20萬，30萬，40萬，50萬筆資料
	for(int j=0;j<5;j++){ 
		//double insertionsort
		cout<<datebig[j]<<endl;
		C(d,datebig[j]);
		start=clock(); //cout<<start<<endl;
		insertion_sort(d,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆double資料insertion_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//float insertionsort
		C(f,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(f,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆float 資料insertion_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//lonf insertionsort
		C(l,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(l,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆long  資料insertion_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//int insertionsort
		C(i,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(i,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆int   資料insertion_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//string insertionsort
		C(s,datebig[j]);
		start=clock();	//cout<<start<<endl;
		insertion_sort(s,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆string資料insertion_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
	}


//bubble_sort
    file<<"bubble_sort執行時間 "<<endl;
    for(int j=0;j<6;j++){ //隨機產生10，20，30，40，50筆資料
		//double bubble_sort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			bubble_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆double資料bubble_sort跑1000000次的時間: "<<alltime-time<<endl;	//cout<<"花費時間"<<alltime-time<<endl;

		//float bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			bubble_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆float 資料bubble_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//lonf bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			bubble_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆long  資料bubble_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
		//int bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			bubble_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆int   資料bubble_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//string bubble_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			bubble_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆string資料bubble_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	}

	for(int j=0;j<5;j++){ //隨機產生10萬，20萬，30萬，40萬，50萬筆資料
		//double bubble_sort
		cout<<datebig[j]<<endl;
		C(d,datebig[j]);
		start=clock(); //cout<<start<<endl;
		bubble_sort(d,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆double資料bubble_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//float bubble_sort
		C(f,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(f,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆float 資料bubble_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//lonf bubble_sort
		C(l,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(l,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆long  資料bubble_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//int bubble_sort
		C(i,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(i,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆int   資料bubble_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//string bubble_sort
		C(s,datebig[j]);
		start=clock();	//cout<<start<<endl;
		bubble_sort(s,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆string資料bubble_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
	}

//selection_sort
	    file<<"selection_sort執行時間 "<<endl;
    for(int j=0;j<6;j++){ //隨機產生10，20，30，40，50筆資料
		//double selection_sort
		cout<<datesmall[j]<<endl;
		start=clock();
		//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			selection_sort(dr,datesmall[j]);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<alltime;
		midstart=clock();
		
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆double資料selection_sort跑1000000次的時間: "<<alltime-time<<endl;	//cout<<"花費時間"<<alltime-time<<endl;

		//float selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			selection_sort(fr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆float 資料selection_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//lonf selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			selection_sort(lr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆long  資料selection_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
		//int selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			selection_sort(ir,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆int   資料selection_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//string selection_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			selection_sort(sr,datesmall[j]);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆string資料selection_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	}

	for(int j=0;j<5;j++){ //隨機產生10萬，20萬，30萬，40萬，50萬筆資料
		//double selection_sort
		cout<<datebig[j]<<endl;
		C(d,datebig[j]);
		start=clock(); //cout<<start<<endl;
		selection_sort(d,datebig[j]);
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆double資料selection_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//float selection_sort
		C(f,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(f,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆float 資料selection_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//lonf selection_sort
		C(l,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(l,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆long  資料selection_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//int selection_sort
		C(i,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(i,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆int   資料selection_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//string selection_sort
		C(s,datebig[j]);
		start=clock();	//cout<<start<<endl;
		selection_sort(s,datebig[j]);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆string資料selection_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
	}



//merge_sort
	file<<"merge_sort執行時間 "<<endl;
    for(int j=0;j<6;j++){ //隨機產生10，20，30，40，50筆資料
		//double merge_sort
		cout<<datesmall[j]<<endl;
		start=clock();
	//	cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(dr,datesmall[j]);
			merge_sort(dr,0,datesmall[j]-1);
		}
		end=clock();
	//	cout<<end<<endl;
 		alltime=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<alltime;
		midstart=clock();
		//cout<<midstart<<endl;
		for(int i=0;i<1000000;i++)
			C(dr,datesmall[j]);
		midend=clock();
	//	cout<<midend<<endl;
		time=double(midend-midstart)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆double資料merge_sort跑1000000次的時間: "<<alltime-time<<endl;	//cout<<"花費時間"<<alltime-time<<endl;

		//float merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(fr,datesmall[j]);
			merge_sort(fr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(fr,datesmall[j]);
		midend=clock();
			
		time=double(midend-midstart)/CLOCKS_PER_SEC; //	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆float 資料merge_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	
		//lonf merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(lr,datesmall[j]);
			merge_sort(lr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(lr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆long  資料merge_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
		//int merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(ir,datesmall[j]);
			merge_sort(ir,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(ir,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆int   資料merge_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;

		//string merge_sort
		start=clock();	//cout<<start<<endl;
		for(int i=0;i<1000000;i++){
			C(sr,datesmall[j]);
			merge_sort(sr,0,datesmall[j]-1);
		}
		end=clock();   //cout<<end<<endl;
		alltime=(double)(end-start)/CLOCKS_PER_SEC;//cout<<"花費時間"<<alltime;
		midstart=clock();
		for(int i=0;i<1000000;i++)
			C(sr,datesmall[j]);
		midend=clock();	
		time=double(midend-midstart)/CLOCKS_PER_SEC;//	cout<<"花費時間"<<time<<endl;
		file<<datesmall[j]<<"  筆string資料merge_sort跑1000000次的時間: "<<alltime-time<<endl;//	cout<<"花費時間"<<alltime-time<<endl;
	}
	

	for(int j=0;j<5;j++){ //隨機產生10萬，20萬，30萬，40萬，50萬筆資料
		cout<<datebig[j]<<endl;
		//double merge_sort
		C(d,datebig[j]);
		start=clock(); //cout<<start<<endl;
		merge_sort(d,0,(datebig[j]-1));
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆double資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//float merge_sort
		C(f,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(f,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆float 資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		
		//long merge_sort
		C(l,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(l,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆long  資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//int merge_sort
		C(i,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(i,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆int   資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		//string merge_sort
		C(s,datebig[j]);
		start=clock();	//cout<<start<<endl;
		merge_sort(s,0,datebig[j]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<datebig[j]<<"筆string資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
	}

	delete []d;
	delete []f;
	delete []l;
	delete []i;
	delete []s;
	file<<"Carray全部已跑完" <<endl;
	system("pause");
	return 0;
}

