// from server: 100% by nuck16
// roc 2009-12 0074a570  unit: RBX::VHandles::?$EventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0074a570
//
// 0074a570  51                   push ecx
// 0074a571  56                   push esi
// 0074a572  c744240400000000     mov dword ptr [esp + 4], 0
// 0074a57a  e8e168d1ff           call 0x460e60
// 0074a57f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0074a583  8b542410             mov edx, dword ptr [esp + 0x10]
// 0074a587  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0074a58b  51                   push ecx
// 0074a58c  52                   push edx
// 0074a58d  56                   push esi
// 0074a58e  8bc8                 mov ecx, eax
// 0074a590  e85be0ffff           call 0x7485f0
// 0074a595  8bc6                 mov eax, esi
// 0074a597  5e                   pop esi
// 0074a598  59                   pop ecx
// 0074a599  c20c00               ret 0xc

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
