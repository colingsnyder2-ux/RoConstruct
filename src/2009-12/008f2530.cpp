// from server: 100% by nuck16
// roc 2009-12 008f2530  unit: CXTPRibbonControlSystemPopupBarListCaption  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2530
//
// 008f2530  56                   push esi
// 008f2531  57                   push edi
// 008f2532  8bf9                 mov edi, ecx
// 008f2534  e887ffffff           call 0x8f24c0
// 008f2539  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f253d  8bf0                 mov esi, eax
// 008f253f  8b06                 mov eax, dword ptr [esi]
// 008f2541  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008f2547  51                   push ecx
// 008f2548  57                   push edi
// 008f2549  8bce                 mov ecx, esi
// 008f254b  ffd2                 call edx
// 008f254d  5f                   pop edi
// 008f254e  8bc6                 mov eax, esi
// 008f2550  5e                   pop esi
// 008f2551  c20400               ret 4

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
