// from server: 100% by EspClaude
// roc 2009-06 004278d0  unit: CPatchedControlComboBox  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004278d0
//
// 004278d0  6aff                 push -1
// 004278d2  68b82b8500           push 0x852bb8
// 004278d7  64a100000000         mov eax, dword ptr fs:[0]
// 004278dd  50                   push eax
// 004278de  64892500000000       mov dword ptr fs:[0], esp
// 004278e5  51                   push ecx
// 004278e6  56                   push esi
// 004278e7  8bf1                 mov esi, ecx
// 004278e9  89742404             mov dword ptr [esp + 4], esi
// 004278ed  e81e1b2f00           call 0x719410
// 004278f2  8d4e58               lea ecx, [esi + 0x58]
// 004278f5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004278fd  c7062c108b00         mov dword ptr [esi], 0x8b102c
// 00427903  e83877ffff           call 0x41f040
// 00427908  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0042790c  8bc6                 mov eax, esi
// 0042790e  5e                   pop esi
// 0042790f  64890d00000000       mov dword ptr fs:[0], ecx
// 00427916  83c410               add esp, 0x10
// 00427919  c3                   ret 
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
