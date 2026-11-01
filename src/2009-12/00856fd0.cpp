// from server: 100% by nuck16
// roc 2009-12 00856fd0  unit: CXTPControlTabWorkspace  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00856fd0
//
// 00856fd0  56                   push esi
// 00856fd1  57                   push edi
// 00856fd2  8bf9                 mov edi, ecx
// 00856fd4  e887ffffff           call 0x856f60
// 00856fd9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00856fdd  8bf0                 mov esi, eax
// 00856fdf  8b06                 mov eax, dword ptr [esi]
// 00856fe1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00856fe7  51                   push ecx
// 00856fe8  57                   push edi
// 00856fe9  8bce                 mov ecx, esi
// 00856feb  ffd2                 call edx
// 00856fed  5f                   pop edi
// 00856fee  8bc6                 mov eax, esi
// 00856ff0  5e                   pop esi
// 00856ff1  c20400               ret 4

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
