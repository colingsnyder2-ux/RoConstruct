// from server: 100% by nuck16
// roc 2009-12 007fad90  unit: CXTPControlComboBoxPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fad90
//
// 007fad90  56                   push esi
// 007fad91  57                   push edi
// 007fad92  8bf9                 mov edi, ecx
// 007fad94  e887ffffff           call 0x7fad20
// 007fad99  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007fad9d  8bf0                 mov esi, eax
// 007fad9f  8b06                 mov eax, dword ptr [esi]
// 007fada1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007fada7  51                   push ecx
// 007fada8  57                   push edi
// 007fada9  8bce                 mov ecx, esi
// 007fadab  ffd2                 call edx
// 007fadad  5f                   pop edi
// 007fadae  8bc6                 mov eax, esi
// 007fadb0  5e                   pop esi
// 007fadb1  c20400               ret 4

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
