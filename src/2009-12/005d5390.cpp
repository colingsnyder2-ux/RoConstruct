// from server: 100% by nuck16
// roc 2009-12 005d5390  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5390  51                   push ecx
// 005d5391  56                   push esi
// 005d5392  c744240400000000     mov dword ptr [esp + 4], 0
// 005d539a  e851afe4ff           call 0x4202f0
// 005d539f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d53a3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d53a7  83ec10               sub esp, 0x10
// 005d53aa  8bd4                 mov edx, esp
// 005d53ac  890a                 mov dword ptr [edx], ecx
// 005d53ae  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d53b2  894a04               mov dword ptr [edx + 4], ecx
// 005d53b5  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d53b9  894a08               mov dword ptr [edx + 8], ecx
// 005d53bc  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d53c0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d53c3  56                   push esi
// 005d53c4  8bc8                 mov ecx, eax
// 005d53c6  e825e5ffff           call 0x5d38f0
// 005d53cb  8bc6                 mov eax, esi
// 005d53cd  5e                   pop esi
// 005d53ce  59                   pop ecx
// 005d53cf  c21400               ret 0x14

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
