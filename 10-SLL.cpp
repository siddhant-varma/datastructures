#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		
		T data;
		Node *next;
		Node(){
			next = 0;
		}
		Node(T el, Node *ptr = 0){
			data = el;
			next = ptr;
		}
};

template <class T>
class List{
	Node <T>*head, *tail;
	
	public:
		List(){
			head = tail = 0;
		}
		
		int isEmpty(){
			return head==0;
		}
		
		void addToHead(T el){
			Node <T>*temp = new Node<T>(el);
			if(head == tail && head == 0){
				head = tail = temp;
			}
			else{
				temp -> next = head;
				head = temp;
			}
		}
		
		void addToTail(T el){
			if(!isEmpty()){
				tail -> next = new Node<T>(el);
				tail = tail -> next;
			}
			else{
				head = tail = new Node<T>(el);
			}
		}
		T delHead(){
			if(!isEmpty()){
				T el = head -> data;
				Node <T> *temp = head;
				if(head == tail){
					head = tail = 0;
					delete temp;
				}
				else{
					head = head -> next;
					delete temp;
				}
				return el;
			}
			else{
				cout<<"\nList is Empty...\n";
				return -1;
			}		
		}
		
		T delTail(){
			if(!isEmpty()){
				T el = tail -> data;
				Node <T>*temp = tail;
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
			else{
				cout<<"\nList is Empty...\n";
				return -1;
			}
		}
		
		void display(void){
			Node <T> *temp;
			cout<<endl;
			for(temp = head; temp!= 0; temp = temp -> next){
				cout<<temp -> data <<" >> ";
			}
			return;
		}
};

int main(void){
	List <int> sll; /*
	sll.addToHead(5);
	sll.addToHead(8);
	sll.addToTail(3);
	sll.display();
	sll.addToHead(1);
	sll.display();
	sll.delHead();
	sll.delTail();
	sll.display();*/
	int ch, temp;
	while(true){	
		cout<<"Enter:\t1.Add to Head\n\t2.Add to Tail\n\t3.Delete From Head\n\t4.Delete From Tail\n\t5.Display\n\t6.Exit:\t";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"\n\nEnter Element:\t";
				cin>>temp;
				sll.addToHead(temp);
				break;
			}
			case 2:{
				cout<<"\nEnter Element:\t";
				cin>>temp;
				sll.addToTail(temp);
				break;
			}
			case 3:{
				cout<<cout<<sll.delHead()<<" deleted from head.\n";
				break;
			}
			case 4:{
				cout<<cout<<sll.delTail()<<" deleted from tail.\n";
				break;
			}
			case 5:{
				sll.display();
				break;
			}
			case 6:
				return 0;
		}
	}
	return 0;
}
