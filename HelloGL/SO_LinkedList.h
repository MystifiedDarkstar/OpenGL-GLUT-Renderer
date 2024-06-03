#pragma once
#ifndef _SO_LINKEDLIST_H
#define _SO_LINKEDLIST_H

#include "Structures.h"
#include "SO_BaseClass.h"
#include <iostream>
#include <iomanip>

struct ListNode
{
	ListNode* next;
	SO_BaseClass* objectData;
};


class SO_LinkedList
{
public:
	SO_LinkedList();
	~SO_LinkedList();

	ListNode* MakeNode(ListNode** head,SO_BaseClass* scObj);

	ListNode* InsertFirst(ListNode** head,SO_BaseClass* scObj);
	void InsertAfter(ListNode* lastNode,SO_BaseClass* scObj);

	void DeleteList(ListNode** node);
	void DeleteFirst(ListNode** head);
	void DeleteAfter(ListNode* node);
	void DeleteAtPosition(ListNode* node, int pos);

	ListNode* GetNodeAtPos(ListNode* node, int pos);
	ListNode* Find(ListNode* node, SO_BaseClass* scObj);

	void DrawList(ListNode* node);
	void UpdateList(ListNode* node);

	void PrintList(ListNode* node);
	void PrintListBackwards(ListNode* node);

	int ReturnSizeList();

private:
	ListNode* head = nullptr;
	int m_listLength = 0;
};
#endif

