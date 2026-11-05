// from server: 100% by Yeetserama
// roc 2007-08 0045bc90  unit: CPublishAsPlaceDialog  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045bc90
//
// 0045bc90  6aff                 push -1
// 0045bc92  68c88e7300           push 0x738ec8
// 0045bc97  64a100000000         mov eax, dword ptr fs:[0]
// 0045bc9d  50                   push eax
// 0045bc9e  51                   push ecx
// 0045bc9f  56                   push esi
// 0045bca0  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045bca5  33c4                 xor eax, esp
// 0045bca7  50                   push eax
// 0045bca8  8d44240c             lea eax, [esp + 0xc]
// 0045bcac  64a300000000         mov dword ptr fs:[0], eax
// 0045bcb2  8bf1                 mov esi, ecx
// 0045bcb4  89742408             mov dword ptr [esp + 8], esi
// 0045bcb8  8b442424             mov eax, dword ptr [esp + 0x24]
// 0045bcbc  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0045bcc0  50                   push eax
// 0045bcc1  51                   push ecx
// 0045bcc2  6a71                 push 0x71
// 0045bcc4  8bce                 mov ecx, esi
// 0045bcc6  e8450fffff           call 0x44cc10
// 0045bccb  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0045bccf  52                   push edx
// 0045bcd0  8bce                 mov ecx, esi
// 0045bcd2  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045bcda  c706443e7900         mov dword ptr [esi], 0x793e44
// 0045bce0  c74674183e7900       mov dword ptr [esi + 0x74], 0x793e18
// 0045bce7  e8004c1d00           call 0x6308ec
// 0045bcec  8bc6                 mov eax, esi
// 0045bcee  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045bcf2  64890d00000000       mov dword ptr fs:[0], ecx
// 0045bcf9  59                   pop ecx
// 0045bcfa  5e                   pop esi
// 0045bcfb  83c410               add esp, 0x10
// 0045bcfe  c20c00               ret 0xc
// copied from an identical function in another client (function ??0CPublishAsPlaceDialog@ns_ROCX000000@@QAE@HHH@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
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
