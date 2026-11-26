// from server: 100% by Xemicl
// roc 2012-06 00449f50  unit: CObjectBrowser  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00449f50
//
// 00449f50  6aff                 push -1
// 00449f52  686a21aa00           push 0xaa216a
// 00449f57  64a100000000         mov eax, dword ptr fs:[0]
// 00449f5d  50                   push eax
// 00449f5e  64892500000000       mov dword ptr fs:[0], esp
// 00449f65  51                   push ecx
// 00449f66  68b4000000           push 0xb4
// 00449f6b  e8aa815300           call 0x98211a
// 00449f70  83c404               add esp, 4
// 00449f73  890424               mov dword ptr [esp], eax
// 00449f76  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00449f7e  85c0                 test eax, eax
// 00449f80  7416                 je 0x449f98
// 00449f82  8bc8                 mov ecx, eax
// 00449f84  e8c7f7ffff           call 0x449750
// 00449f89  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00449f8d  64890d00000000       mov dword ptr fs:[0], ecx
// 00449f94  83c410               add esp, 0x10
// 00449f97  c3                   ret 
// 00449f98  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00449f9c  33c0                 xor eax, eax
// 00449f9e  64890d00000000       mov dword ptr fs:[0], ecx
// 00449fa5  83c410               add esp, 0x10
// 00449fa8  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

// 0044edf0  6aff                 push -1
// 0044edf2  681afa7b00           push 0x7bfa1a
// 0044edf7  64a100000000         mov eax, dword ptr fs:[0]
// 0044edfd  50                   push eax
// 0044edfe  64892500000000       mov dword ptr fs:[0], esp
// 0044ee05  51                   push ecx
// 0044ee06  6884010000           push 0xb4
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
    char storage[0xb4];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}