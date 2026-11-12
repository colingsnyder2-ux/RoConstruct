// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 00426890  unit: RBX::Reflection::Metadata::VEvents::?$FactoryProduct  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426890
// 00426890  6aff                 push -1
// 00426892  6808b07300           push 0x73b008
// 00426897  64a100000000         mov eax, dword ptr fs:[0]
// 0042689d  50                   push eax
// 0042689e  51                   push ecx
// 0042689f  56                   push esi
// 004268a0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004268a5  33c4                 xor eax, esp
// 004268a7  50                   push eax
// 004268a8  8d44240c             lea eax, [esp + 0xc]
// 004268ac  64a300000000         mov dword ptr fs:[0], eax
// 004268b2  8bf1                 mov esi, ecx
// 004268b4  89742408             mov dword ptr [esp + 8], esi
// 004268b8  e863fdffff           call 0x426620
// 004268bd  33c0                 xor eax, eax
// 004268bf  8d8eec000000         lea ecx, [esi + 0xec]
// 004268c5  89442414             mov dword ptr [esp + 0x14], eax
// 004268c9  c7060c9a7800         mov dword ptr [esi], 0x789a0c
// 004268cf  c74604049a7800       mov dword ptr [esi + 4], 0x789a04
// 004268d6  c74610fc997800       mov dword ptr [esi + 0x10], 0x7899fc
// 004268dd  c74614ec997800       mov dword ptr [esi + 0x14], 0x7899ec
// 004268e4  c7462cdc997800       mov dword ptr [esi + 0x2c], 0x7899dc
// 004268eb  c74644cc997800       mov dword ptr [esi + 0x44], 0x7899cc
// 004268f2  c7465cbc997800       mov dword ptr [esi + 0x5c], 0x7899bc
// 004268f9  c74674ac997800       mov dword ptr [esi + 0x74], 0x7899ac
// 00426900  c7868c0000009c997800 mov dword ptr [esi + 0x8c], 0x78999c
// 0042690a  c686e800000001       mov byte ptr [esi + 0xe8], 1
// 00426911  8886e9000000         mov byte ptr [esi + 0xe9], al
// 00426917  8886ea000000         mov byte ptr [esi + 0xea], al
// 0042691d  ff15a4e67700         call dword ptr [0x77e6a4]
// 00426923  8bc6                 mov eax, esi
// 00426925  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00426929  64890d00000000       mov dword ptr fs:[0], ecx
// 00426930  59                   pop ecx
// 00426931  5e                   pop esi
// 00426932  83c410               add esp, 0x10
// 00426935  c3                   ret 
#include <string>

namespace RBX {
namespace Reflection {

// polymorphic subobjects at the offsets whose vfptrs the target stores:
// 0, 4, 0x10, 0x14, 0x2c, 0x44, 0x5c, 0x74, 0x8c; base size 0xe8 (first member at 0xe8)
struct S0 { virtual ~S0(); };
struct S1 { virtual ~S1(); int pad[2]; };
struct S2 { virtual ~S2(); };
struct S3 { virtual ~S3(); int pad[5]; };
struct S4 { virtual ~S4(); int pad[5]; };
struct S5 { virtual ~S5(); int pad[5]; };
struct S6 { virtual ~S6(); int pad[5]; };
struct S7 { virtual ~S7(); int pad[5]; };
struct S8 { virtual ~S8(); int pad[0x16]; };

class Base : public S0, public S1, public S2, public S3, public S4, public S5, public S6, public S7, public S8
{
public:
    Base();
};

class FactoryProduct : public Base
{
    bool flag0;
    bool flag1;
    bool flag2;
    std::string text;
public:
    FactoryProduct();
};

FactoryProduct::FactoryProduct()
    : flag0(true), flag1(false), flag2(false)
{
}

}
}
