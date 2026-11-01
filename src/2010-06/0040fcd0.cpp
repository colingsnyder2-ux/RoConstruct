// from server: 100% by Yeetserama
// roc 2010-06 0040fcd0  unit: CBrush  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040fcd0
//
// 0040fcd0  6aff                 push -1
// 0040fcd2  68a9fe9700           push 0x97fea9
// 0040fcd7  64a100000000         mov eax, dword ptr fs:[0]
// 0040fcdd  50                   push eax
// 0040fcde  64892500000000       mov dword ptr fs:[0], esp
// 0040fce5  51                   push ecx
// 0040fce6  56                   push esi
// 0040fce7  8bf1                 mov esi, ecx
// 0040fce9  8d4c2404             lea ecx, [esp + 4]
// 0040fced  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 0040fcf3  8d442404             lea eax, [esp + 4]
// 0040fcf7  50                   push eax
// 0040fcf8  8bce                 mov ecx, esi
// 0040fcfa  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0040fd02  e881823900           call 0x7a7f88
// 0040fd07  8b0d54b7b700         mov ecx, dword ptr [0xb7b754]
// 0040fd0d  51                   push ecx
// 0040fd0e  8d4c2408             lea ecx, [esp + 8]
// 0040fd12  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 0040fd18  85c0                 test eax, eax
// 0040fd1a  750c                 jne 0x40fd28
// 0040fd1c  68fe08a000           push 0xa008fe
// 0040fd21  8bce                 mov ecx, esi
// 0040fd23  e82c803900           call 0x7a7d54
// 0040fd28  8d4c2404             lea ecx, [esp + 4]
// 0040fd2c  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0040fd32  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040fd36  5e                   pop esi
// 0040fd37  64890d00000000       mov dword ptr fs:[0], ecx
// 0040fd3e  83c410               add esp, 0x10
// 0040fd41  c3                   ret 
// copied from an identical function in another client (function ?f@CBrush@ns_ROCX000015@@QAEXXZ)

namespace ns_ROCX000015 {
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
