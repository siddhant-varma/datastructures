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
};

int precedence(char sym){
	
	switch(sym){
		case '-':
			return 1;
		case '+':
			return 2;
		case '*':
			return 3;
		case '/':
			return 4;
		case '^':
			return 5;
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
				
		if(scan == '('){
			ops.push(scan);
			continue;
		}
		else if(scan == ')'){
			char c = ops.pop();
			while(c != '('){
				if(precedence(c))
					output += c;
				c = ops.pop();
			}
			continue;
		}
		
		int temp = precedence(scan);
		if(temp){
			if(temp > precedence(ops.arr[ops.tos]) || ops.isEmpty()){
				ops.push(scan);
			}
			else{
				while(temp <= precedence(ops.arr[ops.tos])){
					output += ops.pop();
				}
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
