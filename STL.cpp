///////////////////////// Header files ////////////////////////////////////

#include<iostream>
using namespace std;	

/////////////////////// Structure of Nodes ///////////////////////////////

// Structure of " Singly Linked List "

template<class T>
struct NodeSLL
{
	T Data;
	struct NodeSLL *Next;	
};

// Structure of " Doubly Linked List "

template<class T>
struct NodeDLL
{
	T Data;
	struct NodeDLL *Next;
	struct NodeDLL *Prev;
};

// Structure of " Stack "

template<class T>
struct NodeST
{
    T Data;
    NodeST *Next;
};

// Structure of " Queue "

template<class T>
struct NodeQ
{
    T Data;
    NodeQ *Next;
};

//////////////////////////////  Class    /////////////////////////////////////////

// Class of Singly Linear Linked List

template<class T>
class SinglyLL
{
private:

 	struct NodeSLL <T> *Head;
 	int NodeCount; 

 public:

 			SinglyLL();

 			~SinglyLL();
			
			void insertFirst(T No);

			void insertLast(T No);

			void insertAtPos(T No,int iPos);

			void deleteFirst();

			void deleteLast();

			void deleteAtPos(int iPos);

			void display();

			int count();

};


// Class of Singly Circular Linked List

template<class T>
class SinglyCLL
{

private:

		struct NodeSLL<T> *Head;

		struct NodeSLL<T> *Tail;

		int NodeCount;

public:
		SinglyCLL();

		~SinglyCLL();

		void insertFirst(T No);

		void insertLast(T No);

		void insertAtPos(T No,int iPos);

		void deleteFirst();

		void deleteLast();

		void deleteAtPos(int iPos);

		void display();

		int count();

	
};


// Class of Doubly Linear Linked List

template<class T>
class DoublyLL
{

private:

		struct NodeDLL<T>*Head;

		int NodeCount;

public:
			DoublyLL();

			~DoublyLL();

			void insertFirst(T No);

			void insertLast(T No);

			void insertAtPos(T No,int iPos);

			void deleteFirst();

			void deleteLast();

			void deleteAtPos(int iPos);

			void display();

			int count();
	
};

// Class of Doubly Circular Linked List

template<class T>
class DoublyCLL
{
private:
		struct NodeDLL<T> *Head;
		struct NodeDLL<T> *Tail;
		int NodeCount;

public:

			DoublyCLL();

			~DoublyCLL();

			void insertFirst(T No);

			void insertLast(T No);

			void insertAtPos(T No,int iPos);

			void deleteFirst();

			void deleteLast();

			void deleteAtPos(int iPos);

			void display();

			void displayRev();

			int count();	
};


// Class of Stack

template<class T>
class Stack
{

private:

		struct NodeST<T>*Head;
		int NodeCount;

public:
		Stack();

		~Stack();

		void push(T No);

		T pop();

		void display();

		T peek();

		int count();
};

// Class of Queue

template<class T>
class Queue
{

private: 

		struct NodeQ<T> *Head;
		int NodeCount;

public:
		Queue();

		~Queue();

		void enqueue(T No);

		void dequeue();

		void display();

		int count();

};


///////////////////////// Defination of Function ////////////////////////////////


