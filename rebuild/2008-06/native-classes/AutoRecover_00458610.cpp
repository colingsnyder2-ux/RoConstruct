// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>
#include <stdlib.h>

// INFERRED: the CRT header does not declare this here, so declare it locally as an imported function.
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: minimal local stand-ins for the types used, since no header excerpt was provided.
namespace RBX {
    class Instance {
    public:
        void setParent(Instance* parent);
    };
}

namespace boost {
    void call_once(void (*f)(), long& flag);
}

extern "C" int __fastcall fn_00457b60(void* self, int unusedEdx);
extern "C" int fn_00458590(void* outPtr);
extern "C" int fn_00455ea0(void);
extern "C" void fn_00456400(void);

namespace {

struct CountBase {
    virtual void dispose() = 0;   // slot 0
    virtual void destroy() = 0;   // slot 1
    long use_count_;
    long weak_count_;
};

// boost::detail::shared_count
struct SharedCount {
    CountBase* pi_;
    SharedCount& assign(const SharedCount& o);
    ~SharedCount()
    {
        if (pi_) {
            if (_InterlockedDecrement(&pi_->use_count_) == 0) {
                pi_->dispose();
                if (_InterlockedDecrement(&pi_->weak_count_) == 0)
                    pi_->destroy();
            }
        }
    }
};

struct SharedHolder {
    RBX::Instance* px;
    SharedCount pn;
};

struct Elem {
    RBX::Instance* px;
    SharedCount pn;
};

long g_onceFlag;

}

// boost::detail::shared_count::operator=
extern "C" SharedCount* __fastcall fn_004025b0(SharedCount* self, int unusedEdx, const SharedCount* o);

extern "C" RBX::Instance* __fastcall fn_00458610(char* self, int unusedEdx)
{
    int r = fn_00457b60(self, 0);
    if (r != 0)
        return (RBX::Instance*)r;

    SharedHolder h;
    h.pn.pi_ = 0;
    fn_00458590(&h);
    RBX::Instance* inst = h.px;

    boost::call_once(fn_00456400, g_onceFlag);

    unsigned idx = (unsigned)fn_00455ea0();
    Elem* begin = *(Elem**)(self + 0x19c);
    Elem* end   = *(Elem**)(self + 0x1a0);
    if (idx >= (unsigned)(end - begin))
        _invalid_parameter_noinfo();

    Elem* e = *(Elem**)(self + 0x19c) + idx;
    e->px = h.px;
    fn_004025b0(&e->pn, 0, &h.pn);

    inst->setParent((RBX::Instance*)self);
    return inst;
}
