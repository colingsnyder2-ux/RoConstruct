// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Factory analog for 00551920: selector 00942ec4 picks a 0x60-byte object
// (ctor 00551e30) or a 0x54-byte object (ctor 00551b30); otherwise throws.
#include <string>
#include <exception>

class ProxyBase {
public:
    virtual ~ProxyBase();
};

class ProxyA : public ProxyBase { public: ProxyA(int owner, const std::string& name, bool flag); char data[0x5c]; };
class ProxyB : public ProxyBase { public: ProxyB(int owner, const std::string& name, bool flag); char data[0x50]; };

extern int materialFactoryType;

ProxyBase* createProxy(int owner, const std::string& name, bool flag)
{
    if (materialFactoryType == 0)
        return new ProxyA(owner, name, flag);
    else if (materialFactoryType == 1)
        return new ProxyB(owner, name, flag);
    else
        throw std::exception("Invalid factory type");
}
