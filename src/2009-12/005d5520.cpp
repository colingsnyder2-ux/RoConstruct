// from server: 100% by nuck16
// roc 2009-12 005d5520  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5520  51                   push ecx
// 005d5521  56                   push esi
// 005d5522  c744240400000000     mov dword ptr [esp + 4], 0
// 005d552a  e8c1ade4ff           call 0x4202f0
// 005d552f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5533  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5537  83ec10               sub esp, 0x10
// 005d553a  8bd4                 mov edx, esp
// 005d553c  890a                 mov dword ptr [edx], ecx
// 005d553e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5542  894a04               mov dword ptr [edx + 4], ecx
// 005d5545  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5549  894a08               mov dword ptr [edx + 8], ecx
// 005d554c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5550  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5553  56                   push esi
// 005d5554  8bc8                 mov ecx, eax
// 005d5556  e875eaffff           call 0x5d3fd0
// 005d555b  8bc6                 mov eax, esi
// 005d555d  5e                   pop esi
// 005d555e  59                   pop ecx
// 005d555f  c21400               ret 0x14

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
