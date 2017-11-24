#include <iostream>

using namespace std;

template <class T>
class Queue{
	int size, front, rear;
	T *arr;
	public:
		Queue(int s){
			size = s;
			front = rear = -1;
			arr = new T[size];
		}
		
		bool isEmpty(void){
			return (front == rear && rear == -1);
		}
		
		bool isFull(void){
			return ((rear + 1)%size == front);
		}
		
		void enqueue(T el){
			if(isFull()){
				cout<<"\nQueue is Full...\n";
			}
			else if(isEmpty()){
				front = rear = 0;
				arr[front] = el;
			}
			else{
				rear = (rear + 1) % size;
				arr[rear] = el;
			}
		}
		
		T dequeue(void){
			int temp = front;
			if(isEmpty()){
				cout<<"\nQueue is empty...";
				return -1;
			}
			else if(front == rear){
				front = rear = -1;
			}
			else{
				front = (front + 1) % size;
			}
			return arr[temp];
		}
};

int main(void){
	int temp;
	cout<<"Enter size of Queue:\t";
	cin>>temp;
	Queue <int>q(temp);
	while(true){
		cout<<"\nEnter\t1.Enqueue\n\t2.Dequeue\n\t3.Exit\t:";
		cin>>temp;
		switch(temp){
			case 1:{
				int t;
				cout<<"Enter element:\t";
				cin>>t;
				q.enqueue(t);
				break;
			}
			case 2:{
				cout<<endl<<q.dequeue()<<" dequeued.";
				break;
			}
			case 3:
				return 0;
		}
	}
}
