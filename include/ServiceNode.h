#ifndef serviceN
#define serviceN

#include "ServiceList.h"
#include<Info.h>
class ServiceList;
/*
class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/
class ServiceNode{
public:
	int tag; // 0 -> info 1-> reff
    Info info;
	int reff;
	ServiceNode* link;
	ServiceList* dlink;
	ServiceNode(int tag1, int reff1, Info* info1, ServiceList* dli);
};

#endif
