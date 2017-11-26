#include <iostream>

using namespace std;

template <class T>
class Node{
	public:
		T key;
		Node *left, *right;
		Node(){
			left = right = nullptr;
		}
		Node(T el, Node *l = nullptr, Node *r = nullptr){
			key = el;
			left = l;
			right = r;
		}
};

template <class T>
class BST{
	public:
		Node<T> *root;
		BST(){
			root = nullptr;
		}
		bool isEmpty(void){
			return root == nullptr;
		}
		void insert(T el){
			if(isEmpty()){
				root = new Node<T>(el);
			}
			else{
				Node<T> *temp = root, *prev;
				while(temp != nullptr){
					prev = temp;
					if(el < temp->key)
						temp = temp->left;
					else	temp = temp->right;
				}
				if(el < prev->key){
					cout<<"\nAdded to left of "<<prev->key<<endl;
					prev->left = new Node<T>(el);
				}
				else{
					cout<<"\nAdded to right of "<<prev->key<<endl;
					prev->right = new Node<T>(el);
				}
			}
		}
		bool search(Node<T> *temp, T target){
			/*if(temp->key == target){
				return true;
			}
			else if(temp->key < target){
				return search(temp->right, target);				
			}
			else if(temp->key > target)	return search(temp->left, target);
			else	return false; 	*/
			while(temp != nullptr){
				if(temp->key == target)
					return true;
				else if(target < temp->key)
					temp = temp->left;
				else
					temp = temp->right;
			}
			return false;
			
		}
};

int main(void){
	BST <int>tree;
	int temp, el;
	while(true){
		cout<<"\nEnter:\t1.Insert Element\n\t2.Search\n\t8.Exit:\t";
		cin>>temp;
		switch(temp){
			case 1:{
				cout<<"\nEnter Element:\t";
				cin>>el;
				tree.insert(el);
				break;
			}
			case 2:{
				cout<<"\nEnter Target:\t";
				cin>>el;
				if(tree.search(tree.root, el))
					cout<<"\nTarget in Tree.\n";
				else	cout<<"\nTarget not in Tree...\n";
				break;
			}
			case 8:	return 0;
		}
	}
}
