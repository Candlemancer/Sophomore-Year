// Jonathan Petersen
// A01236750
// Stack Lock and Unlock
// Driver Code

#include <iostream>
#include "Node.hpp"

using namespace std;

//So . . . I'm just going to leave this here where I found it.
//Note that it will be more difficult to use since I can't include
//guard the class. Whatever.
class Stack {
  
public:
  //Access controls for the stack.
  void lock();
  void unlock();

  void push(int data);
  void pop();

private:
  //Pointer to the object that locked the stack.
  //NULL if the stack is unlocked.
  static int    m_pLockedTo;
  static int    m_position;
  static Node*  m_pTop;

};

int main (void)
{
  Stack aStack;
  
  aStack.push (1);
  
  Stack bStack;
  
  bStack.push (2);
  
  Stack cStack;
  
  cStack.push (3);
  
  Stack dStack;
  
  dStack.pop ();
  cStack.pop ();
  dStack.push (4);
  aStack.pop ();
  bStack.unlock ();   //Not locked fail
  cStack.lock ();     
  cStack.push (5);
  aStack.pop ();      //Locked Fail
  dStack.lock ();     //Already locked fail
  bStack.unlock ();   //Not owner fail
  dStack.push (6);    //Locked Fail
  cStack.unlock ();
  cStack.push (7);
  aStack.pop ();
  dStack.pop ();
  bStack.pop ();
  cStack.pop ();      //Nothing left error
  
  cin.get();
  return 0;
}

//Static initializiation
int   Stack::m_pLockedTo = NULL;
int   Stack::m_position = 0;
Node* Stack::m_pTop = NULL;

//Lock the stack if it is unlocked
void Stack::lock() {

  //See if the stack is already locked.  
  if(m_pLockedTo != NULL) {
    cout << "lock failed; stack locked" << endl;
    return;
  }

  //Lock the stack
  m_pLockedTo = reinterpret_cast<int>(this);
  cout << "lock successful" << endl;

  return;
}

//Unlock the stack if you are the owner
void Stack::unlock() {

  //See if the stack is locked to someone else
  if(m_pLockedTo != reinterpret_cast<int>(this)) {
    cout << "unlock failed; not lock owner" << endl;
    return;
  }

  //Or if the stack isn't locked at all.
  if(m_pLockedTo == NULL) {
    cout << "unlock failed; stack not locked" << endl;
    return;
  }

  //Or unlock the stack.
  m_pLockedTo = NULL;
  cout << "unlock successful" << endl;

  return;
}

void Stack::push(int data) {

  //cout << "Locked to: " << m_pLockedTo << " I am " << reinterpret_cast<int>(this) << endl;

  //Check for locked stack
  if(m_pLockedTo != reinterpret_cast<int>(this) && m_pLockedTo != NULL) {
    cout << data << " push failed; stack locked" << endl;
    return;
  }

  //Keep track of where we started
  Node* temp = m_pTop;

  //Create a new node.
  m_pTop = new Node(data);

  //Add the downward pointing reference.
  m_pTop->setNext(temp);

  cout << data << " pushed to location " << m_position++ << endl;
  return;
}

void Stack::pop() {

  //Check for empty stack.
  if (m_pTop == NULL) {
    cout << "error: nothing on stack to pop" << endl;
    return;
  }

  //Check for locked stack.
  if(m_pLockedTo != reinterpret_cast<int>(this) && m_pLockedTo != NULL) {
    cout << "pop failed; stack locked" << endl;
    return;
  }

  //Get the data from the current node
  int result = m_pTop->getData();
  Node* temp = m_pTop;

  //Destroy the current node
  m_pTop = m_pTop->getNext();
  delete temp;

  cout << result << " popped from location " << --m_position << endl;
  return;
}
