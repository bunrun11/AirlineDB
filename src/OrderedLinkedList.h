/*
 * OrderedLinkedList.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Job
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include "LinkedList.h"

template<class T>
class OrderedLinkedList : public LinkedList<T>{

public:
	 void insert(T&);
	 void deleteData(T&);
	 T& find(T&);
};

//inserts the data in and stores it in the ascending order in the LinkedList
template<class T>
void OrderedLinkedList<T>::insert(T& _data){
	if(this->mpHead == NULL){
		this->mpHead = new typename OrderedLinkedList<T>::Node(0, _data);
		this->mpTail = this->mpHead;
	}
	else{
		typename OrderedLinkedList<T>::Node *pCurrent = this->mpHead;
		while(pCurrent != 0 && pCurrent->data > _data)
		{
			pCurrent = pCurrent->pNext;
		}

		if(pCurrent != 0){
			if(pCurrent == this->mpHead){
				this->mpHead = new typename OrderedLinkedList<T>::Node(pCurrent->pPrev, pCurrent, _data);
			}
			else{
				new typename OrderedLinkedList<T>::Node(pCurrent->pPrev, pCurrent, _data);
			}
		}
		else{
			this->mpTail = new typename OrderedLinkedList<T>::Node(this->mpTail, _data);
		}
	}
	this->mcount++;
}

//delete specified data from the list
template<class T>
void OrderedLinkedList<T>::deleteData(T& _data){
	typename OrderedLinkedList<T>::Node *pCurrent = this->mpHead;
	for(int i = 0; i < this->mcount; i++){
		if(pCurrent->data == _data){
			if(i == 0){
				this->mpHead = this->mpHead->pNext;
			}
			else if(i == this->mcount){
				this->mpTail = this->mpTail->pPrev;
			}
			pCurrent->Delete();
			this->mcount--;
			return;
		}
		if(pCurrent->data < _data){
			return;
		}
		pCurrent = pCurrent->pNext;
	}
}

//returns the specified data
template<class T>
T& OrderedLinkedList<T>::find(T& _data){
	typename OrderedLinkedList<T>::Node *pCurrent = this->mpHead;
	for(int i = 0; i < this->mcount; i++){
		if(pCurrent->data == _data){
			return pCurrent->data;
		}
		if(pCurrent->data < _data){
			break;
		}
		pCurrent = pCurrent->pNext;
	}
	throw std::exception();
}

#endif /* ORDEREDLINKEDLIST_H_ */
