// from server: 100% by nuck16
// roc 2009-12 0087bff0  unit: CXTPControlComboBoxGalleryPopupBar  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087bff0
//
// 0087bff0  56                   push esi
// 0087bff1  57                   push edi
// 0087bff2  8bf9                 mov edi, ecx
// 0087bff4  e887ffffff           call 0x87bf80
// 0087bff9  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0087bffd  8bf0                 mov esi, eax
// 0087bfff  8b06                 mov eax, dword ptr [esi]
// 0087c001  8b90dc010000         mov edx, dword ptr [eax + 0x1dc]
// 0087c007  51                   push ecx
// 0087c008  57                   push edi
// 0087c009  8bce                 mov ecx, esi
// 0087c00b  ffd2                 call edx
// 0087c00d  5f                   pop edi
// 0087c00e  8bc6                 mov eax, esi
// 0087c010  5e                   pop esi
// 0087c011  c20400               ret 4

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
