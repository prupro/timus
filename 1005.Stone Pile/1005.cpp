#include<iostream>
using namespace std;

inline int absdiff(int a, int b){
	if (a>b) return a-b;
	return b-a;
}

bool numCloseToDiff( int n, int w[], int halfDiff, int &index){
	int diff = halfDiff;
	int ind = 0;

	bool found = 0;
	for(int i=0;i<n;i++){
		if( absdiff(w[i],halfDiff) < diff && w[i] > 0 ) {
			found = 1; 
			diff = absdiff(w[i],halfDiff);
			ind = i;
		}	
	}	

	index = ind;

	return found;
}

bool maxLessThan( int n, int w[], int halfDiff, int &index){
	int max = 0;
	int ind = 0;

	bool found = 0;
	for(int i=0;i<n;i++){
		if(w[i] >max && w[i] <= halfDiff && w[i] > 0 ) {
			found = 1;
			max = w[i];
			ind = i;
		}
	}

	index = ind;

	return found;
}

int main(){
	int n;
	int sum=0, sum1=0, sum2=0;
	cin >> n;
	int *w = new int[n];
	int *w1 = new int[n];
	for(int i=0;i<n;i++){
		cin >> w[i];
		w1[i] = w[i];
		sum += w[i];		
	}

	int index=0;
	
	sum1 = sum;

	while(	numCloseToDiff(n, w, absdiff(sum1,sum2)/2, index) ){
		sum1 -= w[index];
		sum2 += w[index];
		w[index] = 0;	

	}	
	int diff1 = absdiff(sum1,sum2);
	
	sum1 = sum;
	sum2 = 0;	

	while(	maxLessThan(n, w1, (sum1-sum2)/2, index) ){
		sum1 -= w1[index];
		sum2 += w1[index];
		w1[index] = 0;	

	}	
	int diff2 = absdiff(sum1,sum2);
	
	if (diff1 > diff2) cout << diff2 << endl;
	else cout << diff1 << endl;

	return 0;
}
