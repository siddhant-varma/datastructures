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
		Node(T el, Node* ptr = nullptr){
			data = el;
			next = ptr;
		}
};

template <class T>
class OLL{
	public:
		Node<T> *head, *tail;
		OLL(){
			head = tail = nullptr;
		}
		void insert(T el);
		void display(void){
			cout<<endl;
			for(Node<T> *temp=head; temp!=nullptr; temp = temp->next){
				cout<<temp->data<<"\t";
			}
			cout<<endl;
			return;
		}
};

template<class T> void OLL<T>::insert(T el){
	if(head == nullptr){
		head = tail = new Node<T>(el);
	}
	else{
		Node<T> *prev, *temp = head;
		prev = temp;
		for(;temp != nullptr; temp = temp->next){
			if(el > temp->data)
				prev = temp;
			else
				break;
		}
		if(head->data > el){
			head = new Node<T>(el, head);
			cout<<"\n"<<el<<" added before "<<prev->data;
		}
		else{
			cout<<"\n"<<el<<" added after "<<prev->data;
			prev->next = new Node<T>(el, prev->next);	
		}
	}
}

int main(void){
	OLL<int> olst;
	olst.insert(5);
	olst.insert(3);
	olst.insert(7);
	olst.insert(27);
	olst.insert(14);
	olst.insert(47);
	olst.insert(10);
	olst.insert(1);
	
	olst.display();
	
	return 0;
}
