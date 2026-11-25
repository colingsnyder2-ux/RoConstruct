// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: minimal local stand-in for boost::shared_ptr<RBX::Instance>
// (px at +0, pn at +4), with inlined atomic refcounting as in the disassembly
// (use count at +4, weak count at +8, vtable slots 1 (dispose) and 2 (destroy)).
struct sp_counted_base_local {
    virtual void dummy0() {}
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
};

struct InstanceSP {
    void* px;
    sp_counted_base_local* pn;

    InstanceSP(const InstanceSP& o) : px(o.px), pn(o.pn) {
        if (pn)
            _InterlockedIncrement(&pn->use_count_);
    }
    ~InstanceSP() {
        if (pn) {
            if (_InterlockedDecrement(&pn->use_count_) == 0) {
                pn->dispose();
                if (_InterlockedDecrement(&pn->weak_count_) == 0)
                    pn->destroy();
            }
        }
    }
};

// INFERRED: guard that releases the by-value shared_ptr parameter (callee-destroyed)
struct InstanceSPParamGuard {
    InstanceSP* p;
    ~InstanceSPParamGuard() { p->~InstanceSP(); }
};

extern "C" int __fastcall fn_005fda30(void* self, int unusedEdx, int a1, InstanceSP a2);

// boost::function void_function_obj_invoker1<bind_t<mf1<void,FlagStand,shared_ptr<Instance>>,...>>::invoke
// INFERRED: the real routine is static invoke(function_buffer&, shared_ptr<Instance>) with
// stack args; the required ABI here exposes no stack params, so the arguments are read
// relative to the return address (buf at +4, shared_ptr at +8).
extern "C" void __fastcall fn_00618cd0(void* self, int unusedEdx)
{
    char* ra = (char*)_AddressOfReturnAddress();
    char* buf = *(char**)(ra + 4);
    InstanceSPParamGuard g;
    g.p = (InstanceSP*)(ra + 8);
    fn_005fda30(buf, 0, *(int*)(buf + 0x10), *g.p);
}
