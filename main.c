#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node *next;
}node;

typedef struct {
    node *head;
    node *tail;
}queue;

void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value){
    node *new_node = malloc(sizeof (node));
    if(new_node == NULL) return false;

    new_node->value = value;

    if(q->tail != NULL){
        q->tail->next = (struct node *) new_node;
    }

    q->tail = new_node;

    if(q->head == NULL){
        q->head = new_node;
    }
    return true;

}

int dequeue(queue *q){
    if(q->head == NULL) return -1;
    node *tmp = q->head;
    int result = tmp->value;
    q->head = (node *) q->head->next;
    if(q->head == NULL){
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main() {
    queue q1;
    init_queue(&q1);
    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);
    enqueue(&q1, 4);

    int t;
    t = dequeue(&q1);
    while (t != -1){
        printf("%d\n", t);
        t = dequeue(&q1);
    }


    return 0;
}
