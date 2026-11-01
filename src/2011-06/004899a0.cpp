// from server: 100% by Yeetserama
// roc 2011-06 004899a0  unit: CPublishAsPlaceDialog  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004899a0
//
// 004899a0  6aff                 push -1
// 004899a2  68e85d9d00           push 0x9d5de8
// 004899a7  64a100000000         mov eax, dword ptr fs:[0]
// 004899ad  50                   push eax
// 004899ae  64892500000000       mov dword ptr fs:[0], esp
// 004899b5  51                   push ecx
// 004899b6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004899ba  56                   push esi
// 004899bb  8bf1                 mov esi, ecx
// 004899bd  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004899c1  50                   push eax
// 004899c2  51                   push ecx
// 004899c3  6a71                 push 0x71
// 004899c5  8bce                 mov ecx, esi
// 004899c7  89742410             mov dword ptr [esp + 0x10], esi
// 004899cb  e82053feff           call 0x46ecf0
// 004899d0  8b542418             mov edx, dword ptr [esp + 0x18]
// 004899d4  52                   push edx
// 004899d5  8bce                 mov ecx, esi
// 004899d7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004899df  c706cc34a700         mov dword ptr [esi], 0xa734cc
// 004899e5  c74674a034a700       mov dword ptr [esi + 0x74], 0xa734a0
// 004899ec  e86b143800           call 0x80ae5c
// 004899f1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004899f5  8bc6                 mov eax, esi
// 004899f7  5e                   pop esi
// 004899f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004899ff  83c410               add esp, 0x10
// 00489a02  c20c00               ret 0xc
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
