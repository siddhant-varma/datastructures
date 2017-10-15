#include <iostream>

#define MAX 16

using namespace std;

template<class t>
class stack{
	private:
		t *buffer;
		int top,size;
	
	public:
		stack(int s){
			if (s>16)
				s = 16;
			size = s;
			buffer = new t[size];
			top = -1;
		}
		
		bool isEmpty(void){
			return (top == -1);
		}
		
		void push(t el){
			if(top==size-1){
				cout<<"\tStack overflow...Stack Full...Exiting";
			}
			else{
				buffer[++top] = el;
				cout<<"\t"<<el<<" pushed in Stack.\n";
			}
		}
		
		t pop(void){
			if(isEmpty()){
				cout<<"\tStack Underflow... Empty Stack...Exiting";
			}
			else{
				t poped = buffer[top--];
				cout<<"\t"<<poped<<" removed from Stack.\n";
				return poped;
			}
		}
		
		t topEl(void){
			if(top == -1){
				cout<<"\n\tStack Underflow... Empty Stack...Exiting";
			}
			else{
				t poped = buffer[top];
				cout<<"\t"<<poped<<" is on top of Stack.\n";
				return poped;
			}
		}
		
};

int main(void){
	int temp;
	char ch;
	
	cout<<"\nEnter Size of Stack (Max = 16): ";
	cin>>temp;
	stack<int> st(temp);
	
	do{
		cout<<"\nEnter\n1. Push()\t2.Pop()\t3.topEl()\t4.isEmpty():\n";
		cin>>temp;
		switch(temp){
			case 1:
				cout<<"\tEnter element: ";
				cin>>temp;
				st.push(temp);
				break;
			case 2:
				st.pop();
				break;
			case 3:
				st.topEl();
				break;
			case 4:
				if(st.isEmpty())
					cout<<"\tStack is Empty.";
				else
					cout<<"\tStack is not Empty.";
				break;
			default:
				cout<<"\n\tWrong Choice...";
				break;
		}
		cout<<"\n\t\tPress X to exit...";
		cin>>ch;
	}while(ch!='x' || ch!='X');
	
	return 0;
}
