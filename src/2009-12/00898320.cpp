// from server: 100% by nuck16
// roc 2009-12 00898320  unit: CXTPRibbonBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00898320
//
// 00898320  56                   push esi
// 00898321  57                   push edi
// 00898322  8bf9                 mov edi, ecx
// 00898324  e887ffffff           call 0x8982b0
// 00898329  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0089832d  8bf0                 mov esi, eax
// 0089832f  8b06                 mov eax, dword ptr [esi]
// 00898331  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 00898337  51                   push ecx
// 00898338  57                   push edi
// 00898339  8bce                 mov ecx, esi
// 0089833b  ffd2                 call edx
// 0089833d  5f                   pop edi
// 0089833e  8bc6                 mov eax, esi
// 00898340  5e                   pop esi
// 00898341  c20400               ret 4

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
