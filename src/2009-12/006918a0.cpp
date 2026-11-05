// from server: 100% by nuck16
// roc 2009-12 006918a0  unit: RBX::LegacyHopperService  size: 66 bytes
//
// 006918a0  51                   push ecx
// 006918a1  56                   push esi
// 006918a2  c744240400000000     mov dword ptr [esp + 4], 0
// 006918aa  e861add8ff           call 0x41c610
// 006918af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006918b3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006918b7  83ec10               sub esp, 0x10
// 006918ba  8bd4                 mov edx, esp
// 006918bc  890a                 mov dword ptr [edx], ecx
// 006918be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006918c2  894a04               mov dword ptr [edx + 4], ecx
// 006918c5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006918c9  894a08               mov dword ptr [edx + 8], ecx
// 006918cc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006918d0  894a0c               mov dword ptr [edx + 0xc], ecx
// 006918d3  56                   push esi
// 006918d4  8bc8                 mov ecx, eax
// 006918d6  e865eaffff           call 0x690340
// 006918db  8bc6                 mov eax, esi
// 006918dd  5e                   pop esi
// 006918de  59                   pop ecx
// 006918df  c21400               ret 0x14

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
