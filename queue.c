#include <stdio.h>
#define n 5

// Global Variables (Standard Exam Terms)
int q[n];      // The array
int front = -1; // The Tail (Follows)
int rear = -1;  // The Head (Leads)

void enqueue(int value) {
    // 1. Check Overflow (Did Head hit the wall?)
    if (rear == n - 1) {
        printf("Queue Overflow\n");
    } else {
        // 2. If it's the first item, initiate the Tail
        if (front == -1) {
            front = 0;
        }
        
        // 3. Move Head forward and add value
        rear++;
        q[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    // 1. Check Underflow (Has Tail passed Head? Or is it -1?)
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        // 2. Remove item (Tail scoots forward)
        printf("Dequeued: %d\n", q[front]);
        front++;

        // 3. Reset: If Tail passes Head, the queue is empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Current Queue: ");
        // Loop from Tail (front) to Head (rear)
        for (int i = front; i <= rear; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10); 
    enqueue(20); 
    enqueue(30); 
    
    display();   // Output: 10 20 30
    
    dequeue();   // Removes 10 (front moves to index 1)
    
    display();   // Output: 20 30
    
    return 0;
}