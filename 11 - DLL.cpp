#include <iostream>

using namespace std;

template<class T>
class Node{
	public:
		T data;
		Node <T>*next, *prev;
		Node(){
			next = prev = nullptr;
		}
		Node(T el = 0){
			data = el;
			Node();
		}
};

template <class T>
class DList{
	public:
		Node <T> *head, *tail;
		Dlist(){
			head = tail = nullptr;
		}
		bool isEmpty(void){
			return head == nullptr;
		}
		void addToHead(T el){
			Node <T> *newNode = new Node<T>(el);
			if(head == 0){
				head = tail = newNode;
			}
			else{
				head -> prev = newNode;
				newNode -> next = head;
				head = newNode;
			}
			return;
		}
		void addtoTail(T el){
			Node<T> *newNode = new Node<T>(el);
			if(head == 0){
				head = tail = newNode;
			}
			else{
				tail -> next = newNode;
				newNode -> prev = tail;
				tail = newNode;
			}
			return;
		}
		T delHead(void){
			if(!isEmpty()){	
				T el = head -> data;
				Node<t> *oldNode = head;
				if(head == tail){
					head = tail = nullptr;
				}
				else{
					head = head -> next;
					head -> prev = nullptr;
				}
				delete oldNode;
				return el;
			}
			else{
				cout<<"\nList is empty...\n";
				return -1;
			}
		}
		T delTail(void){
			if(!isEmpty()){
				T el = tail -> data;
				Node <T> *oldNode = tail;
				if(head == tail){
					head = tail = nullptr;
				}
				else{
					tail = tail -> prev;
					tail -> next = nullptr;
				}
				delete oldNode;
				return el;
			}
			else{
				cout<<"\nList is empty...";
				return -1;
			}
		}
		void display(void){
			Node <T> *temp;
			cout<<endl;
			for(temp = head; temp != nullptr; temp = temp -> next)
				cout<<temp -> data << " << ";
			
			cout<<endl;
			return;
		}
};

int main(void){
	
	return 0;
}
