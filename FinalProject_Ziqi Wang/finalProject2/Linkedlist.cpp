//
//Ziqi Wang 12/17/2018
//
#include "Linkedlist.h"
#include <iomanip>
const string &Node::getStockName() const {
	return stockName;
}
float Node::getStockPrice() const {
	return stockPrice;
}
int Node::getShares() const {
	return shares;
}

Node *Node::getNext() const {
	return next;
}

Node *Node::getFormal() const {
	return formal;
}

void Node::setShares(int shares) {
	Node::shares = shares;
}

void Node::setStockPrice(float stockPrice) {
	Node::stockPrice = stockPrice;
}

LinkedList::LinkedList() {
	myHead = NULL;
	myTail = NULL;
	mySize = 0;
}
void LinkedList::addToHead(Node *NewNode) {
	if (mySize == 0)
	{
		myHead = NewNode;
		myTail = NewNode;
		mySize++;
	}
	else
	{
		myHead->formal = NewNode;
		NewNode->next = myHead;
		myHead = NewNode;
		mySize++;
	}
}
void LinkedList::addToEnd(Node *NewNode)
{
	if (mySize == 0)
	{
		myHead = NewNode;
		myTail = NewNode;
		mySize++;
	}
	else
	{
		myTail->next = NewNode;
		NewNode->formal = myTail;
		myTail = NewNode;
		mySize++;
	}
}
void LinkedList::printList() {
	if (mySize == 0)
		cout << "stocklist hasn't been inserted" << endl;
	else
	{
		Node *currentNode = myHead;
		while (currentNode != myTail)
		{
			cout << std::left << setw(20) << currentNode->stockName << std::left << setw(10)
				<< currentNode->shares << std::left << setw(10) << currentNode->stockPrice << std::left << setw(15)
				<< currentNode->stockPrice*currentNode->shares << "\n";
			currentNode = currentNode->next;
		}
		if (currentNode == myTail)
		{
			cout << std::left << setw(20) << currentNode->stockName << std::left << setw(10)
				<< currentNode->shares << std::left << setw(10) << currentNode->stockPrice << std::left << setw(15)
				<< currentNode->stockPrice*currentNode->shares << "\n";
		}
	}
}
void LinkedList::popFront() {
	if (mySize == 0)
		cout << "There is no stock in the list, can't remove!" << endl;
	else
	{
		if (mySize == 1)
		{
			Node *cur = myTail;
			myHead = myTail = NULL;
			delete cur;
			mySize--;
			cout << "Remove successfully!" << endl;
		}
		else
		{
			Node *cur = myHead;
			myHead = cur->next;
			myHead->formal = NULL;
			delete cur;
			mySize--;
			cout << "Remove successfully!" << endl;
		}

	}
}
void LinkedList::popBack() {
	if (mySize == 0)
		cout << "There is no stock in the list, can't remove!" << endl;
	else
	{
		if (mySize == 1)
		{
			Node *cur = myTail;
			myHead = myTail = NULL;
			delete cur;
			mySize--;
			cout << "Remove successfully!" << endl;
		}
		else
		{
			Node *cur = myTail;
			myTail = cur->formal;
			myTail->next = NULL;
			delete cur;
			mySize--;
			cout << "Remove successfully!" << endl;
		}
	}
}
void LinkedList::removeNodeFromList(string name) {
	bool flag = false;
	if (mySize == 0)
		cout << "There is no stock in the list, can't remove!" << endl;
	else
	{
		Node *currentNode = myHead;
		if (currentNode->stockName == name && currentNode == myHead)
		{
			popFront();
			flag = true;
		}
		else if (myTail->stockName == name)
		{
			popBack();
			flag = true;
		}
		else
		{
			int counter;
			for (counter = 0; counter < mySize - 2; counter++)
			{
				if ((currentNode->next)->stockName == name)
				{
					Node *s = currentNode->next;
					currentNode->next = s->next;
					(s->next)->formal = currentNode;
					delete s;
					mySize--;
					cout << "Remove successfully!" << endl;
					flag = true;
					break;
				}
				else
					currentNode = currentNode->next;
			}
			if (!flag)
				cout << "Item Not Found" << endl;
		}
	}
}

