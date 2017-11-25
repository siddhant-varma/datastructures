#include <iostream>

using namespace std;

template <class T>
class Node{
	T data;
	public:
		Node<T> *next;
		Node(){
			next = 0;
		}
		Node(T el, Node<T> *ptr = 0){
			data = el;
			next = ptr;
		}
};

template <class T>
class List{
	public:
		Node <T>*head, *tail;
		List(){
			head = tail = 0;
		}
		bool isEmpty(void){
			return head == 0;
		}
		void addToTail(T el){
			if(isEmpty()){
				head = tail = new Node<T>(el);
			}
			else{
				tail -> next = new Node<T>(el);
				tail = tail -> next;
			}
		}
		T delHead(void){
			if(!isEmpty()){
				T el = head -> data;
				if(head == tail){
					delete head;
					head = tail = 0;
				}
				else{
					head = head -> next;
				}
				return el;
			}
			else{
				cout<<"\nQueue is Empty...\n";
				return -1;
			}
		}
		void display(void){
			
		}
};
