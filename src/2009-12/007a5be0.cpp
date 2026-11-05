// from server: 100% by nuck16
// roc 2009-12 007a5be0  unit: RBX::$$A6AXABVStepped::?$signal::slot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007a5be0
//
// 007a5be0  51                   push ecx
// 007a5be1  56                   push esi
// 007a5be2  c744240400000000     mov dword ptr [esp + 4], 0
// 007a5bea  e851ffffff           call 0x7a5b40
// 007a5bef  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a5bf3  8b542410             mov edx, dword ptr [esp + 0x10]
// 007a5bf7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007a5bfb  51                   push ecx
// 007a5bfc  52                   push edx
// 007a5bfd  56                   push esi
// 007a5bfe  8bc8                 mov ecx, eax
// 007a5c00  e8fbfdffff           call 0x7a5a00
// 007a5c05  8bc6                 mov eax, esi
// 007a5c07  5e                   pop esi
// 007a5c08  59                   pop ecx
// 007a5c09  c20c00               ret 0xc

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Impl
{
    Ret g(void *a0, void *a1);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(void *a0, void *a1);
};

Ret S::f(void *a0, void *a1)
{
    Impl *impl = Getter::get();
    return impl->g(a0, a1);
}
