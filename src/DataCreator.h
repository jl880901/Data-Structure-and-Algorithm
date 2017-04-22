/*
 * DataCreator.h
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_DATACREATOR_H_
#define SRC_DATACREATOR_H_

#define FILEFOLDER "file"

#include<vector>
#include<string>

using namespace std;

class DataCreator {
public:
	DataCreator();
	DataCreator(int n);
	virtual ~DataCreator();

	bool BuildRandomData(int max);
	void PrintData();
	bool WriteToFile(string filename);

private:
	int size;
	vector<int> data;
};

#endif /* SRC_DATACREATOR_H_ */
