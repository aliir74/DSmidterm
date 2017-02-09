#include <arpa/nameser.h>
/*
class AgencyList;
class AgencyNode;
class ServiceList;
class ServiceNode;
class Queuee;
class Info;
class struc;
*/
#include<Queuee.h>
#include<iostream>
#include<string>
using namespace std;

Queuee::Queuee(){
}

void Queuee::Add(struc m) {
	mm.push_back(m);
	struc tmp = *(new struc("", -1, "", ""));
	for(vector<struc>::iterator it = mm.end()-1; it > mm.begin(); it--) {
        //cout << "hello" << endl;
        //cout << 1 << it->key << endl;
        //cout << 2 << (it-1)->key << endl;
        if(it->key > (it-1)->key) {
            tmp = *it;
            *it = *(it-1);
            *(it-1) = tmp;
        } else {
            break;
        }
	}
	//heapify();
}

void Queuee::heapify() {
	int RCkey = -1, LCkey, key1, max1;
	struc tmp = *(new struc("ali", 0, "ali", "ali"));
	int n = mm.size();
	for(int i = n/2; i >= 1; i--) {
        cout << i << endl;
        RCkey = -1;
        if(2*i < n)
            RCkey = mm[2*i].key;
		LCkey = mm.at(2*i-1).key;
		cout << "lc: " << LCkey << "\trc:" << RCkey << endl;
		max1 = max(RCkey, LCkey);
		cout << max1 << endl;
		key1 = mm[i-1].key;
		cout << key1 << endl;
		if(max1 > key1) {
            cout << "hello" << endl;
			if(RCkey == LCkey || max1 == LCkey) {
				//chapi biad balas
				//mm[2*i-1].key = key1;
				//mm[i].key = LCkey;
				tmp = mm[2*i - 1];
				mm[2*i-1] = mm[i-1];
				mm[i-1] = tmp;
				cout << 111 << mm[i-1].username << " " << mm[2*i-1].username << endl;
			} else {
				//rasti bala
				//mm[2*i].key = key1;
				//mm[i].key = RCkey;
				tmp = mm[2*i];
				mm[2*i] = mm[i-1];
				mm[i-1] = tmp;
				cout << 222 << mm[i-1].username << " " << mm[2*i-1].username << endl;
			}
		}
	}
}

void Queuee::print() {
	int i = 1;
	for(vector<struc>::iterator it = mm.begin(); it < mm.end(); it++) {
		cout << i << " : username = " << it->username << "\t agencyname = " << it->agencyName << "\t servicename = " <<
				it->serviceName <<endl;
		i++;
	}
}

void Queuee::getRequest(string agency) {
	int i = 1;
	for(vector<struc>::iterator it = mm.begin(); it < mm.end(); it++) {
		if(it->agencyName == agency) {
			cout << i << ": agency : " << agency << "\tservice: " << it->serviceName << "\tusername: " << it->username << endl;
			i++;
		}
	}
}
