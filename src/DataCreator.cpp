/*
 * DataCreator.cpp
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#include "DataCreator.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

DataCreator::DataCreator() {
	// TODO Auto-generated constructor stub
	this->size = 0;
}

DataCreator::DataCreator(int n){
	this->size = n;
}

DataCreator::~DataCreator() {
	// TODO Auto-generated destructor stub
}

bool DataCreator::BuildRandomData(int max){
	bool ret = true;
	for(int i = 0; i < this->size; i++){
		this->data.push_back(rand() % max);
	}
	return ret;
}

void DataCreator::PrintData(){
	for(int i = 0; i < this->size; i++){
		cout<< this->data[i] << " ";
	}
	cout<<endl;
}

bool DataCreator::WriteToFile(string filename){
	bool ret = false;

	if(filename.length() == 0)
		return ret;

	string path(FILEFOLDER);
	path = path + "/" + filename;
	fstream out;
	out.open(path.c_str(), ios::out);

	for(int i = 0; i < this->size; i++){
		out << this->data[i] << " ";
	}
	out.close();
	return ret;
}
