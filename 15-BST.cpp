#include <iostream>
#include <queue>
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
		void preOrder(Node<T> *temp){
			if(temp == nullptr)
				return;
			else{
				cout<<temp->key<<"\t";
				preOrder(temp->left);
				preOrder(temp->right);
			}
		}
		void inOrder(Node<T> *temp){
			if(temp == nullptr)
				return;
			else{
				inOrder(temp->left);
				cout<<temp->key<<"\t";
				inOrder(temp->right);
			}
		}
		void postOrder(Node<T> *temp){
			if(temp == nullptr)
				return;
			else{
				postOrder(temp->left);
				postOrder(temp->right);
				cout<<temp->key<<"\t";
			}
		}
		void level(Node<T> *temp){
			if(temp == nullptr)
				return;
			else{
				queue<Node<T>*> q;
				q.push(temp);
				while(! q.empty()){
					Node<T> *node = q.front();
					q.pop();
					cout<<node->key<<"\t";
					if(node->left != nullptr)
						q.push(node->left);
					if(node->right != nullptr)
						q.push(node->right);
				}
			}
		}
};

int main(void){
	BST <int>tree;
	int temp, el;
	while(true){
		cout<<"\nEnter:\t1.Insert Element\n\t2.Search\n\t3.Pre Order traversal\n\t4.In Order traversal\n\t5.Post Order";
		cout<<" traversal\n\t6.Breadth First Traversal\n\t7.\n\t8.Exit:\t";
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
			case 3:	tree.preOrder(tree.root);	break;
			case 4:	tree.inOrder(tree.root);	break;
			case 5:	tree.postOrder(tree.root);	break;
			case 6:	tree.level(tree.root);	break;
			case 8:	return 0;
		}
	}
}
