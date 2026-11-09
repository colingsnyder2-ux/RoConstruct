// from server: 100% by nuck16
// roc 2009-12 006fa890  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa890
//
// 006fa890  51                   push ecx
// 006fa891  56                   push esi
// 006fa892  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa89a  e8c165d6ff           call 0x460e60
// 006fa89f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006fa8a3  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fa8a7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa8ab  51                   push ecx
// 006fa8ac  52                   push edx
// 006fa8ad  56                   push esi
// 006fa8ae  8bc8                 mov ecx, eax
// 006fa8b0  e89bdeffff           call 0x6f8750
// 006fa8b5  8bc6                 mov eax, esi
// 006fa8b7  5e                   pop esi
// 006fa8b8  59                   pop ecx
// 006fa8b9  c20c00               ret 0xc

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
