// from server: 100% by nuck16
// roc 2009-12 0083d0d0  unit: CXTPControlButtonColor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083d0d0
//
// 0083d0d0  56                   push esi
// 0083d0d1  57                   push edi
// 0083d0d2  8bf9                 mov edi, ecx
// 0083d0d4  e887ffffff           call 0x83d060
// 0083d0d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083d0dd  8bf0                 mov esi, eax
// 0083d0df  8b06                 mov eax, dword ptr [esi]
// 0083d0e1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0083d0e7  51                   push ecx
// 0083d0e8  57                   push edi
// 0083d0e9  8bce                 mov ecx, esi
// 0083d0eb  ffd2                 call edx
// 0083d0ed  5f                   pop edi
// 0083d0ee  8bc6                 mov eax, esi
// 0083d0f0  5e                   pop esi
// 0083d0f1  c20400               ret 4

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
