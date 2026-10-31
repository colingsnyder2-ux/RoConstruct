// from server: 100% by EspClaude
// roc 2009-06 0040faf0  unit: CBrush  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0040faf0
//
// 0040faf0  6aff                 push -1
// 0040faf2  6839068500           push 0x850639
// 0040faf7  64a100000000         mov eax, dword ptr fs:[0]
// 0040fafd  50                   push eax
// 0040fafe  64892500000000       mov dword ptr fs:[0], esp
// 0040fb05  51                   push ecx
// 0040fb06  56                   push esi
// 0040fb07  8bf1                 mov esi, ecx
// 0040fb09  8d4c2404             lea ecx, [esp + 4]
// 0040fb0d  ff15bcfc8900         call dword ptr [0x89fcbc]
// 0040fb13  8d442404             lea eax, [esp + 4]
// 0040fb17  50                   push eax
// 0040fb18  8bce                 mov ecx, esi
// 0040fb1a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040fb22  e8f9943000           call 0x719020
// 0040fb27  8b0d6ce69d00         mov ecx, dword ptr [0x9de66c]
// 0040fb2d  51                   push ecx
// 0040fb2e  8d4c2408             lea ecx, [esp + 8]
// 0040fb32  ff15d4fc8900         call dword ptr [0x89fcd4]
// 0040fb38  85c0                 test eax, eax
// 0040fb3a  750c                 jne 0x40fb48
// 0040fb3c  6816d28a00           push 0x8ad216
// 0040fb41  8bce                 mov ecx, esi
// 0040fb43  e8a4923000           call 0x718dec
// 0040fb48  8d4c2404             lea ecx, [esp + 4]
// 0040fb4c  ff1510fd8900         call dword ptr [0x89fd10]
// 0040fb52  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040fb56  5e                   pop esi
// 0040fb57  64890d00000000       mov dword ptr fs:[0], ecx
// 0040fb5e  83c410               add esp, 0x10
// 0040fb61  c3                   ret 
// copied from an identical function in another client (function ?f@CBrush@ns_ROCX000017@@QAEXXZ)

namespace ns_ROCX000017 {
// from server: 93% by king_originala
// roc 2008-06 004115c0  unit: CBrush  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004115c0
//
// 004115c0  6aff                 push -1
// 004115c2  68c9107c00           push 0x7c10c9
// 004115c7  64a100000000         mov eax, dword ptr fs:[0]
// 004115cd  50                   push eax
// 004115ce  64892500000000       mov dword ptr fs:[0], esp
// 004115d5  51                   push ecx
// 004115d6  56                   push esi
// 004115d7  8bf1                 mov esi, ecx
// 004115d9  8d4c2404             lea ecx, [esp + 4]
// 004115dd  ff15043f8000         call dword ptr [0x803f04]
// 004115e3  8d442404             lea eax, [esp + 4]
// 004115e7  50                   push eax
// 004115e8  8bce                 mov ecx, esi
// 004115ea  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004115f2  e883f62800           call 0x6a0c7a
// 004115f7  8b0d80b79200         mov ecx, dword ptr [0x92b780]
// 004115fd  51                   push ecx
// 004115fe  8d4c2408             lea ecx, [esp + 8]
// 00411602  ff15f02f8000         call dword ptr [0x802ff0]
// 00411608  85c0                 test eax, eax
// 0041160a  750c                 jne 0x411618
// 0041160c  6816b78000           push 0x80b716
// 00411611  8bce                 mov ecx, esi
// 00411613  e802f62800           call 0x6a0c1a
// 00411618  8d4c2404             lea ecx, [esp + 4]
// 0041161c  ff15143f8000         call dword ptr [0x803f14]
// 00411622  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00411626  5e                   pop esi
// 00411627  64890d00000000       mov dword ptr fs:[0], ecx
// 0041162e  83c410               add esp, 0x10
// 00411631  c3                   ret 

struct String;

extern void (__thiscall *constructString)(String*);
extern void (__thiscall *destroyString)(String*);
extern int (__thiscall *compareString)(const String*, const char*);

extern const char* expectedText;
extern const char replacementText[];

struct __declspec(dllimport) String
{
    char* data;
    String();
    ~String() throw();
    int Compare(const char*) const;
};



struct CBrush
{
    void GetWindowText(String&) const;
    void SetWindowText(const char*);
    void f();
};

void CBrush::f()
{
    String text;
    GetWindowText(text);
    if (text.Compare(expectedText) == 0)
        SetWindowText(replacementText);
}
}
