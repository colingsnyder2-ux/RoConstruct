// from server: 100% by EspClaude
// from server: 53% by Intel
// from server: 48% by tester
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.34.1 roc_claude_2496c2dcfa6106fa.cpp

// Candidate translation unit (score above; library headers required).
// 0058be50 (Roblox app code, not Boost.Signals): create a child through a static
// shared_ptr-returning factory (cdecl 0058bd10, hidden return + one dword argument = this
// function's 2nd stack argument), name it (virtual slot +8 taking const std::string&, built
// from the 1st stack argument through MSVCP80 basic_string(const char*)), parent it to this
// (thiscall 00541630), and return the raw pointer (ret 8).
// The recipe preprocesses without /MD; the target calls MSVCP80 through the IAT.
#ifndef NDEBUG
#define NDEBUG
#endif
#ifndef _DLL
#define _DLL
#endif
#include <string>
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    virtual void vslot1();
    virtual void setName(const std::string& name);
    void setParent(Instance* parent);
};
class Child : public Instance {
public:
    static boost::shared_ptr<Child> create(const char* arg);
};
class Owner : public Instance {
public:
    Instance* createChild(const char* name, const char* arg);
};

Instance* Owner::createChild(const char* name, const char* arg)
{
    boost::shared_ptr<Instance> child = Child::create(arg);
    child->setName(name);
    child->setParent(this);
    return child.get();
}
}
