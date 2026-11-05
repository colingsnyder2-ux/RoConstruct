// from server: 100% by nuck16
// roc 2009-12 004548a0  unit: CRobloxControlMaterialSelector  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004548a0
//
// 004548a0  56                   push esi
// 004548a1  57                   push edi
// 004548a2  8bf9                 mov edi, ecx
// 004548a4  e897ffffff           call 0x454840
// 004548a9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004548ad  8bf0                 mov esi, eax
// 004548af  8b06                 mov eax, dword ptr [esi]
// 004548b1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 004548b7  51                   push ecx
// 004548b8  57                   push edi
// 004548b9  8bce                 mov ecx, esi
// 004548bb  ffd2                 call edx
// 004548bd  5f                   pop edi
// 004548be  8bc6                 mov eax, esi
// 004548c0  5e                   pop esi
// 004548c1  c20400               ret 4

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
