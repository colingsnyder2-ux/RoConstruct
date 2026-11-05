// from server: 100% by Yeetserama
// roc 2007-08 0042ec90  unit: CPatchedControlComboBox  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ec90
//
// 0042ec90  6aff                 push -1
// 0042ec92  68f8257400           push 0x7425f8
// 0042ec97  64a100000000         mov eax, dword ptr fs:[0]
// 0042ec9d  50                   push eax
// 0042ec9e  51                   push ecx
// 0042ec9f  56                   push esi
// 0042eca0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042eca5  33c4                 xor eax, esp
// 0042eca7  50                   push eax
// 0042eca8  8d44240c             lea eax, [esp + 0xc]
// 0042ecac  64a300000000         mov dword ptr fs:[0], eax
// 0042ecb2  8bf1                 mov esi, ecx
// 0042ecb4  89742408             mov dword ptr [esp + 8], esi
// 0042ecb8  e84b182000           call 0x630508
// 0042ecbd  8d4e58               lea ecx, [esi + 0x58]
// 0042ecc0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042ecc8  c706a4a97800         mov dword ptr [esi], 0x78a9a4
// 0042ecce  e8dd47ffff           call 0x4234b0
// 0042ecd3  8bc6                 mov eax, esi
// 0042ecd5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042ecd9  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ece0  59                   pop ecx
// 0042ece1  5e                   pop esi
// 0042ece2  83c410               add esp, 0x10
// 0042ece5  c3                   ret 
// copied from an identical function in another client (function ??0CPatchedControlComboBox@ns_ROCX00001d@@QAE@XZ)

namespace ns_ROCX00001d {
// from server: 100% by king_originala
struct Base
{
    char padding[84];

    Base();
    virtual ~Base();
};

struct Member
{
    Member();
    ~Member();
};

struct CPatchedControlComboBox : Base
{
    Member member;

    CPatchedControlComboBox();
    virtual ~CPatchedControlComboBox();
};

CPatchedControlComboBox::CPatchedControlComboBox()
    : Base(), member()
{
}
}
