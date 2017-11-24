#include <iostream>

using namespace std;

void MustBeZero(){
	//cout<<"\n\tMust Be Zero...\n";
	return;
}

void OutOfBounds(){
	//cout<<"\n\tOut Of Bound...\n";
	return;
}

template <class T>
class SpecialMatrix{
	private:
		int n;
		T *arr;
	public:
		int choice;
		SpecialMatrix(int size, int ch){
			choice = ch;
			n = size;
			switch(choice){
				case 1:
					arr = new T[n];
					break;
				case 2:
					arr = new T[3*n - 2];
					break;
				case 3:
					arr= new T[n * (n +1) / 2];
					break;
				case 4:
					arr= new T[n * (n +1) / 2];
					break;
			}
		}
		
		~SpecialMatrix(){
			delete [] arr;
		}
		
		void store(T x, int i, int j){
			
			if(i < 1 || j < 1 || i > n || j > n)
				OutOfBounds();
				
			if(i != j && x != 0)
				MustBeZero();
				
			switch(choice){
				case 1:		//Diagonal
					if(i == j)
						arr[i - 1] = x;
					break;
				case 2:		//Tridiagonal
					switch(i - j){
						case 1:
							arr[i - 2] = x;
							break;
						case 0:
							arr[n + i - 2] = x;
							break;
						case -1:
							arr[2 * n + i - 2] = x;
							break;
						default:
							if(x != 0)
								MustBeZero();
							break;
					}
				case 3:		//Lower Triangle
					if(i >= j) 
						arr[i * (i-1) / 2 + j - 1] = x;
					else if (x != 0)
						MustBeZero();
					break;
				
				case 4:		//Upper Triangle
					if(i <= j)
						arr[j * (j-1) / 2 + i - 1] = x;
					else if (x != 0)
						MustBeZero();
					break;
			}
		}
				
		T retrieve(int i, int j){
			
			if(i < 1 || j < 1 || i > n || j > n)
			OutOfBounds();
			
			switch(choice){
				case 1:
					if(i == j)
						return arr[i - 1];
					else return 0;
					break;
				case 2:
					switch(i - j){
						case 1:
							return arr[i - 2];
							break;
						case 0:
							return arr[n + i - 2];
							break;
						case -1:
							return arr[n * 2 + i - 2];
							break;
						default:
							return 0;
					}
					break;
					case 3:
						if(i >= j)
							return arr[i * (i-1) / 2 + j - 1];
						else return 0;
						break;
					case 4:
						if(i <= j)
							return arr[j * (j-1)/2 + i - 1];
						else return 0;
						break;
			}
		}
};

int main(void){
	int temp, s;
	cout<<"Enter Size of Matrix:\t";
	cin>>s;
	cout<<"\n\nChoose:\t1.Diagonal Matrix\n\t2.Tridiagonal Matrix\n\t3.Lower Triangle\n\t4.Upper Triangle\n\t:";
	cin>>temp;
	SpecialMatrix<int> matrix(s, temp);
	for(int i = 1; i <= s; i++){
		for(int j = 1; j <= s; j++){
			cout<<"Element at A["<<i-1<<"]["<<j-1<<"]\t:";
			cin>>temp;
			matrix.store(temp, i, j);
		}
	}
	
	for(int i = 1; i <= s; i++){
		cout<<endl;
		for(int j = 1; j <= s; j++){
			cout<<matrix.retrieve(i, j)<<"\t";
		}
	}
}
