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
			cout<<endl;
			return;
		}
		
		bool search(T el){
			Node <T> *temp;
			for(temp = head; temp != 0; temp = temp -> next){
				if(temp -> data == el)
					return true;
			}
			return false;
		}
		
		void reverse(void){
			Node<T> *tempH = head, *i;
			tail = head = 0;
			for(i = tempH;i != 0; i = i -> next){
				addToHead(i -> data);
			}
		}
		
		void sort(void);
};

template<class T> void List<T>::sort(void){
	Node<T> *temp = head, *tempI;
	for(temp = head; temp->next != nullptr; temp = temp->next){
		//cout<<"\ntemp = "<<temp->data;
		for(tempI = temp->next; tempI != nullptr; tempI = tempI->next){
			//cout<<"\ntempI = "<<tempI->data;
			if(tempI->data < temp->data){
				//cout<<"\n\tSwapping "<< temp->data << "\t" << tempI->data;
				swap(temp->data, tempI->data);
			}
			/*cout<<endl;
			display();*/
		}
	}
}


int main(void){
	List <int> sll;
	int ch, temp;
	sll.addToHead(5);
	sll.addToHead(59);
	sll.addToTail(2);
	sll.addToHead(9);
	sll.display();
	sll.sort();
	sll.display();
	/*
	while(true){	
		cout<<"Enter:\t1.Add to Head\n\t2.Add to Tail\n\t3.Delete From Head\n\t4.Delete From Tail\n\t5.Display\n\t";
		cout<<"6.Reverse\n\t7.Search\n\t8.Sort\n\t9.Exit:\t";
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
			case 6:{
				sll.reverse();
				break;
			}
			case 7:{
				cout<<"\nEnter target:\t";
				cin>>temp;
				if(sll.search(temp)){
					cout<<"\n\tElement Found...\n";
				}
				else{
					cout<<"\n\tElement Not Found...\n";
				}
				break;
			}
			case 8:{
				sll.sort();
				break;
			}
			case 9:
				return 0;
		}
	}*/
	return 0;
}
