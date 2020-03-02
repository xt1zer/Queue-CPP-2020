#pragma once
#include <limits>

template<typename T>
struct Node {
	T value;
	Node* next;

	Node(T data) : value(data), next(nullptr) {
	}

	~Node() {
		next = nullptr;
	}
};

template<typename T>
class Queue {
private:
	Node<T>* m_front = nullptr;
	Node<T>* m_back = nullptr;

public:
	Queue<T>() : m_front(nullptr), m_back(nullptr) {
	}

	typedef Node<T>* Iterator;
	Iterator front() const {
		return m_front;
	}
	Iterator back() const {
		return m_back;
	}
	T getValue(const Iterator& iter) const {
		if (iter) return iter->value;
		return std::numeric_limits<int>::min();
	}
	Iterator getNext(const Iterator& iter) const {
		if (iter) return iter->next;
		return nullptr;
	}

	void push(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		if (isEmpty())
			m_back = m_front = newNode;
		else {
			m_back->next = newNode;
			m_back = newNode;
		}
	}

	T pop() {
		if (isEmpty()) return std::numeric_limits<int>::min();
		//return INT_MIN;

		T output = m_front->value;
		Node<T>* oldFront = m_front;

		if (m_front->next)
			m_front = m_front->next;
		else
			m_back = m_front = nullptr;

		delete oldFront;
		return output;
	}

	T peekFront() const {
		if (!isEmpty()) return m_front->value;
		return std::numeric_limits<int>::min();
		//return INT_MIN;
	}

	T peekBack() const {
		if (!isEmpty()) return m_back->value;
		return std::numeric_limits<int>::min();
//		return INT_MIN;
	}

	void clear() {
		while (!isEmpty())
			pop();
	}

	bool isEmpty() const {
		return m_front == nullptr && m_back == nullptr;
	}
};
