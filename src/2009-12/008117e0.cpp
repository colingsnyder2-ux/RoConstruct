// from server: 100% by nuck16
// roc 2009-12 008117e0  unit: CXTPToolBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008117e0
//
// 008117e0  56                   push esi
// 008117e1  57                   push edi
// 008117e2  8bf9                 mov edi, ecx
// 008117e4  e887ffffff           call 0x811770
// 008117e9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008117ed  8bf0                 mov esi, eax
// 008117ef  8b06                 mov eax, dword ptr [esi]
// 008117f1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008117f7  51                   push ecx
// 008117f8  57                   push edi
// 008117f9  8bce                 mov ecx, esi
// 008117fb  ffd2                 call edx
// 008117fd  5f                   pop edi
// 008117fe  8bc6                 mov eax, esi
// 00811800  5e                   pop esi
// 00811801  c20400               ret 4

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
