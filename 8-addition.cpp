#include <iostream>

using namespace std;

template <class T>
class Stack{
	int size, tos;
	T *arr;
		
	public:
		Stack(int s){
			size = s;
			arr = new T[size];
			tos = -1;
		}
			
		bool isEmpty(void){
			return tos == -1;
		}
		
		bool isFull(void){
			return tos == size-1;
		}
		
		void push(T el){
			if(!isFull()){
				arr[++tos] = el;
			}
			return;
		}
		
		T pop(void){
			if(!isEmpty()){
				T temp = arr[tos--];
				return temp;
			}
		}
		
		void display(void){
			for(int i = tos;i > -1; i--){
				cout<<arr[i];
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
	int carry = 0;
	for(int  i = 0; i < n1.length(); i++){
		num1.push((int)n1[i] - 48);
	}
	for(int  i = 0; i < n2.length(); i++){
		num2.push((int)n2[i] - 48);
	}
	while(!num1.isEmpty() && !num2.isEmpty()){
		int add = num1.pop() + num2.pop() + carry;
		sum.push(add%10);
		carry = add / 10;
	}
	while(!num1.isEmpty()){
		int add = num1.pop() + carry;
		sum.push(add%10);
		carry = add / 10;
	}
	while(!num2.isEmpty()){
		int add = num2.pop() + carry;
		sum.push(add%10);
		carry = add / 10;
	}
	cout<<"\nSum is:\t";
	sum.display();
}
