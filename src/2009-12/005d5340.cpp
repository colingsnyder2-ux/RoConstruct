// from server: 100% by nuck16
// roc 2009-12 005d5340  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5340  51                   push ecx
// 005d5341  56                   push esi
// 005d5342  c744240400000000     mov dword ptr [esp + 4], 0
// 005d534a  e8319ee9ff           call 0x46f180
// 005d534f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5353  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5357  83ec10               sub esp, 0x10
// 005d535a  8bd4                 mov edx, esp
// 005d535c  890a                 mov dword ptr [edx], ecx
// 005d535e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5362  894a04               mov dword ptr [edx + 4], ecx
// 005d5365  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5369  894a08               mov dword ptr [edx + 8], ecx
// 005d536c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5370  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5373  56                   push esi
// 005d5374  8bc8                 mov ecx, eax
// 005d5376  e815e4ffff           call 0x5d3790
// 005d537b  8bc6                 mov eax, esi
// 005d537d  5e                   pop esi
// 005d537e  59                   pop ecx
// 005d537f  c21400               ret 0x14

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
