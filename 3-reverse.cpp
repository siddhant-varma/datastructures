#include <iostream>
#include <cstring>

using namespace std;

string reverse(string str){
	if(str.length() == 1){
		string a = "";
		a += str[0];
		return a;
	}
	return (str[str.length() - 1] + reverse(str.substr(0,str.length() - 1)));
}

int main(void){
	string s;
	cout<<"Enter a String:\t";
	cin>>s;
	cout<<"\nReverse of the string is "<<reverse(s);
	return 0;
}
