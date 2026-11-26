// from server: 100% by Xemicl
// roc 2012-06 0049c6d0  unit: CPublishAsPlaceDialog  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049c6d0
//
// 0049c6d0  6aff                 push -1
// 0049c6d2  68489fa900           push 0xa99f48
// 0049c6d7  64a100000000         mov eax, dword ptr fs:[0]
// 0049c6dd  50                   push eax
// 0049c6de  64892500000000       mov dword ptr fs:[0], esp
// 0049c6e5  51                   push ecx
// 0049c6e6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049c6ea  56                   push esi
// 0049c6eb  8bf1                 mov esi, ecx
// 0049c6ed  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049c6f1  50                   push eax
// 0049c6f2  51                   push ecx
// 0049c6f3  6a71                 push 0x71
// 0049c6f5  8bce                 mov ecx, esi
// 0049c6f7  89742410             mov dword ptr [esp + 0x10], esi
// 0049c6fb  e820d5fdff           call 0x479c20
// 0049c700  8b542418             mov edx, dword ptr [esp + 0x18]
// 0049c704  52                   push edx
// 0049c705  8bce                 mov ecx, esi
// 0049c707  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0049c70f  c70674fab500         mov dword ptr [esi], 0xb5fa74
// 0049c715  c7467448fab500       mov dword ptr [esi + 0x74], 0xb5fa48
// 0049c71c  e8cd674e00           call 0x982eee
// 0049c721  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0049c725  8bc6                 mov eax, esi
// 0049c727  5e                   pop esi
// 0049c728  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c72f  83c410               add esp, 0x10
// 0049c732  c20c00               ret 0xc
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