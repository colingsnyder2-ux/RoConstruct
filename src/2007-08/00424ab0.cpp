// from server: 100% by EspClaude
// roc 2007-08 00424ab0  dtor of an Instance-derived class with one std::string member at 0xec
#include <string>

namespace RBX {
class Instance {
public:
    char data[0xe8];
    virtual ~Instance();
};

class __declspec(novtable) StringHolder : public Instance {
public:
    std::string value;
    virtual ~StringHolder();
};

StringHolder::~StringHolder()
{
}
}
