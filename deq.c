#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct {
	int a[MAX];
	int front, rear;
}queue;

void enqueuerear(queue *q, int ele) {
	if(q -> rear == MAX - 1) {
		printf("QUEUE OVERFLOW\n");
		return;
	}
	q -> rear++;
	q -> a[q -> rear] = ele;
}

void enqueuefront(queue *q, int ele) {
	if(q -> front == -1) {
		printf("QUEUE OVERRFLOW\n");
		return;
	}
	q -> a[q -> front] = ele;
	q -> front--;
}

int isempty(queue *q) {
	if(q -> rear == q -> front)
	return 1;
	else
	return 0;
}

int dequeuerear(queue *q) {
	int x;
	if(isempty(q))
	return -1;
	x = q -> a[q -> rear];
	q -> rear--;
	return x;
}

int dequeuefront(queue *q) {
	int x;
	if(isempty(q))
	return -1;
	q -> front++;
	x = q -> a[q -> front];
	return x;
}

void display(queue *q) {
	int i;
	if(isempty(q)) {
		printf("QUEUE UNDERFLOW\n");
		return;
	}
	else {
		for(i = q -> front; i < q -> rear; i++) {
			printf("%d\t", q -> a[i]);
		}
		printf("\n");
	}
}

int main() {
	int ch, ele;
	queue q;
	q.front = MAX / 2;
	q.rear = MAX / 2;
	
	while(1) {
		printf("1:ENQUEUEREAR\n2:ENQUEUEFRONT\n3:DEQUEUEREAR\n4:DEQUEUEFRONT\n5:DISSPLAY\n");
		printf("Enter Choice:\n");
		scanf("%d", &ch);
		if(ch == 6)
		break;
		switch(ch) {
			case 1: printf("Enter element to enqueue\n");
					scanf("%d", &ele);
					enqueuerear(&q, ele);
					break;
			case 2: printf("Enter element to enqueue\n");
					scanf("%d", &ele);
					enqueuefront(&q, ele);
					break;
			case 3: ele = dequeuerear(&q);
					if(ele == -1) 
					printf("QUEUE UNDERFLOW\n");
					else
					printf("Element dequeued = %d\n", ele);
					break;
			case 4: ele = dequeuefront(&q);
					if(ele == -1) 
					printf("QUEUE UNDERFLOW\n");
					else
					printf("Element dequeued = %d\n", ele);
					break;
			case 5: display(&q);
					break;
			default : printf("INVALID CHOICE\n");
		}
	}
	
	return 0;
}