//////////////////////////////////////////////////////////
//
//  Function Name : SinglyLL
//  Description   : It is used to initialise characteristcs
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
SinglyLL<T>::SinglyLL()
{
	Head=NULL;
	NodeCount=0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~SinglyLL
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
SinglyLL<T>::~SinglyLL()
{
	delete Head;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertFirst
//  Description   : It is used to insert node at First
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::insertFirst(T No)
{
	struct NodeSLL <T>*NewNode=NULL;

	NewNode=new NodeSLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{
		NewNode->Next=Head;
		Head=NewNode;
	}
	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertLast
//  Description   : It is used to insert node at last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::insertLast(T No)
{
	struct NodeSLL <T> *NewNode=NULL;

	struct NodeSLL <T>*Temp=NULL;

	NewNode=new NodeSLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}
	

	NewNode->Data=No;
	NewNode->Next=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{
		Temp=Head;

		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=NewNode;
	}

	NodeCount++;

}

////////////////////////////////////////////////////////////////////////
//
//  Function Name : insertAtPos
//  Input         : Integer (Position)
//  Description   : It is used to insert node at any position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::insertAtPos(T No,int iPos)
{
	struct NodeSLL<T> *NewNode=NULL;
	struct NodeSLL<T> *Temp=NULL;

	int iSize=NodeCount;
	
	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		insertFirst(No);
	}
	else if(iPos==iSize+1)
	{
		insertLast(No);
	}
	else
	{
		NewNode=new NodeSLL<T>;

		if(NewNode==NULL)
		{
			cout<<"Unable to Allowcate Memory!!!\n";
			return;
		}

		NewNode->Data=No;
		NewNode->Next=NULL;

		Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		NewNode->Next=Temp->Next;
		Temp->Next=NewNode;

		NodeCount++;
	}
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name : deleteFirst
//  Description   : It is used to delete first node from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::deleteFirst()
{
	if(Head==NULL)
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct NodeSLL<T>*Temp=Head;

		Head=Head->Next;
		delete Temp;
	}

	NodeCount--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : deleteLast
//  Description   : It is used to delete node from last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::deleteLast()
{
	if(Head==NULL)
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct NodeSLL<T>*Temp=Head;

		while(Temp->Next->Next!=NULL)
		{
			Temp=Temp->Next;
		}

		delete Temp->Next;
		Temp->Next=NULL;
	}

	NodeCount--;

}

///////////////////////////////////////////////////////////////////
//
//  Function Name : deleteAtPos
//  Input         : Integer (Position)
//  Description   : It is used to delete node desired position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::deleteAtPos(int iPos)
{
	int iSize=count();

	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iSize)
	{
		deleteLast();
	}
	else
	{
		struct NodeSLL<T> *Temp=Head;
		struct NodeSLL<T> *DeleteNode=NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		DeleteNode=Temp->Next;

		Temp->Next=DeleteNode->Next;
		delete DeleteNode;

		NodeCount--;
	}
}

//////////////////////////////////////////////////////////
//
//  Function Name : display
//  Description   : It is used to display nodes 
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T>::display()
{
	struct NodeSLL<T>*Temp=Head;

	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"NULL\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count nodes from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T>::count()
{
	return NodeCount;
}


//////////////////////////////////////////////////////////
//
//  Function Name : SinglyCLL
//  Description   : It is used to initialise characteristcs
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////


template<class T>
SinglyCLL<T>::SinglyCLL()
{
	Head=NULL;
	Tail=NULL;
	NodeCount=0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~SinglyCLL
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T>::~SinglyCLL()
{
	delete Head;
	delete Tail;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertFirst
//  Description   : It is used to insert node at First
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::insertFirst(T No)
{
	struct NodeSLL<T> *NewNode=NULL;

	NewNode=new NodeSLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=NewNode;
		Tail=NewNode;
	}
	else
	{
		NewNode->Next=Head;
		Head=NewNode;
	}

	Tail->Next=Head;

	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertLast
//  Description   : It is used to insert node at last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::insertLast(T No)
{
	struct NodeSLL<T> *NewNode=NULL;

	NewNode=new NodeSLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=NewNode;
		Tail=NewNode;
	}
	else
	{
		Tail->Next=NewNode;
		Tail=NewNode;
	}

	Tail->Next=Head;

	NodeCount++;
}


////////////////////////////////////////////////////////////////////////
//
//  Function Name : insertAtPos
//  Input         : Integer (Position)
//  Description   : It is used to insert node at any position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
///////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::insertAtPos(T No,int iPos)
{

	int iSize=NodeCount;

	
	if((iPos<1) || (iPos>iSize+1))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		insertFirst(No);
	}
	else if(iPos==iSize+1)
	{
		insertLast(No);
	}
	else
	{
		struct NodeSLL<T> *NewNode=NULL;
		struct NodeSLL<T> *Temp=NULL;

		NewNode=new NodeSLL<T>;

		if(NewNode==NULL)
		{
			cout<<"Unable to Allowcate Memory!!!\n";
			return;
		}

		NewNode->Data=No;
		NewNode->Next=NULL;

		Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		NewNode->Next=Temp->Next;
		Temp->Next=NewNode;

		NodeCount++;
	}
}


////////////////////////////////////////////////////////////////////////
//
//  Function Name : deleteFirst
//  Description   : It is used to delete first node from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::deleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Tail->Next;
		Tail->Next=Head;
	}

	NodeCount--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : deleteLast
//  Description   : It is used to delete node from last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::deleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		struct NodeSLL<T> *Temp=Head;

		while(Temp->Next!=Tail)
		{
			Temp=Temp->Next;
		}

		Temp->Next=Head;
		delete Tail;
		Tail=Temp;
	}

	NodeCount--;

}

