// from server: 100% by nuck16
// roc 2009-12 00576ac0  unit: RBX::ViewRbxGfx  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00576ac0
//
// 00576ac0  51                   push ecx
// 00576ac1  56                   push esi
// 00576ac2  c744240400000000     mov dword ptr [esp + 4], 0
// 00576aca  e891a3eeff           call 0x460e60
// 00576acf  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00576ad3  8b542410             mov edx, dword ptr [esp + 0x10]
// 00576ad7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00576adb  51                   push ecx
// 00576adc  52                   push edx
// 00576add  56                   push esi
// 00576ade  8bc8                 mov ecx, eax
// 00576ae0  e83befffff           call 0x575a20
// 00576ae5  8bc6                 mov eax, esi
// 00576ae7  5e                   pop esi
// 00576ae8  59                   pop ecx
// 00576ae9  c20c00               ret 0xc

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
