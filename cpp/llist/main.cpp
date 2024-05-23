#include <iostream>

class LNode{
	public:
		int val;
		LNode * next;
	LNode(){
		this->val = 0;
		this->next = NULL;
	}
};

class LList{
	public:
		LNode * head;
		size_t size;
	LList(){
		this->head = NULL;
		this->size = 0;
	};

	void append_to_end(LNode * n){
		if(this->head == NULL){
			this->head = n;
			this->size = this->size + 1;
			return;
		}
		LNode * tp = NULL;
		tp = this->head;

		while(tp->next != NULL){
			tp = tp->next;
		}

		tp->next = n;
		this->size = this->size + 1;
	}
};

int main(){
	LNode * n = new LNode();
	n->val = 999;

	LNode * n1 = new LNode();
	n1->val = 666;

	LNode * n2 = new LNode();
	n2->val = 777;
	
	LList * l = new LList();
	
	l->append_to_end(n);
	l->append_to_end(n1);
	l->append_to_end(n2);

	LNode * tp = NULL;

	tp = l->head;

	while(tp != NULL){
		std::cout << "Node : " << tp->val << std::endl;
		tp = tp->next;
	}

	return 0;
}