///////////////////////////////////////////////////////////////////
//
//  Function Name : deleteAtPos
//  Input         : Integer (Position)
//  Description   : It is used to delete node desired position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::deleteAtPos(int iPos)
{
	int iSize=NodeCount;

	if((iPos<1) || (iPos>iSize))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iSize)
	{
		deleteLast();
	}
	else
	{
		struct NodeSLL<T> *Temp=Head;
		struct NodeSLL<T> *DeleteNode=NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		DeleteNode=Temp->Next;

		Temp->Next=DeleteNode->Next;
		delete DeleteNode;

		NodeCount--;
	}
}

//////////////////////////////////////////////////////////
//
//  Function Name : display
//  Description   : It is used to display nodes 
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::display()
{

	struct NodeSLL<T> *Temp=Head;

	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}

	while(Temp!=Tail)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"|"<<Temp->Data<<"|->";
	cout<<"\n";

}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count nodes from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>::count()
{
	return NodeCount;
}


//////////////////////////////////////////////////////////
//
//  Function Name : DoublyLL
//  Description   : It is used to initialise characteristcs
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::DoublyLL()
{
	Head=NULL;
	NodeCount=0;
}	

//////////////////////////////////////////////////////////
//
//  Function Name : ~DoublyLL
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
DoublyLL<T>::~DoublyLL()
{
	delete Head;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertFirst
//  Description   : It is used to insert node at First
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::insertFirst(T No)
{
	struct NodeDLL<T>*NewNode=NULL;

	NewNode=new NodeDLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;
	NewNode->Prev=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{
		NewNode->Next=Head;
		Head->Prev=NewNode;
		Head=NewNode;
	}

	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertLast
//  Description   : It is used to insert node at last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::insertLast(T No)
{
	struct NodeDLL<T>*NewNode=NULL;

	NewNode=new NodeDLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;
	NewNode->Prev=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{	
		struct NodeDLL<T>*Temp=Head;

		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}

		Temp->Next=NewNode;
		NewNode->Prev=Temp;
	}

	NodeCount++;
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name : insertAtPos
//  Input         : Integer (Position)
//  Description   : It is used to insert node at any position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
///////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::insertAtPos(T No,int iPos)
{
	int iSize=NodeCount;

	if((iPos<1)||(iPos>iSize+1))
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		insertFirst(No);
	}
	else if(iPos==iSize+1)
	{
		insertLast(No);
	}
	else
	{
		struct NodeDLL<T> *NewNode=NULL;

		NewNode=new NodeDLL<T>;

		if(NewNode==NULL)
		{
			cout<<"Unable to Allowcate Memory!!!\n";
			return;
		}

		NewNode->Data=No;
		NewNode->Next=NULL;
		NewNode->Prev=NULL;

		struct NodeDLL<T> *Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		NewNode->Next=Temp->Next;
		Temp->Next->Prev=NewNode;
		Temp->Next=NewNode;
		NewNode->Prev=Temp;

		NodeCount++;
	}
}


////////////////////////////////////////////////////////////////////////
//
//  Function Name : deleteFirst
//  Description   : It is used to delete first node from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::deleteFirst()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{

		Head=Head->Next;
		delete Head->Prev;
		Head->Prev=NULL;
	}

	NodeCount--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : deleteLast
//  Description   : It is used to delete node from last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::deleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct NodeDLL<T>*Temp=Head;

		while(Temp->Next->Next!=NULL)
		{
			Temp=Temp->Next;
		}

		delete Temp->Next;
		Temp->Next=NULL;
	}

	NodeCount--;
}

///////////////////////////////////////////////////////////////////
//
//  Function Name : deleteAtPos
//  Input         : Integer (Position)
//  Description   : It is used to delete node desired position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::deleteAtPos(int iPos)
{
	int iSize=NodeCount;

	if(iPos<1||iPos>iSize)
	{
		cout<<"Invalid Position!!!\n";
		return;
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iSize)
	{
		deleteLast();
	}
	else
	{
		struct NodeDLL<T> *Temp=Head;

		for( int i=1 ; i<iPos-1 ; i++ )
		{
			Temp=Temp->Next;
		}

		struct NodeDLL<T> *DeleteNode=NULL;

		DeleteNode=Temp->Next;

		Temp->Next=DeleteNode->Next;
		DeleteNode->Next->Prev=Temp;
		delete DeleteNode;

		NodeCount--;
	}
}

