#include "Info.h"
#include "AgencyNode.h"
#include "ServiceList.h"

using namespace std;
class AgencyList {
public:
	AgencyNode* start;
	Queuee queuee;
	ServiceList* servicelist1;
	AgencyList(ServiceList* s);
	void Add(Info info1);
	void addToQueue(string serviceName, string username, string agencyName, int key);
	void print();
//	void setRequest(string request, string agency);
	void getRequest(string agency);
};

