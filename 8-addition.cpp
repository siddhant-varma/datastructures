#include <iostream>

using namespace std;

template <class T>
class Stack{
	int size, pos;
	T *arr;
	
	bool isEmpty(void){
		return pos == -1;
	}
	
	bool isFull(void){
		return pos == size-1;
	}
	
	public:
		Stack(int s){
			size = s;
			arr = new T[size];
			pos = -1;
		}
		
		void push(T el){
			if(!isFull()){
				arr[++pos] = el;
			}
			else{
				cout<<"\nStack Overflow...";
			}
			return;
		}
		
		T pop(void){
			if(!isEmpty()){
				T temp = arr[pos--];
				cout<<temp<<" popped\n";
				return temp;
			}
			else{
				cout<<"\nStack Underflow...";
				return -1;
			}
		}
		
};

int main(void){
	string n1, n2;
	cout<<"Enter 1st Number:\t";
	cin>>n1;
	cout<<"Enter 2nd Number:\t";
	cin>>n2;
	Stack <int> num1(n1.length()), num2(n2.length()), sum(n1.length()>=n2.length()?n1.length():n2.length());
	for(int  i = 0; i < n1.length(); i++){
		num1.push((int)n1[i]);
	}
	for(int  i = 0; i < n2.length(); i++){
		num2.push((int)n2[i]);
	}
}
