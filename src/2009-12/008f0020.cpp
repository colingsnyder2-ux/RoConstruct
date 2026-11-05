// from server: 100% by nuck16
// roc 2009-12 008f0020  unit: CXTPRibbonGroupPopupToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f0020
//
// 008f0020  56                   push esi
// 008f0021  57                   push edi
// 008f0022  8bf9                 mov edi, ecx
// 008f0024  e887ffffff           call 0x8effb0
// 008f0029  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f002d  8bf0                 mov esi, eax
// 008f002f  8b06                 mov eax, dword ptr [esi]
// 008f0031  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008f0037  51                   push ecx
// 008f0038  57                   push edi
// 008f0039  8bce                 mov ecx, esi
// 008f003b  ffd2                 call edx
// 008f003d  5f                   pop edi
// 008f003e  8bc6                 mov eax, esi
// 008f0040  5e                   pop esi
// 008f0041  c20400               ret 4

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
