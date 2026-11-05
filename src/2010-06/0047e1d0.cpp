// from server: 100% by Yeetserama
// roc 2010-06 0047e1d0  unit: RBX::VKeyframeSequence::?$FactoryProduct::Creator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047e1d0
//
// 0047e1d0  6aff                 push -1
// 0047e1d2  6888529800           push 0x985288
// 0047e1d7  64a100000000         mov eax, dword ptr fs:[0]
// 0047e1dd  50                   push eax
// 0047e1de  64892500000000       mov dword ptr fs:[0], esp
// 0047e1e5  51                   push ecx
// 0047e1e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047e1ea  56                   push esi
// 0047e1eb  8bf1                 mov esi, ecx
// 0047e1ed  50                   push eax
// 0047e1ee  89742408             mov dword ptr [esp + 8], esi
// 0047e1f2  e869391700           call 0x5f1b60
// 0047e1f7  8d4c241c             lea ecx, [esp + 0x1c]
// 0047e1fb  51                   push ecx
// 0047e1fc  8d542420             lea edx, [esp + 0x20]
// 0047e200  52                   push edx
// 0047e201  8d4e28               lea ecx, [esi + 0x28]
// 0047e204  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0047e20c  c706682da100         mov dword ptr [esi], 0xa12d68
// 0047e212  e8f9a64400           call 0x8c8910
// 0047e217  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047e21b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047e21f  894648               mov dword ptr [esi + 0x48], eax
// 0047e222  8bc6                 mov eax, esi
// 0047e224  5e                   pop esi
// 0047e225  64890d00000000       mov dword ptr fs:[0], ecx
// 0047e22c  83c410               add esp, 0x10
// 0047e22f  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX00000c@@QAE@HH@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
struct Base
{
    Base(int value);
    virtual ~Base();
    char data[36];
};

struct Member
{
    Member(const int* first, const int* last);
    ~Member();
    char data[32];
};

struct S : Base
{
    Member member;
    int value;

    S(int value, int initial);
    virtual ~S();
};

S::S(int value, int initial)
    : Base(initial), member(&value + 1, &initial), value(value)
{
}
}
