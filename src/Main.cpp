/*
 * Main.cpp
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#include "DataCreator.h"
#include <iostream>
#include "SortAlgorithms.h"
#include "SortAlgorithms.cpp"

using namespace std;

int main(){
	cout<< "Welcome to Data Structure and Algorithm class." << endl;

	DataCreator *dc = new DataCreator(2000);
	//dc->BuildRandomData(1000); // range 0 - 999;
	//dc->PrintData();
	//dc->WriteToFile("unsort100.txt");

	int idata[] = {5, 24, 0, 27, 69, 34, 78, 58, 62, 64, 67, 45, 81, 41};
	vector<int> data(idata, idata + sizeof(idata)/sizeof(int));
	SortAlgorithms<int> sa;
	sa.MergeSort(data);
	sa.PrintData(data);

	cout<< "end--"<<endl;
}


