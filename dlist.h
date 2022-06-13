#ifndef __DLIST_H__
#define __DLIST_H__

class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  // Maintenance methods

  Dlist();                                // constructor
  Dlist(const Dlist &l);                  // copy constructor
  Dlist &operator=(const Dlist &l);       // assignment
  ~Dlist();                               // destructor

  // Operational methods

  // EFFECTS: returns true if list is empty, false otherwise
  bool IsEmpty() const;

  // MODIFIES: this
  // EFFECTS: inserts o at the front of the list
  void InsertFront(const T &o);

  // MODIFIES: this
  // EFFECTS: inserts o at the back of the list
  void InsertBack(const T &o);

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveFront();

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveBack();

 private:
  // A private type

  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  // Private member variables 

  node   *first; // The pointer to the first node (NULL if none)
  node   *last;  // The pointer to the last node (NULL if none)

  // Private utility methods

  // EFFECTS: called by constructors to establish empty list invariant
  void MakeEmpty();

  // EFFECTS: called by copy constructor/operator= to copy nodes
  //          from a source instance l to this instance
  void CopyAll(const Dlist &l);
    
  // EFFECTS: called by destructor and operator= to remove and destroy
  //          all list nodes
  void RemoveAll();
};

// Constructor
template <typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
}

// Copy constructor
template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  MakeEmpty();
  CopyAll(l);
}

// Assignment operator
template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist<T> &l) {
  if (this != &l) {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

// Destructor 
template <typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}

// EFFECTS: returns true if list is empty, false otherwise
//
// PSEUDOCODE:
// algorithm IsEmpty
//    if(first and last pointers are NULL) return true
//    else return false
//
template <typename T>
bool Dlist<T>::IsEmpty() const {
  if(first == NULL && last == NULL)
    return true;
  else
    return false;
}

// MODIFIES: this
// EFFECTS: inserts o at the front of the list
//
// PSEUDOCODE:
// algorithm InsertFront(const &T o)
//  create newNode
//  object T in newNode = argument o
//  newNode previous address pointer = NULL
//
//  if(Dlist is empty)
//    newNode next address pointer = NULL
//    first and loast pointers = newNode
//  else
//    newNode next address pointer = first
//    first node previous address pointer = newNode
//    first pointer = newNode

template <typename T>
void Dlist<T>::InsertFront(const T& o)
{
  node* newNode = new node;
  newNode->o = o;
  newNode->prev = NULL;
  
  if(IsEmpty())
  {
    newNode->next = NULL;
    first = newNode;
    last = newNode;
  }
  else
  {
    newNode->next = first;
    first->prev = newNode;
    first = newNode;
  }

}

// MODIFIES: this
// EFFECTS: inserts o at the back of the list
//
// PSEUDOCODE:
// algorithm InsertBack
//  create newNode
//  object T in newNode = argument o
//  newNode next address pointer = NULL
//
//  if(Dlist is empty)
//    newNode previous address pointer = NULL
//    first and loast pointers = newNode
//  else
//    newNode previous address pointer = last
//    last node next address pointer = newNode
//    last pointer = newNode

template <typename T>
void Dlist<T>::InsertBack(const T& o)
{
  node* newNode = new node;
  newNode->o = o;
  newNode->next = NULL;
  
  if(IsEmpty())
  {
    newNode->prev = NULL;
    last = newNode;
    first = newNode;
  }
  else
  {
    newNode->prev = last;
    last->next = newNode;
    last = newNode;
  }
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
//
// PSEUDOCODE:
// algorithm RemoveFront
//  if(DList is empty)
//    throw an empty list
//
//  newNode pointer frontNode = first
//  first = frontNode next
//
//  if(first ==  NULL)
//    last = NULL
//  else
//    first previous = NULL;
//
//  object val = frontNodes object
//  delete frontNode
//
//  return val

template <typename T>
T Dlist<T>::RemoveFront()
{
  if(IsEmpty())
    throw emptyList();
  
  node* frontNode = first;
  first = frontNode->next;
  
  if(first == NULL)
    last = NULL;
  else
    first->prev = NULL;
  
  T val = frontNode->o;
  delete frontNode;
  
  return val;
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
//
// PSEUDOCODE:
// algorithm RemoveBack
//  if(DList is empty)
//    throw an empty list
//
//  newNode pointer endNode = last
//  last = endNode previous
//
//  if(last ==  NULL)
//    first = NULL
//  else
//    last next address = NULL;
//
//  object val = endNodes object
//  delete endNode
//
//  return val

template <typename T>
T Dlist<T>::RemoveBack()
{
  if(IsEmpty())
  {
    emptyList eList;
    throw eList;
  }
  
  node* endNode = last;
  last = endNode->prev;
  
  if(last == NULL)
    first = NULL;
  else
    last->next = NULL;
  
  T val = endNode->o;
  delete endNode;
  
  return val;
}

// EFFECTS: called by constructors to establish empty list invariant
//
// PSEUDOCODE:
// algorithm MakeEmpty
//  first pointer = NULL
//  last pointer = NULL

template <typename T>
void Dlist<T>::MakeEmpty()
{
  first = NULL;
  last = NULL;
}

// EFFECTS: called by copy constructor/operator= to copy nodes
//          from a source instance l to this instance
//
// PSEUDOCODE:
// algorithm CopyAll
//  new node currentNode = l.first
//
//  while(currentNode != NULL)
//  {
//    InsertBack(currentNodes object)
//    currentNode = currentNode next
//  }

template <typename T>
void Dlist<T>::CopyAll(const Dlist &l)
{
  node* currentNode = l.first;
  
  while(currentNode != NULL)
  {
    InsertBack((currentNode)->o);
    currentNode = currentNode->next;
  }
}

// EFFECTS: called by destructor and operator= to remove and destroy
//          all list nodes
//
// PSEUDOCODE:
// algorithm RemoveAll
//
//  if(Dlist is empty)
//    return
//  while(Dlist is not empty)
//    removeFront()

template <typename T>
void Dlist<T>::RemoveAll()
{
  if(IsEmpty())
    return;
  while(!IsEmpty())
  {
    RemoveFront();
  }
}

#endif
