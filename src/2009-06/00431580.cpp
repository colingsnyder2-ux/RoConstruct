// from server: 75% by atomic.potato
// roc 2009-06 00431580  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00431580
//
// 00431580  8964240c             mov dword ptr [esp + 0xc], esp
// 00431584  50                   push eax
// 00431585  ff1508fd8900         call dword ptr [0x89fd08]
// 0043158b  8b06                 mov eax, dword ptr [esi]
// 0043158d  8b5060               mov edx, dword ptr [eax + 0x60]
// 00431590  8bce                 mov ecx, esi
// 00431592  ffd2                 call edx
// 00431594  5e                   pop esi
// 00431595  c20400               ret 4

extern "C" void __stdcall sub_89fd08();

struct S {
    void f(int);
};

void S::f(int) {
    sub_89fd08();
    void** vt = *(void***)this;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x60 / 4];
    fn(this);
}
