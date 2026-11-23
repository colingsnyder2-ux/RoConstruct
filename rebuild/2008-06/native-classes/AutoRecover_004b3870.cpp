// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout of the 8-byte (Instance*, shared_count) vector element and the call_once flag/init names come from the disassembly only.
#include <stdlib.h>

extern "C" void __cdecl _invalid_parameter_noinfo(void);

namespace boost {
namespace detail {
class shared_count {
public:
    shared_count& operator=(const shared_count& r);
    ~shared_count();
    void* pi_;
};
}
void call_once(void (*f)(), long& flag);
}

namespace RBX {
class Instance {
public:
    void setParent(Instance* parent);
};
}

struct InstPtr {
    RBX::Instance* px;
    boost::detail::shared_count pn;
};

extern "C" int __fastcall fn_004b3380(void* self, int unusedEdx);
extern "C" void __stdcall fn_004adb60(InstPtr* out);
extern "C" void fn_004ac600();
extern "C" int fn_004ab470();
extern long g_00971490;

extern "C" RBX::Instance* __fastcall fn_004b3870(char* self, int unusedEdx)
{
    int r = fn_004b3380(self, 0);
    if (r)
        return (RBX::Instance*)r;

    InstPtr p;
    p.px = 0;
    fn_004adb60(&p);
    boost::call_once(fn_004ac600, g_00971490);
    unsigned idx = (unsigned)fn_004ab470();

    InstPtr* begin = *(InstPtr**)(self + 0x19c);
    InstPtr* end = *(InstPtr**)(self + 0x1a0);
    if (idx >= (unsigned)(end - begin))
        _invalid_parameter_noinfo();
    InstPtr* slot = (*(InstPtr**)(self + 0x19c)) + idx;
    slot->px = p.px;
    slot->pn = p.pn;
    p.px->setParent((RBX::Instance*)self);
    return p.px;
}
