// from server: 100% by nuck16
// roc 2009-12 004c5f50  unit: Ogre::RbxCluster  size: 66 bytes
//
// 004c5f50  51                   push ecx
// 004c5f51  56                   push esi
// 004c5f52  c744240400000000     mov dword ptr [esp + 4], 0
// 004c5f5a  e801aff9ff           call 0x460e60
// 004c5f5f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004c5f63  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004c5f67  83ec10               sub esp, 0x10
// 004c5f6a  8bd4                 mov edx, esp
// 004c5f6c  890a                 mov dword ptr [edx], ecx
// 004c5f6e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004c5f72  894a04               mov dword ptr [edx + 4], ecx
// 004c5f75  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004c5f79  894a08               mov dword ptr [edx + 8], ecx
// 004c5f7c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004c5f80  894a0c               mov dword ptr [edx + 0xc], ecx
// 004c5f83  56                   push esi
// 004c5f84  8bc8                 mov ecx, eax
// 004c5f86  e8d5f1ffff           call 0x4c5160
// 004c5f8b  8bc6                 mov eax, esi
// 004c5f8d  5e                   pop esi
// 004c5f8e  59                   pop ecx
// 004c5f8f  c21400               ret 0x14

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
