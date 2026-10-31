// from server: 100% by EspClaude
// roc 2009-06 0044cf50  unit: CRobloxControlColorSelector  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044cf50
//
// 0044cf50  6aff                 push -1
// 0044cf52  687aef8400           push 0x84ef7a
// 0044cf57  64a100000000         mov eax, dword ptr fs:[0]
// 0044cf5d  50                   push eax
// 0044cf5e  64892500000000       mov dword ptr fs:[0], esp
// 0044cf65  51                   push ecx
// 0044cf66  6884010000           push 0x184
// 0044cf6b  e8c8ba2c00           call 0x718a38
// 0044cf70  83c404               add esp, 4
// 0044cf73  890424               mov dword ptr [esp], eax
// 0044cf76  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044cf7e  85c0                 test eax, eax
// 0044cf80  7416                 je 0x44cf98
// 0044cf82  8bc8                 mov ecx, eax
// 0044cf84  e837feffff           call 0x44cdc0
// 0044cf89  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044cf8d  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cf94  83c410               add esp, 0x10
// 0044cf97  c3                   ret 
// 0044cf98  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0044cf9c  33c0                 xor eax, eax
// 0044cf9e  64890d00000000       mov dword ptr fs:[0], ecx
// 0044cfa5  83c410               add esp, 0x10
// 0044cfa8  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CRobloxControlColorSelector
{
    char storage[0x184];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}