#include "AgencyList.h"
#include "AgencyNode.h"
#include<iostream>

using namespace std;
AgencyList::AgencyList(ServiceList* s) {
	start = NULL;
	servicelist1 = s;
}

void AgencyList::Add(Info info1) {
	AgencyNode* p = start;
	Info* q = &info1;
	cout << 1 << endl;
	if(start == NULL) {
        start = new AgencyNode(q, servicelist1);
        servicelist1->start->reff++;
        return;
	}
	while(p->link) {
		p = p->link;
	}

	p->link = new AgencyNode(q, servicelist1);
	servicelist1->start->reff++;
}

void AgencyList::print() {
	AgencyNode * p = start;
	while(p) {
		p->print();
		p = p->link;
	}
}
/*
void AgencyList::setRequest(string request, string agency) {
	AgencyNode* p = start;
	bool f = false;
	while(p) {
		if(p->info.name == agency) {
			p->addToQueue(request);
			f = true;
			break;
		}
	}
	if(!f) {
		cout << "The " << agency << " agency not found!" << endl;
	}
}
*/

void AgencyList::getRequest(string agency) {
	queuee.getRequest(agency);
}

void AgencyList::addToQueue(string serviceName, string username, string agencyName, int key) {
	struc* tmp = new struc(username, key, agencyName, serviceName);
	queuee.Add(*tmp);
}
