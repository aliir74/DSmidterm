#ifndef inf
#define inf
#include "string"

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
class Info{
public:
	string name;
    bool operator==(const Info& iii) {
        return (iii.name == this->name);
    };
};

#endif
