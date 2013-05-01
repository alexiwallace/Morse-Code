#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template<typename T>
class tree {
public:
  // tree node structure
	struct tree_node {
		int index;
		std::string _alpha;
		std::string encode_morse;
		std::string morse_overlay;

		tree_node *left, *right;	// left and right child pointers	
		tree_node(int i, std::string a, std::string e, std::string m, tree_node *l, tree_node *r):index(i), _alpha(a), encode_morse(e), morse_overlay(m),left(l),right(r){}
	};
	
	tree_node *root; // root "head" pointer for entire tree
		
public:
	// default constructor
	tree():root(nullptr){}
	
	// constructor which creates a root node
	tree(int i, std::string a, std::string e, std::string m) {
		root=new tree_node(i, a, e, m, nullptr, nullptr);
	}

	// destructor, call delete on all nodes
	~tree(){
		
	}  
	
	
	// recursive insert method for inserting new value into tree
	// only inserts new values at leaves, never in middle of tree
	// does NOT insert duplicate values into tree
	void insert(tree_node* r, int index, std::string _alpha, std::string encode_morse, std::string morse_overlay) {
		if(r->index == index)
			return;
			
		if(r->index > index) {
			if(r->left == nullptr) 
				r->left = new tree_node(index, _alpha, encode_morse, morse_overlay, nullptr, nullptr);
			else
				insert(r->left, index, _alpha, encode_morse, morse_overlay);
		}
		else {
			if(r->right == nullptr) 
				r->right = new tree_node(index, _alpha, encode_morse, morse_overlay, nullptr, nullptr);
			else
				insert(r->right, index, _alpha, encode_morse, morse_overlay);
		}
	}

	// wrapper method for recursive tree insert method
	void insert(int index, std::string _alpha, std::string encode_morse, std::string morse_overlay) {
		if(root == nullptr)
			root = new tree_node(index, _alpha, encode_morse, morse_overlay, nullptr, nullptr);
		else
			insert(root, index, _alpha, encode_morse, morse_overlay);
	}

	// takes the morse code as a parameter and converts it to a phrase
	std::string decode(std::string input) {
		std::string out="";
		tree_node* current = root;
		char letter[4]= " .-";
		
		for(int i=0; i<=input.size(); i++){
			if (input.size()==i){
				out=out+current->morse_overlay;
			}
			
			else if (input[i]==letter[0]){
				out=out+current->morse_overlay;
				current = root;
				if(input[i+1]==letter[0]){
					out = out + " ";
					i++;
				}
			}
			else if (input[i]==letter[1]){
				if(current->right != nullptr && current->left != nullptr)
					current=current->right;
			}
			else if (input[i]==letter[2]){
				if(current->right != nullptr && current->left != nullptr)
					current=current->left;
			}
		}
		return out;
	}


	//takes a phrase and converts it to morse code  
	std::string encode(std::string input) {
        std::string out="";
        tree_node* current = root;
        char letter[4]= " .-";
        std:string find = "";

        for(int i=0; i<input.size(); i++){
                current = root;
                find = input[i];
                while(1){
                        if (input[i] == letter[0]){
                            break;
                        }
                        if (find == current->_alpha){
                                out=out+current->encode_morse;
                                current = root;
                                break;
                        }
                        else if (find < current->_alpha){
                                current = current->left;
                        }
                        else if (find > current->_alpha){
                                current = current->right;
                        }
                }
                out = out + " ";
        }
        return out;
    }

};
