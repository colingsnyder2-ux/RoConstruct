// from server: 100% by nuck16
// roc 2009-12 008f23b0  unit: CXTPRibbonControlSystemPopupBarListItem  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f23b0
//
// 008f23b0  56                   push esi
// 008f23b1  57                   push edi
// 008f23b2  8bf9                 mov edi, ecx
// 008f23b4  e887ffffff           call 0x8f2340
// 008f23b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f23bd  8bf0                 mov esi, eax
// 008f23bf  8b06                 mov eax, dword ptr [esi]
// 008f23c1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008f23c7  51                   push ecx
// 008f23c8  57                   push edi
// 008f23c9  8bce                 mov ecx, esi
// 008f23cb  ffd2                 call edx
// 008f23cd  5f                   pop edi
// 008f23ce  8bc6                 mov eax, esi
// 008f23d0  5e                   pop esi
// 008f23d1  c20400               ret 4

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
