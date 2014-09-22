//Jonathan Petersen
//A01236750
//Templated Queue
//Queue Class Template

#ifndef _QUEUE_H
#define _QUEUE_H

#include "Node.hpp"

using namespace std;

template <class T>
class Queue
{
public:
	Queue(void);
	~Queue(void);

	void enqueue(T);
	T 	 dequeue(void);
	T 	 front(void);
	int  getCount(void);

	void rDestroy(Node<T>*);
	int  rCount(Node<T>*, int&);

	class EmptyQueue {};
private:

	Node<T>* begin;
	Node<T>* end;
};


template<class T>
Queue<T>::Queue(void) {
	begin = end = NULL;
}

template<class T>
Queue<T>::~Queue(void) {

	if(begin == NULL) return;
	
	rDestroy(begin);
	begin = end = NULL;

}

template<class T>
void Queue<T>::enqueue(T input) {

	if (end == NULL) { 
		begin = new Node<T>(input);
		end = begin;
		return;
	}

	end->next = new Node<T>(input);
	end = end->next;
	return;
}

template<class T>
T Queue<T>::dequeue(void) {

	if(begin == NULL) throw EmptyQueue();

	T value = begin->value;
	Node<T>* nextNode = begin->next;

	delete begin;
	begin = nextNode;

	return value;
}

template<class T>
T Queue<T>::front(void) { return begin->value; }

template<class T>
int Queue<T>::getCount(void) { 

	int total = 0;
	return rCount(begin, total); 
}

template<class T>
void Queue<T>::rDestroy(Node<T>* thisNode) {

	//Base Case
	if(thisNode->next == NULL) { return; }


	//Alternative Case
	rDestroy(thisNode->next);

	//Start deleting from the end to the begin
	delete thisNode;
	return;
}

template<class T>
int Queue<T>::rCount(Node<T>* thisNode, int& total) {

	//Base Case
	if(thisNode->next == NULL) return ++total;

	//Alternative Case
	return rCount(thisNode->next, ++total);
}


#endif
