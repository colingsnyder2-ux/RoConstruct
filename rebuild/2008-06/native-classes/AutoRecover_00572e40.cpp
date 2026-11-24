// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <intrin.h>

// INFERRED: minimal boost::shared_ptr layout (px, pn) with the sp_counted_base
// vtable used by the disassembly: slot 1 = dispose, slot 2 = destroy;
// use count at +4, weak count at +8.
namespace RBX { class Instance; }

struct SpCountedBase {
    virtual void unused0() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count;
    long weak_count;
};

struct InstancePtr {
    RBX::Instance* px;
    SpCountedBase* pn;
    InstancePtr() : px(0), pn(0) {}
    ~InstancePtr()
    {
        if (pn) {
            if (_InterlockedExchangeAdd(&pn->use_count, -1) == 1) {
                pn->dispose();
                if (_InterlockedExchangeAdd(&pn->weak_count, -1) == 1)
                    pn->destroy();
            }
        }
    }
};

// INFERRED: ServiceProvider::findServiceByClassName stdcall (out, name), no this in ecx
extern "C" InstancePtr* __stdcall fn_00572a90(InstancePtr* out, const void* className);
// AbstractFactoryProduct<Instance>::create, cdecl (out, name)
extern "C" InstancePtr* __cdecl fn_00420190(InstancePtr* out, const void* className);

// INFERRED: target is unnamed
extern "C" InstancePtr* __stdcall fn_00572e40(InstancePtr* result, const void* className)
{
    InstancePtr found;
    fn_00572a90(&found, className);
    if (found.px) {
        result->px = found.px;
        result->pn = found.pn;
        if (found.pn)
            _InterlockedExchangeAdd(&found.pn->use_count, 1);
    } else {
        fn_00420190(result, className);
    }
    return result;
}
