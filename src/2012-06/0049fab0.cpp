// from server: 100% by Xemicl
// roc 2012-06 0049fab0  unit: CCommonDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0049fab0
//
// 0049fab0  6aff                 push -1
// 0049fab2  686a21aa00           push 0xaa216a
// 0049fab7  64a100000000         mov eax, dword ptr fs:[0]
// 0049fabd  50                   push eax
// 0049fabe  64892500000000       mov dword ptr fs:[0], esp
// 0049fac5  51                   push ecx
// 0049fac6  68ec000000           push 0xec
// 0049facb  e84a264e00           call 0x98211a
// 0049fad0  83c404               add esp, 4
// 0049fad3  890424               mov dword ptr [esp], eax
// 0049fad6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0049fade  85c0                 test eax, eax
// 0049fae0  7416                 je 0x49faf8
// 0049fae2  8bc8                 mov ecx, eax
// 0049fae4  e867edffff           call 0x49e850
// 0049fae9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0049faed  64890d00000000       mov dword ptr fs:[0], ecx
// 0049faf4  83c410               add esp, 0x10
// 0049faf7  c3                   ret 
// 0049faf8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0049fafc  33c0                 xor eax, eax
// 0049fafe  64890d00000000       mov dword ptr fs:[0], ecx
// 0049fb05  83c410               add esp, 0x10
// 0049fb08  c3                   ret 
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