#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] < x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ifstream data;
	ofstream result;
	data.open("score3.txt");
	result.open("result.txt");
	string num;
	float score[20];
	for(int i=0;i<20;i++){
		getline(data,num);
		score[i]=stof(num);
	}
	data.close();
	sort(score,20);
	int j=1,k=1;
	for(int i=19;i>=0;i--){
		if(i<19&&score[i]==score[i+1])result<<k<<" : "<<score[i];
		else{
			result<<j<<" : "<<score[i];
			k=j;
		}
		result<<"\n";
		j++;
	}
	result.close();
	return 0;
}

