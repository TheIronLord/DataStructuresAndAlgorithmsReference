#include <iostream>

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
		head_ = nullptr;
		tail_ = nullptr;
	}

	void push_back(int data){
		Node* tmp = new Node(data);
		if (head_ && tail_){
			tmp->prev_ = tail_;
			tail_->next_ = tmp;
			tmp->next_ = head_;
			head_->prev_ = tail_;
			tail_ = tmp;
		} else{
			head_ = tail_ = tmp;
		}
	}

	void push_front(int data){
		Node* tmp = new Node(data);
		if (head_ && tail_){
			tmp->next_ = head_;
			head_->prev_ = tmp;
			tmp->prev_ = tail_;
			tail_->next_ = tmp;
			head_ = tmp;
		} else{
			head_ = tail_ = tmp;
		}
	}

	void pop_back(){
		if (head_ && tail_){
			if (head_ != tail_){
				Node* tailPrv = tail_->prev_;
				delete tail_;
				tailPrv->next_ = head_;
				//head_->prev_ = tailPrv;
				tail_ = tailPrv;
			}
			else{
				delete tail_;
				head_ = tail_ = nullptr;
			}
		}
	}

	void pop_front(){
		if (head_ && tail_){
			if (head_ != tail_){
				Node* headNxt = head_->next_;
				delete head_;
				headNxt->prev_ = tail_;
				//tail_->next_ = headNxt;
				head_ = headNxt;
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
			it = it->prev_;
			cout << "Circular Rerversal" << endl;

			while (it != head_){
				cout << "Data: " << it->data_ << endl;
				it = it->prev_;
			}
		}
	}

	~DList(){
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