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
		Node(T el){
			data = el;
			next = prev = nullptr;
		}
};

template <class T>
class DList{
	Node <T> *head, *tail;
	public:
		Dlist(){
			head = tail = nullptr;
		}
		bool isEmpty(void){
			return head == nullptr;
		}
		void addToHead(T el){
			Node <T> *newNode = new Node<T>(el);
			cout<<"here";
			if(head == nullptr){
				head = tail = new Node<T>(el);
			cout<<"here after if";
			}
			else{
				head -> prev = newNode;
				newNode -> next = head;
				head = newNode;
			}
			return;
		}
		void addToTail(T el){
			Node<T> *newNode = new Node<T>(el);
			if(head == nullptr){
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
				Node<T> *oldNode = head;
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
	DList <int> dlst;
	int temp, el;
	while(true){
		cout<<"Enter\t1.Add to Head\n\t2.Add to Tail\n\t3.Delete from Head\n\t4.Delete from Tail\n\t8.Exit:\t";
		cin>>temp;
		switch(temp){
			case 1:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				dlst.addToHead(el);
				break;
			}
			case 2:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				dlst.addToTail(el);
				break;
			}
			case 3:{
				el = dlst.delHead();
				if(el != -1){
					cout<<endl<<el<<" dequeued";
				}
				break;
			}
			case 4:{
				el = dlst.delTail();
				if(el != -1){
					cout<<endl<<el<<" dequeued";
				}
				break;
			}
			case 5:	dlst.display();
					break;
			case 8:	return 0;
		}
	}
	return 0;
}
