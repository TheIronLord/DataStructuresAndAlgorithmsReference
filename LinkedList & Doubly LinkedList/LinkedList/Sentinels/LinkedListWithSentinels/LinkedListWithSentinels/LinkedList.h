#include<iostream>
class List{
	struct Node{
		int data_;
		Node* next_;

		Node(int data = 0, Node* next = nullptr){
			data_ = data;
			next_ = next;
		}
	};
	Node* head_;
	Node* tail_;

public:

	List(){
		head_ = new Node();
		tail_ = new Node();
		head_->next_ = tail_;
	}

	void push_back(int data){
		Node* srch = head_;
		Node* tmp = new Node(data, tail_);

		if (head_->next_ != tail_){
			while (srch->next_ != tail_){
				srch = srch->next_;
			}
		}
		srch->next_ = tmp;
	}

	void push_front(int data){
		Node* headNxt = head_->next_;
		Node* tmp = new Node(data, headNxt);
		head_->next_ = tmp;
	}

	void pop_front(){
		if (head_->next_ != tail_){
			Node* delt = head_->next_;
			Node* connct = delt->next_;

			delete delt;
			head_->next_ = connct;
		}
	}

	void pop_back(){
		if (head_->next_ != tail_){
			Node* srch = head_;
			Node* connct = srch;

			while (srch->next_ != tail_){
				connct = srch;
				srch = srch->next_;
			}

			delete srch;
			connct->next_ = tail_;
		}
	}

	void print(){
		Node* it = head_->next_;

		if (it != tail_){
			while (it->next_ != tail_){
				std::cout << "Data: " << it->data_ << std::endl;
				it = it->next_;
			}
		}
	}

	~List(){
		Node* curr = head_;
		Node* nxt;

		while (curr){
			nxt = curr->next_;
			delete curr;
			curr = nullptr;
			curr = nxt;
		}
		head_ = tail_ = nullptr;
	}
};