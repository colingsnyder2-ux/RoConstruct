// from server: 100% by EspClaude
// roc 2009-06 0042d360  unit: CObjectBrowser  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042d360
//
// 0042d360  6aff                 push -1
// 0042d362  687aef8400           push 0x84ef7a
// 0042d367  64a100000000         mov eax, dword ptr fs:[0]
// 0042d36d  50                   push eax
// 0042d36e  64892500000000       mov dword ptr fs:[0], esp
// 0042d375  51                   push ecx
// 0042d376  68b4000000           push 0xb4
// 0042d37b  e8b8b62e00           call 0x718a38
// 0042d380  83c404               add esp, 4
// 0042d383  890424               mov dword ptr [esp], eax
// 0042d386  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0042d38e  85c0                 test eax, eax
// 0042d390  7416                 je 0x42d3a8
// 0042d392  8bc8                 mov ecx, eax
// 0042d394  e897f9ffff           call 0x42cd30
// 0042d399  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d39d  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d3a4  83c410               add esp, 0x10
// 0042d3a7  c3                   ret 
// 0042d3a8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0042d3ac  33c0                 xor eax, eax
// 0042d3ae  64890d00000000       mov dword ptr fs:[0], ecx
// 0042d3b5  83c410               add esp, 0x10
// 0042d3b8  c3                   ret 
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