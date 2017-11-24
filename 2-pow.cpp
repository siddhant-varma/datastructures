#include <iostream>

using namespace std;

long int power(int b,int r){
	if(r == 1)
		return b;
	return (b * power(b, r-1));
}

int main(void){
	cout<<power(2,3);
	return 0;
}
