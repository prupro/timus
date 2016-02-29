#include<iostream>
using namespace std;

inline int absdiff(int a, int b){
	if (a>b) return a-b;
	return b-a;
}
bool numCloseToDiff( int n, int w[], int halfDiff, int *index){
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

	*index = ind;

	return found;
}

int main(){
	int n;
	int sum1=0, sum2=0;
	cin >> n;
	int *w = new int[n];
	for(int i=0;i<n;i++){
		cin >> w[i];
		sum1 += w[i];		
	}

	int index=0;

	while(	numCloseToDiff(n, w, (sum1-sum2)/2, &index) ){
		sum1 -= w[index];
		sum2 += w[index];
		w[index] = 0;	

	}	

	cout << absdiff(sum1,sum2)<< endl;
	return 0;
}
