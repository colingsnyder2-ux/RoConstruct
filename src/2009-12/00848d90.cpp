// from server: 100% by nuck16
// roc 2009-12 00848d90  unit: CXTPControlToolbars  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00848d90
//
// 00848d90  56                   push esi
// 00848d91  57                   push edi
// 00848d92  8bf9                 mov edi, ecx
// 00848d94  e887ffffff           call 0x848d20
// 00848d99  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00848d9d  8bf0                 mov esi, eax
// 00848d9f  8b06                 mov eax, dword ptr [esi]
// 00848da1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00848da7  51                   push ecx
// 00848da8  57                   push edi
// 00848da9  8bce                 mov ecx, esi
// 00848dab  ffd2                 call edx
// 00848dad  5f                   pop edi
// 00848dae  8bc6                 mov eax, esi
// 00848db0  5e                   pop esi
// 00848db1  c20400               ret 4

struct S
{
    void* f();
    void* g(void* p);
};

void* S::g(void* p)
{
    void* v = f();
    ((void (__thiscall*)(void*, void*, void*))(*(void***)v)[56])(v, this, p);
    return v;
}
