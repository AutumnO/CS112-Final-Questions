#pragma once
#include <vector>
#include "ListNode.hpp"
using namespace std;

template<typename DATA_TYPE>
class LinkedList {
public:

	ListNode* _front = nullptr;

	//Problem 1
	int deleteNode(ListNode* front, int value)
	{
		int counter = 0;
		if (front != nullptr && front->value == value) // if value to be removed is first value
		{
			ListNode* new_front = front->next;
			delete front;
			front = new_front;
			return counter;
		}
		ListNode* current = front;
		ListNode* before = nullptr;
		while (current != nullptr && current->value != value) //if the next value is not the one to be removed
		{
			before = current;
			current = current->next;
			counter++;
		}
		if (current != nullptr)								// if the value is the one to be removed
		{
			before->next = current->next;
			delete current;
			return counter;
		}
		else
		{
			return -1;
		}
	}
	
	// Problem 2
	vector<int> toArray(ListNode* front)
	{
		vector<int> a_vector;
		while (front != nullptr)
		{
			a_vector.push_back(front);
			ListNode* new_front = front->next;
			delete front;
			front = new_front;
		}
		return a_vector;
	}

	// Problem 3
	ListNode reverse(ListNode* head)
	{

	}

};