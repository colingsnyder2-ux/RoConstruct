// from server: 100% by nuck16
// roc 2009-12 00691850  unit: RBX::LegacyHopperService  size: 66 bytes
//
// 00691850  51                   push ecx
// 00691851  56                   push esi
// 00691852  c744240400000000     mov dword ptr [esp + 4], 0
// 0069185a  e84104e3ff           call 0x4c1ca0
// 0069185f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00691863  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00691867  83ec10               sub esp, 0x10
// 0069186a  8bd4                 mov edx, esp
// 0069186c  890a                 mov dword ptr [edx], ecx
// 0069186e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00691872  894a04               mov dword ptr [edx + 4], ecx
// 00691875  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00691879  894a08               mov dword ptr [edx + 8], ecx
// 0069187c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00691880  894a0c               mov dword ptr [edx + 0xc], ecx
// 00691883  56                   push esi
// 00691884  8bc8                 mov ecx, eax
// 00691886  e855e9ffff           call 0x6901e0
// 0069188b  8bc6                 mov eax, esi
// 0069188d  5e                   pop esi
// 0069188e  59                   pop ecx
// 0069188f  c21400               ret 0x14

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2, f3;
};

struct Impl
{
    Ret g(Arg arg);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(Arg arg);
};

Ret S::f(Arg arg)
{
    Impl *impl = Getter::get();
    return impl->g(arg);
}
