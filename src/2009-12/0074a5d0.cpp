// from server: 100% by nuck16
// roc 2009-12 0074a5d0  unit: RBX::VHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074a5d0
//
// 0074a5d0  51                   push ecx
// 0074a5d1  56                   push esi
// 0074a5d2  c744240400000000     mov dword ptr [esp + 4], 0
// 0074a5da  e8a1edffff           call 0x749380
// 0074a5df  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074a5e3  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074a5e7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074a5eb  51                   push ecx
// 0074a5ec  52                   push edx
// 0074a5ed  56                   push esi
// 0074a5ee  8bc8                 mov ecx, eax
// 0074a5f0  e87be2ffff           call 0x748870
// 0074a5f5  8bc6                 mov eax, esi
// 0074a5f7  5e                   pop esi
// 0074a5f8  59                   pop ecx
// 0074a5f9  c20c00               ret 0xc

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
