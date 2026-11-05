// from server: 100% by nuck16
// roc 2009-12 00894120  unit: CXTPMenuBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00894120
//
// 00894120  56                   push esi
// 00894121  57                   push edi
// 00894122  8bf9                 mov edi, ecx
// 00894124  e887ffffff           call 0x8940b0
// 00894129  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089412d  8bf0                 mov esi, eax
// 0089412f  8b06                 mov eax, dword ptr [esi]
// 00894131  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00894137  51                   push ecx
// 00894138  57                   push edi
// 00894139  8bce                 mov ecx, esi
// 0089413b  ffd2                 call edx
// 0089413d  5f                   pop edi
// 0089413e  8bc6                 mov eax, esi
// 00894140  5e                   pop esi
// 00894141  c20400               ret 4

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
