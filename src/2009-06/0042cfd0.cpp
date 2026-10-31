// from server: 100% by EspClaude
// roc 2009-06 0042cfd0  unit: CClassTreeView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042cfd0
//
// 0042cfd0  6aff                 push -1
// 0042cfd2  687aef8400           push 0x84ef7a
// 0042cfd7  64a100000000         mov eax, dword ptr fs:[0]
// 0042cfdd  50                   push eax
// 0042cfde  64892500000000       mov dword ptr fs:[0], esp
// 0042cfe5  51                   push ecx
// 0042cfe6  6888020000           push 0x288
// 0042cfeb  e848ba2e00           call 0x718a38
// 0042cff0  83c404               add esp, 4
// 0042cff3  890424               mov dword ptr [esp], eax
// 0042cff6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042cffe  85c0                 test eax, eax
// 0042d000  7416                 je 0x42d018
// 0042d002  8bc8                 mov ecx, eax
// 0042d004  e827faffff           call 0x42ca30
// 0042d009  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d00d  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d014  83c410               add esp, 0x10
// 0042d017  c3                   ret 
// 0042d018  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d01c  33c0                 xor eax, eax
// 0042d01e  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d025  83c410               add esp, 0x10
// 0042d028  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

// 0044edf0  6aff                 push -1
// 0044edf2  681afa7b00           push 0x7bfa1a
// 0044edf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044edfd  50                   push eax
// 0044edfe  64892500000000       mov dword ptr fs:[0], esp
// 0044ee05  51                   push ecx
// 0044ee06  6884010000           push 0x288
// 0044ee0b  e8101b2500           call 0x6a0920
// 0044ee10  83c404               add esp, 4
// 0044ee13  890424               mov dword ptr [esp], eax
// 0044ee16  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044ee1e  85c0                 test eax, eax
// 0044ee20  7416                 je 0x44ee38
// 0044ee22  8bc8                 mov ecx, eax
// 0044ee24  e837feffff           call 0x44ec60
// 0044ee29  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044ee2d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ee34  83c410               add esp, 0x10
// 0044ee37  c3                   ret 
// 0044ee38  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044ee3c  33c0                 xor eax, eax
// 0044ee3e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044ee45  83c410               add esp, 0x10
// 0044ee48  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CRobloxControlColorSelector
{
    char storage[0x288];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}