//////////////////////////////////////////////////////////
//
//  Function Name : display
//  Description   : It is used to display nodes 
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyLL<T>::display()
{
	struct NodeDLL<T> *Temp=Head;

	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|<=>";
		Temp=Temp->Next;
	}
	cout<<"NULL\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count nodes from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int DoublyLL<T>::count()
{	
	return NodeCount;
}
	

//////////////////////////////////////////////////////////
//
//  Function Name : DoublyCLL
//  Description   : It is used to initialise characteristcs
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::DoublyCLL()
{
	Head=NULL;
	Tail=NULL;
	NodeCount=0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~DoublyCLL
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T>::~DoublyCLL()
{
	delete Head;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertFirst
//  Description   : It is used to insert node at First
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::insertFirst(T No)
{
	struct NodeDLL<T> *NewNode=NULL;

	NewNode=new NodeDLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;
	NewNode->Prev=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=NewNode;
		Tail=NewNode;
	}
	else
	{
		NewNode->Next=Head;
		Head->Prev=NewNode;
		Head=NewNode;
	}
	Tail->Next=Head;
	Head->Prev=Tail;

	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : insertLast
//  Description   : It is used to insert node at last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::insertLast(T No)
{
	struct NodeDLL<T> *NewNode=NULL;

	NewNode=new NodeDLL<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;
	NewNode->Prev=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=NewNode;
		Tail=NewNode;
	}
	else
	{
		Tail->Next=NewNode;
		NewNode->Prev=Tail;
		Tail=NewNode;
	}
	Tail->Next=Head;
	Head->Prev=Tail;

	NodeCount++;
}

////////////////////////////////////////////////////////////////////////
//
//  Function Name : insertAtPos
//  Input         : Integer (Position)
//  Description   : It is used to insert node at any position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
///////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::insertAtPos(T No,int iPos)
{
	int iSize=NodeCount;

	if(iPos<1||iPos>iSize+1)
	{
		cout<<"Invalid Position!!!\n";
		return;
	}
	else if(iPos==1)
	{
		insertFirst(No);
	}
	else if(iPos==iSize+1)
	{
		insertLast(No);
	}
	else
	{
		struct NodeDLL<T> *NewNode=NULL;

		NewNode=new NodeDLL<T>;

		if(NewNode==NULL)
		{
			cout<<"Unable to Allowcate Memory!!!\n";
			return;
		}

		NewNode->Data=No;
		NewNode->Next=NULL;
		NewNode->Prev=NULL;

		struct NodeDLL<T>*Temp=Head;

		for (int i = 1; i < iPos-1; i++)
		{
			Temp=Temp->Next;
		}

		NewNode->Next=Temp->Next;
		Temp->Next->Prev=NewNode;
		NewNode->Prev=Temp;
		Temp->Next=NewNode;

		NodeCount++;
	}

}

////////////////////////////////////////////////////////////////////////
//
//  Function Name : deleteFirst
//  Description   : It is used to delete first node from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::deleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty\n";
		return;
	}
	else if(Head==Tail)
	{

		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Tail->Next;
		Head->Prev=Tail;
		Tail->Next=Head;
	}

	NodeCount--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : deleteLast
//  Description   : It is used to delete node from last
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::deleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty\n";
		return;
	}
	else if(Head==Tail)
	{

		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Tail=Tail->Prev;
		Tail->Next=Head;
		delete Head->Prev;
		Head->Prev=Tail;
	}

	NodeCount--;
}

///////////////////////////////////////////////////////////////////
//
//  Function Name : deleteAtPos
//  Input         : Integer (Position)
//  Description   : It is used to delete node desired position
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::deleteAtPos(int iPos)
{
	int iSize=NodeCount;

	if(iPos<1||iPos>iSize)
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iSize)
	{
		deleteLast();
	}
	else
	{
		struct NodeDLL<T>*Temp=Head;

		for (int i = 1; i < iPos-1 ; ++i)
		{
			Temp=Temp->Next;
		}

		struct NodeDLL<T>*DeleteTemp=Temp->Next;

		Temp->Next=DeleteTemp->Next;
		DeleteTemp->Next->Prev=Temp;

		delete DeleteTemp;

		NodeCount--;

	}
}

