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
};

int main(void){
	int temp;
	cout<<"Enter size of list: ";
	cin>>temp;
	sort<int> array(temp);
	array.initialize();
	array.show();
	
	return 0;
}
