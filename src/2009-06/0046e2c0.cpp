// from server: 100% by EspClaude
// roc 2009-06 0046e2c0  unit: VCContent::?$CComObject  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046e2c0
//
// 0046e2c0  6aff                 push -1
// 0046e2c2  68a8368500           push 0x8536a8
// 0046e2c7  64a100000000         mov eax, dword ptr fs:[0]
// 0046e2cd  50                   push eax
// 0046e2ce  64892500000000       mov dword ptr fs:[0], esp
// 0046e2d5  51                   push ecx
// 0046e2d6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046e2da  56                   push esi
// 0046e2db  8bf1                 mov esi, ecx
// 0046e2dd  50                   push eax
// 0046e2de  89742408             mov dword ptr [esp + 8], esi
// 0046e2e2  e8291b1b00           call 0x61fe10
// 0046e2e7  8d4c241c             lea ecx, [esp + 0x1c]
// 0046e2eb  51                   push ecx
// 0046e2ec  8d542420             lea edx, [esp + 0x20]
// 0046e2f0  52                   push edx
// 0046e2f1  8d4e28               lea ecx, [esi + 0x28]
// 0046e2f4  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046e2fc  c70644d58b00         mov dword ptr [esi], 0x8bd544
// 0046e302  e859032900           call 0x6fe660
// 0046e307  8b442418             mov eax, dword ptr [esp + 0x18]
// 0046e30b  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046e30f  894648               mov dword ptr [esi + 0x48], eax
// 0046e312  8bc6                 mov eax, esi
// 0046e314  5e                   pop esi
// 0046e315  64890d00000000       mov dword ptr fs:[0], ecx
// 0046e31c  83c410               add esp, 0x10
// 0046e31f  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000036@@QAE@HH@Z)

namespace ns_ROCX000036 {
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
