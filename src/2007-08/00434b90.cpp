// from server: 100% by Yeetserama
// roc 2007-08 00434b90  unit: CObjectBrowser  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434b90
//
// 00434b90  6aff                 push -1
// 00434b92  68eaf27500           push 0x75f2ea
// 00434b97  64a100000000         mov eax, dword ptr fs:[0]
// 00434b9d  50                   push eax
// 00434b9e  51                   push ecx
// 00434b9f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434ba4  33c4                 xor eax, esp
// 00434ba6  50                   push eax
// 00434ba7  8d442408             lea eax, [esp + 8]
// 00434bab  64a300000000         mov dword ptr fs:[0], eax
// 00434bb1  68b4000000           push 0xb4
// 00434bb6  e83bb31f00           call 0x62fef6
// 00434bbb  83c404               add esp, 4
// 00434bbe  89442404             mov dword ptr [esp + 4], eax
// 00434bc2  85c0                 test eax, eax
// 00434bc4  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00434bcc  7417                 je 0x434be5
// 00434bce  8bc8                 mov ecx, eax
// 00434bd0  e80bf8ffff           call 0x4343e0
// 00434bd5  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00434bd9  64890d00000000       mov dword ptr fs:[0], ecx
// 00434be0  59                   pop ecx
// 00434be1  83c410               add esp, 0x10
// 00434be4  c3                   ret 
// 00434be5  33c0                 xor eax, eax
// 00434be7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00434beb  64890d00000000       mov dword ptr fs:[0], ecx
// 00434bf2  59                   pop ecx
// 00434bf3  83c410               add esp, 0x10
// 00434bf6  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

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