//////////////////////////////////////////////////////////
//
//  Function Name : display
//  Description   : It is used to display nodes 
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::display()
{

	struct NodeDLL<T> *Temp=Head;

	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}

	while(Temp!=Tail)
	{
		cout<<"|"<<Temp->Data<<"|<=>";
		Temp=Temp->Next;
	}
	cout<<"|"<<Temp->Data<<"|<=>";
	cout<<"\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : displayRev
//  Description   : It is used to display nodes in Reverse Order
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::displayRev()
{
	struct NodeDLL<T> *Temp=Tail;

	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}

	while(Temp!=Head)
	{
		cout<<"|"<<Temp->Data<<"|<=>";
		Temp=Temp->Prev;
	}
	cout<<"|"<<Temp->Data<<"|<=>";
	cout<<"\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count nodes from Linked List
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::count()
{
	return NodeCount;
}	

//////////////////////////////////////////////////////////
//
//  Function Name : Stack
//  Description   : It is used to initialise characteristcs
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////


template<class T>
Stack<T>::Stack()
{
	Head=NULL;
	NodeCount=0;

}

//////////////////////////////////////////////////////////
//
//  Function Name : ~Stack
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
Stack<T>::~Stack()
{
	delete Head;
}

//////////////////////////////////////////////////////////
//
//  Function Name : push
//  Description   : It is used to push value into stack
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void Stack<T>::push(T No)
{
	struct NodeST<T> *NewNode=NULL;

	NewNode=new NodeST<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}
	NewNode->Data=No;
	NewNode->Next=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{
		NewNode->Next=Head;	
		Head=NewNode;
	}
	

	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : pop
//  Description   : It is used to pop (remove) value from stack
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
T Stack<T>::pop()
{	
	
	if(Head==NULL)
	{
		return -1;
	}

	T No=Head->Data;

	if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		struct NodeST<T> *Temp=Head;

		Head=Head->Next;
		delete Temp;
	}

	NodeCount--;
	return No;
}

//////////////////////////////////////////////////////////
//
//  Function Name : peek
//  Description   : It is used to return top element of stack
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
T Stack<T>::peek()
{
	if(Head==NULL)
	{
		return -1;
	}
	else
	{
		return Head->Data;
	}
	
}

//////////////////////////////////////////////////////////
//
//  Function Name : display
//  Description   : It is used to display stack
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void Stack<T>::display()
{
	if(Head==NULL)
	{
			return;
	}
	struct NodeST<T> *Temp=Head;

	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|\n";
		cout<<"___\n";
		Temp=Temp->Next;
	}
	cout<<"\n";	
}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count value in stack
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int Stack<T>::count()
{
	return NodeCount;
}


//////////////////////////////////////////////////////////
//
//  Function Name : Queue
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
Queue<T>::Queue()
{
	Head=NULL;
	NodeCount=0;
}

//////////////////////////////////////////////////////////
//
//  Function Name : ~Queue
//  Description   : It is used to deallocate memory
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
Queue<T>::~Queue()
{
	delete Head;
}

//////////////////////////////////////////////////////////
//
//  Function Name : enqueue
//  Description   : It is used to insert value into queue
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void Queue<T>::enqueue(T No)
{
	struct NodeQ<T> *NewNode=NULL;

	NewNode=new NodeQ<T>;

	if(NewNode==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	NewNode->Data=No;
	NewNode->Next=NULL;

	if(Head==NULL)
	{
		Head=NewNode;
	}
	else
	{
		struct NodeQ<T>*Temp=Head;

		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}

		Temp->Next=NewNode;
	}

	NodeCount++;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Deueue
//  Description   : It is used to remove value from queue
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void Queue<T>::dequeue()
{
	T No;

	if(Head==NULL)
	{
		cout<<"Queue is Empty!!!\n";
		return;
	}

	No=Head->Data;
	if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	} 	
	else
	{
		struct NodeQ<T> *Temp=Head;

		Head=Head->Next;
		delete Temp;
	}

	cout<<"Removed Element is:"<<No<<endl;

	NodeCount--;
}

//////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : It is used to display queue
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
void Queue<T>::display()
{
	struct NodeQ<T>* Temp=Head;

	while(Temp!=NULL)
	{
		cout<<Temp->Data<<" ";
		Temp=Temp->Next;
	}
	cout<<"\n";
}

//////////////////////////////////////////////////////////
//
//  Function Name : count
//  Description   : It is used to count elements from queue
//  Author        : Omkar Navnath Kadam
//  Date          : 07/09/2022
//
//////////////////////////////////////////////////////////

template<class T>
int Queue<T>::count()
{
	return NodeCount;
}