#pragma once
#include <iostream>
#include <fstream>
#include "Queue.h"

void save(Queue<int>& queue, const std::string& fileName) {
//    queue.reverse();
	std::ofstream outFile(fileName);

	while (!outFile.is_open()) {
		std::cout << "File didn't open, give me just a bit\n";
		outFile.open(fileName, std::ios::out);
	}

	Queue<int>::Iterator it = queue.front();

	while (it) {
		outFile << it->value << " ";
		it = it->next;
	}

	outFile.close();
	std::cout << "Queue saved to file!\n";
}

void load(Queue<int>& queue, const std::string fileName) {
	std::ifstream inFile(fileName);

	int i = 0;
	while (!inFile.is_open()) {
		if (i > 2) {
			std::cout << "File failed to open, probably not found, idk\n";
			return;
		}
		std::cout << "File didn't open, give me just a bit\n";
		inFile.open(fileName, std::ios::in);
		++i;
	}

	if (!queue.isEmpty()) queue.clear();

	int data;
	while (inFile >> data)
		queue.push(data);

	inFile.close();
	std::cout << "Queue created from file!\n";
}

void choice(const int& c, Queue<int>& queue) {
	system("clear");

	switch (c) {
		case 0: {
			std::cout << std::endl;
			Queue<int>::Iterator it = queue.front();
			while (it) {
				std::cout << queue.getValue(it) << " ";
				it = queue.getNext(it);
			}
			std::cout << std::endl;
			break;
		}
		case 1: {
			int value;
			std::cout << "Enter value: ";
			std::cin >> value;
			queue.push(value);
			break;
		}

		case 2: {
			int value = queue.pop();
			std::cout << "Popped value " << value << std::endl;
			break;
		}

		case 3: {
			if (queue.isEmpty())
				std::cout << "Queue is empty\n";
			else
				std::cout << "Front = " << queue.peekFront() << std::endl;
			break;
		}

		case 4: {
			if (queue.isEmpty())
				std::cout << "Queue is empty\n";
			else
				std::cout << "Back = " << queue.peekBack() << std::endl;
			break;
		}

		case 5: {
			queue.clear();
			std::cout << "Queue cleared\n";
			break;
		}

		case 6: {
			if (queue.isEmpty())
				std::cout << "Queue is empty\n";
			else
				std::cout << "Queue is not empty\n";
			break;
		}

		case 7: {
			std::string fileName;
			std::cout << "Enter filename: ";
			std::cin >> fileName;
			save(queue, fileName);
			break;
		}

		case 8: {
			std::string fileName;
			std::cout << "Enter filename: ";
			std::cin >> fileName;
			load(queue, fileName);
			break;
		}

	}
}

void menu(Queue<int>& queue) {
	int c;
	while (true) {
		std::cout << "Options:\n\n";
		std::cout << "0. Print queue\n";
		std::cout << "1. Push element\n";
		std::cout << "2. Pop element\n";
		std::cout << "3. Get front element value\n";
		std::cout << "4. Get back element value\n";
		std::cout << "5. Clear queue\n";
		std::cout << "6. Check if empty\n";
		std::cout << "7. Save to file\n";
		std::cout << "8. Read from file\n";

		std::cin >> c;

		choice(c, queue);
	}
}
