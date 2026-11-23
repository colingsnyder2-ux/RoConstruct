// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: boost::bind storage objects; layouts guessed from the disassembly offsets only.
struct FnBase { void (*manager)(void*, void*, int); };
struct BoundFn { int a; FnBase* vtable; char pad[0x38]; int tail; };
struct BindStorage { int first; char fn[0x3c]; int last; };

extern "C" int __fastcall fn_00596700(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16);
extern "C" void __fastcall fn_005962d0(void* self, int unusedEdx, void* src);
extern "C" void __fastcall fn_00596470(void* self, int unusedEdx);

// INFERRED: hidden struct return in ebp; arg is a std::string by value copied for the bind.
extern "C" BindStorage* __fastcall fn_005968d0(void* self, int unusedEdx, BindStorage* out, std::string name)
{
    std::string copy(name);
    char tmp[0x20];
    int* src = reinterpret_cast<int*>(self);
    int* srcFn = src ? reinterpret_cast<int*>(*src) : 0;
    (void)srcFn; (void)tmp;
    int* r = reinterpret_cast<int*>(fn_00596700(self, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0));
    out->first = 0;
    fn_005962d0(&out->fn, 0, r);
    out->last = r[0x10];
    fn_00596470(self, 0);
    return out;
}
