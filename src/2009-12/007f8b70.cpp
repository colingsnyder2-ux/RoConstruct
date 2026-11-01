// from server: 100% by nuck16
// roc 2009-12 007f8b70  unit: CXTPControl  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f8b70
//
// 007f8b70  56                   push esi
// 007f8b71  57                   push edi
// 007f8b72  8bf9                 mov edi, ecx
// 007f8b74  e887ffffff           call 0x7f8b00
// 007f8b79  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007f8b7d  8bf0                 mov esi, eax
// 007f8b7f  8b06                 mov eax, dword ptr [esi]
// 007f8b81  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 007f8b87  51                   push ecx
// 007f8b88  57                   push edi
// 007f8b89  8bce                 mov ecx, esi
// 007f8b8b  ffd2                 call edx
// 007f8b8d  5f                   pop edi
// 007f8b8e  8bc6                 mov eax, esi
// 007f8b90  5e                   pop esi
// 007f8b91  c20400               ret 4

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
