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
		Node(T el, Node ptr = nullptr){
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
				tail -> next = new Node<T>(el, tail -> next);
				tail = tail -> next;
			}
		}
};
