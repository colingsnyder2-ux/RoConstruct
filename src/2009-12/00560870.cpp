// from server: 100% by nuck16
// roc 2009-12 00560870  unit: RBX::Network::ErrorCompPhysicsSender  size: 66 bytes
//
// 00560870  51                   push ecx
// 00560871  56                   push esi
// 00560872  c744240400000000     mov dword ptr [esp + 4], 0
// 0056087a  e891bdebff           call 0x41c610
// 0056087f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00560883  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00560887  83ec10               sub esp, 0x10
// 0056088a  8bd4                 mov edx, esp
// 0056088c  890a                 mov dword ptr [edx], ecx
// 0056088e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00560892  894a04               mov dword ptr [edx + 4], ecx
// 00560895  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00560899  894a08               mov dword ptr [edx + 8], ecx
// 0056089c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005608a0  894a0c               mov dword ptr [edx + 0xc], ecx
// 005608a3  56                   push esi
// 005608a4  8bc8                 mov ecx, eax
// 005608a6  e825f6ffff           call 0x55fed0
// 005608ab  8bc6                 mov eax, esi
// 005608ad  5e                   pop esi
// 005608ae  59                   pop ecx
// 005608af  c21400               ret 0x14

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
