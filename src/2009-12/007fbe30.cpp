// from server: 100% by nuck16
// roc 2009-12 007fbe30  unit: CXTPControlComboBox  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fbe30
//
// 007fbe30  56                   push esi
// 007fbe31  57                   push edi
// 007fbe32  8bf9                 mov edi, ecx
// 007fbe34  e887ffffff           call 0x7fbdc0
// 007fbe39  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007fbe3d  8bf0                 mov esi, eax
// 007fbe3f  8b06                 mov eax, dword ptr [esi]
// 007fbe41  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 007fbe47  51                   push ecx
// 007fbe48  57                   push edi
// 007fbe49  8bce                 mov ecx, esi
// 007fbe4b  ffd2                 call edx
// 007fbe4d  5f                   pop edi
// 007fbe4e  8bc6                 mov eax, esi
// 007fbe50  5e                   pop esi
// 007fbe51  c20400               ret 4

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
