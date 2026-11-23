// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

#include <stdlib.h>
#include <intrin.h>

#pragma intrinsic(_InterlockedDecrement)

// INFERRED: minimal local stand-ins for the types; no native headers are used.
struct sp_counted_base {
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
};

struct SharedCount {
    sp_counted_base* pi_;
};

struct ForceField;

struct SharedFF {
    ForceField* px;
    SharedCount pn;
    ~SharedFF()
    {
        // inlined boost::detail::shared_count destructor
        if (pn.pi_) {
            if (_InterlockedDecrement((long volatile*)&((long*)pn.pi_)[1]) == 0) {
                pn.pi_->dispose();
                if (_InterlockedDecrement((long volatile*)&((long*)pn.pi_)[2]) == 0)
                    pn.pi_->destroy();
            }
        }
    }
};

struct SharedInst {
    void* px;
    SharedCount pn;
};

struct ForceFieldHost {
    char pad[0x19c];
    SharedInst* childrenBegin; // 0x19c
    SharedInst* childrenEnd;   // 0x1a0
};

extern "C" int __fastcall fn_0045dce0(ForceFieldHost* self, int unusedEdx);
extern "C" int fn_0045b2b0(void);
// ?create@ForceField from Creatable<Instance>
extern "C" SharedFF* fn_0045c580(SharedFF* out);
// shared_count::operator=
extern "C" SharedCount* __fastcall fn_004025b0(SharedCount* self, int unusedEdx, const SharedCount* rhs);
// Instance::setParent
extern "C" void __fastcall fn_0055a8f0(ForceField* self, int unusedEdx, ForceFieldHost* parent);
extern "C" void fn_0045b820(void);

namespace boost {
void call_once(void (*f)(), long& flag);
}

extern long g_forceFieldOnceFlag; // INFERRED: at 0x96de94

extern "C" ForceField* __fastcall fn_0045de20(ForceFieldHost* self, int unusedEdx)
{
    int existing = fn_0045dce0(self, 0);
    if (existing != 0)
        return (ForceField*)existing;

    SharedFF ff;
    fn_0045c580(&ff);
    ForceField* result = ff.px;

    boost::call_once(fn_0045b820, g_forceFieldOnceFlag);
    unsigned idx = (unsigned)fn_0045b2b0();

    if (idx >= (unsigned)(self->childrenEnd - self->childrenBegin))
        _invalid_parameter_noinfo();

    SharedInst* slot = &self->childrenBegin[idx];
    slot->px = ff.px;
    fn_004025b0(&slot->pn, 0, &ff.pn);

    fn_0055a8f0(result, 0, self);
    return result;
}
