#ifndef serviceL
#define serviceL


#include "ServiceNode.h"
#include<Info.h>
class ServiceNode;
/*
class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/



using namespace std;


class ServiceList{
public:
	ServiceNode* start;
	void normalAdd(Info info);//	void addreff(ServiceNode* p);
	void addSubService(Info info, Info subinfo);
	ServiceNode* searchh(Info info, ServiceNode* &p);
	void findDelete(Info info1);
//	void Delete(ServiceNode* p, ServiceNode* q);
	void deleteServiceList(ServiceList* p);
	void addParent(Info parent, Info service);
	void print();
	void printSubService(Info parent);
	ServiceList();
};

#endif
