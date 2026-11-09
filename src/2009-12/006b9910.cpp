// from server: 100% by nuck16
// roc 2009-12 006b9910  unit: RBX::VStockSound::?$FactoryProduct::Creator  size: 66 bytes
//
// 006b9910  51                   push ecx
// 006b9911  56                   push esi
// 006b9912  c744240400000000     mov dword ptr [esp + 4], 0
// 006b991a  e8611ffeff           call 0x69b880
// 006b991f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006b9923  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006b9927  83ec10               sub esp, 0x10
// 006b992a  8bd4                 mov edx, esp
// 006b992c  890a                 mov dword ptr [edx], ecx
// 006b992e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006b9932  894a04               mov dword ptr [edx + 4], ecx
// 006b9935  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006b9939  894a08               mov dword ptr [edx + 8], ecx
// 006b993c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006b9940  894a0c               mov dword ptr [edx + 0xc], ecx
// 006b9943  56                   push esi
// 006b9944  8bc8                 mov ecx, eax
// 006b9946  e8a5dbffff           call 0x6b74f0
// 006b994b  8bc6                 mov eax, esi
// 006b994d  5e                   pop esi
// 006b994e  59                   pop ecx
// 006b994f  c21400               ret 0x14

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
