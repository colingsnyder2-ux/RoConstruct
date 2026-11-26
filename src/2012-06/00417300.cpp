// from server: 100% by Xemicl
// roc 2012-06 00417300  unit: ChatEnter  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00417300
//
// 00417300  6aff                 push -1
// 00417302  68d9aea900           push 0xa9aed9
// 00417307  64a100000000         mov eax, dword ptr fs:[0]
// 0041730d  50                   push eax
// 0041730e  64892500000000       mov dword ptr fs:[0], esp
// 00417315  51                   push ecx
// 00417316  56                   push esi
// 00417317  8bf1                 mov esi, ecx
// 00417319  8d4c2404             lea ecx, [esp + 4]
// 0041731d  ff158447b200         call dword ptr [0xb24784]
// 00417323  8d442404             lea eax, [esp + 4]
// 00417327  50                   push eax
// 00417328  8bce                 mov ecx, esi
// 0041732a  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00417332  e8bfb35600           call 0x9826f6
// 00417337  8b0db034d600         mov ecx, dword ptr [0xd634b0]
// 0041733d  51                   push ecx
// 0041733e  8d4c2408             lea ecx, [esp + 8]
// 00417342  ff159c47b200         call dword ptr [0xb2479c]
// 00417348  85c0                 test eax, eax
// 0041734a  750c                 jne 0x417358
// 0041734c  68e83bb400           push 0xb43be8
// 00417351  8bce                 mov ecx, esi
// 00417353  e864b15600           call 0x9824bc
// 00417358  8d4c2404             lea ecx, [esp + 4]
// 0041735c  ff15d047b200         call dword ptr [0xb247d0]
// 00417362  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00417366  5e                   pop esi
// 00417367  64890d00000000       mov dword ptr fs:[0], ecx
// 0041736e  83c410               add esp, 0x10
// 00417371  c3                   ret 
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