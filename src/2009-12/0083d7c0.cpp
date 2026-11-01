// from server: 100% by nuck16
// roc 2009-12 0083d7c0  unit: CXTPControlColorSelector  size: 36 bytes
//
// 0083d7c0  56                   push esi
// 0083d7c1  57                   push edi
// 0083d7c2  8bf9                 mov edi, ecx
// 0083d7c4  e887ffffff           call 0x83d750
// 0083d7c9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0083d7cd  8bf0                 mov esi, eax
// 0083d7cf  8b06                 mov eax, dword ptr [esi]
// 0083d7d1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 0083d7d7  51                   push ecx
// 0083d7d8  57                   push edi
// 0083d7d9  8bce                 mov ecx, esi
// 0083d7db  ffd2                 call edx
// 0083d7dd  5f                   pop edi
// 0083d7de  8bc6                 mov eax, esi
// 0083d7e0  5e                   pop esi
// 0083d7e1  c20400               ret 4

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
