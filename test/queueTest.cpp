#include <gtest/gtest.h>
#include "Queue.h"

class QueueTest: public testing::Test {
public:
	Queue<int>* q;
	int size = 0;

	void SetUp() {
	}
	void TearDown() {
	}

};

TEST_F(QueueTest, InitQueue) {
	q = new Queue<int>;
	ASSERT_TRUE(!q->front());
	ASSERT_TRUE(!q->back());
}

TEST_F(QueueTest, FillQueue) {
	for (int i = 0; i < 50; ++i) {
		q->push(i);
		++size;
	}
	EXPECT_EQ(q->peekFront(), 0);
	EXPECT_EQ(q->peekBack(), 49);
	ASSERT_EQ(size, 50);
}

TEST_F(QueueTest, ClearQueue) {
	q->clear();
	size = 0;
	ASSERT_EQ(q->isEmpty(), true);
}

TEST_F(QueueTest, PushAndPop) {
	q->push(size++);
	int popped = q->pop();
	size = 0;

	ASSERT_EQ(popped, 0);
	ASSERT_EQ(q->pop(), INT32_MIN);
}
