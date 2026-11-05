// from server: 100% by nuck16
// roc 2009-12 006fa990  unit: RBX::Network::VPlayer::?$RemoteEventDesc  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006fa990
//
// 006fa990  51                   push ecx
// 006fa991  56                   push esi
// 006fa992  c744240400000000     mov dword ptr [esp + 4], 0
// 006fa99a  e8612ee1ff           call 0x50d800
// 006fa99f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006fa9a3  8b542410             mov edx, dword ptr [esp + 0x10]
// 006fa9a7  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa9ab  51                   push ecx
// 006fa9ac  52                   push edx
// 006fa9ad  56                   push esi
// 006fa9ae  8bc8                 mov ecx, eax
// 006fa9b0  e8dbe2ffff           call 0x6f8c90
// 006fa9b5  8bc6                 mov eax, esi
// 006fa9b7  5e                   pop esi
// 006fa9b8  59                   pop ecx
// 006fa9b9  c20c00               ret 0xc

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
