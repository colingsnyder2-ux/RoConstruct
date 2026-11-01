// from server: 100% by Yeetserama
// roc 2007-08 00466d80  unit: VCWorkspace::?$CComObject  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00466d80
//
// 00466d80  6aff                 push -1
// 00466d82  68682c7400           push 0x742c68
// 00466d87  64a100000000         mov eax, dword ptr fs:[0]
// 00466d8d  50                   push eax
// 00466d8e  a188518b00           mov eax, dword ptr [0x8b5188]
// 00466d93  33c4                 xor eax, esp
// 00466d95  50                   push eax
// 00466d96  8d442404             lea eax, [esp + 4]
// 00466d9a  64a300000000         mov dword ptr fs:[0], eax
// 00466da0  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 00466da3  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00466dab  e8506d0c00           call 0x52db00
// 00466db0  8d4c2418             lea ecx, [esp + 0x18]
// 00466db4  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00466dbc  e83f6cfbff           call 0x41da00
// 00466dc1  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00466dc5  64890d00000000       mov dword ptr fs:[0], ecx
// 00466dcc  59                   pop ecx
// 00466dcd  83c40c               add esp, 0xc
// 00466dd0  c21400               ret 0x14
// copied from an identical function in another client (function ?fn_ROCX000013_0046ab10@S@ns_ROCX000013@@QAEXHUValue@2@@Z)

namespace ns_ROCX000013 {
// from server: 100% by king_originala
struct Value
{
    unsigned char data[16];
    ~Value();
};

struct Target
{
    void fn_ROCX000013_00555350();
};

struct S
{
    unsigned char padding[20];
    Target* target;
    void fn_ROCX000013_0046ab10(int, Value);
};

void S::fn_ROCX000013_0046ab10(int, Value)
{
    target->fn_ROCX000013_00555350();
}
}
