#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
	T data;
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
			Node <T>* temp;
			cout<<endl;
			for(temp = head; temp != 0; temp = temp -> next)
				cout<<temp -> data<<" << ";
			cout<<endl;
		}
};

template <class T>
class Queue{
	public:
		List<int> lst;
		void enqueue(T el){
			lst.addToTail(el);
		}
		T dequeue(void){
			T el = lst.delHead();
			if(el != -1){
				cout<<endl<<el<<" dequeued\n";
			}
			else{
				cout<<"\nQueue is Empty...\n";
			}
			return el;
		}
};

int main(void){
	Queue<int> q;
	int temp, el;
	while(true){
		cout<<"\nEnter\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit:\t";
		cin>>temp;
		switch(temp){
			case 1:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				q.enqueue(el);
				break;
			}
			case 2:{
				q.dequeue();
				break;
			}
			case 3:	q.lst.display();
					break;
			case 4:	return 0;
		}
	}
	return 0;
}
