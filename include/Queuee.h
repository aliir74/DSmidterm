#ifndef Queueee
#define Queueee

#include<vector>
#include<cmath>
#include<struc.h>
/*
class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/
//#include "struc"
using namespace std;


class Queuee{
public:
	vector<struc> mm;
	Queuee();
	void Add(struc m);
	void heapify();
	void print();
	void getRequest(string agency);
};
#endif
