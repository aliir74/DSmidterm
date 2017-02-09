#include "ServiceList.h"

/*
class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/
#include<iostream>
using namespace std;

ServiceNode::ServiceNode(int tag1, int reff1, Info* info1, ServiceList* dli) {
	tag = tag1;
	link = NULL;
	dlink = dli;
	if(tag == 0) {
		info = *info1;
		//cout << 888 << info.name << endl;
	} else {
		reff = reff1;
	}
}
