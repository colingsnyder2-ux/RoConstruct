// from server: 100% by nuck16
// roc 2009-12 005d52f0  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d52f0  51                   push ecx
// 005d52f1  56                   push esi
// 005d52f2  c744240400000000     mov dword ptr [esp + 4], 0
// 005d52fa  e81173e4ff           call 0x41c610
// 005d52ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5303  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5307  83ec10               sub esp, 0x10
// 005d530a  8bd4                 mov edx, esp
// 005d530c  890a                 mov dword ptr [edx], ecx
// 005d530e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5312  894a04               mov dword ptr [edx + 4], ecx
// 005d5315  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5319  894a08               mov dword ptr [edx + 8], ecx
// 005d531c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5320  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5323  56                   push esi
// 005d5324  8bc8                 mov ecx, eax
// 005d5326  e805e3ffff           call 0x5d3630
// 005d532b  8bc6                 mov eax, esi
// 005d532d  5e                   pop esi
// 005d532e  59                   pop ecx
// 005d532f  c21400               ret 0x14

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
