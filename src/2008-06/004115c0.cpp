// from server: 100% by colin
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
