// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <intrin.h>

// INFERRED: std::tr1::shared_ptr is unavailable in this toolchain, so a minimal local
// refcounted pointer matches the lock-xadd use/weak count pattern (+4 use, +8 weak).
struct Rep {
    virtual void dispose();  // slot 0 (+0), unused here
    virtual void destroy();  // slot 1 (+4) called when use count hits 0
    virtual void del();      // slot 2 (+8) called when weak count hits 0
    long use;
    long weak;
};

struct Instance {
    virtual void vf0();
    virtual void setName(const std::string& name);  // vtable slot 1 (+4)
    void setParent(Instance* parent);               // ?setParent@Instance@RBX@@QAEXPAV12@@Z
};

struct SP {
    Instance* p;
    Rep* r;
    SP() : p(0), r(0) {}
    SP(const SP& o) : p(o.p), r(o.r) {
        if (r) _InterlockedExchangeAdd(&r->use, 1);
    }
    ~SP() {
        if (r && _InterlockedExchangeAdd(&r->use, -1) == 1) {
            r->destroy();
            if (_InterlockedExchangeAdd(&r->weak, -1) == 1)
                r->del();
        }
    }
};

// INFERRED: arg object holds a std::string at +0xC024 (size at +0xC038, cap 0x10).
struct NamedSource {
    char pad[0xC024];
    std::string name;
};

// INFERRED: cdecl(out, source) returns out; the 8 raw args in the generic declaration are a mis-inference.
extern "C" SP* fn_005ca1c0(SP* out, NamedSource* source);

struct Owner {
    Instance* fn_005ca240(NamedSource* source);
};

extern "C" Instance* __fastcall fn_005ca240(Owner* self, int unusedEdx, NamedSource* source)
{
    SP tmp;
    SP child = *fn_005ca1c0(&tmp, source);
    child.p->setName(std::string(source->name.c_str()));
    child.p->setParent((Instance*)self);
    return child.p;
}
