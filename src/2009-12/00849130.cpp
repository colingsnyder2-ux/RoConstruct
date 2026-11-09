// from server: 100% by nuck16
// roc 2009-12 00849130  unit: CXTPControlOleItems  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00849130
//
// 00849130  56                   push esi
// 00849131  57                   push edi
// 00849132  8bf9                 mov edi, ecx
// 00849134  e887ffffff           call 0x8490c0
// 00849139  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084913d  8bf0                 mov esi, eax
// 0084913f  8b06                 mov eax, dword ptr [esi]
// 00849141  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00849147  51                   push ecx
// 00849148  57                   push edi
// 00849149  8bce                 mov ecx, esi
// 0084914b  ffd2                 call edx
// 0084914d  5f                   pop edi
// 0084914e  8bc6                 mov eax, esi
// 00849150  5e                   pop esi
// 00849151  c20400               ret 4

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