void LinkedList::swapNode(Node* Node1, Node* Node2) {
	if (Node1 == myHead && Node2 != myTail)
	{
		if (Node1->next == Node2)
		{
			Node*after = Node2->next;
			Node2->formal = NULL;
			Node2->next = Node1;
			Node1->formal = Node2;
			Node1->next = after;
			after->formal = Node1;
			myHead = Node2;
		}
		else
		{
			Node* pre = Node2->formal;
			Node* after_2 = Node2->next;
			Node* after_1 = Node1->next;
			Node1->next = after_2;
			after_2->formal = Node1;
			after_1->formal = Node2;
			Node2->next = after_1;
			Node2->formal = NULL;
			pre->next = Node1;
			Node1->formal = pre;
			myHead = Node2;
		}

	}
	else if (Node1 != myHead && Node2 == myTail)
	{
		if (Node1->next == Node2)
		{
			Node*pre = Node1->formal;
			pre->next = Node2;
			Node2->formal = pre;
			Node2->next = Node1;
			Node1->formal = Node2;
			Node1->next = NULL;
			myTail = Node1;
		}
		else
		{
			Node* pre_1 = Node1->formal;
			Node*pre_2 = myTail->formal;
			Node* after = Node1->next;

			Node1->next = NULL;
			Node1->formal = pre_2;
			pre_2->next = Node1;
			Node2->next = after;
			Node2->formal = pre_1;
			pre_1->next = Node2;
			after->formal = Node2;
			myTail = Node1;
		}

	}
	else if ((Node1 == myHead && Node2 == myTail) || (Node1 == myTail && Node2 == myHead))
	{
		if (Node1->next == Node2)
		{
			Node1->next = NULL;
			Node1->formal = Node2;
			Node2->formal = NULL;
			Node2->next = Node1;
			myHead = Node2;
			myTail = Node1;
		}
		else if (Node2->next == Node1)
		{
			Node2->next = NULL;
			Node2->formal = Node1;
			Node1->next = Node2;
			Node1->formal = NULL;
			myHead = Node1;
			myTail = Node2;
		}
		else
		{
			Node* after = myHead->next;
			Node* pre = myTail->formal;
			Node* head = myHead;
			Node* tail = myTail;

			tail->next = after;
			after->formal = tail;
			myTail->formal = NULL;
			pre->next = head;
			head->formal = pre;
			head->next = NULL;
			myHead = tail;
			myTail = head;
		}

	}
	else if (Node1 != myTail && Node2 == myHead)
	{
		if (Node2->next == Node1)
		{
			Node*after = Node1->next;
			Node1->formal = NULL;
			Node1->next = Node2;
			Node2->formal = Node1;
			Node2->next = after;
			after->formal = Node2;
			myHead = Node1;
		}
		else
		{
			Node* pre_1 = Node1->formal;
			Node* after_1 = Node1->next;
			Node* after_2 = Node2->next;

			Node1->next = after_2;
			after_2->formal = Node1;
			Node1->formal = NULL;
			Node2->next = after_1;
			after_1->formal = Node2;
			Node2->formal = pre_1;
			pre_1->next = Node2;
			myHead = Node1;
		}

	}
	else if (Node1 == myTail && Node2 != myHead)
	{
		if (Node2->next == Node1)
		{
			Node*pre = Node2->formal;
			pre->next = Node1;
			Node1->formal = pre;
			Node1->next = Node2;
			Node2->formal = Node1;
			Node2->next = NULL;
			myTail = Node2;
		}
		else
		{
			Node* pre_1 = Node1->formal;
			Node* pre_2 = Node2->formal;
			Node* after_2 = Node2->next;

			Node1->next = after_2;
			after_2->formal = Node1;
			Node1->formal = pre_2;
			pre_2->next = Node1;
			Node2->next = NULL;
			Node2->formal = pre_1;
			pre_1->next = Node2;
			myTail = Node2;
		}

	}
	else
	{
		if (Node1->next == Node2)
		{
			Node*pre = Node1->formal;
			Node*after = Node2->next;
			pre->next = Node2;
			Node2->formal = pre;
			Node2->next = Node1;
			Node1->formal = Node2;
			Node1->next = after;
			after->formal = Node1;
		}
		else if (Node2->next == Node1)
		{

			Node*pre = Node2->formal;
			Node*after = Node1->next;
			pre->next = Node1;
			Node1->formal = pre;
			Node1->next = Node2;
			Node2->formal = Node1;
			Node2->next = after;
			after->formal = Node2;
		}
		else
		{
			Node* pre_1 = Node1->formal;
			Node* pre_2 = Node2->formal;
			Node* after_1 = Node1->next;
			Node* after_2 = Node2->next;

			Node1->next = after_2;
			after_2->formal = Node1;
			Node1->formal = pre_2;
			pre_2->next = Node1;
			Node2->next = after_1;
			after_1->formal = Node2;
			Node2->formal = pre_1;
			pre_1->next = Node2;
		}

	}
}
void LinkedList::selectsort() {
	if (mySize <= 1)
		return;
	for (Node* test = myHead; test != NULL; test = test->next)
	{
		for (Node* cur = test->next; cur != NULL; cur = cur->next)
		{
			if (cur->stockPrice*cur->shares < test->stockPrice*test->shares)
			{
				swapNode(cur, test);
				Node* t;
				t = cur;
				cur = test;
				test = t;
			}
		}
	}
}
Node *LinkedList::getMyHead() const {
	return myHead;
}

