// from server: 100% by nuck16
// roc 2009-12 0083ccb0  unit: CXTPControlPopupColor  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083ccb0
//
// 0083ccb0  56                   push esi
// 0083ccb1  57                   push edi
// 0083ccb2  8bf9                 mov edi, ecx
// 0083ccb4  e887ffffff           call 0x83cc40
// 0083ccb9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083ccbd  8bf0                 mov esi, eax
// 0083ccbf  8b06                 mov eax, dword ptr [esi]
// 0083ccc1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0083ccc7  51                   push ecx
// 0083ccc8  57                   push edi
// 0083ccc9  8bce                 mov ecx, esi
// 0083cccb  ffd2                 call edx
// 0083cccd  5f                   pop edi
// 0083ccce  8bc6                 mov eax, esi
// 0083ccd0  5e                   pop esi
// 0083ccd1  c20400               ret 4

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
