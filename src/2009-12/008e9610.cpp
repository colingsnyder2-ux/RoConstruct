// from server: 100% by nuck16
// roc 2009-12 008e9610  unit: CXTPRibbonGroupControlPopup  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e9610
//
// 008e9610  56                   push esi
// 008e9611  57                   push edi
// 008e9612  8bf9                 mov edi, ecx
// 008e9614  e887ffffff           call 0x8e95a0
// 008e9619  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008e961d  8bf0                 mov esi, eax
// 008e961f  8b06                 mov eax, dword ptr [esi]
// 008e9621  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008e9627  51                   push ecx
// 008e9628  57                   push edi
// 008e9629  8bce                 mov ecx, esi
// 008e962b  ffd2                 call edx
// 008e962d  5f                   pop edi
// 008e962e  8bc6                 mov eax, esi
// 008e9630  5e                   pop esi
// 008e9631  c20400               ret 4

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
