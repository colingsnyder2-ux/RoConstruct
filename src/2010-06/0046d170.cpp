// from server: 100% by Yeetserama
// roc 2010-06 0046d170  unit: CPublishAsPlaceDialog  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0046d170
//
// 0046d170  6aff                 push -1
// 0046d172  68f8449800           push 0x9844f8
// 0046d177  64a100000000         mov eax, dword ptr fs:[0]
// 0046d17d  50                   push eax
// 0046d17e  64892500000000       mov dword ptr fs:[0], esp
// 0046d185  51                   push ecx
// 0046d186  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0046d18a  56                   push esi
// 0046d18b  8bf1                 mov esi, ecx
// 0046d18d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0046d191  50                   push eax
// 0046d192  51                   push ecx
// 0046d193  6a71                 push 0x71
// 0046d195  8bce                 mov ecx, esi
// 0046d197  89742410             mov dword ptr [esp + 0x10], esi
// 0046d19b  e8b087feff           call 0x455950
// 0046d1a0  8b542418             mov edx, dword ptr [esp + 0x18]
// 0046d1a4  52                   push edx
// 0046d1a5  8bce                 mov ecx, esi
// 0046d1a7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046d1af  c7064401a100         mov dword ptr [esi], 0xa10144
// 0046d1b5  c746741801a100       mov dword ptr [esi + 0x74], 0xa10118
// 0046d1bc  e8d1b53300           call 0x7a8792
// 0046d1c1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046d1c5  8bc6                 mov eax, esi
// 0046d1c7  5e                   pop esi
// 0046d1c8  64890d00000000       mov dword ptr fs:[0], ecx
// 0046d1cf  83c410               add esp, 0x10
// 0046d1d2  c20c00               ret 0xc
// copied from an identical function in another client (function ??0CPublishAsPlaceDialog@ns_ROCX000015@@QAE@HHH@Z)

namespace ns_ROCX000015 {
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
