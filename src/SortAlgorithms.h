/*
 * SortAlgorithms.h
 *
 *  Created on: 2017Äê4ÔÂ22ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_SORTALGORITHMS_H_
#define SRC_SORTALGORITHMS_H_

#include <iostream>
#include <vector>

using namespace std;

template<class T> class SortAlgorithms {
public:
	SortAlgorithms();
	virtual ~SortAlgorithms();

	void QuickSort(vector<T> &data);
	void MergeSort(vector<T> &data);
	void ShellSort(vector<T> &data);
	void BucketSort(vector<T> &data);
	void HeapSort(vector<T> &data);
	void BubbleSort(vector<T> &data);
	void InsertionSort(vector<T> &data);
	void SelectionSort(vector<T> &data);

	void QuickSortHelper(vector<T> &data, int left, int right);
	void QuickSortPartition(vector<T> &data, int left, int right, int& pivot);
	void MergeSortHelper(vector<T> &data, int left, int right);

	void PrintData(vector<T> &data, char split = ' ');
private:
	vector<T> data;

	void SwapByIndex(vector<T> &data, int index1, int index2);
	void Swap(vector<T> &data, T &element1, T &element2);
};

#endif /* SRC_SORTALGORITHMS_H_ */
