// from server: 100% by Yeetserama
// roc 2007-08 00462780  unit: CSelectionCaption  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00462780
//
// 00462780  6aff                 push -1
// 00462782  68682c7400           push 0x742c68
// 00462787  64a100000000         mov eax, dword ptr fs:[0]
// 0046278d  50                   push eax
// 0046278e  a188518b00           mov eax, dword ptr [0x8b5188]
// 00462793  33c4                 xor eax, esp
// 00462795  50                   push eax
// 00462796  8d442404             lea eax, [esp + 4]
// 0046279a  64a300000000         mov dword ptr fs:[0], eax
// 004627a0  81c16cfeffff         add ecx, 0xfffffe6c
// 004627a6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004627ae  e86df6ffff           call 0x461e20
// 004627b3  8d4c2418             lea ecx, [esp + 0x18]
// 004627b7  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 004627bf  e83cb2fbff           call 0x41da00
// 004627c4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004627c8  64890d00000000       mov dword ptr fs:[0], ecx
// 004627cf  59                   pop ecx
// 004627d0  83c40c               add esp, 0xc
// 004627d3  c21400               ret 0x14
// copied from an identical function in another client (function ?f@CSelectionCaption@ns_ROCX000000@@QAEXHUArgument@2@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
struct Argument
{
    unsigned char storage[16];
    ~Argument();
};

struct Owner
{
    void g();
};

struct CSelectionCaption
{
    void f(int, Argument);
};

void CSelectionCaption::f(int, Argument)
{
    reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 0x194)->g();
}
}
