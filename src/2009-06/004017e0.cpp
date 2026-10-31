// from server: 100% by EspClaude
// roc 2009-06 004017e0  unit: CAboutRobloxDialog  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004017e0
//
// 004017e0  6aff                 push -1
// 004017e2  687aef8400           push 0x84ef7a
// 004017e7  64a100000000         mov eax, dword ptr fs:[0]
// 004017ed  50                   push eax
// 004017ee  64892500000000       mov dword ptr fs:[0], esp
// 004017f5  51                   push ecx
// 004017f6  6830010000           push 0x130
// 004017fb  e838723100           call 0x718a38
// 00401800  83c404               add esp, 4
// 00401803  890424               mov dword ptr [esp], eax
// 00401806  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0040180e  85c0                 test eax, eax
// 00401810  7418                 je 0x40182a
// 00401812  6a00                 push 0
// 00401814  8bc8                 mov ecx, eax
// 00401816  e8e5fdffff           call 0x401600
// 0040181b  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040181f  64890d00000000       mov dword ptr fs:[0], ecx
// 00401826  83c410               add esp, 0x10
// 00401829  c3                   ret 
// 0040182a  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040182e  33c0                 xor eax, eax
// 00401830  64890d00000000       mov dword ptr fs:[0], ecx
// 00401837  83c410               add esp, 0x10
// 0040183a  c3                   ret 
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