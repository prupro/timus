#include <iostream>
#include <vector>
#include <cmath>
#include<cstdio>
using namespace std;

int main(){

vector<long long int> numbers;
//code to read input
long long int in;

while(cin >> in){
numbers.push_back(in);

}
// output
for(int i=numbers.size()-1;i>-1;i--){
	printf("%.4f\n", sqrt(numbers[i]));
}
return 0;
}
