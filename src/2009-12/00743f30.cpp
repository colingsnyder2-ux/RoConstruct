// from server: 100% by nuck16
// roc 2009-12 00743f30  unit: RBX::VMotorFeature::?$FactoryProduct  size: 66 bytes
//
// 00743f30  51                   push ecx
// 00743f31  56                   push esi
// 00743f32  c744240400000000     mov dword ptr [esp + 4], 0
// 00743f3a  e841b2d2ff           call 0x46f180
// 00743f3f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00743f43  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00743f47  83ec10               sub esp, 0x10
// 00743f4a  8bd4                 mov edx, esp
// 00743f4c  890a                 mov dword ptr [edx], ecx
// 00743f4e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00743f52  894a04               mov dword ptr [edx + 4], ecx
// 00743f55  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00743f59  894a08               mov dword ptr [edx + 8], ecx
// 00743f5c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00743f60  894a0c               mov dword ptr [edx + 0xc], ecx
// 00743f63  56                   push esi
// 00743f64  8bc8                 mov ecx, eax
// 00743f66  e8a5f4ffff           call 0x743410
// 00743f6b  8bc6                 mov eax, esi
// 00743f6d  5e                   pop esi
// 00743f6e  59                   pop ecx
// 00743f6f  c21400               ret 0x14

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
