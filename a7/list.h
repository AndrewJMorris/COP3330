// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor
   //-------Copy & Assignment Op--------//
   List(const NODETYPE &value);                                           // Copy constructor
   List& operator= (const NODETYPE &value);                               // Assignment operator.
   //----------insertFunctions----------//
   void insertAtFront( const NODETYPE & );           // Given
   void insertMiddle( const NODETYPE &, int x);      // Added middle insert function with added parameter int.
   void insertAtBack( const NODETYPE & );            // Given
   //----------removeFunctions----------//
   bool removeFromFront( NODETYPE & );               // Given
   bool removeMiddle(NODETYPE &, int x);             // Added remove middle function with added parameter int.
   bool removeFromBack( NODETYPE & );                // Given
   bool isEmpty() const;                             // Given
   void print() const;                               // Given

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List() 
   : firstPtr( 0 ), 
     lastPtr( 0 ) 
{ 
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {  
         tempPtr = currentPtr;

// commented out the output -- no need to print what we are deallocating
//         cout << tempPtr->data << '\n';  

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      }

   }

//   cout << "All nodes destroyed\n\n";

} // end List destructor

// Copy Constructor 
template < class NODETYPE >                     // two steps, empty list, new list ptr = 0
List< NODETYPE >::List(const NODETYPE &value)
{
   ListNode< NODETYPE > *tempPtr = value.firstPtr;
   firstPtr = value.firstPtr;

   // tempPtr->data;
   while (tempPtr != 0)
   { 
      tempPtr = tempPtr->nextPtr;
      firstPtr->nextPtr = tempPtr->nextPtr;
      this->data = tempPtr->data;
   }

   delete tempPtr;

}// End copy constructor. 

// Assignment Operator
template < class NODETYPE > 
List < NODETYPE >&List< NODETYPE >::operator= (const NODETYPE &value)
{
   ListNode< NODETYPE > *tempPtr = value.firstPtr;
   firstPtr = value.firstPtr;

   // tempPtr->data;
   while (tempPtr->nextPtr != NULL)
   { 
      tempPtr = tempPtr->nextPtr;
      insertAtFront(value.data);
   }
   delete tempPtr;

   return *this;
}

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else
//1 1 2 2 2 3 2 4 2 5 2 6 2 7 2 8
} // end function insertAtFront

//---------------------Define insertMiddle-----------------------//
// insert node at middle of the list.
template< class NODETYPE >
void List< NODETYPE >::insertMiddle(const NODETYPE &value, int pos)
{  
   int counter = 0;                                             // Will hold the length of the linked list
   ListNode< NODETYPE > *newPtr = getNewNode( value );


   if (isEmpty())
      firstPtr = lastPtr = newPtr;

   else
   {
      if ( pos <= 1 )
      {
         insertAtFront(value);                                     // When pos calls to place the value less than the list or at the first slot of the list insert the value at the front. 
      }

      ListNode< NODETYPE > *currentPtr = firstPtr;                 // set current = to first.
      while (counter != pos)
      {  
         counter++;
         currentPtr = currentPtr->nextPtr;                     
         
         if (counter - 1 == pos-1)                                   // Pos - 1 = desired set posiiton. 
         {  
            cout << "Counter is: " << counter << '\n';
            newPtr->nextPtr = currentPtr->nextPtr;                 // Set value at the position.
            currentPtr->nextPtr = newPtr;
            break;
         }
         else if (currentPtr->nextPtr == NULL)   
         {
            cout << "Counter when >: " << counter << '\n';
            insertAtBack(value);
            break;
         }
         cout << "Counter after: " << counter << '\n';
      }
   }

}// End function insertMiddle

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;
   } // end else

} // end function insertAtBack

// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromFront

//---------------------Define removeMiddle-----------------------//
// delete node from middle of the list
template< class NODETYPE >
bool List< NODETYPE >::removeMiddle( NODETYPE &value, int pos)
{
   int counter = 0;
   ListNode<NODETYPE> *tempPtr;
   ListNode<NODETYPE> *currentPtr = firstPtr;

   if (isEmpty())                                           // If its empty return false.
      return false;

   if (pos <= 0)                                         // It is less than 0 return false and remove nothing.
      return false;
      
   
   while (currentPtr != 0)   
   {  
      cout << "This is what Counter is: " << counter << endl;
      currentPtr = currentPtr->nextPtr;
      counter++;

      if (currentPtr->nextPtr == NULL)                                  // If it is null then the position is greater than the size of the linked list.
      {
         return false;
      }
      else if (counter == pos - 1)                                      // at pos-1 currentPtr should be where we want it so that if we insert currentPtr->nextPtr it deletes the next value, the desired value. 
      {
         cout << "This is what Counter is: " << counter << endl;
         tempPtr = currentPtr->nextPtr;
         value = tempPtr->data;
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
         return true;
      }
   }
//1 1 2 2 2 3 2 4 2 5 2 6 2 7 2 8
}// end function removeMiddle

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromBack

// is List empty?
template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
   
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
