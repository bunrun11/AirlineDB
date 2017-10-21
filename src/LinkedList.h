/*
 * TemplateLinkedList.h
 *
 *  Created on: Oct 6, 2017
 *      Author: jobbe_000
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

template<class T>
class LinkedList {

	protected:
	struct Node{
		T data;
		Node *pNext;
		Node *pPrev;
		Node(Node*, T&);
		Node(Node*, Node*, T&);
		void Delete();
		~Node();
	};

	Node *mpHead = 0;
	Node *mpTail = 0;
	int mcount = 0;

	public:
	LinkedList<T>();
	virtual ~LinkedList<T>();

	virtual void insert(T&);
	void insertAt(T&, int);
	virtual void deleteData(T&);
	void clearList();
	bool find(T&);
	virtual T& search(T&);
	bool getLength();
	void nodePrint();
	void print();

	std::ostream& operator<<(std::ostream&);
};

template<class T>
LinkedList<T>::Node::Node(Node *_prev, T& _data):data(_data){
	pPrev = _prev;
	pNext = 0;
	//data = _data;

	if(pPrev != 0){
		pPrev->pNext = this;
	}
}

template<class T>
LinkedList<T>::Node::Node(Node *prev, Node *next, T& _data):data(_data){
	pPrev = prev;
	pNext = next;
	//data = _data;

	if(pPrev != 0){
		pPrev->pNext = this;
	}

	if(pNext != 0){
		pNext->pPrev = this;
	}
}

template<class T>
void LinkedList<T>::Node::Delete(){
	if(pPrev != 0)
	{
		pPrev->pNext = pNext;
	}
	pNext = 0;

	if(pNext != 0)
	{
		pNext->pPrev = pPrev;
	}
	pPrev = 0;

	delete this;
}

template<class T>
LinkedList<T>::Node::~Node(){
	delete pNext;
}

template<class T>
LinkedList<T>::LinkedList(){

}

template<class T>
LinkedList<T>::~LinkedList(){
	delete mpHead;
}

//inserts data onto end of the LinkedList
template<class T>
void LinkedList<T>::insert(T& data){
	if(mpHead == NULL){
		mpHead = new Node(0, data);
		mpTail = mpHead;
	}
	else{
		mpTail = new Node(mpTail, data);
	}
	mcount++;
}

//inserts data at the specified index. (0 => x < count)
template<class T>
void LinkedList<T>::insertAt(T& data, int index){
	if(mpHead == NULL){
		mpHead = new Node(0, data);
		mpTail = mpHead;
	}
	else{
		if(index <= 0){
			mpHead = new Node(0, mpHead, data);
		}
		else if(index >= mcount){
			mpTail = new Node(mpTail, data);
		}
		else{
			Node *pCurrent = mpHead;
			for(int i = 0; i < index; i++){
				pCurrent = pCurrent->pNext;
			}
			new Node(pCurrent->pPrev, pCurrent, data);
		}
	}
	mcount++;
}

//deletes specified data
template<class T>
void LinkedList<T>::deleteData(T& _data){
	if(mpHead == 0){
		return;
	}
	else if(mpHead->data == _data)
	{
		Node *pCurrent = mpHead;
		mpHead = mpHead->pNext;
		if(mpTail->data == _data)
		{
			mpTail = mpTail->pPrev;
		}
		pCurrent->Delete();
		mcount--;
	}
	else
	{
		Node *pCurrent = mpHead;
		do{
			if(pCurrent->data == _data){
				if(pCurrent->pNext == 0)
				{
					mpTail = pCurrent->pPrev;
					std::cout<<"tail: "<<mpTail->data<<std::endl;
				}
				pCurrent->Delete();
				mcount--;
				break;
			}
			pCurrent = pCurrent->pNext;
		}while(pCurrent != 0);
	}
}

//deletes all the data in the LinkedList
template<class T>
void LinkedList<T>::clearList(){
	delete mpHead;
	mpHead = 0;
	mpTail = 0;
}

//find whether the data is in the LinkedList
template<class T>
bool LinkedList<T>::find(T& _data){
	if(mpHead == 0){
		return 0;
	}

	Node *pCurrent = mpHead;
	do{
		if(pCurrent->data == _data){
			return 1;
		}
		pCurrent = pCurrent->pNext;
	}while(pCurrent != 0);

	return 0;
}

//returns the specified data
template<class T>
T& LinkedList<T>::search(T& _data){
	if(mpHead == 0){
		throw exception();
	}

	Node *pCurrent = mpHead;
	do{
		if(pCurrent->data == _data){
			return pCurrent->data;
		}
		pCurrent = pCurrent->pNext;
	}while(pCurrent != 0);

	throw exception();
}

//prints the LinkedList in node form
template<class T>
void LinkedList<T>::nodePrint(){
	if(mpHead == 0){
		return;
	}

	Node *pCurrent = mpHead;
	while(pCurrent->pNext != 0){
		std::cout<<"["<<(pCurrent->data)<<"]->";
		pCurrent = pCurrent->pNext;
	}
	std::cout<<"["<<(pCurrent->data)<<"]"<<std::endl;
}

//prints the list
template<class T>
void LinkedList<T>::print(){
	if(mpHead == 0){
		return;
	}

	Node *pCurrent = mpHead;
	while(pCurrent->pNext != 0){
		cout<<pCurrent->data<<endl;
		pCurrent = pCurrent->pNext;
	}
	cout<<pCurrent->data<<endl;
}

template<class T>
std::ostream& LinkedList<T>::operator<<(std::ostream& os)
{
	if(mpHead != 0){
		return os;
	}

	LinkedList<T>::Node *pCurrent;
	pCurrent = mpHead;

	while(pCurrent->pNext != 0){
		os<<"["<<(pCurrent->data)<<"]-";
		pCurrent = pCurrent->pNext;
	}
	os<<"["<<(pCurrent->data)<<"]"<<std::endl;
	return os;
}

#endif /* LINKEDLIST_H_ */
