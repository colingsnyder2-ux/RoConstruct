// from server: 100% by Xemicl
// roc 2012-06 00478730  unit: CRobloxControlColorSelector  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00478730
//
// 00478730  6aff                 push -1
// 00478732  686a21aa00           push 0xaa216a
// 00478737  64a100000000         mov eax, dword ptr fs:[0]
// 0047873d  50                   push eax
// 0047873e  64892500000000       mov dword ptr fs:[0], esp
// 00478745  51                   push ecx
// 00478746  6884010000           push 0x184
// 0047874b  e8ca995000           call 0x98211a
// 00478750  83c404               add esp, 4
// 00478753  890424               mov dword ptr [esp], eax
// 00478756  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0047875e  85c0                 test eax, eax
// 00478760  7416                 je 0x478778
// 00478762  8bc8                 mov ecx, eax
// 00478764  e847feffff           call 0x4785b0
// 00478769  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0047876d  64890d00000000       mov dword ptr fs:[0], ecx
// 00478774  83c410               add esp, 0x10
// 00478777  c3                   ret 
// 00478778  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0047877c  33c0                 xor eax, eax
// 0047877e  64890d00000000       mov dword ptr fs:[0], ecx
// 00478785  83c410               add esp, 0x10
// 00478788  c3                   ret 
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