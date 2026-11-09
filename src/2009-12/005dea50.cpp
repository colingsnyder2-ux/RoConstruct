// from server: 100% by nuck16
// roc 2009-12 005dea50  unit: RBX::ViewG3D  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dea50
//
// 005dea50  51                   push ecx
// 005dea51  56                   push esi
// 005dea52  c744240400000000     mov dword ptr [esp + 4], 0
// 005dea5a  e8b1dbe3ff           call 0x41c610
// 005dea5f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005dea63  8b542410             mov edx, dword ptr [esp + 0x10]
// 005dea67  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005dea6b  51                   push ecx
// 005dea6c  52                   push edx
// 005dea6d  56                   push esi
// 005dea6e  8bc8                 mov ecx, eax
// 005dea70  e8ebfaffff           call 0x5de560
// 005dea75  8bc6                 mov eax, esi
// 005dea77  5e                   pop esi
// 005dea78  59                   pop ecx
// 005dea79  c20c00               ret 0xc

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
