// from server: 100% by nuck16
// roc 2009-12 007faf20  unit: CXTPControlComboBoxList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007faf20
//
// 007faf20  56                   push esi
// 007faf21  57                   push edi
// 007faf22  8bf9                 mov edi, ecx
// 007faf24  e887ffffff           call 0x7faeb0
// 007faf29  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007faf2d  8bf0                 mov esi, eax
// 007faf2f  8b06                 mov eax, dword ptr [esi]
// 007faf31  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 007faf37  51                   push ecx
// 007faf38  57                   push edi
// 007faf39  8bce                 mov ecx, esi
// 007faf3b  ffd2                 call edx
// 007faf3d  5f                   pop edi
// 007faf3e  8bc6                 mov eax, esi
// 007faf40  5e                   pop esi
// 007faf41  c20400               ret 4

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
