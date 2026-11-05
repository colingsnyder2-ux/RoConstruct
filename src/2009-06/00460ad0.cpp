// from server: 100% by EspClaude
// roc 2009-06 00460ad0  unit: CPublishAsPlaceDialog  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00460ad0
//
// 00460ad0  6aff                 push -1
// 00460ad2  68482b8500           push 0x852b48
// 00460ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00460add  50                   push eax
// 00460ade  64892500000000       mov dword ptr fs:[0], esp
// 00460ae5  51                   push ecx
// 00460ae6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00460aea  56                   push esi
// 00460aeb  8bf1                 mov esi, ecx
// 00460aed  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00460af1  50                   push eax
// 00460af2  51                   push ecx
// 00460af3  6a71                 push 0x71
// 00460af5  8bce                 mov ecx, esi
// 00460af7  89742410             mov dword ptr [esp + 0x10], esi
// 00460afb  e810c5feff           call 0x44d010
// 00460b00  8b542418             mov edx, dword ptr [esp + 0x18]
// 00460b04  52                   push edx
// 00460b05  8bce                 mov ecx, esi
// 00460b07  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00460b0f  c70624af8b00         mov dword ptr [esi], 0x8baf24
// 00460b15  c74674f8ae8b00       mov dword ptr [esi + 0x74], 0x8baef8
// 00460b1c  e8fd8c2b00           call 0x71981e
// 00460b21  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00460b25  8bc6                 mov eax, esi
// 00460b27  5e                   pop esi
// 00460b28  64890d00000000       mov dword ptr fs:[0], ecx
// 00460b2f  83c410               add esp, 0x10
// 00460b32  c20c00               ret 0xc
// copied from an identical function in another client (function ??0CPublishAsPlaceDialog@ns_ROCX00005b@@QAE@HHH@Z)

namespace ns_ROCX00005b {
struct Primary
{
    virtual void primary();
    char padding[112];
};

struct Secondary
{
    virtual void secondary();
};

struct Base : Primary, Secondary
{
    Base(int, int, int);
    ~Base();
    void initialize(int);
};

struct CPublishAsPlaceDialog : Base
{
    CPublishAsPlaceDialog(int, int, int);
    virtual void primary();
    virtual void secondary();
};

CPublishAsPlaceDialog::CPublishAsPlaceDialog(int a, int b, int c)
    : Base(0x71, b, c)
{
    initialize(a);
}
}
