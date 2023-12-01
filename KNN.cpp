#include<iostream>
#include<math.h>
using namespace std;
int n=20;
struct ToaDo{
	float x1,x2;
	bool label;
};

float distanceAB(ToaDo a, ToaDo b){
	return sqrt(pow((a.x1-b.x1),2)+pow((a.x2-b.x2),2));
}

main(){
	//import training values
	ToaDo list[20];
	list[0].x1= 4; list[0].x2= 3; list[0].label = 0;
	list[1].x1= 3; list[1].x2= 7; list[1].label = 0;
	list[2].x1= 7; list[2].x2= 4; list[2].label = 0;
	list[3].x1= 4; list[3].x2= 1; list[3].label = 0;
	list[4].x1= 6; list[4].x2= 5; list[4].label = 0;
	list[5].x1= 5; list[5].x2= 6; list[5].label = 0;
	list[6].x1= 3; list[6].x2= 7; list[6].label = 0;
	list[7].x1= 6; list[7].x2= 2; list[7].label = 0;
	list[8].x1= 4; list[8].x2= 6; list[8].label = 1;
	list[9].x1= 4; list[9].x2= 4; list[9].label = 1;
	list[10].x1= 5; list[10].x2= 8; list[10].label = 1;
	list[11].x1= 7; list[11].x2= 8; list[11].label = 1;
	list[12].x1= 7; list[12].x2= 6; list[12].label = 1;
	list[13].x1= 4; list[13].x2= 10; list[13].label = 1;
	list[14].x1= 9; list[14].x2= 7; list[14].label = 1;
	list[15].x1= 5; list[15].x2= 4; list[15].label = 1;
	list[16].x1= 8; list[16].x2= 5; list[16].label = 1;
	list[17].x1= 6; list[17].x2= 6; list[17].label = 1;
	list[18].x1= 7; list[18].x2= 4; list[18].label = 1;
	list[19].x1= 8; list[19].x2= 8; list[19].label = 1;
	//import predict sample
	ToaDo test; 
	test.x1=7; test.x2=5;
	
	float distemp[n];//mang khoang cach
	for(int i=0; i<n; i++) distemp[i] = distanceAB(test, list[i]);
	for(int i=0; i<n ;i++) cout<< distemp[i]<<endl;
	cout<<endl;
	
	cout<<"sap xep distance"<<endl;
	for(int i=0; i < n-1; i++)
		for(int j=i+1; j<n; j++){
			if(distemp[i]>distemp[j]){
				swap(list[i],list[j]);
				swap(distemp[i],distemp[j]);
			}
		}
	for(int i=0; i<n ;i++) cout<< distemp[i]<<endl;
	
	int k;
	cout<<"nhap k lang gieng gan nhat: "; cin>>k;
	cout<<endl;
	int count=0;
	for(int i=0 ; i<k; i++){
		count+= (int)list[i].label;
	}
	if(count<((k/2)+1)){
		test.label = 0;
	}
	else{
		test.label=1;
	}
	cout<<"nhan cua mau se la: "<<test.label;
}
