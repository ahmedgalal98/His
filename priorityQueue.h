#pragma once
#include <vector>
#include <iostream>

template< typename T >
class priorityQueue
{
	std::vector<T> nodes;

public:
	int size() const {
		return nodes.size();
	}

	// insert new node in the priorityQueue with value 'v'
	void insertNode(T v) {
		nodes.push_back(v);
		int nodeIdx = size() - 1;
		siftUp(nodeIdx);
	}


	// return the root node and delete it
	T deque() {
		if (size() < 1)
		{
			std::cout << "The Heap is empty!\n";
			// Close the app
			exit(1);
		}
		int lastNodeIdx = size() - 1;
		std::swap(nodes[lastNodeIdx], nodes[0]);
		T val = nodes.back();
		nodes.pop_back();
		siftDown(0);
		return val;
	}

	// return the root node
	T peek() {
		if (size() < 1)
		{
			std::cout << "The Heap is empty!\n";
			// Close the app
			exit(1);
		}
		return nodes[0];
	}


private:
	void siftUp(int idx) {
		if (idx < 0) return;

		int parent = parentNode(idx);

		// pointer
		if (std::is_pointer<T>::value) {
			if (idx > 0 && nodes[idx]->getSeverity() > nodes[parent]->getSeverity())
			{
				std::swap(nodes[idx], nodes[parent]);
				siftUp(parent);
			}
		}
		else {
			if (idx > 0 && nodes[idx] > nodes[parent])
			{
				std::swap(nodes[idx], nodes[parent]);
				siftUp(parent);
			}
		}
	}

	void siftDown(int idx) {

		int left = leftNode(idx);
		int right = rightNode(idx);
		int minIdx = idx;

		// pointer
		if (std::is_pointer<T>::value) {
			if (left < size() && nodes[left]->getSeverity() > nodes[minIdx]->getSeverity())
				minIdx = left;

			if (right < size() && nodes[right]->getSeverity() > nodes[minIdx]->getSeverity())
				minIdx = right;
		}
		else {
			if (left < size() && nodes[left] > nodes[minIdx])
				minIdx = left;

			if (right < size() && nodes[right] > nodes[minIdx])
				minIdx = right;
		}

		if (minIdx != idx)
		{
			std::swap(nodes[minIdx], nodes[idx]);
			siftDown(minIdx);
		}
	}

	static int parentNode(int idx) { 
		return (idx - 1) / 2; 
	}

	static int leftNode(int idx) { 
		return 2 * idx + 1; 
	}

	static int rightNode(int idx) {
		return 2 * idx + 2; 
	}
};
