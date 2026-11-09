// from server: 100% by nuck16
// roc 2009-12 005dea20  unit: RBX::ViewG3D  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dea20
//
// 005dea20  51                   push ecx
// 005dea21  56                   push esi
// 005dea22  c744240400000000     mov dword ptr [esp + 4], 0
// 005dea2a  e83124e8ff           call 0x460e60
// 005dea2f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dea33  8b542410             mov edx, dword ptr [esp + 0x10]
// 005dea37  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005dea3b  51                   push ecx
// 005dea3c  52                   push edx
// 005dea3d  56                   push esi
// 005dea3e  8bc8                 mov ecx, eax
// 005dea40  e8dbf9ffff           call 0x5de420
// 005dea45  8bc6                 mov eax, esi
// 005dea47  5e                   pop esi
// 005dea48  59                   pop ecx
// 005dea49  c20c00               ret 0xc

struct Ret
{
    Ret(const Ret &);
    ~Ret();
    void *p;
};

struct Impl
{
    Ret g(void *a0, void *a1);
};

struct Getter { static Impl *get(); };

struct S
{
    Ret f(void *a0, void *a1);
};

Ret S::f(void *a0, void *a1)
{
    Impl *impl = Getter::get();
    return impl->g(a0, a1);
}
