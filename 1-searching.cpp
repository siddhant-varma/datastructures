#include <iostream>

using namespace std;

template<class t>
class list{
	private:
		t *buffer;
		int size;
	public:
		list(int s){
			size = s;
			buffer = new t[size];
		}
		void initialize(void){
			cout<<"";
			for(int i = 0; i < size; i++){
				cout<<"\tEnter element at position "<<i+1<<":\t";
				cin>>buffer[i];
			}
		}
		int linearSearch(t tar){
			for(int i = 0; i < size; i++){
				if(tar == buffer[i])
					return (i+1);
			}
			return -1;
		}
		int binarySearch(t tar){
			int beg=0, last=size-1, mid;
			while(beg<=last){
				mid = (beg+last)/2;
				if(buffer[mid] == tar)
					return mid+1;
				
				if(buffer[mid] > tar)
					last = mid - 1;
				else if(buffer[mid] < tar)
					beg = mid + 1;
				else if(beg > last)
					return -1;
			}
		}
		
};

int main(void){
	int temp, pos=-1, target;
	cout<<"Enter size of list: ";
	cin>>temp;
	list<int> array(temp);
	array.initialize();
	cout<<"\nEnter element to be found:\t";
	cin>>target;
	cout<<"\nEnter:\t1. Linear Search\t2.Binary Search:\t";
	cin>>temp;
	switch(temp){
		case 1:
			pos = array.linearSearch(target);
			break;
		case 2:
			pos = array.binarySearch(target);
			break;
		default:
			cout<<"Wrong Choice entered...";
			break;
	}
	if(pos<0)
		cout<<"\n\t\tElement not found.";
	else
		cout<<"\n\t\tElement found at position "<<pos;
	
	return 0;
}
