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
	int temp;
	cout<<"Enter Size of Stack:\t";
	cin>>temp;
	Stack <int>stk(temp);
	while(true){
		int ch;
		cout<<"\nEnter\t1.Push\n\t2.Pop\n\t3.Exit\t:";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter Element:\t";
				cin>>temp;
				stk.push(temp);
				break;
			case 2:
				stk.pop();
				break;
			case 3:
				return 0;
		}
	}
}
