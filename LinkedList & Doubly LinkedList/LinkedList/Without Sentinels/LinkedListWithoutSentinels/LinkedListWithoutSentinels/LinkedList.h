#include <iostream>

class List{
	struct Node{
		int data;
		Node* next;
		
		Node(int data_ = 0, Node* next_ = nullptr){
			data = data_;
			next = next_;
		}
	};
	Node* head_;
	Node* tail_;

public:
	List(){
		head_ = nullptr;
		tail_ = nullptr;
	}

	void push_back(int data){
		if (head_ && tail_){
			Node* tmp = new Node(data);
			tail_->next = tmp;
			tail_ = tmp;
		}
		else{
			head_ = new Node(data);
			tail_ = head_;
		}
	}

	void push_front(int data){
		if (head_ && tail_){
			Node* tmp = new Node(data);
			tmp->next = head_;
			head_ = tmp;
		}
		else{
			head_ = new Node(data);
			tail_ = head_;
		}
	}

	void pop_front(){
		if (head_){
			Node* tmp = head_->next;
			delete head_;
			if (tmp){
				head_ = tmp;
			} else{
				head_ = tail_ = nullptr;
			}
		}
	}

	void pop_back(){
		Node* srch = head_;
		if (head_ && tail_){
			if (head_ != tail_){  //Check if there is more than one value in the list
				while (srch->next != tail_){
					srch = srch->next;
				}
				delete tail_;
				tail_ = srch;
				srch->next = nullptr;
			}
			else{
				delete srch;
				head_ = tail_ = nullptr;
			}
		}
	}

	void print(){
		Node* it = head_;
		
		if (it){
			while (it->next){
				std::cout << "Data: " << it->data << std::endl;
				it = it->next;
			}
		}
	}

	~List(){
		Node* it = head_;
		Node* curr = it;
		while (it->next){
			it = it->next;
			delete curr;
			curr = nullptr;
			curr = it;
		}
		head_ = tail_ = nullptr;
	}
};