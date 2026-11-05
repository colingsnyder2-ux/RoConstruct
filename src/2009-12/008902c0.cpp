// from server: 100% by nuck16
// roc 2009-12 008902c0  unit: CXTPToolBar::CControlButtonHide  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008902c0
//
// 008902c0  56                   push esi
// 008902c1  57                   push edi
// 008902c2  8bf9                 mov edi, ecx
// 008902c4  e887ffffff           call 0x890250
// 008902c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008902cd  8bf0                 mov esi, eax
// 008902cf  8b06                 mov eax, dword ptr [esi]
// 008902d1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 008902d7  51                   push ecx
// 008902d8  57                   push edi
// 008902d9  8bce                 mov ecx, esi
// 008902db  ffd2                 call edx
// 008902dd  5f                   pop edi
// 008902de  8bc6                 mov eax, esi
// 008902e0  5e                   pop esi
// 008902e1  c20400               ret 4

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
