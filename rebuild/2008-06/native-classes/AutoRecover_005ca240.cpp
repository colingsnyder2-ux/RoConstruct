// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
#include <string>

// INFERRED: minimal local stand-ins for the shared_ptr control block and Instance,
// since no headers were provided for them.
namespace RBX {
class Instance {
public:
    virtual void vslot0() = 0;
    virtual void setName(const std::string& name) = 0;
    void setParent(Instance* parent);
};
}

namespace {
struct SpCounted {
    virtual void slot0() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use;
    long weak;
};

struct SpInstance {
    RBX::Instance* px;
    SpCounted* pn;
    SpInstance() {}
    SpInstance(const SpInstance& o) : px(o.px), pn(o.pn) {
        if (pn) _InterlockedIncrement(&pn->use);
    }
    ~SpInstance() {
        if (pn && _InterlockedDecrement(&pn->use) == 0) {
            pn->dispose();
            if (_InterlockedDecrement(&pn->weak) == 0)
                pn->destroy();
        }
    }
};

// INFERRED: object holding a std::string at +0xc024
struct SourceObj {
    char pad[0xc024];
    std::string name;
};
}

// INFERRED: returns pointer to the shared_ptr written into the out parameter
extern "C" SpInstance* fn_005ca1c0(SpInstance* out, SourceObj* src);

// INFERRED: unnamed target; member-like thiscall with one stack arg
extern "C" RBX::Instance* __fastcall fn_005ca240(RBX::Instance* self, int unusedEdx, SourceObj* src)
{
    SpInstance inst;
    {
        SpInstance tmp;
        inst = *fn_005ca1c0(&tmp, src);
        if (inst.pn) _InterlockedIncrement(&inst.pn->use);
    }
    // note: inst was bit-copied above, then its refcount was incremented manually
    inst.px->setName(std::string(src->name.c_str()));
    inst.px->setParent(self);
    return inst.px;
}
