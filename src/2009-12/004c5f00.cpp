// from server: 100% by nuck16
// roc 2009-12 004c5f00  unit: Ogre::RbxCluster  size: 66 bytes
//
// 004c5f00  51                   push ecx
// 004c5f01  56                   push esi
// 004c5f02  c744240400000000     mov dword ptr [esp + 4], 0
// 004c5f0a  e891bdffff           call 0x4c1ca0
// 004c5f0f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c5f13  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c5f17  83ec10               sub esp, 0x10
// 004c5f1a  8bd4                 mov edx, esp
// 004c5f1c  890a                 mov dword ptr [edx], ecx
// 004c5f1e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c5f22  894a04               mov dword ptr [edx + 4], ecx
// 004c5f25  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c5f29  894a08               mov dword ptr [edx + 8], ecx
// 004c5f2c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004c5f30  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c5f33  56                   push esi
// 004c5f34  8bc8                 mov ecx, eax
// 004c5f36  e8c5f0ffff           call 0x4c5000
// 004c5f3b  8bc6                 mov eax, esi
// 004c5f3d  5e                   pop esi
// 004c5f3e  59                   pop ecx
// 004c5f3f  c21400               ret 0x14

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
