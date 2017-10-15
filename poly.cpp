#include<iostream>

using namespace std;


struct poly{
	int n;
	
	struct term{
		int coeff;
		//int power;
	} *terms;
	
	poly(int a){
		n=a;
		terms = new term[n];
	}
};

void print(poly &);

int main(void){
	int temp;
	cout<<"Enter Order of Polynomial P1: ";
	cin>>temp;
	poly p1(temp);
	cout<<"Enter Order of Polynomial P2: ";
	cin>>temp;
	poly p2(temp);
	
	//Inputting values of Polynomial P1
	for(int i=0;i<=p1.n;i++){
		/*cout<<"Enter power of "<<i+1<<" term of p1: ";
		cin>>p1.terms[i].power;*/
		cout<<"Enter coeff for X^"<<i<<" term of p1: ";
		cin>>p1.terms[i].coeff;
	}
	
	
	//Inputting values of Polynomial P2
	for(int i=0;i<=p2.n;i++){
		/*cout<<"Enter power of "<<i+1<<" term of p2: ";
		cin>>p2.terms[i].power;*/
		cout<<"Enter coeff for X^"<<i<<" term of p2: ";
		cin>>p2.terms[i].coeff;
	}
	
	//Outputting values of Polynomial P1
	cout<<"\nPolynomial P1 is\n\t";
	print(p1);
	
	//Outputting values of Polynomial P2
	cout<<"\nPolynomial P2 is\n\t";
	print(p2);
	
	temp=(p1.n<p2.n)?p2.n:p1.n;
	poly p3(temp);
	
	/*
	int k=0;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			
			//If deg is same then adds coeff.
			if (p1.terms[i].power == p2.terms[j].power){
				p3.terms[k].coeff=p1.terms[i].coeff+p2.terms[j].coeff;
				k++;
				cout<<"\n\tEquals\ti="<<i<<"\tj="<<j;
				goto ter; //jumps out of loop
				
			}
			
			//If deg of p1 term is lesser than p2 term
			else if (p1.terms[i].power <= p2.terms[j].power){
				if (j == (b-1)){
					p3.terms[k].coeff=p2.terms[j].coeff;
					k++;
					cout<<"\n\tLesser\ti="<<i<<"\tj="<<j;
				}
				else
					goto inner;
					
				
			}
			
			//If deg of p1 term is greater than p2 term
			else{
				if (j == (b-1)){
					p3.terms[k].coeff=p1.terms[i].coeff;
					k++;
					cout<<"\n\tGreater\ti="<<i<<"\tj="<<j;
				}				
				else
					goto inner;
				
				
			}
			inner:
				cout<<"";
			
		}
		ter:
			cout<<"";
	}
	*/
	
	for(int i=0, j=0, k=0 ;i<=p1.n , j<=p2.n , k<=p3.n ;i++ , j++, k++){
		p3.terms[k].coeff = 0;
		p3.terms[k].coeff += p1.terms[i].coeff;
		p3.terms[k].coeff += p2.terms[j].coeff;
	}
	
	//Outputting values of Polynomial P3
	cout<<"\nPolynomial P3 = P1 + P2 is\n\t";
	print(p3);
	
	delete p1.terms;
	delete p2.terms;
	delete p3.terms;
	
	return 0;
	
}

void print(poly &p){
	for(int i=0;i<=p.n;i++){
		cout<<p.terms[i].coeff<<" X^"<<i;
		if (i != p.n ){
			cout<<" + ";
		}
	}
}
