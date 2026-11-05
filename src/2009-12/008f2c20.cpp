// from server: 100% by nuck16
// roc 2009-12 008f2c20  unit: CXTPRibbonSystemPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2c20
//
// 008f2c20  56                   push esi
// 008f2c21  57                   push edi
// 008f2c22  8bf9                 mov edi, ecx
// 008f2c24  e887ffffff           call 0x8f2bb0
// 008f2c29  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f2c2d  8bf0                 mov esi, eax
// 008f2c2f  8b06                 mov eax, dword ptr [esi]
// 008f2c31  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008f2c37  51                   push ecx
// 008f2c38  57                   push edi
// 008f2c39  8bce                 mov ecx, esi
// 008f2c3b  ffd2                 call edx
// 008f2c3d  5f                   pop edi
// 008f2c3e  8bc6                 mov eax, esi
// 008f2c40  5e                   pop esi
// 008f2c41  c20400               ret 4

struct S
{
    void* f();
    void* g(void* p);
};

void* S::g(void* p)
{
    void* v = f();
    ((void (__thiscall*)(void*, void*, void*))(*(void***)v)[119])(v, this, p);
    return v;
}
