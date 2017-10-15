#include<iostream>

using namespace std;

template<class t>
class sort{
	private:
		t *list;
		int size;
	public:
		sort(int a){
			size = a;
			list = new t[size];
		}
		void initialize(void){
			cout<<"";
			for(int i = 0; i < size; i++){
				cout<<"\tEnter element at position "<<i+1<<":\t";
				cin>>list[i];
			}
		}
		void show(void){
			cout<<"\nList is:";
			for(int i = 0; i < size; i++){
				cout<<"\t"<<list[i];
			}
		}
		
		void bubbleSort(void){
			t hold;
			int i, j;
			bool switched = true;
			
			for(i = 0; i < size - 1 && switched; i++){
				switched = false;
				for(j = 0; j < size - i - 1; j++){
					if(list[j] > list[j+1]){
						hold = list[j+1];
						list[j+1] = list[j];
						list[j] = hold;
						switched = true;
					}
				}
			}
		}

};

int main(void){
	int temp;
	cout<<"Enter size of list: ";
	cin>>temp;
	sort<int> array(temp);
	array.initialize();
	array.show();
	cout<<"\nEnter:\t1. Bubble Sort:\t";
	cin>>temp;
	switch(temp){
		case 1:
			array.bubbleSort();
			break;
		default:
			cout<<"Wrong Choice entered...";
			break;
	}
	array.show();
	
	return 0;
}
