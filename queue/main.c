#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int val;
	struct node * next;
} node;

typedef struct{
	node *head;
	node *tail;
} Queue;

void init_queue(Queue *q){
	q->head = NULL;
	q->tail = NULL;
}

int enqueue(Queue *q, int val){
	node * new_node = malloc(sizeof(Queue));
	if(new_node == NULL){
		return 1;
	}
	new_node->val = val;
	new_node->next = NULL;
	if(q->tail != NULL){
		q->tail->next = new_node;
	}
	
	q->tail = new_node;
	if(q->head == NULL){
		q->head = new_node;
	}
	
	return 0;
}

int deqeue(Queue *q){
	if(q->head == NULL){
		return 1;
	}
	node * tmp = q->head;	
	int result = tmp->val;

	q->head = q->head->next;

	if(q->head == NULL){
		q->tail = NULL;
	}

	free(tmp);

	return 0;
}

int main(){
	Queue q;

	init_queue(&q);

	enqueue(&q, 3);
	enqueue(&q, 5);
	enqueue(&q, 8);
	
	deqeue(&q); 

	printf("Queue q->head->value %d\n", q.head->val);
	printf("Queue q->tail->value %d\n", q.tail->val);
	return 0;
}
