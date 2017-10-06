#include<iostream>
using namespace std;

class DList{
	struct Node{
		int data_;
		Node* next_;
		Node* prev_;

		Node(int data = 0, Node* next = nullptr, Node* prev = nullptr) :
			data_(data),
			next_(next),
			prev_(prev){}
	};
	Node* head_;
	Node* tail_;

public:
	DList(){
		head_ = new Node();
		tail_ = new Node();
		head_->next_ = tail_;
		tail_->prev_ = head_;
	}

	void push_back(int data){
		Node* prvTail = tail_->prev_;
		Node* tmp = new Node(data, tail_, prvTail);
		tail_->prev_ = tmp;
		prvTail->next_ = tmp;
	}

	void push_front(int data){
		Node* headNxt = head_->next_;
		Node* tmp = new Node(data, headNxt, head_);
		headNxt->prev_ = tmp;
		head_->next_ = tmp;
	}

	void pop_front(){
		if (head_->next_ != tail_){
			Node* delte = head_->next_;
			Node* connct = delte->next_;
			delete delte;
			connct->prev_ = head_;
			head_->next_ = tail_;
		}
	}

	void pop_back(){
		if (tail_->prev_ != head_){
			Node* delte = tail_->prev_;
			Node* connct = delte->prev_;
			delete delte;
			connct->next_ = tail_;
			tail_->prev_ = connct;
		}
	}

	void print(){
		Node* it = head_->next_;
		
		while (it != tail_){
			cout << "Data: " << it->data_ << endl;
			it = it->next_;
		}
	}

	~DList(){
		Node* it = head_;
		Node* curr = it;

		while (curr){
			curr = it->next_;
			delete it;
			it = nullptr;
			it = curr;
		}
		head_ = tail_ = nullptr;
	}
};