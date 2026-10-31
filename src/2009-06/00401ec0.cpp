// from server: 95% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00405e30  unit: boost::detail::sp_counted_base  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00405e30
//
// 00405e30  56                   push esi
// 00405e31  8b742408             mov esi, dword ptr [esp + 8]
// 00405e35  56                   push esi
// 00405e36  e835591500           call 0x55b770
// 00405e3b  83c404               add esp, 4
// 00405e3e  85f6                 test esi, esi
// 00405e40  7413                 je 0x405e55
// 00405e42  8b4610               mov eax, dword ptr [esi + 0x10]
// 00405e45  8d4e10               lea ecx, [esi + 0x10]
// 00405e48  5e                   pop esi
// 00405e49  c744240401000000     mov dword ptr [esp + 4], 1
// 00405e51  8b10                 mov edx, dword ptr [eax]
// 00405e53  ffe2                 jmp edx
// 00405e55  5e                   pop esi
// 00405e56  c20400               ret 4

struct Object {
    virtual void destroy(unsigned int);
};

struct S {
    unsigned char padding[16];
    Object object;
};

extern unsigned int __cdecl cleanup(const S&);

void __stdcall f(S* p)
{
    cleanup(*p);
    if (p)
        p->object.destroy(1);
}
