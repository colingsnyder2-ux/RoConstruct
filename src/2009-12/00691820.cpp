// from server: 100% by nuck16
// roc 2009-12 00691820  unit: RBX::LegacyHopperService  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00691820
//
// 00691820  51                   push ecx
// 00691821  56                   push esi
// 00691822  c744240400000000     mov dword ptr [esp + 4], 0
// 0069182a  e831f6dcff           call 0x460e60
// 0069182f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00691833  8b542410             mov edx, dword ptr [esp + 0x10]
// 00691837  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069183b  51                   push ecx
// 0069183c  52                   push edx
// 0069183d  56                   push esi
// 0069183e  8bc8                 mov ecx, eax
// 00691840  e85be8ffff           call 0x6900a0
// 00691845  8bc6                 mov eax, esi
// 00691847  5e                   pop esi
// 00691848  59                   pop ecx
// 00691849  c20c00               ret 0xc

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
