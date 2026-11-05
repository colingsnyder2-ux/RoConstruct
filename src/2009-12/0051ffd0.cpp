// from server: 100% by nuck16
// roc 2009-12 0051ffd0  unit: RBX::Network::Players  size: 66 bytes
//
// 0051ffd0  51                   push ecx
// 0051ffd1  56                   push esi
// 0051ffd2  c744240400000000     mov dword ptr [esp + 4], 0
// 0051ffda  e831c6efff           call 0x41c610
// 0051ffdf  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0051ffe3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0051ffe7  83ec10               sub esp, 0x10
// 0051ffea  8bd4                 mov edx, esp
// 0051ffec  890a                 mov dword ptr [edx], ecx
// 0051ffee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0051fff2  894a04               mov dword ptr [edx + 4], ecx
// 0051fff5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0051fff9  894a08               mov dword ptr [edx + 8], ecx
// 0051fffc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00520000  894a0c               mov dword ptr [edx + 0xc], ecx
// 00520003  56                   push esi
// 00520004  8bc8                 mov ecx, eax
// 00520006  e8a5b4ffff           call 0x51b4b0
// 0052000b  8bc6                 mov eax, esi
// 0052000d  5e                   pop esi
// 0052000e  59                   pop ecx
// 0052000f  c21400               ret 0x14

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
