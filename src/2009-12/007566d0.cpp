// from server: 100% by nuck16
// roc 2009-12 007566d0  unit: RBX::VehicleSeat  size: 80 bytes
//
// 007566d0  51                   push ecx
// 007566d1  56                   push esi
// 007566d2  c744240400000000     mov dword ptr [esp + 4], 0
// 007566da  e8c1b5d6ff           call 0x4c1ca0
// 007566df  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007566e3  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007566e7  83ec18               sub esp, 0x18
// 007566ea  8bd4                 mov edx, esp
// 007566ec  890a                 mov dword ptr [edx], ecx
// 007566ee  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007566f2  894a04               mov dword ptr [edx + 4], ecx
// 007566f5  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007566f9  894a08               mov dword ptr [edx + 8], ecx
// 007566fc  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00756700  894a0c               mov dword ptr [edx + 0xc], ecx
// 00756703  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00756707  894a10               mov dword ptr [edx + 0x10], ecx
// 0075670a  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0075670e  894a14               mov dword ptr [edx + 0x14], ecx
// 00756711  56                   push esi
// 00756712  8bc8                 mov ecx, eax
// 00756714  e827f4ffff           call 0x755b40
// 00756719  8bc6                 mov eax, esi
// 0075671b  5e                   pop esi
// 0075671c  59                   pop ecx
// 0075671d  c21c00               ret 0x1c

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
