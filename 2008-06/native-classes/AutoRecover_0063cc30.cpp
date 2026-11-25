// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

#pragma intrinsic(_AddressOfReturnAddress)

// INFERRED: minimal local stand-ins for boost::shared_ptr<RBX::Instance> and function_buffer.
// vtable slot 1 (+4) is dispose and slot 2 (+8) is destroy, so slot 0 is a destructor.
struct sp_counted_base2 {
    virtual ~sp_counted_base2() {}
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
};

struct Instance;

struct InstancePtr {
    Instance* px;
    sp_counted_base2* pn;

    InstancePtr(const InstancePtr& o) : px(o.px), pn(o.pn) {
        if (pn) _InterlockedIncrement(&pn->use_count_);
    }
    ~InstancePtr() {
        if (pn) {
            if (_InterlockedDecrement(&pn->use_count_) == 0) {
                pn->dispose();
                if (_InterlockedDecrement(&pn->weak_count_) == 0)
                    pn->destroy();
            }
        }
    }
};

// INFERRED: the bound FlagStand* is at offset 0x10 of the function buffer.
struct function_buffer {
    char pad[0x10];
    int obj;
};

// INFERRED: thiscall on the bind_t's mf1 (ecx), args (FlagStand*, shared_ptr<Instance> by value).
extern "C" int __fastcall fn_005d2180(void* self, int unusedEdx, int a1, InstancePtr a2);

// INFERRED: destroys the by-value shared_ptr parameter on exit (callee-destroyed arg).
struct ParamGuard {
    InstancePtr* p;
    ~ParamGuard() { p->~InstancePtr(); }
};

// INFERRED: real signature is cdecl invoke(function_buffer&, shared_ptr<Instance>);
// declared per the required ABI and the stack arguments are read relative to the return address.
extern "C" void __fastcall fn_0063cc30(void* self, int unusedEdx)
{
    char* ra = (char*)_AddressOfReturnAddress();
    function_buffer& buf = **(function_buffer**)(ra + 4);
    InstancePtr* a0 = (InstancePtr*)(ra + 8);
    ParamGuard guard = { a0 };
    fn_005d2180(&buf, 0, buf.obj, *a0);
}
