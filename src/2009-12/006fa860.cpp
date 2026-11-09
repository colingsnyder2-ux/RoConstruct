// from server: 100% by nuck16
// roc 2009-12 006fa860  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa860
//
// 006fa860  51                   push ecx
// 006fa861  56                   push esi
// 006fa862  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa86a  e8f165d6ff           call 0x460e60
// 006fa86f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006fa873  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fa877  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa87b  51                   push ecx
// 006fa87c  52                   push edx
// 006fa87d  56                   push esi
// 006fa87e  8bc8                 mov ecx, eax
// 006fa880  e88bddffff           call 0x6f8610
// 006fa885  8bc6                 mov eax, esi
// 006fa887  5e                   pop esi
// 006fa888  59                   pop ecx
// 006fa889  c20c00               ret 0xc

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
