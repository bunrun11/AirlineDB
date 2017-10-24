/*
 * TemplateLinkedList.h
 *
 *  Created on: Oct 6, 2017
 *      Author: jobbe_000
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

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
	struct Iterator{
		friend class LinkedList<T>;
		private:
		LinkedList<T> &mlist;
		Node* mpCurrent;

		Iterator(LinkedList<T>&);

		public:
		T& getValue();

		bool hasNext();
		bool hasPrev();

		void next();
		void prev();
	};

	//public:
	LinkedList<T>();
	virtual ~LinkedList<T>();

	virtual void insert(T&);
	void insertAt(T&, int);
	virtual void deleteData(T&);
	void clearList();
	bool search(T&);
	virtual T& find(T&);
	bool getLength();
	Iterator getIterator();
	void nodePrint();
	void print();

	template<class U>
	friend std::ostream& operator<<(std::ostream&, LinkedList<U>&);
	T* operator[](std::string);
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
LinkedList<T>::Iterator::Iterator(LinkedList<T> &list):mlist(list){
	//mlist = list;
	mpCurrent = mlist.mpHead;
}

//returns the data of the current node
template<class T>
T& LinkedList<T>::Iterator::getValue(){
	return mpCurrent->data;
}

//checks if there is a next node
template<class T>
bool LinkedList<T>::Iterator::hasNext(){
	return mpCurrent->pNext;
}

//check whether there is a previous node
template<class T>
bool LinkedList<T>::Iterator::hasPrev(){
	return mpCurrent->pPrev;
}

//goes to the next node if there is one
template<class T>
void LinkedList<T>::Iterator::next(){
	if(hasNext()){
		mpCurrent = mpCurrent->pNext;
	}
}

//goes to the previous node if there is one
template<class T>
void LinkedList<T>::Iterator::prev(){
	if(hasPrev()){
		mpCurrent = mpCurrent->pNext;
	}
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

//searches the LinkedList to see if the data is present
template<class T>
bool LinkedList<T>::search(T& _data){
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

//returns the specified data if present
template<class T>
T& LinkedList<T>::find(T& _data){
	if(mpHead == 0){
		throw std::exception();
	}

	Node *pCurrent = mpHead;
	do{
		if(pCurrent->data == _data){
			return pCurrent->data;
		}
		pCurrent = pCurrent->pNext;
	}while(pCurrent != 0);

	throw std::exception();
}


//returns an iterator for the linkedlist
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::getIterator(){
	Iterator it(*this);
	return it;
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
		std::cout<<pCurrent->data<<std::endl;
		pCurrent = pCurrent->pNext;
	}
	std::cout<<pCurrent->data<<std::endl;
}

template<class T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list){
    if(list.mpHead == 0){
		return os;
	}

	typename LinkedList<T>::Node *pCurrent = list.mpHead;
	while(pCurrent->pNext != 0){
		os<<pCurrent->data<<std::endl;
		pCurrent = pCurrent->pNext;
	}
	os<<pCurrent->data<<std::endl;
	return os;
}

template<class T>
T* LinkedList<T>::operator [](std::string s){
	if(mpHead == 0){
		return 0;
	}

	Node *pCurrent = mpHead;
	while(pCurrent != 0){
		if(s == pCurrent->data){
			return &pCurrent->data;
		}
		pCurrent = pCurrent->pNext;
	}
	return 0;
}

#endif /* LINKEDLIST_H_ */
