/*
 * SortAlgorithms.cpp
 *
 *  Created on: 2017Äê4ÔÂ22ÈÕ
 *      Author: lajiao
 */

#include "SortAlgorithms.h"

template<class T> SortAlgorithms<T>::SortAlgorithms() {
	// TODO Auto-generated constructor stub
	//JL - TODO
}

template<class T> SortAlgorithms<T>::~SortAlgorithms() {
	// TODO Auto-generated destructor stub
	// JL - TODO
}

template<class T> void SortAlgorithms<T>::QuickSort(vector<T>& data) {
	cout << "Quick Sort Begin --" << endl;

	int size = data.size();
	this->QuickSortHelper(data, 0, size - 1);
}

template<class T> void SortAlgorithms<T>::QuickSortHelper(vector<T> &data,
		int left, int right) {
	if (left >= right) // elements = 0 or 1, return
		return;
	int pivot = (left + right) / 2;
	this->QuickSortPartition(data, left, right, pivot);
	this->QuickSortHelper(data, left, pivot - 1);
	this->QuickSortHelper(data, pivot + 1, right);
}

template<class T> void SortAlgorithms<T>::QuickSortPartition(vector<T> &data,
		int left, int right, int& pivot) {
	// pivot is an index, put the element at pivot to correct place.
	this->SwapByIndex(data, pivot, right);
	pivot = right;
	int l = left, r = right;
	while (l < r) {
		while (l < pivot && data[l] <= data[pivot])
			l++;
		this->SwapByIndex(data, l, pivot);
		pivot = l;

		while (r > pivot && data[r] >= data[pivot])
			r--;
		this->SwapByIndex(data, pivot, r);
		pivot = r;
	}
}

template<class T> void SortAlgorithms<T>::MergeSort(vector<T>& data) {
	int size = data.size();
	this->MergeSortHelper(data, 0, size - 1);
}

template<class T> void SortAlgorithms<T>::MergeSortHelper(vector<T> &data, int left, int right){
	// terminal condition
	if((right - left) <= 1)
		return;

	// step1 divide array
	int mid = (left + right) / 2;
	this->MergeSortHelper(data, left, mid);
	this->MergeSortHelper(data, mid + 1, right);

	// step2 do merge, merge two ordered array
	vector<T> datatemp = data;
	int index1 = left, index2 = mid + 1;
	int current = left;
	while(index1 <= mid && index2 <= right){
		if(datatemp[index1] <= datatemp[index2])
			data[current++] = datatemp[index1++];
		else
			data[current++] = datatemp[index2++];
	}

	while(index1 <= mid)
		data[current++] = datatemp[index1++];
	while(index2 <= right)
		data[current++] = datatemp[index2++];
}

template<class T> void SortAlgorithms<T>::ShellSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::BucketSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::HeapSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::BubbleSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::InsertionSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::SelectionSort(vector<T>& data) {
}

template<class T> void SortAlgorithms<T>::SwapByIndex(vector<T> &data,
		int index1, int index2) {
	T temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
}

template<class T> void SortAlgorithms<T>::Swap(vector<T> &data, T& element1,
		T& element2) {
	T temp = element1;
	element1 = element2;
	element2 = temp;
}

template<class T> void SortAlgorithms<T>::PrintData(vector<T>& data,
		char split) {
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << split;

	cout << endl;
}

