#include <iostream>

using namespace std;


template <class T>
class Stack{
	public:
		
		int size, tos;
		T *arr;
			
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

int precedence(char sym){
	
	switch(sym){
		case '-':
			return 1;
		case '+':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return 0;
	}
	
}

int main(void){
	string input, output = "";
	cout<<"Enter Expression:\t";
	cin>>input;
	Stack <char>ops(10);
	for(int i = 0; i < input.length(); i++){
		char scan = input[i];
		cout<<endl<<scan;
		int temp = precedence(scan);
		if(temp){
			if(temp > precedence(ops.arr[ops.tos]) || ops.isEmpty()){
				ops.push(scan);
			}
			else{
				char c;
				do{
					c = ops.pop();
					output += c;
					cout<<"\t\t\t\t"<<c;
				}while(temp <= precedence(ops.arr[ops.tos]));
				ops.push(scan);
			}
		}
		else{
			output += scan;
		}
	}
	while(!ops.isEmpty()){
		output += ops.pop();
	}
	cout<<"\nPostfix is "<<output;
	return 0;
}
