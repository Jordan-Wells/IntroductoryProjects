#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Bnode{
	string data;
	Bnode * left;
	Bnode * right;
};

void inorder(Bnode* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<endl;
		inorder(root->right);
	}
}

void add(Bnode *& root, string item){
	if(root == NULL){
		root=new Bnode;
		root->data = item;
		root->left=root->right=NULL;
	}
	else if (item <= root->data)
		add(root->left,item);
	else
		add(root->right,item);
}

int size(Bnode * root){
	if(root == NULL) 
        return 0;
	else
	    return size(root->left) + size(root->right) + 1;
}

void search(Bnode * root, string searchName){
    int counter = 0;
    Bnode * cursor = root;
    while(cursor != NULL){
        if(cursor -> data == searchName){
            counter++;
        }
        if (searchName <= cursor->data)
		    cursor = cursor -> left;
	    else
		    cursor = cursor -> right;
    }
    cout << "Your search appears " << counter << " times." << endl;
}
void greaterThan(Bnode * root, int & counter, string searchName){
    if(root == NULL){
        return;
    }
    if(searchName >= root -> data){
        greaterThan(root -> right, counter, searchName);
    }
    else{
        counter++;
        greaterThan(root -> right, counter, searchName);
        greaterThan(root -> left, counter, searchName);
    }
    return;
}

int main(){
    int counter = 0;
    string searchName = "";
    
    ifstream ins;
    ins.open("name.txt");
    if(ins.fail()){
        cout << "Invalid data file." << endl;
        return 0;
    }
    Bnode * names = new Bnode;
    string name = "";
    while(ins >> name){
        add(names, name);
    }
    cout << "Enter name to search: " << endl;
    cin >> searchName;
    search(names, searchName);
    greaterThan(names, counter, searchName);
    cout << "There are " << counter << " names larger than this in the list.\n";
    return 0;
}
