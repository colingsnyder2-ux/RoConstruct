// from server: 100% by nuck16
// roc 2009-12 00844fe0  unit: CXTPPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00844fe0
//
// 00844fe0  56                   push esi
// 00844fe1  57                   push edi
// 00844fe2  8bf9                 mov edi, ecx
// 00844fe4  e887ffffff           call 0x844f70
// 00844fe9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00844fed  8bf0                 mov esi, eax
// 00844fef  8b06                 mov eax, dword ptr [esi]
// 00844ff1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00844ff7  51                   push ecx
// 00844ff8  57                   push edi
// 00844ff9  8bce                 mov ecx, esi
// 00844ffb  ffd2                 call edx
// 00844ffd  5f                   pop edi
// 00844ffe  8bc6                 mov eax, esi
// 00845000  5e                   pop esi
// 00845001  c20400               ret 4

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
