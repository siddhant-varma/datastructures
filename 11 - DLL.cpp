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
		void addToHead(T el){
			
		}
		void addtoTail(T el){
			
		}
		T delHead(void){
			
		}
		T delTail(void){
			
		}
		void display(void){
			
		}
		
};

int main(void){
	
	return 0;
}
