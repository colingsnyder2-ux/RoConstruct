// from server: 100% by Xemicl
// roc 2012-06 00479c20  unit: CAboutRobloxDialog  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00479c20
//
// 00479c20  6aff                 push -1
// 00479c22  68770eaa00           push 0xaa0e77
// 00479c27  64a100000000         mov eax, dword ptr fs:[0]
// 00479c2d  50                   push eax
// 00479c2e  64892500000000       mov dword ptr fs:[0], esp
// 00479c35  51                   push ecx
// 00479c36  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00479c3a  56                   push esi
// 00479c3b  8bf1                 mov esi, ecx
// 00479c3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00479c41  50                   push eax
// 00479c42  6a72                 push 0x72
// 00479c44  51                   push ecx
// 00479c45  8bce                 mov ecx, esi
// 00479c47  89742410             mov dword ptr [esp + 0x10], esi
// 00479c4b  e874925000           call 0x982ec4
// 00479c50  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00479c54  52                   push edx
// 00479c55  8d8e14010000         lea ecx, [esi + 0x114]
// 00479c5b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00479c63  c706d4b5b500         mov dword ptr [esi], 0xb5b5d4
// 00479c69  c74674a4b5b500       mov dword ptr [esi + 0x74], 0xb5b5a4
// 00479c70  ff154826b200         call dword ptr [0xb22648]
// 00479c76  b801000000           mov eax, 1
// 00479c7b  88442410             mov byte ptr [esp + 0x10], al
// 00479c7f  898690000000         mov dword ptr [esi + 0x90], eax
// 00479c85  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 00479c8b  0d13408401           or eax, 0x1844013
// 00479c90  50                   push eax
// 00479c91  8bce                 mov ecx, esi
// 00479c93  e81c875000           call 0x9823b4
// 00479c98  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00479c9c  8bc6                 mov eax, esi
// 00479c9e  5e                   pop esi
// 00479c9f  64890d00000000       mov dword ptr fs:[0], ecx
// 00479ca6  83c410               add esp, 0x10
// 00479ca9  c20c00               ret 0xc
// copied from an identical function in another client (function ??0S@@QAE@IPBDI@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Primary
{
    virtual void primary();
    char padding[0x70];
};

struct Secondary
{
    virtual void secondary();
    char padding1[0x18];
    int enabled;
    char padding2[0x78];
    unsigned flags;
    unsigned padding3;
};

struct Base : Primary, Secondary
{
    Base(unsigned, unsigned, unsigned);
    ~Base();
    void setFlags(unsigned);
};

struct S : Base
{
    std::string text;

    S(unsigned, const char *, unsigned);
    virtual void primary();
    virtual void secondary();
};

S::S(unsigned first, const char *value, unsigned third)
    : Base(first, 0x72, third), text(value)
{
    enabled = 1;
    setFlags(flags | 0x01844013);
}