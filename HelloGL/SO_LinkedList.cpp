#include "SO_LinkedList.h"

SO_LinkedList::SO_LinkedList()
{

}

SO_LinkedList::~SO_LinkedList()
{

}

ListNode* SO_LinkedList::MakeNode(ListNode** head,SO_BaseClass* scObj)
{
	ListNode* newNode = new ListNode;
	ListNode* last = *head;

	newNode->objectData = scObj;
	newNode->next = nullptr;

	if (*head == nullptr)
	{
		*head = newNode;
		m_listLength++;
		return newNode;
	}

	while (last->next != nullptr)
	{
		last = last->next;
	}

	last->next = newNode;
	m_listLength++;
	return newNode;
}

ListNode* SO_LinkedList::InsertFirst(ListNode** head,SO_BaseClass* scObj)
{
	ListNode* newNode = new ListNode;

	newNode->objectData = scObj;
	newNode->next = *head;
	*head = newNode;
	m_listLength++;
	return newNode;
}

void SO_LinkedList::InsertAfter(ListNode* lastNode,SO_BaseClass* scObj)
{
	if (lastNode == nullptr)
	{
		std::cout << "lastNode cannot be null." << std::endl;
		return;
	}
	ListNode* newNode = new ListNode;

	newNode->objectData = scObj;
	newNode->next = lastNode->next;
	lastNode->next = newNode;
	m_listLength++;
}

void SO_LinkedList::DeleteList(ListNode** node)
{
	std::cout << "Deleting List..." << std::endl;

	ListNode* pTemp = *node;
	ListNode* next;

	while (pTemp != nullptr)
	{
		next = pTemp->next;
		delete pTemp;
		pTemp = next;
	}
	m_listLength = 0;
	*node = nullptr;
}

void SO_LinkedList::DeleteFirst(ListNode** head) 
{
	ListNode* dTemp = *head;
	*head = dTemp->next;

	m_listLength--;

	delete dTemp;
	dTemp = nullptr;
}

void SO_LinkedList::DeleteAfter(ListNode* node)
{
	ListNode* pTemp;
	if (node != nullptr && node->next != nullptr)
	{
		pTemp = node->next;
		node->next = pTemp->next;
		m_listLength--;
		delete pTemp;
		pTemp = nullptr;
	}
}

void SO_LinkedList::DeleteAtPosition(ListNode* node, int pos)
{
	if (pos == 0)
	{
		delete node;
		node = nullptr;
	}
	else
	{
		ListNode* pTemp;
		ListNode* dTemp;

		int posCount = 0;
		while (node != nullptr)
		{
			if (posCount == pos)
			{
				pTemp = node;
				if (pTemp != nullptr && pTemp->next != nullptr)
				{
					dTemp = pTemp->next;
					if (dTemp->next != nullptr)
						pTemp->next = dTemp->next;

					m_listLength--;
					delete dTemp;
					dTemp = nullptr;
				}
			}
			posCount++;
			node = node->next;
		}
		std::cout << pos << " was not a valid ID In list..." << std::endl;
		return;
	}
}

ListNode* SO_LinkedList::GetNodeAtPos(ListNode* node, int pos)
{
	int posCount = 0;
	while (node != nullptr)
	{
		if (posCount == pos)
		{	
			return node;
		}
		posCount++;
		node = node->next;
	}
	std::cout << pos << " was not a valid ID In list..." << std::endl;
	return nullptr;
}

ListNode* SO_LinkedList::Find(ListNode* node, SO_BaseClass* scObj)
{
	while (node != nullptr)
	{
		if (node->objectData == scObj)
		{
			return node;
		}
		node = node->next;
	}

	std::cout << "Sceneobject could not be found..." << std::endl;
	return nullptr;
}

void SO_LinkedList::DrawList(ListNode* node)
{
	if (node != nullptr)
	{
		node->objectData->Draw();
		DrawList(node->next);
	}
}

void SO_LinkedList::UpdateList(ListNode* node)
{

	while (node != nullptr)
	{
		node->objectData->Update();
		node = node->next;
	}
}

void SO_LinkedList::PrintList(ListNode* node)
{
	if (node != nullptr)
	{
		std::cout << std::setw(5) << "| " << node->objectData << " |-->";
		PrintList(node->next);
	}
	else if (node == nullptr)
		std::cout << std::endl;
}

void SO_LinkedList::PrintListBackwards(ListNode* node)
{
	if (node != nullptr)
	{
		PrintListBackwards(node->next);
		std::cout << std::setw(5) << "| " << node->objectData << " |-->";
	}
}

int SO_LinkedList::ReturnSizeList()
{
    return m_listLength;
}
