// from server: 100% by Yeetserama
// roc 2012-06 00453950  unit: CStandardOutputView  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00453950
//
// 00453950  6aff                 push -1
// 00453952  686a21aa00           push 0xaa216a
// 00453957  64a100000000         mov eax, dword ptr fs:[0]
// 0045395d  50                   push eax
// 0045395e  64892500000000       mov dword ptr fs:[0], esp
// 00453965  51                   push ecx
// 00453966  684c010000           push 0x14c
// 0045396b  e8aae75200           call 0x98211a
// 00453970  83c404               add esp, 4
// 00453973  890424               mov dword ptr [esp], eax
// 00453976  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0045397e  85c0                 test eax, eax
// 00453980  7416                 je 0x453998
// 00453982  8bc8                 mov ecx, eax
// 00453984  e8b7f8ffff           call 0x453240
// 00453989  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045398d  64890d00000000       mov dword ptr fs:[0], ecx
// 00453994  83c410               add esp, 0x10
// 00453997  c3                   ret 
// 00453998  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0045399c  33c0                 xor eax, eax
// 0045399e  64890d00000000       mov dword ptr fs:[0], ecx
// 004539a5  83c410               add esp, 0x10
// 004539a8  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CRobloxControlColorSelector
{
    char storage[0x14c];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}