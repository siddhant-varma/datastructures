#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node <T> *next;
		
		Node(){
			next = 0;
		}
		Node(T el, Node *ptr = 0){
			data = el;
			next = ptr;
		}
};

template<class T>
class List{
	public:
		Node <T> *head, *tail;
		List(){
			head = tail = 0;
		}
		bool isEmpty(){
			return head == 0;
		}
		
		void addtoTail(T el){
			if(isEmpty()){
				head = tail = new Node<T>(el);
			}
			else{
				tail -> next = new Node<T>(el);
				tail = tail -> next;
			}
		}
		
		T delTail(void){
			if(!isEmpty()){
				T el = tail -> data;
				Node<T> *temp;
				if(head == tail){
					head = tail = 0;
					delete temp;
				}
				else{
					for(temp = head; temp -> next != tail; temp = temp -> next);
					delete tail;
					tail = temp;
					tail -> next = 0;
				}
				return el;
			}
			return -1;
		}
		
		void display(void){
			Node <T> *temp;
			cout<<endl;
			for(temp = head; temp != 0; temp = temp -> next){
				cout<<temp -> data <<" << ";
			}
			cout<<endl;
			return;
		}
		
		~List(){
			/*Node<T> *temp, *del = 0;
			for(temp = head; temp != 0; temp = temp -> next){
				del = temp;
				delete del;
			}*/
			tail = head = 0;
		}
};

template <class T>
class Stack{
	public:
		
		List<int> lst;
		bool isEmpty(void){
			return lst.isEmpty();
		}
		void push(T el){
			lst.addtoTail(el);
		}
		T pop(void){
			T el = lst.delTail();
			if(el != -1){
				cout<<endl<<el<<" poped from stack.";
				return el;
			}
			else{
				cout<<"\nStack underFlow...\n";
				return el;
			}
		}
};

int main(void){
	Stack <int> stk;
	int temp, el;
	while(true){
		cout<<"\nEnter:\t1.Push\n\t2.Pop\n\t3.Clear\n\t4.Display\n\t5.Exit:\t";
		cin>>temp;
		switch(temp){
			case 1:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				stk.push(el);
				break;
			}
			case 2:stk.pop();
					break;
			case 3:{
				stk.lst.~List();
				cout<<"\nStack is Cleared...\n";
				break;
			}
			case 4:{
				if(!stk.isEmpty())
					stk.lst.display();
				else
					cout<<"\nStack is Empty...\n";
				break;
			}
			case 5:
				return 0;
		}
	}
	return 0;
}
