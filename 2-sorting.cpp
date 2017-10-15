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
				cout<<"\tEnter element at "<<i+1;
				cin>>list[i];
			}
		}
};

int main(void){
	int temp;
	cout<<"Enter size of list: ";
	cin>>temp;
	sort<int> array(temp);
	
	return 0;
}
