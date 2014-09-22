#include "gtest\gtest.h"
#include "Queue.hpp"

#include <string>

/*
 * Update this once you've templated the Queue class
 */
TEST(Queue, intTest)
{

	Queue<int> myQueue;

  myQueue.enqueue(1);
  myQueue.enqueue(2);
  myQueue.enqueue(3);
  myQueue.enqueue(4);
  myQueue.enqueue(5);
  myQueue.enqueue(6);

  EXPECT_EQ(6, myQueue.getCount());

  EXPECT_EQ(1, myQueue.front());

  EXPECT_EQ(1, myQueue.dequeue());
  EXPECT_EQ(2, myQueue.dequeue());
  EXPECT_EQ(3, myQueue.dequeue());
  EXPECT_EQ(4, myQueue.dequeue());
  EXPECT_EQ(5, myQueue.dequeue());
  EXPECT_EQ(6, myQueue.dequeue());
}

/*
 * Update this once you've templated the Queue class
 * Make it use chars
 */
TEST(Queue, charTest)
{
  Queue<char> myQueue;

  myQueue.enqueue('A');
  myQueue.enqueue('B');
  myQueue.enqueue('C');
  myQueue.enqueue('D');
  myQueue.enqueue('E');
  myQueue.enqueue('F');

  EXPECT_EQ(6, myQueue.getCount());

  EXPECT_EQ('A', myQueue.front());

  EXPECT_EQ('A', myQueue.dequeue());
  EXPECT_EQ('B', myQueue.dequeue());
  EXPECT_EQ('C', myQueue.dequeue());
  EXPECT_EQ('D', myQueue.dequeue());
  EXPECT_EQ('E', myQueue.dequeue());
  EXPECT_EQ('F', myQueue.dequeue());
}

/*
 * Update this once you've templated the Queue class
 * Make it use doubles
 */
TEST(Queue, doubleTest)
{
  Queue<double> myQueue;

  myQueue.enqueue(1.15);
  myQueue.enqueue(2.15);
  myQueue.enqueue(3.15);
  myQueue.enqueue(4.15);
  myQueue.enqueue(5.15);
  myQueue.enqueue(6.15);

  EXPECT_EQ(6, myQueue.getCount());

  EXPECT_EQ(1.15, myQueue.front());

  EXPECT_EQ(1.15, myQueue.dequeue());
  EXPECT_EQ(2.15, myQueue.dequeue());
  EXPECT_EQ(3.15, myQueue.dequeue());
  EXPECT_EQ(4.15, myQueue.dequeue());
  EXPECT_EQ(5.15, myQueue.dequeue());
  EXPECT_EQ(6.15, myQueue.dequeue());
}

/*
 * Update this once you've templated the Queue class
 * Make it use strings
 */
TEST(Queue, stringTest)
{
  Queue<string> myQueue;

  myQueue.enqueue("1 blind mice");
  myQueue.enqueue("2 blind mice");
  myQueue.enqueue("3 blind mice");
  myQueue.enqueue("4 blind mice");
  myQueue.enqueue("5 blind mice");
  myQueue.enqueue("6 blind mice");

  // Use EXPECT_STREQ when EXPECT-ing on strings
  EXPECT_EQ(6, myQueue.getCount());

  EXPECT_EQ("1 blind mice", myQueue.front());

  EXPECT_EQ("1 blind mice", myQueue.dequeue());
  EXPECT_EQ("2 blind mice", myQueue.dequeue());
  EXPECT_EQ("3 blind mice", myQueue.dequeue());
  EXPECT_EQ("4 blind mice", myQueue.dequeue());
  EXPECT_EQ("5 blind mice", myQueue.dequeue());
  EXPECT_EQ("6 blind mice", myQueue.dequeue());
}
