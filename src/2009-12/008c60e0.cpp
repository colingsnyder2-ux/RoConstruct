// from server: 100% by nuck16
// roc 2009-12 008c60e0  unit: CXTPControlCustom  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c60e0
//
// 008c60e0  56                   push esi
// 008c60e1  57                   push edi
// 008c60e2  8bf9                 mov edi, ecx
// 008c60e4  e887ffffff           call 0x8c6070
// 008c60e9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008c60ed  8bf0                 mov esi, eax
// 008c60ef  8b06                 mov eax, dword ptr [esi]
// 008c60f1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008c60f7  51                   push ecx
// 008c60f8  57                   push edi
// 008c60f9  8bce                 mov ecx, esi
// 008c60fb  ffd2                 call edx
// 008c60fd  5f                   pop edi
// 008c60fe  8bc6                 mov eax, esi
// 008c6100  5e                   pop esi
// 008c6101  c20400               ret 4

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
