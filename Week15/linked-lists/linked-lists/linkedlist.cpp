#include <iostream>
using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

class Element
{
private:
	Element* next;
	int data;
public:
	int getData(  );
	void setNext( Element* );
	Element* getNext(  );
	Element( int );
};

// Constructor. Input: data item to be stored
// Use a parameterised constructor. Element cannot be created unless there is an data item.
Element::Element( int d )
{
	data = d;
}

// Get the data item from the current element. Returns: data of current element.
int Element::getData(  )
{
	return data;
}

// Set the next pointer of an Element to the given address
void Element::setNext( Element* tmp )
{
	next = tmp;
}

// Get the next pointer of an Element. Returns: next element in the linked list.
Element* Element::getNext(  )
{
	return next;
}

class LinkedList
{
private:
	Element* head;
public:
	LinkedList( );
	~LinkedList( );
	void pushFront( int );
	void popFront( );
	int getFront( );
	void display( );

	void pushBack( int );
	void popBack( );
	int getBack( );

	void pushSort( int );
};

// Constructor. Set the head pointer to 0
LinkedList::LinkedList()
{
	head = 0;
}

// Destructor. Cleans up the linked list. There would be a memory leak without
// this function. Try it and see!
LinkedList::~LinkedList()
{
	Element* prior; // stores the previous element ready for deletion
	while( head )	// relies on head becoming 0 at the end of the list. 0 is false.
	{
		prior = head; // store previous element
		head = head->getNext( ); // move head to next element
		delete prior; // destroy previous element
	}
}

// Push the given data on to the front of the linked list.
// head is updated so that it will point at the new front Element
// Input: data item
void LinkedList::pushFront( int d )
{
	Element* tmp = new Element( d ) ; // allocate memory for new element
	tmp->setNext( head ); // new element is going on the front, so next points at head 
	head = tmp; // head update that it point at new, i.e. the new front of the list
}

// Pop the front of the linked list.
// Deletes the first element on the linked list (if one exists)
// head is updated so that it will point at the new front Element, or at 0
// if the list is now emtpy.
void LinkedList::popFront()
{
	if ( head ) // check that the list has at least one element
	{
		Element* current = head; // temp points at the front of the list
		head = head->getNext(  );
		delete current;
	}
}

// Gets the first element on the linked list. If the list is empty then
// exits with an error message. This is in line with with STL approach.
// The list is left unchanged.
// Returns: data item
int LinkedList::getFront( )
{
	if( head ) // check that the list has at least one element
	{
		return head->getData( );
	}
	// only reached if the linked list is empty
	cout << "ERROR: list is empty" << endl;
	system( "pause" );
	exit( 0 );
}

// Display each of the data items on the linked list
void LinkedList::display()
{
	Element* current;
	current = head; // can't use head, otherwise we'd loose track of the start of the list
	while( current ) // relies on current becoming 0 at the end of the list. 0 is false.
	{
		cout << current->getData( ) << endl;
		current = current->getNext( );
	}
	cout << endl;
}

// Push the given data on to the back of the linked list.
// head only needs to be updated if the list was empty to start with
// Input: data item
void LinkedList::pushBack( int d )
{
	Element* tmp = new Element( d ) ; // allocate memory for new element
	tmp->setNext( 0 ); // going on the end, so next must be 0 
	if( head ) // the list is not empty
	{
		Element* current = head;
		while ( current->getNext() ) // only move forward if another element exists
		{
			current = current->getNext( );
		}
		current->setNext( tmp );
	}
	else	// list is empty so first element on the list
	{
		head = tmp; // head points that the new element
	}
}

// Pop the back of the linked list.
// Deletes the last element on the linked list (if one exists)
// head only needs to be updated if the list is now emtpy.
void LinkedList::popBack( )
{
	if ( head ) // check that the list has at least one element
	{
		if( head->getNext() == 0 ) // only one element on list
		{
			delete head; // delete it
			head = 0;	// and set head to 0 because list is now emtpy
		}
		else
		{
			Element* nextToLast = head; // tracks prior element
			Element* current = head;
			while ( current->getNext() ) // only move forward if another element exists
			{
				nextToLast = current;
				current = current->getNext( );
			}
			nextToLast->setNext( 0 ); // going on the end, so next must be 0
			delete current;
		}
	}
}

// Gets the last element on the linked list. If the list is empty then
// exits with an error message. This is in line with with STL approach.
// The list is left unchanged.
// Returns: data item
int LinkedList::getBack( )
{
	if( head ) // check that the list has at least one element
	{
		Element* current = head;
		while ( current->getNext() )
		{
			current = current->getNext( );
		}
		return current->getData( );
	}
	// only reached if the linked list is empty
	cout << "ERROR: list is empty" << endl;
	system( "pause" );
	exit( 0 );
}

// Create a sorted list.
// Push the given data in to the linked list.
// head is updated so that it will point at the new front Element
// Input: data item
void LinkedList::pushSort( int d )
{
	Element* tmp = new Element( d ) ; // allocate memory for new element

	Element* current = head;
	Element* prior = 0;
	while( current )
	{
		if( current->getData() <= d )
		{    // carry on the search
			prior = current;
			current = current->getNext( );
		}
		else
		{
			if( prior )
			{      // goes in the middle
				prior->setNext( tmp );
				tmp->setNext( current );
				return; // stop
			}
			tmp->setNext( current );    // new first element
			head = tmp;
			return; // stop
		}
	}

	if( prior )	// put on end
	{ 
		prior->setNext( tmp );
		tmp->setNext( 0 );
		return; // stop
	}
	else	// first ever element in list
	{
		tmp->setNext( current );
		head = tmp;
	}
}

int main()
{
	_crtBreakAlloc=-1;

	LinkedList* myList = new LinkedList;

	myList->pushBack( 7 );
	myList->pushBack( 5 );
	myList->pushBack( 3 );
	myList->pushBack( 9 );
	myList->display(  );
	cout << endl;

	cout << "last item on the list: " << myList->getBack( ) << endl;
	myList->popBack( );
	cout << endl;

	cout << "new last on the list: " << myList->getBack( ) << endl;
	myList->popBack( );
	cout << endl << endl;

	myList->display(  );

	delete myList;

	system( "pause" );

    _CrtDumpMemoryLeaks();
}