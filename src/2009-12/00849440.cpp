// from server: 100% by nuck16
// roc 2009-12 00849440  unit: CXTPControlRecentFileList  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00849440
//
// 00849440  56                   push esi
// 00849441  57                   push edi
// 00849442  8bf9                 mov edi, ecx
// 00849444  e887ffffff           call 0x8493d0
// 00849449  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0084944d  8bf0                 mov esi, eax
// 0084944f  8b06                 mov eax, dword ptr [esi]
// 00849451  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00849457  51                   push ecx
// 00849458  57                   push edi
// 00849459  8bce                 mov ecx, esi
// 0084945b  ffd2                 call edx
// 0084945d  5f                   pop edi
// 0084945e  8bc6                 mov eax, esi
// 00849460  5e                   pop esi
// 00849461  c20400               ret 4

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
