#pragma once
//
//Ziqi Wang 12/17/2018
//data structure for storing stock information
#include <iostream>
#include <string>
using namespace std;
#ifndef FINALPROJECT_LINKEDLIST_H
#define FINALPROJECT_LINKEDLIST_H
class Node {
	friend class LinkedList;
	friend class decentSortStrategy;
	friend class ascendSortStrategy;
public:
	Node(string& name, float price, int number)
		:stockName(name), stockPrice(price), shares(number)
	{
		this->next = NULL;
		this->formal = NULL;
	}
	const string &getStockName() const;
	float getStockPrice() const;
	int getShares() const;
	Node *getNext() const;
	Node *getFormal() const;

	void setStockPrice(float stockPrice);

	void setShares(int shares);

private:
	string stockName;
	float stockPrice;
	int shares;
	Node *next;
	Node *formal;
};

class LinkedList {

	friend class decentSortStrategy;
	friend class ascendSortStrategy;
public:
	LinkedList();
	bool changeStockShares(string&, int, double, bool);//for buy&sell stock
	void addToEnd(Node *);//add new stock to the end
	void addToHead(Node *);
	void popFront();//remove stock
	void popBack();
	void removeNodeFromList(string);
	void printList();
	void swapNode(Node*, Node*);//use this function to swap Node 2 and Node2
	void selectsort();//sort is part of the Linkedlist
	Node *getMyHead() const;
	Node *getMyTail() const;
	int getMySize() const;

	virtual ~LinkedList();

private:
	Node *myHead;
	Node *myTail;
	int mySize;//current size of list
};

class ISortStrategy {//sortstrategy,using strategy design pattern
public:
	virtual void Sort(LinkedList*) = 0;
};
class decentSortStrategy :public ISortStrategy {
public:
	virtual void Sort(LinkedList* list) {//sort in decent order

		list->myTail->next = 0;
		if (list->mySize <= 1)
			return;
		for (Node* test = list->myHead; test != 0; test = test->next)
		{
			for (Node* cur = test->next; cur != 0; cur = cur->next)
			{
				if (cur->stockPrice*cur->shares > test->stockPrice*test->shares)
				{
					list->swapNode(cur, test);
					Node* t;
					t = cur;
					cur = test;
					test = t;
				}
			}
		}
	}
};
class ascendSortStrategy :public ISortStrategy {//sort in ascending order
public:
	virtual void Sort(LinkedList*list) {
		list->myTail->next = 0;
		if (list->mySize <= 1)
			return;
		for (Node* test = list->myHead; test != 0; test = test->next)
		{
			for (Node* cur = test->next; cur != 0; cur = cur->next)
			{
				if (cur->stockPrice*cur->shares < test->stockPrice*test->shares)
				{
					list->swapNode(cur, test);
					Node* t;
					t = cur;
					cur = test;
					test = t;
				}
			}
		}
	}
};
class Sorter {
public:
	static void Sort(LinkedList* list, const shared_ptr<ISortStrategy>& sorter) {
		sorter->Sort(list);
	}
};

#endif //FINALPROJECT_LINKEDLIST_H
