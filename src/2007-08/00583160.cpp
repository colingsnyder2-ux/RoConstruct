// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 00583160  unit: RBX::VAccoutrement::?$FactoryProduct  size: 216 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00583160
//
// 00583160  6aff                 push -1
// 00583162  68b85d7500           push 0x755db8
// 00583167  64a100000000         mov eax, dword ptr fs:[0]
// 0058316d  50                   push eax
// 0058316e  64892500000000       mov dword ptr fs:[0], esp
// 00583175  51                   push ecx
// 00583176  837c241400           cmp dword ptr [esp + 0x14], 0
// 0058317b  56                   push esi
// 0058317c  8bf1                 mov esi, ecx
// 0058317e  89742404             mov dword ptr [esp + 4], esi
// 00583182  7414                 je 0x583198
// 00583184  c786f8000000c0c57a00 mov dword ptr [esi + 0xf8], 0x7ac5c0
// 0058318e  c7867c010000cc4c7a00 mov dword ptr [esi + 0x17c], 0x7a4ccc
// 00583198  6a00                 push 0
// 0058319a  e821ffffff           call 0x5830c0
// 0058319f  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 005831a5  c7067cc57a00         mov dword ptr [esi], 0x7ac57c
// 005831ab  c7460474c57a00       mov dword ptr [esi + 4], 0x7ac574
// 005831b2  c746106cc57a00       mov dword ptr [esi + 0x10], 0x7ac56c
// 005831b9  c746145cc57a00       mov dword ptr [esi + 0x14], 0x7ac55c
// 005831c0  c7462c4cc57a00       mov dword ptr [esi + 0x2c], 0x7ac54c
// 005831c7  c746443cc57a00       mov dword ptr [esi + 0x44], 0x7ac53c
// 005831ce  c7465c2cc57a00       mov dword ptr [esi + 0x5c], 0x7ac52c
// 005831d5  c746741cc57a00       mov dword ptr [esi + 0x74], 0x7ac51c
// 005831dc  c7868c0000000cc57a00 mov dword ptr [esi + 0x8c], 0x7ac50c
// 005831e6  c786e8000000f4c47a00 mov dword ptr [esi + 0xe8], 0x7ac4f4
// 005831f0  8b4804               mov ecx, dword ptr [eax + 4]
// 005831f3  c78431f8000000ecc47a00 mov dword ptr [ecx + esi + 0xf8], 0x7ac4ec
// 005831fe  8b96f8000000         mov edx, dword ptr [esi + 0xf8]
// 00583204  8b4204               mov eax, dword ptr [edx + 4]
// 00583207  8d887cffffff         lea ecx, [eax - 0x84]
// 0058320d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00583215  898c30f4000000       mov dword ptr [eax + esi + 0xf4], ecx
// 0058321c  e8dff1ffff           call 0x582400
// 00583221  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00583225  89460c               mov dword ptr [esi + 0xc], eax
// 00583228  8bc6                 mov eax, esi
// 0058322a  5e                   pop esi
// 0058322b  64890d00000000       mov dword ptr fs:[0], ecx
// 00583232  83c410               add esp, 0x10
// 00583235  c20400               ret 4

// Layout read from the target: vfptrs at 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c,0xe8;
// vbptr at 0xf8; virtual base (vfptr only, inline ctor) at 0xf8+0x84=0x17c with vtordisp
// at 0x178; Base ctor 0x5830c0 takes the hidden most-derived flag; +0xc receives the
// static class descriptor (call 0x582400, cdecl, no args) after the base is constructed.
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {

class Descriptor;

struct V  { virtual void v0(); };
struct B1 { virtual void b1(); };
struct B2 { virtual void b2(); int f8; const Descriptor* descriptor; };
struct B3 { virtual void b3(); };
struct B4 { virtual void b4(); int d[5]; };
struct B5 { virtual void b5(); int d[5]; };
struct B6 { virtual void b6(); int d[5]; };
struct B7 { virtual void b7(); int d[5]; };
struct B8 { virtual void b8(); int d[5]; };
struct B9 { virtual void b9(); int d[0x16]; };
struct B10 { virtual void b10(); int d[3]; };

class Accoutrement : public B1, public B2, public B3, public B4, public B5,
                     public B6, public B7, public B8, public B9, public B10,
                     public virtual V
{
    int members[0x1f];
public:
    Accoutrement();
    ~Accoutrement();
    virtual void v0();
};

template<class Class, class Base>
class FactoryProduct : public Base
{
public:
    static const Descriptor& classDescriptor();
    FactoryProduct()
    {
        this->descriptor = &classDescriptor();
    }
};

class Hat;
template class FactoryProduct<Hat, Accoutrement>;

}
