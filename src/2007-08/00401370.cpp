// from server: 100% by Yeetserama
// roc 2007-08 00401370  unit: CAboutRobloxDialog  size: 105 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401370
//
// 00401370  6aff                 push -1
// 00401372  68eaf27500           push 0x75f2ea
// 00401377  64a100000000         mov eax, dword ptr fs:[0]
// 0040137d  50                   push eax
// 0040137e  51                   push ecx
// 0040137f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00401384  33c4                 xor eax, esp
// 00401386  50                   push eax
// 00401387  8d442408             lea eax, [esp + 8]
// 0040138b  64a300000000         mov dword ptr fs:[0], eax
// 00401391  6830010000           push 0x130
// 00401396  e85beb2200           call 0x62fef6
// 0040139b  83c404               add esp, 4
// 0040139e  89442404             mov dword ptr [esp + 4], eax
// 004013a2  85c0                 test eax, eax
// 004013a4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004013ac  7419                 je 0x4013c7
// 004013ae  6a00                 push 0
// 004013b0  8bc8                 mov ecx, eax
// 004013b2  e8a9feffff           call 0x401260
// 004013b7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004013bb  64890d00000000       mov dword ptr fs:[0], ecx
// 004013c2  59                   pop ecx
// 004013c3  83c410               add esp, 0x10
// 004013c6  c3                   ret 
// 004013c7  33c0                 xor eax, eax
// 004013c9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004013cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004013d4  59                   pop ecx
// 004013d5  83c410               add esp, 0x10
// 004013d8  c3                   ret 
// copied from an identical function in another client (function ?createDialog@@YAPAUCAboutRobloxDialog@@XZ)

// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CAboutRobloxDialog
{
    char storage[0x130];
    CAboutRobloxDialog(int);
};

CAboutRobloxDialog* createDialog()
{
    return new CAboutRobloxDialog(0);
}