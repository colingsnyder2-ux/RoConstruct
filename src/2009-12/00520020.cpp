// from server: 100% by nuck16
// roc 2009-12 00520020  unit: RBX::Network::Players  size: 80 bytes
//
// 00520020  51                   push ecx
// 00520021  56                   push esi
// 00520022  c744240400000000     mov dword ptr [esp + 4], 0
// 0052002a  e8d1d7feff           call 0x50d800
// 0052002f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00520033  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00520037  83ec18               sub esp, 0x18
// 0052003a  8bd4                 mov edx, esp
// 0052003c  890a                 mov dword ptr [edx], ecx
// 0052003e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00520042  894a04               mov dword ptr [edx + 4], ecx
// 00520045  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00520049  894a08               mov dword ptr [edx + 8], ecx
// 0052004c  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00520050  894a0c               mov dword ptr [edx + 0xc], ecx
// 00520053  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00520057  894a10               mov dword ptr [edx + 0x10], ecx
// 0052005a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0052005e  894a14               mov dword ptr [edx + 0x14], ecx
// 00520061  56                   push esi
// 00520062  8bc8                 mov ecx, eax
// 00520064  e8a7c7ffff           call 0x51c810
// 00520069  8bc6                 mov eax, esi
// 0052006b  5e                   pop esi
// 0052006c  59                   pop ecx
// 0052006d  c21c00               ret 0x1c

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Arg
{
    int f0, f1, f2, f3, f4, f5;
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
