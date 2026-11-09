// from server: 100% by nuck16
// roc 2009-12 005d5200  unit: RBX::MaterialBaseRefMaterialAdapter  size: 66 bytes
//
// 005d5200  51                   push ecx
// 005d5201  56                   push esi
// 005d5202  c744240400000000     mov dword ptr [esp + 4], 0
// 005d520a  e851bce8ff           call 0x460e60
// 005d520f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d5213  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005d5217  83ec10               sub esp, 0x10
// 005d521a  8bd4                 mov edx, esp
// 005d521c  890a                 mov dword ptr [edx], ecx
// 005d521e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005d5222  894a04               mov dword ptr [edx + 4], ecx
// 005d5225  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005d5229  894a08               mov dword ptr [edx + 8], ecx
// 005d522c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005d5230  894a0c               mov dword ptr [edx + 0xc], ecx
// 005d5233  56                   push esi
// 005d5234  8bc8                 mov ecx, eax
// 005d5236  e8d5dfffff           call 0x5d3210
// 005d523b  8bc6                 mov eax, esi
// 005d523d  5e                   pop esi
// 005d523e  59                   pop ecx
// 005d523f  c21400               ret 0x14

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
