// from server: 100% by nuck16
// roc 2009-12 005d5480  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5480  51                   push ecx
// 005d5481  56                   push esi
// 005d5482  c744240400000000     mov dword ptr [esp + 4], 0
// 005d548a  e861aee4ff           call 0x4202f0
// 005d548f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5493  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5497  83ec10               sub esp, 0x10
// 005d549a  8bd4                 mov edx, esp
// 005d549c  890a                 mov dword ptr [edx], ecx
// 005d549e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d54a2  894a04               mov dword ptr [edx + 4], ecx
// 005d54a5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d54a9  894a08               mov dword ptr [edx + 8], ecx
// 005d54ac  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d54b0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d54b3  56                   push esi
// 005d54b4  8bc8                 mov ecx, eax
// 005d54b6  e855e8ffff           call 0x5d3d10
// 005d54bb  8bc6                 mov eax, esi
// 005d54bd  5e                   pop esi
// 005d54be  59                   pop ecx
// 005d54bf  c21400               ret 0x14

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
