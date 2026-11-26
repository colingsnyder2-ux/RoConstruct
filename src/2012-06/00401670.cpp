// from server: 100% by Xemicl
// roc 2012-06 00401670  unit: CAboutRobloxDialog  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401670
//
// 00401670  6aff                 push -1
// 00401672  686a21aa00           push 0xaa216a
// 00401677  64a100000000         mov eax, dword ptr fs:[0]
// 0040167d  50                   push eax
// 0040167e  64892500000000       mov dword ptr fs:[0], esp
// 00401685  51                   push ecx
// 00401686  6830010000           push 0x130
// 0040168b  e88a0a5800           call 0x98211a
// 00401690  83c404               add esp, 4
// 00401693  890424               mov dword ptr [esp], eax
// 00401696  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0040169e  85c0                 test eax, eax
// 004016a0  7418                 je 0x4016ba
// 004016a2  6a00                 push 0
// 004016a4  8bc8                 mov ecx, eax
// 004016a6  e8f5fdffff           call 0x4014a0
// 004016ab  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004016af  64890d00000000       mov dword ptr fs:[0], ecx
// 004016b6  83c410               add esp, 0x10
// 004016b9  c3                   ret 
// 004016ba  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004016be  33c0                 xor eax, eax
// 004016c0  64890d00000000       mov dword ptr fs:[0], ecx
// 004016c7  83c410               add esp, 0x10
// 004016ca  c3                   ret 
// copied from an identical function in another client (function ?createDialog@@YAPAUCAboutRobloxDialog@@XZ)

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