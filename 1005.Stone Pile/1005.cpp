#include<iostream>
using namespace std;

bool maxLessThan( int n, int w[], int halfDiff, int *index){
	int max = 0;
	int ind = 0;
	
	bool found = 0;
	for(int i=0;i<n;i++){
		if(w[i] >max && w[i] <= halfDiff && w[i] > 0 ) {found = 1; max = w[i]; ind = i;}	
	}	

	*index = ind;

	return found;
}

int main(){
	int n;
	int sum1=0, sum2=0;
	cin >> n;
	int w[n];
	for(int i=0;i<n;i++){
		cin >> w[i];
		sum1 += w[i];		
	}

	int index=0;

	while(	maxLessThan(n, w, (sum1-sum2)/2, &index) ){
		sum1 -= w[index];
		sum2 += w[index];
		w[index] = 0;	

	}	

	cout << sum1-sum2;
	return 0;
}
