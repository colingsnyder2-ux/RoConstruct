// from server: 100% by nuck16
// roc 2009-12 0087a3b0  unit: CXTPControlGallery  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087a3b0
//
// 0087a3b0  56                   push esi
// 0087a3b1  57                   push edi
// 0087a3b2  8bf9                 mov edi, ecx
// 0087a3b4  e887ffffff           call 0x87a340
// 0087a3b9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0087a3bd  8bf0                 mov esi, eax
// 0087a3bf  8b06                 mov eax, dword ptr [esi]
// 0087a3c1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0087a3c7  51                   push ecx
// 0087a3c8  57                   push edi
// 0087a3c9  8bce                 mov ecx, esi
// 0087a3cb  ffd2                 call edx
// 0087a3cd  5f                   pop edi
// 0087a3ce  8bc6                 mov eax, esi
// 0087a3d0  5e                   pop esi
// 0087a3d1  c20400               ret 4

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
