#ifndef AgencyN
#define AgencyN

#include "Info.h"
#include "Queuee.h"
#include "ServiceNode.h"

using namespace std;

class AgencyNode{
public:
	Info info;
	ServiceNode* service;
	AgencyNode* link;
	ServiceList* dlink;
	AgencyNode(Info* i, ServiceList* p);
	void print();
//	void addToQueue(string nameOfRequest, int key);
//	void printQueue();
};

#endif
