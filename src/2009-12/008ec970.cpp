// from server: 100% by nuck16
// roc 2009-12 008ec970  unit: CXTPDialogBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ec970
//
// 008ec970  56                   push esi
// 008ec971  57                   push edi
// 008ec972  8bf9                 mov edi, ecx
// 008ec974  e887ffffff           call 0x8ec900
// 008ec979  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008ec97d  8bf0                 mov esi, eax
// 008ec97f  8b06                 mov eax, dword ptr [esi]
// 008ec981  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 008ec987  51                   push ecx
// 008ec988  57                   push edi
// 008ec989  8bce                 mov ecx, esi
// 008ec98b  ffd2                 call edx
// 008ec98d  5f                   pop edi
// 008ec98e  8bc6                 mov eax, esi
// 008ec990  5e                   pop esi
// 008ec991  c20400               ret 4

struct S
{
    void* f();
    void* g(void* p);
};

void* S::g(void* p)
{
    void* v = f();
    ((void (__thiscall*)(void*, void*, void*))(*(void***)v)[119])(v, this, p);
    return v;
}
