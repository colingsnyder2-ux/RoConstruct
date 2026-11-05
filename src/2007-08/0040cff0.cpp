// from server: 100% by Yeetserama
// roc 2007-08 0040cff0  unit: CGdiObject  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040cff0
//
// 0040cff0  6aff                 push -1
// 0040cff2  6809477600           push 0x764709
// 0040cff7  64a100000000         mov eax, dword ptr fs:[0]
// 0040cffd  50                   push eax
// 0040cffe  51                   push ecx
// 0040cfff  56                   push esi
// 0040d000  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040d005  33c4                 xor eax, esp
// 0040d007  50                   push eax
// 0040d008  8d44240c             lea eax, [esp + 0xc]
// 0040d00c  64a300000000         mov dword ptr fs:[0], eax
// 0040d012  8bf1                 mov esi, ecx
// 0040d014  8d4c2408             lea ecx, [esp + 8]
// 0040d018  ff15acdd7700         call dword ptr [0x77ddac]
// 0040d01e  8d442408             lea eax, [esp + 8]
// 0040d022  50                   push eax
// 0040d023  8bce                 mov ecx, esi
// 0040d025  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0040d02d  e81e322200           call 0x630250
// 0040d032  8b0dd81d8800         mov ecx, dword ptr [0x881dd8]
// 0040d038  51                   push ecx
// 0040d039  8d4c240c             lea ecx, [esp + 0xc]
// 0040d03d  ff15b8dc7700         call dword ptr [0x77dcb8]
// 0040d043  85c0                 test eax, eax
// 0040d045  750c                 jne 0x40d053
// 0040d047  6854597800           push 0x785954
// 0040d04c  8bce                 mov ecx, esi
// 0040d04e  e8c32f2200           call 0x630016
// 0040d053  8d4c2408             lea ecx, [esp + 8]
// 0040d057  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0040d05d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040d061  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d068  59                   pop ecx
// 0040d069  5e                   pop esi
// 0040d06a  83c410               add esp, 0x10
// 0040d06d  c3                   ret 
// copied from an identical function in another client (function ?f@CBrush@ns_ROCX000010@@QAEXXZ)

namespace ns_ROCX000010 {
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
