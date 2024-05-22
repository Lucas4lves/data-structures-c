#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node * next;
}Node;

typedef struct LinkedList {
	struct Node * head;
	size_t nodes;
}LinkedList;

void init_linked_list(LinkedList *l, int val){

	Node *n = malloc(sizeof(Node));
	n->val = val;
	n->next = NULL;

	l->head = n;
	l->nodes = 1;
}

void insert_into(LinkedList * l, Node * n){
	if(n == NULL) return;
	if(l->head == NULL) return; 

	Node * tp = NULL;
	tp = l->head;

	while(tp->next != NULL){
		tp = tp->next;
	}

	tp->next = n;
	l->nodes = l->nodes + 1;
}

int count_nodes_of(LinkedList l){

	int c = 0;
	if(l.head == NULL){
		printf("List is empty :( \n");
	}

	Node * tp = NULL;
	tp = l.head;
	
	while(tp != NULL){
		++c;
		printf("Node %d Value: %d\n", c, tp->val);
		tp = tp->next;
	}

	return c;
}

void insert_at(int node_val,LinkedList *l , int data){
	Node * new_node = malloc(sizeof(Node));
	new_node->val = data;
		
	Node * tp = NULL;
	tp = l->head;
	while(tp != NULL){
		if(tp->val == node_val){
			new_node->next = tp->next;
			tp->next = new_node;
			l->nodes++;
			return;
		}
		tp = tp->next;
	}
}

int main(){

	Node *a = malloc(sizeof(Node));
	Node *b = malloc(sizeof(Node));

	a->val = 999;
	a->next = NULL;

	b->val = 666;
	b->next = NULL;

	LinkedList l;
	init_linked_list(&l, 555);

	insert_into(&l, a);
	insert_into(&l, b);
	insert_at(666, &l, 777);
	insert_at(666, &l, 888);
	int res = count_nodes_of(l);

	printf("NODES TOTAL: %d\n", res);
}
