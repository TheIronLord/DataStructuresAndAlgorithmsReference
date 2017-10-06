/*Binary Search Tree*/
#include<iostream>

class BST{
	struct Node{
		int data_;
		Node* left_;
		Node* right_;

		Node(int data = 0, Node* left = nullptr, Node* right = nullptr) :
			data_(data),
			left_(left),
			right_(right){}
	};
	Node* root_;
public:

	BST(){
		root_ = nullptr;
	}

	~BST(){
		Node* toDelete = root_;
		cleanup(toDelete);
	}

	BST(BST& cpy){
		Node* source = cpy.root_;
		Node* destination = root_;

		root_ = copy(destination, source);
	}

	/*This operator will compare the
	data in both BST Objects which it
	will get the root node out of and
	send to compare() to compare the
	entire binary search tree to see
	if they are in fact the same or not*/
	bool operator==(const BST& obj){
		Node* obj1 = root_;
		Node* obj2 = obj.root_;

		return compare(obj1, obj2);
	}

	/*Function goes right and left depending if the data
	being passed in is greater or less than the data inside
	of the Node until it reaches a nullptr. It then creates 
	a new Node*/
	void insert(int data){
		if (!root_){
			root_ = new Node(data);
		}
		else{
			Node* srch = root_;
			bool found = false;

			while (srch && !found){
				if (data > srch->data_){
					if (srch->right_){
						srch = srch->right_;
					}
					else{
						Node* newNode = new Node(data);
						srch->right_ = newNode;
						found = true;
					}
				}
				else if (data < srch->data_){
					if (srch->left_){
						srch = srch->left_;
					}
					else{
						Node* newNode = new Node(data);
						srch->left_ = newNode;
						found = true;
					}
				}
			}
		}
	}

	/*Checks if the data being passed in
	is the same data as root. if so makes 
	rootChange true and calls the remove 
	function to remove the Node. It will
	then make root_ equal to delteAndReplace*/
	void removeMain(int data){
		Node* delteAndReplace = root_;
		bool rootChange = false;
		
		if (root_->data_ == data){
			rootChange = true;
		}
		
		remove(data, delteAndReplace);

		if (rootChange){
			root_ = delteAndReplace;
		}
	}

	/*Makes srch Node and point it to root_.
	Then sends it over with data to findRecursive();*/
	int find(int data){
		Node* srch = root_;
		int rc = findRecursive(data, srch);

		return rc;
	}

	/*Prints values between min and max*/
	void printBetween(int min, int max){
		Node* prntBetwn = root_;
		printBetweenRecursive(min, max, prntBetwn);
	}

	/*Gets number of Nodes
	in Binary Search Tree
	and returns it*/
	int numOfNodesInTree(){
		Node* srch = root_;
		int count = 0;
		numOfNodesInTreeRecursive(srch, count);
		
		return count;
	}
	
private:/*Wrapper Functions*/

	/*This function will first check
	if n1 and n2 are not null. If they 
	are it will check if one has values
	and another doesnt and if that is the
	case then they are not the same structure
	but if both are null it will return true. 
	Now when both n1 and n2 are not null it
	will compare the data if the data is the
	same it will recursively call the function
	with the left and right of both n1 and n2.*/
	bool compare(Node*& n1, Node*& n2){
		if (n1 && n2){
			if (n1->data_ == n2->data_){
				compare(n1->left_, n2->left_);
				compare(n1->right_, n2->right_);
			}else{
				return false;
			}
		}
		else if (!n1 && n2 || n1 && !n2){
			return false;
		}
		else{
			return true;
		}
	}

	/*Keeps going left until it cannot anymore.
	It willthen save n into tmp and then Overwrite
	n pointer with the current n right's pointer*/
	Node* detatchSmallest(Node*& n){
		if (!n->left_){
			Node* tmp = n;
			n = n->right_;
			return tmp;
		}
		return detatchSmallest(n->left_);
	}

	/*Goes right and left depending if the data
	being passed in is bigger or less than the 
	data being passed in. If it ends up in a nullptr
	it won't do anything. But if it is found it will
	check if it has one child or two children. If it
	has one child it will overwrite the subrootTree
	pointer with its right or left child. Or else it 
	will call detatchsmallest() function to detatch the
	smallest and then makes its right pointer point to
	subrootTree's right child and left with subrootTree's
	left child. After doing all this it will delete the 
	Node being deleted and make it a nullptr.*/
	void remove(int data, Node*& subrootTree){
		Node* srch = subrootTree;
		if (srch){
			bool found = false;
			if (srch->data_ == data){
				if (srch->left_ && !srch->right_){
					subrootTree = subrootTree->left_;
				}
				else if (!srch->left_ && srch->right_){
					subrootTree = subrootTree->right_;
				}
				else{
					Node* rc = detatchSmallest(subrootTree->right_);
					rc->left_ = subrootTree->left_;
					rc->right_ = subrootTree->right_;
					subrootTree = rc;
				}
				delete srch;
				srch = nullptr;
			}
			else{
				if (srch->data_ < data){
					remove(data, subrootTree->right_);
				}
				else{
					remove(data, subrootTree->left_);
				}
			}
		}
	}

	/*findRecursive() will return -1 if it doesnt find 
	the Node. But if it does it will return the data 
	inside of the Node*/
	int findRecursive(int data, Node*& subtreeRoot){
		if (subtreeRoot){
			if (subtreeRoot->data_ == data){
				return subtreeRoot->data_;
			}
			else{
				if (data > subtreeRoot->data_){
					findRecursive(data, subtreeRoot->right_);
				}
				else{
					findRecursive(data, subtreeRoot->left_);
				}
			}
		}
		else{
			return -1;
		}
	}
	
	/*Recusively calls function printing all values in binary search tree
	with values bigger or equal to min and values less than or equal to max*/
	void printBetweenRecursive(const int min, const int max, Node*& prntVal){
		if (prntVal){
			if (prntVal->data_ <= max && prntVal->data_ >= min){
				std::cout << prntVal->data_ << std::endl;
			}
			printBetweenRecursive(min, max, prntVal->left_);
			printBetweenRecursive(min, max, prntVal->right_);
		}
	}

	/*Recursively goes left and right incrementing count
	until it reaches the bottom of the binary search tree*/
	void numOfNodesInTreeRecursive(Node*& srch, int& count){
		if (srch){
			++count;
			numOfNodesInTreeRecursive(srch->left_, count);
			numOfNodesInTreeRecursive(srch->right_, count);
		}
	}

	/*Keep going left and right
	until you reach the bottom 
	and delete each node until 
	you get back to the root
	which is also deleted*/
	void cleanup(Node*& delte){
		if (delte){
			cleanup(delte->right_);
			cleanup(delte->left_);

			delete delte;
		}
	}

	/*Will check if source is not null. If it is not
	it will make destination a new Node and recursively
	call copy with right and left of both destination
	and source. This function will return the root of
	destination*/
	Node* copy(Node*& destination, Node*& source){
		if (source){
			destination = new Node(source->data_);
			copy(destination->right_, source->right_);
			copy(destination->left_, source->left_);
		}
		return destination;
	}
};