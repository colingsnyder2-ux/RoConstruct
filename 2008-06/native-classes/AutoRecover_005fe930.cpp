// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: headers were not used. Signatures, argument order and local types are reconstructed from the disassembly.
// INFERRED: this is the PropDescriptor<FlagStand,BrickColor> constructor.
// INFERRED: I have not compiled this draft or compared it with the original bytes.
// INFERRED: the call to fn_005fdd50 uses 7 stack dwords as declared, but the disassembly shows 8 dwords pushed. How the 8th (likely `functionality`) is passed is unresolved.
#include <new>

extern "C" char g_00841b18[];   // INFERRED: vtable of PropDescriptor<FlagStand,BrickColor>

extern "C" int __fastcall fn_005fdd50(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" void* fn_005c3810(const char* a, const char* b);
extern "C" void* __fastcall fn_0059a4b0(void* self, int unusedEdx, void* desc);

// INFERRED: owner of the accessor object; deletes it on scope exit, which gives the EH state change
struct Local_005fe930Own {
    int* p;
    Local_005fe930Own(int* q) : p(q) {}
    ~Local_005fe930Own() { if (p) ::operator delete(p); }
};

extern "C" void* __fastcall fn_005fe930(void* self, int unusedEdx,
    const char* name, const char* category,
    int g0, int g1, int g2,
    int s0, int s1, int s2,
    int functionality)
{
    int slot = 0;
    int* r = (int*)(long)fn_005fdd50(self, 0, (int)(long)&slot, g0, g1, g2, s0, s1, s2);
    Local_005fe930Own acc((int*)(long)*r);
    *r = 0;

    fn_0059a4b0(self, 0, fn_005c3810(name, category));

    *(void**)self = (void*)g_00841b18;
    return self;
}
