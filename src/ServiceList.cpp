#include "ServiceNode.h"
#include<Info.h>
#include<iostream>
using namespace std;

ServiceList::ServiceList() {
    Info* infff = new Info();
	start = new ServiceNode(1, 1, infff, this);
}




ServiceNode* ServiceList::searchh(Info infoo, ServiceNode* &q) {
	ServiceNode* p = start->link;
	ServiceNode* tmp = start;
	ServiceNode* t;
	while(p) {
       // cout << p->info.name << endl;
		if(p->info == infoo) {
			q = tmp;
			return p;
		}
		if(p->dlink) {
			t = p->dlink->searchh(infoo, tmp);
			if(t) {
                q = tmp;
                return t;
            }
		}
		tmp = p;
		p = p->link;
	}
	return NULL;
}


void ServiceList::findDelete(Info info1) {
	ServiceNode* q;
	ServiceNode* p = searchh(info1, q);
	q->link = p->link;
	if(p->dlink) {
		deleteServiceList(p->dlink);
	}
	delete p;
}

/*void ServiceList::Delete(ServiceNode *p, ServiceNode *q) {
	ServiceNode* tmp = p;
	ServiceNode* t;
	q->link = p->link;
	if(tmp->dlink) {
		deleteServiceList(tmp->dlink);
	}
	delete p;
}*/

void ServiceList::deleteServiceList(ServiceList *p) {
	p->start->reff--;
	ServiceNode* tmp = p->start;
	ServiceNode* t;
	if(p->start->reff == 0) {
		while(tmp) {
			if (tmp->dlink) {
				deleteServiceList(tmp->dlink);
			}
			t = tmp->link;
			delete tmp;
			tmp = t;
		}
	}
}

void ServiceList::addParent(Info parent, Info service) {
	ServiceNode* q;
	searchh(service, q);
	//cout << "kk1" << endl;
	ServiceNode* tmp;
	ServiceNode* p = searchh(parent, tmp);
//	cout << "kk2" << endl;
	if(p && q) {
        q->dlink->start->reff++;
        if(p->dlink)
            deleteServiceList(p->dlink);
        p->dlink = q->dlink;
    }
    else {
        cout << "Not found!!!" << endl;
    }
}


void ServiceList::normalAdd(Info infooo) {
	ServiceNode* p = start;
	//cout << start->reff << endl;
	while(p->link) {
		p = p->link;
	}
	p->link = new ServiceNode(0, 0, &infooo, NULL);
//	cout << 444 << p->link->info.name << endl;
}




void ServiceList::addSubService(Info info, Info subinfo) {
	ServiceNode* q;
	ServiceNode* p = searchh(info, q);
	//cout << info.name << "=" << p->info.name << endl;
	//cout << q->info.name << endl;
	if(!p) {
		return;
	}
	if(p->dlink) {
		p->dlink->normalAdd(subinfo);
	} else {
		p->dlink = new ServiceList();
		p->dlink->normalAdd(subinfo);
	}
}


/*void ServiceList::Delete(ServiceNode *p, ServiceNode *q) {
	ServiceNode* tmp = p;
	ServiceNode* t;
	q->link = p->link;
	if(tmp->dlink) {
		deleteServiceList(tmp->dlink);
	}
	delete p;
}*/



void ServiceList::print() {
	ServiceNode* p = start->link;
	//cout << 222 << endl;
    cout << "ref: " << start->reff << endl;
	while(p) {
        //cout << 333 << endl;
		cout << p->info.name << endl;
		p = p->link;
	}
	return;
}

void ServiceList::printSubService(Info parent) {
	ServiceNode* q;
	//cout << "h1" << endl;
	ServiceNode* p = searchh(parent, q);
	//cout << "h2" << endl;
	//cout << p->info.name << "=" << parent.name << endl;
	//cout <<"hello :1" << p->dlink->start->link->info.name << endl;
	if(p && p->dlink){
      //  cout << "ref: " << p->dlink->start->reff;
        p->dlink->print();
    }
    //cout << "h3" << endl;
}
