// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <algorithm>

namespace RBX {
class Name {
public:
    static int compare(Name& a, Name& b);
};
class GuidRegistryMutex {
public:
    void lock();
    void unlock();
};
namespace Reflection {
// INFERRED: layout from the disassembly (name ref at +4, category-like object at +0xc whose +4 is a Name ref).
struct Category { int pad; Name* name; };
struct PropertyDescriptor {
    int pad0;
    Name* name;     // +4
    int pad8;
    Category* category; // +0xc
};
class Descriptor;
}
}
namespace boost { void call_once(void (*)(), long&); }

using namespace RBX;
using namespace RBX::Reflection;

extern "C" void fn_004a7d00();
extern "C" GuidRegistryMutex* __fastcall fn_0056be10(void* self, int unusedEdx);
extern "C" bool fn_0056b500(const PropertyDescriptor* a, const PropertyDescriptor* b);

typedef std::vector<PropertyDescriptor*> PropVec;

// INFERRED: process-wide property list created on first use, guarded by call_once.
static PropVec& allProps()
{
    static long flag;
    boost::call_once(fn_004a7d00, flag);
    static PropVec v;
    return v;
}

namespace RBX { namespace Reflection {
class Descriptor {
public:
    PropVec props;                       // +0
    std::vector<Descriptor*> derived;    // +0x18
    void addProperty(PropertyDescriptor* pd);
};
}}

struct ScopedLock {
    GuidRegistryMutex* m;
    bool locked;
    explicit ScopedLock(GuidRegistryMutex* mm) : m(mm), locked(true) { m->lock(); }
    ~ScopedLock() { m->unlock(); }
};

inline void Descriptor::addProperty(PropertyDescriptor* pd)
{
    ScopedLock lock(fn_0056be10(this, 0));

    PropVec::iterator it = std::lower_bound(props.begin(), props.end(), pd, fn_0056b500);
    if (it == props.end() || *it != pd)
        props.insert(it, pd);

    for (std::vector<Descriptor*>::iterator c = derived.begin(); c != derived.end(); ++c)
        (*c)->addProperty(pd);

    PropVec::iterator g = allProps().begin();
    for (; g != allProps().end(); ++g) {
        PropertyDescriptor* o = *g;
        if (o == pd)
            return;
        int c = Name::compare(*pd->name, *o->name);
        if (c < 0)
            break;
        if (c == 0 && Name::compare(*pd->category->name, *o->category->name) < 0)
            break;
    }
    allProps().insert(g, pd);
}

extern "C" void __fastcall fn_0056c170(Descriptor* self, int unusedEdx, PropertyDescriptor* pd)
{
    self->addProperty(pd);
}
