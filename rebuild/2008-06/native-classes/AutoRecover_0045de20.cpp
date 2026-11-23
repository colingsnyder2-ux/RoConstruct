// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/thread/once.hpp>
#include "v8tree/Instance.h"
#include "v8datamodel/ForceField.h"

// INFERRED: owner object has a vector<shared_ptr<Instance>> at +0x19c/+0x1a0
// (8-byte elements, bounds-checked operator[]). Exact class unknown.
struct Fn0045de20Host {
    char pad[0x19c];
    std::vector< boost::shared_ptr<RBX::Instance> > members;
};

extern "C" RBX::Instance* __fastcall fn_0045dce0(Fn0045de20Host* self, int unusedEdx);
extern "C" int fn_0045b2b0(void);
extern "C" void fn_0045b820(void);
// INFERRED: once-flag at 0x96de94 passed to boost::call_once
extern long g_once_flag_0096de94;

extern "C" RBX::Instance* __fastcall fn_0045de20(Fn0045de20Host* self, int unusedEdx)
{
    RBX::Instance* existing = fn_0045dce0(self, 0);
    if (existing)
        return existing;

    boost::shared_ptr<RBX::ForceField> ff = RBX::Creatable<RBX::Instance>::create<RBX::ForceField>();
    RBX::ForceField* raw = ff.get();

    boost::call_once(fn_0045b820, g_once_flag_0096de94);
    int idx = fn_0045b2b0();
    self->members[idx] = ff;
    raw->setParent(reinterpret_cast<RBX::Instance*>(self));
    return raw;
}
