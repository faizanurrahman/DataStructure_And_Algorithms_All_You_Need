#include<iostream>

class Node
{
public:
	int data;
	Node* next;

	Node(int nodeValue)
	{
		data = nodeValue;
		next = nullptr;
	}
};

class SingleLinkedList
{
public:
	Node* head;
	Node* tail;
	// Initialize head and tail of linkedlist as nullptr
	SingleLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	/*******************************************************
	Freeing memory on heap, occupied by LinkedList
	Linked List Destructor.
	Time Complexity: O(n)
	Space Complexity: O(1)
	*******************************************************/
	~SingleLinkedList()
	{

		Node* current = NULL;

		if (head != NULL)
		{
			while (head != NULL)
			{
				current = head;
				head = head->next;
				delete current;
			}


		}
		
	}
	
	/*******************************************************
	Insert node at end, append node functionality
	Time Complexity: O(1) with tail pointer, O(n) without tail ponter
	Space Complexity: O(1)
	*******************************************************/
	
	void insertAtEnd(int nodeValue)
	{
		// Create a new node on heap.
		Node* node = new Node(nodeValue);
		
		if (head == NULL) // if list is empty
			head = node;
		else
			tail->next = node;
		tail = node;
	}

	
	/*******************************************************
	Insert new node at front of linked list
	Time Complexity: O(1)
	Space Complexity: O(1)
	*******************************************************/
	
	void insertAtFront(int nodeValue)
	{
		// Create a node
		Node* node = new Node(nodeValue);

	
		if (head != NULL)
			node->next = head;	
		else
			tail = node;
		
		head = node;

	}

	/*******************************************************
	Add value in linkedlist from front to a pos. 
	constrain pos >= 1;
	time complexity: O(n)
	space complexity: O(n)
	*******************************************************/
	void insertFromFront(int pos, int nodeValue)
	{
		if(pos <= 0)
		{
			std::cout << "pos " << pos << " not found in list\n";
			return;
		}

		int index = 0;
		Node* current = head;

		// Create new node on heap
		Node* node = new Node(nodeValue);

		// Search for postion in linkedlist
		while(current != NULL)
		{
			if(pos == ++index)
				// postion found
				break;
		    current = current->next;
		    
		}

		if(head == NULL) // if linkedlist is empty
		{
			head = node;
			tail = node;
			return;

		}

		if (current != NULL)
		{
			node->next = current->next;
			current->next = node;

			// if node added to last, update tail
			if(node->next == NULL)
				tail = node;
		}
		else
		{
			std::cout << "pos " << pos << " not found in list\n";
			delete node;
		}

	}

	/*******************************************************
	Insert new node at given postion from end of linked list.

	Time Complexity: O(n)
	Space Complexity: O(1)
	*******************************************************/
	void insertFromEnd(int pos, int nodeValue)
	{
		if (pos <=0)
		{
			std::cout << "pos " << pos <<" not found in list\n";
			return;
		}

		int index = 0;
		Node* current = head;
		Node* result = head;

		while(current != NULL)
		{
			current = current->next;

			if(index++ >= pos)
			{
				result = result->next;
			}
		}

		// Create new node on heap.
		Node* node = new Node(nodeValue);

		if(head == NULL) // if linkedlist is empty
		{
			head = node;
			tail = node;

		}
		else if (index < pos)
		{
			std::cout << "pos " << pos << " not found in list\n";
			delete node;
		}
		else // if linkedlist is not empty
		{
			node->next = result->next;
			result->next = node;

			if(node->next == NULL)// if node is last, update tail
				tail = node;

		}
	}

	

	/*******************************************************
	Overload operator<< to print LinkedList
	
	Time Complexity: O(n)
	Space Complexity: O(1)
	*******************************************************/
	
	friend std::ostream& operator<<(std::ostream &out, SingleLinkedList &list)
	{
		Node* curr = list.head;
		if(curr == NULL)
		{
			out << "Linked list is Empty: \n";
			return out;
		}
		else
		{
			while(curr != NULL)
			{
				out << curr->data << " --> ";
				curr = curr->next;
			}
			out << "NULL \n";
		}
		
		return out;
	}
	

};



int main(int argc, char const *argv[])
{
	// Set input and output of program to text file.
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	
	// Initialize Empty LinkedList
	SingleLinkedList list;

	// Add node to LinkedList

	list.insertFromEnd(1, 8);
	list.insertFromEnd(1, 7);
	list.insertFromEnd(1, 6);

	list.insertFromFront(1, 8);
	list.insertFromFront(1, 7);
	list.insertFromFront(1, 6);

	list.insertAtFront(234);
	list.insertAtFront(233);

	list.insertAtEnd(3434);
	list.insertAtEnd(3445);

	std::cout << list << '\n';
	return 0;
}