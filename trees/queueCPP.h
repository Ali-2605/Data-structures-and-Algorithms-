#include<iostream>
#include<stdio.h>
#include<stdlib.h>

#ifndef QUEUECPP_H
#define QUEUECPP_H

class Node
{
public:
    Node *leftChild;
    int data;
    Node *rightChild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node * x);
    Node * dequeue();
    void display();
    int isEmpty();
};

void Queue::enqueue(Node * x)
{
    if(rear == size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node * Queue::dequeue()
{
    Node * x = NULL; 
    if(front == rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}

#endif