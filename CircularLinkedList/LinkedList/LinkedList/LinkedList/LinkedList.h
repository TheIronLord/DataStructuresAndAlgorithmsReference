#include<iostream>

using namespace std;

class List{
	struct Node{
		int data_;
		Node* next_;
		Node(int data = 0, Node* next = nullptr) :
			data_(data),
			next_(next){}
	};

	Node* head_;
	Node* tail_;

public:
	List()
	{
		head_ = nullptr;
		tail_ = nullptr;
	}

	void push_back(int data){
		Node* tmp = new Node(data);

		if (head_ && tail_){
			tail_->next_ = tmp;
			tail_ = tmp;
			tail_->next_ = head_;
		} else{
			head_ = tail_ = tmp;
		}
	}

	void push_front(int data){
		Node* tmp = new Node(data);

		if (head_ && tail_){
			tmp->next_ = head_;
			tail_->next_ = tmp;
			head_ = tmp;
		} else{
			head_ = tail_ = tmp;
		}
	}

	void pop_back(){
		Node* srch = head_;
		if (head_ && tail_){
			if (head_ != tail_){
				while (srch->next_ != tail_){
					srch = srch->next_;
				}
				delete tail_;
				srch->next_ = head_;
				tail_ = srch;
			} else{
				delete tail_;
				head_ = tail_ = nullptr;
			}
		}
	}

	void pop_front(){
		Node* headNxt = head_;
		if (head_ && tail_){
			if (head_ != tail_){
				headNxt = head_->next_;
				delete head_;
				head_ = nullptr;
				head_ = headNxt;
				tail_->next_ = head_;
			} else{
				delete head_;
				head_ = tail_ = nullptr;
			}
		}
	}

	void print(){
		Node* it = head_;

		if (it){
			while (it != tail_){
				cout << "Data: " << it->data_ << endl;
				it = it->next_;
			}
			it = it->next_;

			cout << "Circular" << endl;
			while (it != tail_){
				cout << "Data: " << it->data_ << endl;
				it = it->next_;
			}
		}
	}

	~List(){
		Node* it = head_;
		Node* curr = it;

		while (curr != tail_){
			curr = it->next_;
			delete it;
			it = nullptr;
			it = curr;
		}
		delete tail_;
		head_ = tail_ = nullptr;
	}
};