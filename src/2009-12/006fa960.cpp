// from server: 100% by nuck16
// roc 2009-12 006fa960  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa960
//
// 006fa960  51                   push ecx
// 006fa961  56                   push esi
// 006fa962  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa96a  e83173dcff           call 0x4c1ca0
// 006fa96f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006fa973  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fa977  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa97b  51                   push ecx
// 006fa97c  52                   push edx
// 006fa97d  56                   push esi
// 006fa97e  8bc8                 mov ecx, eax
// 006fa980  e8cbe1ffff           call 0x6f8b50
// 006fa985  8bc6                 mov eax, esi
// 006fa987  5e                   pop esi
// 006fa988  59                   pop ecx
// 006fa989  c20c00               ret 0xc

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
