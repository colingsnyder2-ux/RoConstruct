// from server: 75% by colin
// roc 2007-08 00438be0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00438be0
//
// 00438be0  8964240c             mov dword ptr [esp + 0xc], esp
// 00438be4  50                   push eax
// 00438be5  ff15b8dd7700         call dword ptr [0x77ddb8]
// 00438beb  8b06                 mov eax, dword ptr [esi]
// 00438bed  8b5060               mov edx, dword ptr [eax + 0x60]
// 00438bf0  8bce                 mov ecx, esi
// 00438bf2  ffd2                 call edx
// 00438bf4  5e                   pop esi
// 00438bf5  c20400               ret 4

struct S {
    void f(int);
};

extern "C" void __stdcall sub_77ddb8();

void S::f(int)
{
    sub_77ddb8();
    void** vtbl = *(void***)this;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vtbl[0x60 / 4];
    fn(this);
}