Node *LinkedList::getMyTail() const {
	return myTail;
}

int LinkedList::getMySize() const {
	return mySize;
}

LinkedList::~LinkedList() {}

bool LinkedList::changeStockShares(string & name, int changeShares, double price, bool flag) {
	if (mySize == 0)
	{
		cout << "There is no stock in the list" << endl;
		return false;
	}
	Node*currentNode = myHead;
	while (currentNode != myTail)
	{
		if (currentNode->stockName == name)
		{
			if (flag)
			{
				currentNode->shares += changeShares;
				currentNode->stockPrice = price;
				cout << "The stock is in the list, has increase the shares." << endl;
				return true;
			}
			else
			{
				if (changeShares <= currentNode->shares)
				{
					currentNode->shares -= changeShares;
					currentNode->stockPrice = price;
					cout << "The stock is in the list, has decrease the shares" << endl;
					if (currentNode->shares == 0)
					{
						cout << "The shares of the stock is 0, remove it from the list" << endl;
						removeNodeFromList(name);
					}

					return true;
				}
				else
				{
					cout << "The current shares is less than you want to sell!" << endl;
					return false;
				}


			}
		}
		currentNode = currentNode->next;
	}
	if (currentNode == myTail)
	{
		if (currentNode->stockName == name)
		{
			if (flag)
			{
				currentNode->shares += changeShares;
				currentNode->stockPrice = price;
				cout << "The stock is in the list, has increase the shares." << endl;
				return true;
			}
			else
			{
				if (changeShares <= currentNode->shares)
				{
					currentNode->shares -= changeShares;
					currentNode->stockPrice = price;
					cout << "The stock is in the list, has decrease the shares" << endl;
					if (currentNode->shares == 0)
					{
						cout << "The shares of the stock is 0, remove it from the list" << endl;
						removeNodeFromList(name);
					}

					return true;
				}
				else
				{
					cout << "The current shares is less than you want to sell!" << endl;
					return false;
				}


			}
		}
	}
	cout << "didn't find the stock, need add it in the end" << endl;
	return false;
}


