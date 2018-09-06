#include "queue.h"
#define MAX 128
int flag=0;
void qinit(queue *q){
	q->head=q->tail=0;
}
void enqueue(queue *q, data d){
	q->arr[q->tail] = d;
	if(q->tail<MAX)
		(q->tail)++;
	else{
		q->tail=0;
		flag=1;
	}
}
data dequeue(queue *q){
	data tmp;
	tmp = q->arr[q->head];
	if(q->head<MAX)
		(q->head)++;
	else{
		q->head=0;
		flag=2;
	}
	return tmp;
}
int qempty(queue *q){
	if((flag==2) && (q->head==q->tail))		
		return 1;
	return 0;
}
int qfull(queue *q){
	if((flag==1) && (q->head==q->tail))
		return 1;
	return 0;
}
