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
		head_ = tail_ = nullptr;
	}

	void push_back(int data){
		Node* tmp = new Node(data);
		if (!head_ && !tail_){
			head_ = tail_ = tmp;
		} else{
			Node* tmpTail = tail_;
			tmp->prev_ = tmpTail;
			tmpTail->next_ = tmp;
			tail_ = tmp;
		}
	}

	void push_front(int data){
		Node* tmp = new Node(data);
		if (!head_ && !tail_){
			head_ = tail_ = tmp;
		} else{
			Node* tmpHead = head_;
			tmpHead->prev_ = tmp;
			tmp->next_ = tmpHead;
			head_ = tmp;
		}
	}

	void pop_front(){
		if (head_ && tail_){
			if (head_->next_ != tail_){
				Node* headNxt = head_->next_;
				delete head_;
				head_ = nullptr;
				head_ = headNxt;
			} else{
				delete head_;
				head_ = tail_ = nullptr;
			}
		}
	}

	void pop_back(){
		if (head_ && tail_){
			if (tail_->prev_ != head_){
				Node* tailPrv = tail_->prev_;
				delete tail_;
				tail_ = nullptr;
				tail_ = tailPrv;
			} else{
				delete tail_;
				tail_ = head_ = nullptr;
			}
		}
	}

	void print(){
		Node* it = head_;

		if (it){
			while (it->next_){
				cout << "Data: " << it->data_ << endl;
				it = it->next_;
			}
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