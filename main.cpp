#include "AgencyList.h"
#include "AgencyNode.h"
#include "ServiceList.h"
#include "ServiceNode.h"
#include "Queuee.h"
#include "Info.h"

#include "struc.h"



/*
#include "AgencyList"
#include "AgencyNode"
#include "ServiceList"
#include "ServiceNode"
#include "Queuee"
#include "Info"

#include "struc"
*/
#include "string"

/*class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/
#include<iostream>
using namespace std;

int main() {
	Info* info = new Info();
	ServiceList* serviceList = new ServiceList();
	AgencyList* agencyList = new AgencyList(serviceList);
	Queuee* queueee = new Queuee();
	string s;
	while(1) {
        cin >> s;
       // cout << s << endl;
		if(s == "Add") {
			cin >> s;
		//	cout << s << endl;
			if(s == "new") {
				cin >> s;
			//	cout << s << endl;
				if (s == "agency") {
					cin >> s;
				//	cout << s << endl;
					Info *tmp = new Info();
					tmp->name = s;
					agencyList->Add(*tmp);
					cout << "agnecy " << s << " added!" << endl;
				} else if (s == "service") {
					cin >> s;
					//cout << s << endl;
					Info *tmp = new Info();
					tmp->name = s;
					serviceList->normalAdd(*tmp);
					cout << "service " << s << " added!" << endl;
				}
			} else if(s == "parent") {
				Info *name = new Info(), *parent = new Info();
				cin >> parent->name;
				string ts;
				cin >> ts;
				cin >> name->name;

				serviceList->addParent(*parent, *name);
				cout << name->name << " added to subservices from " << parent->name << endl;
			} else if(s == "subservice") {
				Info *name = new Info(), *parent = new Info();
				cin >> name->name;
				string ts;
				cin >> ts;
				cin >> parent->name;
				serviceList->addSubService(*parent, *name);
				cout << name->name << " added to subservices from " << parent->name << endl;
			}
		} else if(s == "List") {
			getline(cin, s);
			//cout << s << endl;
			if(s == " agency") {
				cout << "List of agencies:" << endl;
				agencyList->print();
			} else if(s == " services") {
                cout << "List of services:" << endl;
				serviceList->print();
			} else {
				info->name = s[15];
				for(int i = 16; i < s.length(); i++) {
					info->name += s[i];
				}
				//cout << 1233 << info->name << endl;
				cout << "List of subservices from " << info->name << ":" << endl;
				serviceList->printSubService(*info);
			}
		} else if(s == "Delete") {
			Info *info1 = new Info();
			string st;
			cin >> st;
			info1->name = st;
			serviceList->findDelete(*info1);
			cout << st << " service deleted!" << endl;
		} else if(s == "Request") {
			string serviceName, tp, agencyName, userName;
			int key;
			cin >> serviceName >> tp >> agencyName >> tp >> userName >> key;
			Info* info1 = new Info();
			info1->name = serviceName;
			ServiceNode* q;
			if(serviceList->searchh(*info1, q) == NULL) {
                cout << "Service Name: " << serviceName << " Not Found!" << endl;
                continue;
			}
			AgencyNode* p = agencyList->start;
			bool f = false;
			while(p) {
                if(p->info.name == agencyName) {
                    f = true;
                    break;
                }
                p = p->link;
			}
			if(!f) {
                cout << "Agency Name: " << agencyName << " Not Found!" << endl;
                continue;
			}
			struc *strrrr = new struc(userName, key, agencyName, serviceName);
			queueee->Add(*strrrr);
			cout << "Request added!" << endl;
		} else if(s == "Get") {
			cin >> s;
			if(s == "request") {
				cin >> s;
				cout << "List of request to " << s << " agency!" << endl;
				queueee->getRequest(s);
			}
		}
	}
	return 0;
}
