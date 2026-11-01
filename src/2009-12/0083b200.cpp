// from server: 100% by nuck16
// roc 2009-12 0083b200  unit: CXTPToolBar::CControlButtonExpand  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b200
//
// 0083b200  56                   push esi
// 0083b201  57                   push edi
// 0083b202  8bf9                 mov edi, ecx
// 0083b204  e887ffffff           call 0x83b190
// 0083b209  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083b20d  8bf0                 mov esi, eax
// 0083b20f  8b06                 mov eax, dword ptr [esi]
// 0083b211  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0083b217  51                   push ecx
// 0083b218  57                   push edi
// 0083b219  8bce                 mov ecx, esi
// 0083b21b  ffd2                 call edx
// 0083b21d  5f                   pop edi
// 0083b21e  8bc6                 mov eax, esi
// 0083b220  5e                   pop esi
// 0083b221  c20400               ret 4

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
