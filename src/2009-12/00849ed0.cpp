// from server: 100% by nuck16
// roc 2009-12 00849ed0  unit: CXTPControlRadioButton  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00849ed0
//
// 00849ed0  56                   push esi
// 00849ed1  57                   push edi
// 00849ed2  8bf9                 mov edi, ecx
// 00849ed4  e887ffffff           call 0x849e60
// 00849ed9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00849edd  8bf0                 mov esi, eax
// 00849edf  8b06                 mov eax, dword ptr [esi]
// 00849ee1  8b90e0000000         mov edx, dword ptr [eax + 0xe0]
// 00849ee7  51                   push ecx
// 00849ee8  57                   push edi
// 00849ee9  8bce                 mov ecx, esi
// 00849eeb  ffd2                 call edx
// 00849eed  5f                   pop edi
// 00849eee  8bc6                 mov eax, esi
// 00849ef0  5e                   pop esi
// 00849ef1  c20400               ret 4

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
