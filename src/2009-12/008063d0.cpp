// from server: 100% by nuck16
// roc 2009-12 008063d0  unit: CXTPCommandBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008063d0
//
// 008063d0  56                   push esi
// 008063d1  57                   push edi
// 008063d2  8bf9                 mov edi, ecx
// 008063d4  e887ffffff           call 0x806360
// 008063d9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008063dd  8bf0                 mov esi, eax
// 008063df  8b06                 mov eax, dword ptr [esi]
// 008063e1  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008063e7  51                   push ecx
// 008063e8  57                   push edi
// 008063e9  8bce                 mov ecx, esi
// 008063eb  ffd2                 call edx
// 008063ed  5f                   pop edi
// 008063ee  8bc6                 mov eax, esi
// 008063f0  5e                   pop esi
// 008063f1  c20400               ret 4

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
