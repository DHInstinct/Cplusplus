#pragma once

#include <iostream>
#include <list>

using namespace std;

template<class T>
class LinkedList
{
public:
	class Node
	{
	public:
		Node(T data, Node* next = nullptr)
			: next(next),
			data(data)
		{
			//this->next = next;
			//this->data = data;
		}

		//private:
		T data;
		Node* next;
	};//end of node class

	//has to be defined explicitly because we defined a copy constructor down below
	LinkedList()
	{

	}

	~LinkedList()
	{
		//delete all nodes
		Node* temp, * temp2;
		temp2 = temp = head;

		while (temp != nullptr)
		{
			temp2 = temp->next;
			delete temp;
			temp = temp2;
		}
	}

	//= delete means do not automatically provide this function
	LinkedList(LinkedList& otherList) = delete;
	LinkedList& operator=(LinkedList& otherList) = delete;

	void Display() const
	{
		if (IsEmpty())
			cout << "list is empty" << endl;
		else
		{
			//cout << head->next->next->data << endl;

			Node* temp = head;
			while (temp != nullptr)//loop through all nodes
			{
				cout << temp->data << " -> ";
				temp = temp->next;	//move to the next node (by assigning its address to temp)
			}
			cout << "nullptr" << endl;
		}
	}
	
	//For testing and making sure when you implement something (like for assignment 8) you 
	//haven't messed up what head and tail point to.
	void GetTailValue()
	{
		if (IsEmpty())
			cout << "tail is nullptr" << endl;
		else
			cout << "tail: " << tail->data << endl;
	}
	
	void GetHeadValue()
	{
		if (IsEmpty())
			cout << "head is nullptr" << endl;
		else
			cout << "head: " << head->data << endl;
	}

	//Purpose: Append a value to the beginning of the list
	//Precondtions: what needs to be setup/true before this can run (otherwise it may break): none
	//Postconditions: The new value should be at the front of the list
	void PushFront(T data)
	{
		if (IsEmpty())
			head = tail = new Node(data, head);
		else
			head = new Node(data, head);
		size++;
	}

	void PushBack(T data)
	{
		//With Tail pointer
		if (IsEmpty())
			head = tail = new Node(data, head);
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
		}

		//Without Tail pointer
		/*if (IsEmpty())
			PushFront(data);
		else
		{
			Node* temp = head;
			while (temp->next != nullptr)//loop until we find the last node
				temp = temp->next;
			temp->next = new Node(data);
		}*/
		size++;
	}

	void Insert(T data, T searchFor)
	{
		if (IsEmpty())
		{
			PushBack(data);
			return;
		}

		Node* temp1;
		Node* temp2 = head;
		temp1 = head;
		
		if (head->data == searchFor)
		{
			PushFront(data);
			return;
		}

		if (head->next != nullptr)
			temp2 = head->next;

		while (temp2->next != nullptr && temp2->data != searchFor)
		{
			temp1 = temp1->next;
			temp2 = temp1->next;
			
		}
		
		if (temp2->data != searchFor)
		{
			PushBack(data);
			return;
		}

		temp1->next = new Node(data);
		temp1->next->next = temp2;
		
	}

	void Remove(T data)
	{
		if (IsEmpty())
			return;

		Node* temp1;
		Node* temp2 = head;
		temp1 = head;

		if (head->data == data)
		{
			PopFront();
			return;
		}

		if (head->next != nullptr)
			temp2 = head->next;

		while (temp2->next != nullptr && temp2->data != data)
		{
			temp1 = temp1->next;
			temp2 = temp1->next;

		}

		if (temp2->data != data)
			return;

		if (temp2 == tail)
		{
			PopBack();
			return;
		}
		
		temp1->next = temp2->next;
	}

	void PopFront()
	{
		if (IsEmpty())//Case 1: List is Empty
			return;

		if (head == tail)
		{
			//Case 2: List has 1 node
			delete head;
			head = tail = nullptr;
		}
		else
		{
			//Case 3: list has multiple nodes
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		size--;
	}

	void PopBack()
	{
		if (IsEmpty())//Case 1: List is Empty
			return;

		if (head == tail)
		{
			//Case 2: List has 1 node
			delete head;
			head = tail = nullptr;
		}
		else//Case 3: List has multiple nodes
		{
			Node* temp = head;
			while (temp->next != tail)//loop until we find the 2nd to last node.
				temp = temp->next;

			temp->next = nullptr;
			delete tail;
			tail = temp;
		}
		size--;
	}

	int Size() const
	{
		return size;
	}

	bool IsEmpty() const
	{
		return head == nullptr;
		return size == 0;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;
};