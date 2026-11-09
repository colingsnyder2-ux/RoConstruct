// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_9434faa532987174.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>

namespace RBX {
class Instance;
class ServiceProvider;
}

typedef std::vector<boost::shared_ptr<RBX::Instance> > Instances;

struct Object {
    char pad[0x20c];
    RBX::Instance* parent;
};

typedef boost::shared_ptr<Object> Shared;

struct Guard {
    unsigned char data[4];
    Guard(Shared, int);
    ~Guard();
};

struct List;

struct Result {
    List* value;
    explicit Result(List* p) : value(p) {}
    ~Result();
};

struct Provider {
    char pad[0x8c];
    const Instances* children;
};

RBX::ServiceProvider* __cdecl func_00421cb0(RBX::Instance*);
void __cdecl collect(List*, boost::shared_ptr<RBX::Instance>);

struct S {
    unsigned char pad[0x1c];
    Shared object;
    List* create();
    Result f();
};

Result S::f() {
    Result result(create());
    {
    Guard guard(object, 1);

    Object* p = object.get();
    Provider* provider = reinterpret_cast<Provider*>(func_00421cb0(p ? p->parent : 0));

    std::for_each(provider->children->begin(), provider->children->end(),
                  boost::bind(&collect, result.value, _1));

    }
    return result;
}
