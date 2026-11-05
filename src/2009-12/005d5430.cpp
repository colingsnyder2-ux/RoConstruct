// from server: 100% by nuck16
// roc 2009-12 005d5430  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5430  51                   push ecx
// 005d5431  56                   push esi
// 005d5432  c744240400000000     mov dword ptr [esp + 4], 0
// 005d543a  e8419de9ff           call 0x46f180
// 005d543f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5443  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5447  83ec10               sub esp, 0x10
// 005d544a  8bd4                 mov edx, esp
// 005d544c  890a                 mov dword ptr [edx], ecx
// 005d544e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5452  894a04               mov dword ptr [edx + 4], ecx
// 005d5455  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5459  894a08               mov dword ptr [edx + 8], ecx
// 005d545c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5460  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5463  56                   push esi
// 005d5464  8bc8                 mov ecx, eax
// 005d5466  e845e7ffff           call 0x5d3bb0
// 005d546b  8bc6                 mov eax, esi
// 005d546d  5e                   pop esi
// 005d546e  59                   pop ecx
// 005d546f  c21400               ret 0x14

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
