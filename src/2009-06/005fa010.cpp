// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <map>

namespace RBX {

class Instance;

struct SP
{
    Instance* px;
    void* pn;
    SP();
    SP(const SP&);
    ~SP();
    SP& operator=(const SP&);
};

struct Name;

class ServiceProvider
{
    char instancePad[0x8c];
    std::vector<SP> serviceArray;
    std::map<const Name*, SP> serviceMap;
protected:
    void clearServices();
};

void ServiceProvider::clearServices()
{
	serviceArray.clear();
	serviceMap.clear();
}

}
