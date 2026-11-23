// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>
#include <new>

// INFERRED: heap-stored functor of size 0x28 (boost::function-style manager)
struct ManagerVT {
    void (__cdecl *fn)(void* a, void* b, int op);
};

struct StoredFunctor {
    char pad0[8];
    ManagerVT* mgr;      // +8
    char pad1[8];
    char inner[0x18];    // +0x10 embedded sub-functor storage
};

extern "C" void* fn_006a0920(int size);
extern "C" int fn_0055f6a0(void* dst, void* src);

void __cdecl manage(void const* const* in, void** out, int op)
{
    if (op == 0) {
        void* src = (void*)*in;
        void* p = fn_006a0920(0x28);
        fn_0055f6a0(p, src);
        *out = p;
        return;
    }
    if (op == 1) {
        StoredFunctor* f = (StoredFunctor*)*out;
        if (f->mgr) {
            void (__cdecl *d)(void*, void*, int) = f->mgr->fn;
            void* inner = f->inner;
            if (d)
                d(inner, inner, 1);
            f->mgr = 0;
        }
        ::operator delete(f);
        *out = 0;
        return;
    }
    // INFERRED: type query; original compares against type_info at 0x944430
    if (*(const std::type_info*)*out == typeid(StoredFunctor)) {
        *out = (void*)*in;
    } else {
        *out = 0;
    }
}
