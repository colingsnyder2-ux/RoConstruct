// from server: 100% by nuck16
// roc 2009-12 005d5250  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5250  51                   push ecx
// 005d5251  56                   push esi
// 005d5252  c744240400000000     mov dword ptr [esp + 4], 0
// 005d525a  e841caeeff           call 0x4c1ca0
// 005d525f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5263  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5267  83ec10               sub esp, 0x10
// 005d526a  8bd4                 mov edx, esp
// 005d526c  890a                 mov dword ptr [edx], ecx
// 005d526e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5272  894a04               mov dword ptr [edx + 4], ecx
// 005d5275  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5279  894a08               mov dword ptr [edx + 8], ecx
// 005d527c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5280  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5283  56                   push esi
// 005d5284  8bc8                 mov ecx, eax
// 005d5286  e8e5e0ffff           call 0x5d3370
// 005d528b  8bc6                 mov eax, esi
// 005d528d  5e                   pop esi
// 005d528e  59                   pop ecx
// 005d528f  c21400               ret 0x14

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
