#include "queue.h"

// Initialize the queue
void initQueue(QUEUE* queue)
{
	*queue = (QUEUE) malloc(sizeof(struct queueHead));
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
}

// Is queue empty: Yes - 1 / No - 0
int isEmpty(QUEUE queue)
{
	if (queue == NULL || queue->front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// Add an item to the queue
void insert(QUEUE queue, T data)
{
	// Create new element
	LINK pElement;
	pElement = (LINK)malloc(sizeof(LINK));
	pElement->data = data;
	pElement->nextEl = NULL;

	if (!isEmpty(queue))
	{
		queue->rear->nextEl = pElement;
		queue->rear = queue->rear->nextEl;
	}
	else
	{
		queue->rear = pElement;
		queue->front = pElement;
	}
}

// Extract item from the queue
// If queue is empty - NULL
int extract(QUEUE queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is EMPTY!");
		return NULL;
	}

	LINK pElement;
	T data;
	pElement = queue->front;

	data = pElement->data;
	queue->front = pElement->nextEl;

	//free(pElement);

	// If it was the last element
	if (isEmpty(queue))
	{
		queue->rear = queue->front; // NULL
	}

	return data;
}

// Print queue
void printQueue(QUEUE queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is EMPTY!");
		return;
	}

	LINK el;
	el = queue->front;

	while (el != NULL)
	{
		printf("%d\n", el->data);
		el = el->nextEl;
	}

}