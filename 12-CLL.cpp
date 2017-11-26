#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		T data;
		Node *next;
		Node(){
			next = nullptr;
		}
		Node(T el, Node *ptr = nullptr){
			data = el;
			next = ptr;
		}
};

template <class T>
class CList{
	public:
		Node<T> *tail;
		CList(){
			tail = nullptr;
		}
		bool isEmpty(void){
			return tail == nullptr;
		}
		void addToHead(T el){
			if(isEmpty()){
				tail = new Node<T>(el);
				tail -> next = tail;
			}
			else{
				//Node<T> *newNode = new Node<T>(el, tail -> next);
				tail -> next = new Node<T>(el, tail -> next);
				//tail = tail -> next;
			}
		}
		
		void display(void){
			Node<T> *start = tail -> next;
			Node<T> *temp = tail->next;
			do{
				cout<<temp -> data<<" << ";
				temp = temp -> next;
			}while( temp != start);
			
		}
};

int main(void){
	CList <int>clst;
	int temp, el;
	while(true){
		cout<<"\nEnter:\t1.Add to Head\n\t2.Add to Tail\n\t5.Display\n\t8.Exit:\t";
		cin>>temp;
		switch(temp){
			case 1:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				clst.addToHead(el);
				break;
			}
			case 5:{
				clst.display();
				break;
			}
			case 8:	return 0;
		}
	}
}
