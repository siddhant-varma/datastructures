#include<iostream>

using namespace std;

struct poly{
	int n;
	
	struct term{
		int coeff;
		int power;
	} *terms;
	
	poly(int a){
		n=a;
		terms = new term[n];
	}
};

void print(poly &);

int main(void){
	int temp;
	cout<<"Enter Number of terms in Polynomial P1: ";
	cin>>temp;
	poly p1(temp);
	cout<<"Enter Number of terms in Polynomial P2: ";
	cin>>temp;
	poly p2(temp);
	
	//Inputting values of Polynomial P1
	for(int i=0;i<p1.n;i++){
		cout<<"Enter power of "<<i+1<<" term of p1: ";
		cin>>p1.terms[i].power;
		cout<<"Enter coeff for X^"<<p1.terms[i].power<<" term of p1: ";
		cin>>p1.terms[i].coeff;
	}
	
	
	//Inputting values of Polynomial P2
	for(int i=0;i<p2.n;i++){
		cout<<"Enter power of "<<i+1<<" term of p2: ";
		cin>>p2.terms[i].power;
		cout<<"Enter coeff for X^"<<p2.terms[i].power<<" term of p2: ";
		cin>>p2.terms[i].coeff;
	}
	
	//Outputting values of Polynomial P1
	cout<<"\nPolynomial P1 is\n\t";
	print(p1);
	
	//Outputting values of Polynomial P2
	cout<<"\nPolynomial P2 is\n\t";
	print(p2);
	
	//temp=(p1.n<p2.n)?p2.n:p1.n;
	temp = p1.n+p2.n;
	poly p3(temp);
	
	//initializing counters for all 3 polynomials
	int k=0,i=0,j=0;
	while(i!=(p1.n) && j!=(p2.n+1)){
			
			//If deg is same then adds coeff.
			if (p1.terms[i].power == p2.terms[j].power){		
				p3.terms[k].power = p3.terms[k].power;
				p3.terms[k++].coeff=p1.terms[i++].coeff+p2.terms[j++].coeff;
			}
			
			//If deg is not equal
			else{
				
				//If deg of p1 term is lesser than p2 term
				if (p1.terms[i].power <= p2.terms[j].power){
						p3.terms[k++]=p1.terms[i++];
					}
					
			//If deg of p1 term is greater than p2 term
			else {
				if(j != p2.n){					
					p3.terms[k++]=p2.terms[j++];
				}
				else{
					p3.terms[k++]=p1.terms[i++];
				}
			}
		}			
	}

	//inserting left over terms of p2 in p3, if p1 is exhausted
	if(i==p1.n){
			while(j<p2.n){
				p3.terms[k++]=p2.terms[j++];
			}
	}
	
	//inserting left over terms of p1 in p3, if p2 is exhausted
	if(j==p2.n){
		while(i<p1.n){
			p3.terms[k++]=p1.terms[i++];
		}
	}
	
	//finalising len of p3 to be total num of insertions
	p3.n = k;
	//Outputting values of Polynomial P3
	cout<<"\nPolynomial P3 = P1 + P2 is\n\t";
	print(p3);
	
	delete p1.terms;
	delete p2.terms;
	delete p3.terms;
	
	return 0;
	
}

void print(poly &p){
	for(int i=0;i<p.n;i++){
		cout<<p.terms[i].coeff<<" X^"<<p.terms[i].power;
		if (i != (p.n - 1) ){
			cout<<" + ";
		}
	}
}
