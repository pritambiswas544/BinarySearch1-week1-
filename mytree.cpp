/*implementing binary search tree in c++ and using insert();display() and search() function*/


#include<iostream>
using namespace std;

				//creating the node class
	class node{
	public:
		int data;
				//ptr to left and right
		node * left;
		node * right;
		node * parent;
				//constructor
	node(int value){
		left=NULL;
		right=NULL;
		parent=NULL;
		data=value;
	}
	};
				//creating class of the tree
	class BiST{
	public:
				//ptr to root
		node * root;
				//constructor
	BiST(){
		root=NULL;
		
	}
				
				//inserting recursively
				//first creating the main function so that it can be called recursively
	void insertH(node * curr,int value){
				//base casee
				//inserting when tree is empty
	if(curr==NULL){
		curr=new node(value);
				//updating the root
	if(root==NULL)
		root=curr;
	}
				//if value is less than the data of curr
	else if(value<curr->data){
				//linking the curr left
		if(curr->left==NULL){curr->left=new node(value);
		curr->left->parent=curr;}
				//if curr is not null the go left recursively
		else{
			insertH(curr->left,value);
		}
	}
				//if value is more than data of curr
	else{
				//linking the edge of curr right
		if(curr->right==NULL){curr->right=new node(value);
		curr->right->parent=curr;}
				//if curr right is not null then go right recursively
		else{
			insertH(curr->right,value);
		}
	}
	}
				//now writing the main insert fucnction using the insertH() recursively
	void insert(int value){
		insertH(root,value);
	}
				//finding the min within the node keeping the inserted value as node
	node* findmin(node * curr){
				//exit condition 
		if(curr->left==NULL){
			
			return curr;
				
		}
				//else keep going to left
		else findmin(curr->left);
		
				
		
	}
				//main minimum finding position and storing it to an int 
	
	int find(int dat){
		node*m=searchH(dat);
		
		node *x=findmin(m);
		int y=x->data;
		return y;
	}
			
				//displaying the linked list in 2d
	void display2dH(node * curr,int space){
				//base condition
		if(curr==NULL){return;}
				//increase the space,we intend to print each node with 5 spaces apart
		space=space+5;
				//process the right child first
		display2dH(curr->right,space);
		cout<<endl;
				//loop for increasing the space for each levels 
		for(int i=5;i<space;i++){
			cout<<" ";
		}
				//printing the node value
		cout<<curr->data<<endl;
				//process left child
		display2dH(curr->left,space);
	}
				//main display2d function using previous function
	void display2d(){
		cout<<"\n************************************"<<endl;
				//calling the display2dH function
		display2dH(root,0);
		cout<<"************************************"<<endl;
	}
							
				//displaying the node inOrder
	

				//writting the function that will be called recursively
	void displayH(node * curr){
				//displaying the left side childerns first
				
				//exit condition
		if(curr==NULL){return;}
				//for left side sub trees
		displayH(curr->left);
				//printing the elements only when the ptr points to null
		cout<<curr->data<<"->";
				//for right side childern
		displayH(curr->right);
	}
					
				//real display function
	void display(){
		displayH(root);
		}
				
				//finding an element within the binary tree
				//main searchH function usinf the search function recursively

		
	node* searchH (int value){
		search(root,value);
		}
				//fucntion that will be called recursively
	node* search(node * curr,int value){
				//exit condition
		if(curr==NULL || curr->data==value)return curr;
		
				//if value is less than root search left
		else if(value<curr->data) return search(curr->left,value);
				//else search right
		else return search(curr->right,value);
		}
				//deleting a node from bst
	void deleteH(node * curr,int value){
		node * temp=searchH(value);
				//if last node to be deleted
		if(temp->left==NULL && temp->right==NULL){
				//if any left node which is a left child to be deleted
			if(temp->data<temp->parent->data){
				temp->parent->left=NULL;
				delete temp;
		}
				//if the leaf node is a right child
			else{
				temp->parent->right=NULL;
				delete temp;
		}
		}
	
				//one child
				//if there is left child only
		else if(temp->right==NULL){
			temp->parent->left=temp->left;
			delete temp;
		}
				//if there is right child only
		else if(temp->left==NULL){
			temp->parent->right=temp->right;
			delete temp;
		}
				//if we want to delete root
		else if(temp==root){
			node*temp1=temp->right;
			int z=temp->right->data;
			int r=find(z);
			temp->data=r;
			if(temp1->left==NULL){
				temp1->parent->right=temp1->right;
				temp1->right->parent=temp1->parent;
			}
			else if(temp1->right==NULL){
				temp1->parent->left=temp1->left;
				temp1->left->parent=temp1->parent;
			}
			else{
			
			
			temp1->left=NULL;}
		}
				//if there is 2 children
		else{
				//replace with the min of right subtree
				//or max of left subtree
				//if a node of root's right is to be deleted
			
			if(temp->parent->data<temp->data){
				int m=temp->left->data;
				int a=find(m);
				temp->data=a;
			
				temp->left=NULL;
				delete temp->left;
			}
				//if a node of root's left to be deleted
			else{
				int n=temp->right->data;
				int b=find(n);
				temp->data=b;
				
				temp->right=NULL;
				delete temp->right;
			}
				
		}
	}
				//main delete function
	void delat(int value){
		deleteH(root,value);
	}
				//swapping a value 
	
	void parswap(int value){
		node * temp=searchH(value);
				//the function will only work when this pointer has only 1 child
				//if the value to be swapped is at the left side of root
	if(temp->data<root->data){
				//if the only child is right child
		if(temp->left==NULL){
				//adjusting the parent pointer
			temp->right->parent=temp->parent;
				//adjusting the child pointer
			temp->parent->left=temp->right;
			delete temp;
		}
				//if the only child is left child
		else if(temp->right==NULL){
				//adjusting the parent pointer
			temp->left->parent=temp->parent;
				//adjusting the child ptr
			temp->parent->left=temp->left;
			delete temp;
		}
		else{return;}
	}
				//if value to be swapped is at the right side
	else{
				//if only child is right
		if(temp->left==NULL){
				//adjusting the parent ptr
			temp->right->parent=temp->parent;
				//adjusting the child ptr
			temp->parent->right=temp->right;
			delete temp;
		}
				//if only child is left
		else if(temp->right==NULL){
				//adjusting the parent ptr
			temp->left->parent=temp->parent;
				//adjusting the child ptr
			temp->parent->right=temp->left;
			delete temp;
		}
		else{return;}
	}
	}		
		
				
		
			
			
	};
	int main(){
	
	BiST b;
	node*root=NULL;
	b.insert(4);
	b.insert(2);
	//b.insert(6);
	b.insert(1);
	b.insert(3);
	b.insert(5);
	b.insert(7);
	b.insert(9);
	b.display();
	b.display2d();
	int n;
	cout<<"select an item to delete within the list"<<endl;
	cin>>n;
	if(b.searchH(n)==NULL){
		cout<<"value to be deleted can't be found\n";
	}
	else{
	cout<<"deleting "<<n<<endl;
	b.delat(n);
	
	//b.parswap(9);
	b.display2d();}
	//b.find(7);
	
				//checking if searched number is available or not
	
	if(b.searchH(7)!=NULL)cout<<"\nsearched value is found\n";
	else cout<<"\nsearched value is not found\n";
	



}
		
		
	
		
