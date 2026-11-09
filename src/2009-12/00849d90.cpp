// from server: 100% by nuck16
// roc 2009-12 00849d90  unit: CXTPControlLabel  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00849d90
//
// 00849d90  56                   push esi
// 00849d91  57                   push edi
// 00849d92  8bf9                 mov edi, ecx
// 00849d94  e877ffffff           call 0x849d10
// 00849d99  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00849d9d  8bf0                 mov esi, eax
// 00849d9f  8b06                 mov eax, dword ptr [esi]
// 00849da1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00849da7  51                   push ecx
// 00849da8  57                   push edi
// 00849da9  8bce                 mov ecx, esi
// 00849dab  ffd2                 call edx
// 00849dad  5f                   pop edi
// 00849dae  8bc6                 mov eax, esi
// 00849db0  5e                   pop esi
// 00849db1  c20400               ret 4

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
