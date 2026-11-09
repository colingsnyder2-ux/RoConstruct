// from server: 100% by EspClaude
// roc 2009-06 00463de0  unit: CCommonDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00463de0
//
// 00463de0  6aff                 push -1
// 00463de2  687aef8400           push 0x84ef7a
// 00463de7  64a100000000         mov eax, dword ptr fs:[0]
// 00463ded  50                   push eax
// 00463dee  64892500000000       mov dword ptr fs:[0], esp
// 00463df5  51                   push ecx
// 00463df6  68ec000000           push 0xec
// 00463dfb  e8384c2b00           call 0x718a38
// 00463e00  83c404               add esp, 4
// 00463e03  890424               mov dword ptr [esp], eax
// 00463e06  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00463e0e  85c0                 test eax, eax
// 00463e10  7416                 je 0x463e28
// 00463e12  8bc8                 mov ecx, eax
// 00463e14  e857edffff           call 0x462b70
// 00463e19  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00463e1d  64890d00000000       mov dword ptr fs:[0], ecx
// 00463e24  83c410               add esp, 0x10
// 00463e27  c3                   ret 
// 00463e28  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00463e2c  33c0                 xor eax, eax
// 00463e2e  64890d00000000       mov dword ptr fs:[0], ecx
// 00463e35  83c410               add esp, 0x10
// 00463e38  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

// 0044edf0  6aff                 push -1
// 0044edf2  681afa7b00           push 0x7bfa1a
// 0044edf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044edfd  50                   push eax
// 0044edfe  64892500000000       mov dword ptr fs:[0], esp
// 0044ee05  51                   push ecx
// 0044ee06  6884010000           push 0xec
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
    char storage[0xec];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}