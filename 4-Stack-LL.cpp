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

tmeplate<class T>
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
				Node<T> *temp;
				for(temp = head; temp -> next != tail; temp = temp -> next);
				T el = tail -> data;
				tail = temp;
				delete temp;
				return el;
			}
			return -1;
		}
};

int main(void){
	
	return 0;
}
