#include<iostream>

#define MAX 16

using namespace std;

struct queue{
	int front, rear, size;
	int *arr;
	bool isFull(void){
		return front==0 && rear==size-1;
	}
	bool isEmpty(void){
		return front == -1 || front == rear + 1;	//	front < 0 || front > rear
	}
	void enqueue(int);
	int dequeue(void);
};

void create(queue &q, int siz){
	q.front= 0;
	q.rear= -1;
	q.size = siz;
	q.arr = new int[siz];
}

void queue::enqueue(int element){
	if(!isFull()){
		arr[++rear] = element;
	}
	else
		cout<<"\nQueue Full.";
}

int queue::dequeue(void){
	int tem;
	if(!isEmpty())
		tem=arr[front++];
	else{
		cout<<"\nQueue Empty...";
		return -1;
	}
	return tem;
}

int main(void){
	int s,t,ch;
	char f;
	queue q;
	cout<<"Enter size of queue: ";
	cin>>s;
	create(q,s);
	/*for(int i=0;i<s;i++){
		cout<<"Enter "<<i+1<<" element in queue: ";
		cin>>t;
		q.enqueue(t);
	}*/
	
	/*cout<<"\nEntered Queue is: ";
	for(int i=0;i<s;i++){
		cout<<q.arr[i]<<"\t";
	}*/
	
	do{
		cout<<"\nPress:\n1)\tFor Insertion of Element\n2)\tFor Deletion of Element\n3)\tFor printing queue:";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\nEnter Element: ";
					cin>>t;
					q.enqueue(t);
					break;
			case 2: cout<<"\nDeleted Element is :\t"<<q.dequeue();
					break;
			case 3: for(int i=q.front;i<=q.rear;i++){
					cout<<q.arr[i]<<"\t";
					}
					break;
		}
		cout<<"\nEnter X to exit or press any key to continue: ";
		cin>>f;
		
	}while(f != 'X' && f != 'x');
	delete q.arr;
	return 0;
}
