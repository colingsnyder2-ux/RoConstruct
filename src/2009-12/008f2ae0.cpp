// from server: 100% by nuck16
// roc 2009-12 008f2ae0  unit: CXTPRibbonSystemPopupBarPage  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2ae0
//
// 008f2ae0  56                   push esi
// 008f2ae1  57                   push edi
// 008f2ae2  8bf9                 mov edi, ecx
// 008f2ae4  e887ffffff           call 0x8f2a70
// 008f2ae9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f2aed  8bf0                 mov esi, eax
// 008f2aef  8b06                 mov eax, dword ptr [esi]
// 008f2af1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008f2af7  51                   push ecx
// 008f2af8  57                   push edi
// 008f2af9  8bce                 mov ecx, esi
// 008f2afb  ffd2                 call edx
// 008f2afd  5f                   pop edi
// 008f2afe  8bc6                 mov eax, esi
// 008f2b00  5e                   pop esi
// 008f2b01  c20400               ret 4

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
