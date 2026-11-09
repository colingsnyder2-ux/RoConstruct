// from server: 100% by nuck16
// roc 2009-12 004c1de0  unit: RBX::VSparkles::?$FactoryProduct::Creator  size: 66 bytes
//
// 004c1de0  51                   push ecx
// 004c1de1  56                   push esi
// 004c1de2  c744240400000000     mov dword ptr [esp + 4], 0
// 004c1dea  e801e5f5ff           call 0x4202f0
// 004c1def  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c1df3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c1df7  83ec10               sub esp, 0x10
// 004c1dfa  8bd4                 mov edx, esp
// 004c1dfc  890a                 mov dword ptr [edx], ecx
// 004c1dfe  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c1e02  894a04               mov dword ptr [edx + 4], ecx
// 004c1e05  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c1e09  894a08               mov dword ptr [edx + 8], ecx
// 004c1e0c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004c1e10  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c1e13  56                   push esi
// 004c1e14  8bc8                 mov ecx, eax
// 004c1e16  e825fdffff           call 0x4c1b40
// 004c1e1b  8bc6                 mov eax, esi
// 004c1e1d  5e                   pop esi
// 004c1e1e  59                   pop ecx
// 004c1e1f  c21400               ret 0x14

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
