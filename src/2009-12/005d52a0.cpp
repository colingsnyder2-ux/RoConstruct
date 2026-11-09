// from server: 100% by nuck16
// roc 2009-12 005d52a0  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d52a0  51                   push ecx
// 005d52a1  56                   push esi
// 005d52a2  c744240400000000     mov dword ptr [esp + 4], 0
// 005d52aa  e871f9ffff           call 0x5d4c20
// 005d52af  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d52b3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d52b7  83ec10               sub esp, 0x10
// 005d52ba  8bd4                 mov edx, esp
// 005d52bc  890a                 mov dword ptr [edx], ecx
// 005d52be  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d52c2  894a04               mov dword ptr [edx + 4], ecx
// 005d52c5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d52c9  894a08               mov dword ptr [edx + 8], ecx
// 005d52cc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d52d0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d52d3  56                   push esi
// 005d52d4  8bc8                 mov ecx, eax
// 005d52d6  e8f5e1ffff           call 0x5d34d0
// 005d52db  8bc6                 mov eax, esi
// 005d52dd  5e                   pop esi
// 005d52de  59                   pop ecx
// 005d52df  c21400               ret 0x14

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
