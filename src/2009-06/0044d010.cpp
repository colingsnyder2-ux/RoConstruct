// from server: 100% by EspClaude
// roc 2009-06 0044d010  unit: CAboutRobloxDialog  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d010
//
// 0044d010  6aff                 push -1
// 0044d012  68370e8500           push 0x850e37
// 0044d017  64a100000000         mov eax, dword ptr fs:[0]
// 0044d01d  50                   push eax
// 0044d01e  64892500000000       mov dword ptr fs:[0], esp
// 0044d025  51                   push ecx
// 0044d026  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044d02a  56                   push esi
// 0044d02b  8bf1                 mov esi, ecx
// 0044d02d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044d031  50                   push eax
// 0044d032  6a72                 push 0x72
// 0044d034  51                   push ecx
// 0044d035  8bce                 mov ecx, esi
// 0044d037  89742410             mov dword ptr [esp + 0x10], esi
// 0044d03b  e8a2c72c00           call 0x7197e2
// 0044d040  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0044d044  52                   push edx
// 0044d045  8d8e14010000         lea ecx, [esi + 0x114]
// 0044d04b  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0044d053  c706747a8b00         mov dword ptr [esi], 0x8b7a74
// 0044d059  c74674447a8b00       mov dword ptr [esi + 0x74], 0x8b7a44
// 0044d060  ff15b4e48900         call dword ptr [0x89e4b4]
// 0044d066  b801000000           mov eax, 1
// 0044d06b  88442410             mov byte ptr [esp + 0x10], al
// 0044d06f  898690000000         mov dword ptr [esi + 0x90], eax
// 0044d075  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0044d07b  0d13408401           or eax, 0x1844013
// 0044d080  50                   push eax
// 0044d081  8bce                 mov ecx, esi
// 0044d083  e850bc2c00           call 0x718cd8
// 0044d088  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044d08c  8bc6                 mov eax, esi
// 0044d08e  5e                   pop esi
// 0044d08f  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d096  83c410               add esp, 0x10
// 0044d099  c20c00               ret 0xc
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