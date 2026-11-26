// from server: 100% by Xemicl
// roc 2012-06 004354f0  unit: CPatchedControlComboBox  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004354f0
//
// 004354f0  6aff                 push -1
// 004354f2  6838d0a900           push 0xa9d038
// 004354f7  64a100000000         mov eax, dword ptr fs:[0]
// 004354fd  50                   push eax
// 004354fe  64892500000000       mov dword ptr fs:[0], esp
// 00435505  51                   push ecx
// 00435506  56                   push esi
// 00435507  8bf1                 mov esi, ecx
// 00435509  89742404             mov dword ptr [esp + 4], esi
// 0043550d  e8b0d55400           call 0x982ac2
// 00435512  8d4e58               lea ecx, [esi + 0x58]
// 00435515  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043551d  c70664fab400         mov dword ptr [esi], 0xb4fa64
// 00435523  e8b87affff           call 0x42cfe0
// 00435528  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043552c  8bc6                 mov eax, esi
// 0043552e  5e                   pop esi
// 0043552f  64890d00000000       mov dword ptr fs:[0], ecx
// 00435536  83c410               add esp, 0x10
// 00435539  c3                   ret 
// copied from an identical function in another client (function ??0CPatchedControlComboBox@ns_ROCX0000e5@@QAE@XZ)

namespace ns_ROCX0000e5 {
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