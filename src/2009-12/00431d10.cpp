// from server: 100% by nuck16
// roc 2009-12 00431d10  unit: RBX::$$A6AXABUStandardOutMessage::?$signal::slot  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00431d10
//
// 00431d10  51                   push ecx
// 00431d11  56                   push esi
// 00431d12  c744240400000000     mov dword ptr [esp + 4], 0
// 00431d1a  e851ffffff           call 0x431c70
// 00431d1f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00431d23  8b542410             mov edx, dword ptr [esp + 0x10]
// 00431d27  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00431d2b  51                   push ecx
// 00431d2c  52                   push edx
// 00431d2d  56                   push esi
// 00431d2e  8bc8                 mov ecx, eax
// 00431d30  e8fbfdffff           call 0x431b30
// 00431d35  8bc6                 mov eax, esi
// 00431d37  5e                   pop esi
// 00431d38  59                   pop ecx
// 00431d39  c20c00               ret 0xc

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
