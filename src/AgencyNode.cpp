#include<AgencyNode.h>
#include<iostream>
using namespace std;
AgencyNode::AgencyNode(Info* i, ServiceList* s) {
	info = *i;
	link = NULL;
	service = NULL;
	dlink = s;
}

void AgencyNode::print() {
	cout << info.name << endl;
}
/*
void AgencyNode::addToQueue(string nameOfRequest, int key) {
	queuee.Add(nameOfRequest, key);
}

void AgencyNode::printQueue() {
	cout << "Queue of " << info.name << " agnecy!" << endl;
	queuee.print();
}
*/
