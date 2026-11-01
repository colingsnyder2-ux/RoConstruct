// from server: 100% by nuck16
// roc 2009-12 008f08f0  unit: CXTPRibbonControlTab  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f08f0
//
// 008f08f0  56                   push esi
// 008f08f1  57                   push edi
// 008f08f2  8bf9                 mov edi, ecx
// 008f08f4  e887ffffff           call 0x8f0880
// 008f08f9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f08fd  8bf0                 mov esi, eax
// 008f08ff  8b06                 mov eax, dword ptr [esi]
// 008f0901  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008f0907  51                   push ecx
// 008f0908  57                   push edi
// 008f0909  8bce                 mov ecx, esi
// 008f090b  ffd2                 call edx
// 008f090d  5f                   pop edi
// 008f090e  8bc6                 mov eax, esi
// 008f0910  5e                   pop esi
// 008f0911  c20400               ret 4

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
