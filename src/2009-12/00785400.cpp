// from server: 100% by nuck16
// roc 2009-12 00785400  unit: RBX::VScriptMouseCommand::?$Named  size: 66 bytes
//
// 00785400  51                   push ecx
// 00785401  56                   push esi
// 00785402  c744240400000000     mov dword ptr [esp + 4], 0
// 0078540a  e891c8d3ff           call 0x4c1ca0
// 0078540f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00785413  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00785417  83ec10               sub esp, 0x10
// 0078541a  8bd4                 mov edx, esp
// 0078541c  890a                 mov dword ptr [edx], ecx
// 0078541e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00785422  894a04               mov dword ptr [edx + 4], ecx
// 00785425  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00785429  894a08               mov dword ptr [edx + 8], ecx
// 0078542c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00785430  894a0c               mov dword ptr [edx + 0xc], ecx
// 00785433  56                   push esi
// 00785434  8bc8                 mov ecx, eax
// 00785436  e865feffff           call 0x7852a0
// 0078543b  8bc6                 mov eax, esi
// 0078543d  5e                   pop esi
// 0078543e  59                   pop ecx
// 0078543f  c21400               ret 0x14

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
