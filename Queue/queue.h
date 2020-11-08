#include <stdio.h>

typedef struct queueHead* QUEUE;
typedef struct element* LINK;
typedef int T;

// Queue element
struct element {
	T data;
	LINK nextEl;
};

// Queue head
struct queueHead {
	LINK front;
	LINK rear;
};

void initQueue(QUEUE* queue);
int isEmpty(QUEUE queue);
void insert(QUEUE queue, T data);
int extract(QUEUE queue);
void printQueue(QUEUE queue);