// from server: 100% by nuck16
// roc 2009-12 00895a40  unit: CXTPRibbonBarControlQuickAccessPopup  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00895a40
//
// 00895a40  56                   push esi
// 00895a41  57                   push edi
// 00895a42  8bf9                 mov edi, ecx
// 00895a44  e887ffffff           call 0x8959d0
// 00895a49  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00895a4d  8bf0                 mov esi, eax
// 00895a4f  8b06                 mov eax, dword ptr [esi]
// 00895a51  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00895a57  51                   push ecx
// 00895a58  57                   push edi
// 00895a59  8bce                 mov ecx, esi
// 00895a5b  ffd2                 call edx
// 00895a5d  5f                   pop edi
// 00895a5e  8bc6                 mov eax, esi
// 00895a60  5e                   pop esi
// 00895a61  c20400               ret 4

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
