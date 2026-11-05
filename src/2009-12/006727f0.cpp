// from server: 100% by nuck16
// roc 2009-12 006727f0  unit: RBX::DataModel  size: 66 bytes
//
// 006727f0  51                   push ecx
// 006727f1  56                   push esi
// 006727f2  c744240400000000     mov dword ptr [esp + 4], 0
// 006727fa  e891f8ffff           call 0x672090
// 006727ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00672803  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00672807  83ec10               sub esp, 0x10
// 0067280a  8bd4                 mov edx, esp
// 0067280c  890a                 mov dword ptr [edx], ecx
// 0067280e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00672812  894a04               mov dword ptr [edx + 4], ecx
// 00672815  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00672819  894a08               mov dword ptr [edx + 8], ecx
// 0067281c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00672820  894a0c               mov dword ptr [edx + 0xc], ecx
// 00672823  56                   push esi
// 00672824  8bc8                 mov ecx, eax
// 00672826  e84599ffff           call 0x66c170
// 0067282b  8bc6                 mov eax, esi
// 0067282d  5e                   pop esi
// 0067282e  59                   pop ecx
// 0067282f  c21400               ret 0x14

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
