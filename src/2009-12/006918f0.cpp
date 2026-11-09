// from server: 100% by nuck16
// roc 2009-12 006918f0  unit: RBX::LegacyHopperService  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006918f0
//
// 006918f0  51                   push ecx
// 006918f1  56                   push esi
// 006918f2  c744240400000000     mov dword ptr [esp + 4], 0
// 006918fa  e8a103e3ff           call 0x4c1ca0
// 006918ff  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00691903  8b542410             mov edx, dword ptr [esp + 0x10]
// 00691907  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0069190b  51                   push ecx
// 0069190c  52                   push edx
// 0069190d  56                   push esi
// 0069190e  8bc8                 mov ecx, eax
// 00691910  e88bebffff           call 0x6904a0
// 00691915  8bc6                 mov eax, esi
// 00691917  5e                   pop esi
// 00691918  59                   pop ecx
// 00691919  c20c00               ret 0xc

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
