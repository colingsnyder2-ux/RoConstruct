// from server: 100% by nuck16
// roc 2009-12 008f27c0  unit: CXTPRibbonControlSystemRecentFileList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f27c0
//
// 008f27c0  56                   push esi
// 008f27c1  57                   push edi
// 008f27c2  8bf9                 mov edi, ecx
// 008f27c4  e887ffffff           call 0x8f2750
// 008f27c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008f27cd  8bf0                 mov esi, eax
// 008f27cf  8b06                 mov eax, dword ptr [esi]
// 008f27d1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008f27d7  51                   push ecx
// 008f27d8  57                   push edi
// 008f27d9  8bce                 mov ecx, esi
// 008f27db  ffd2                 call edx
// 008f27dd  5f                   pop edi
// 008f27de  8bc6                 mov eax, esi
// 008f27e0  5e                   pop esi
// 008f27e1  c20400               ret 4

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
