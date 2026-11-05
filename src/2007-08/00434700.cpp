// from server: 100% by Yeetserama
// roc 2007-08 00434700  unit: CClassTreeView  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00434700
//
// 00434700  6aff                 push -1
// 00434702  68eaf27500           push 0x75f2ea
// 00434707  64a100000000         mov eax, dword ptr fs:[0]
// 0043470d  50                   push eax
// 0043470e  51                   push ecx
// 0043470f  a188518b00           mov eax, dword ptr [0x8b5188]
// 00434714  33c4                 xor eax, esp
// 00434716  50                   push eax
// 00434717  8d442408             lea eax, [esp + 8]
// 0043471b  64a300000000         mov dword ptr fs:[0], eax
// 00434721  6888020000           push 0x288
// 00434726  e8cbb71f00           call 0x62fef6
// 0043472b  83c404               add esp, 4
// 0043472e  89442404             mov dword ptr [esp + 4], eax
// 00434732  85c0                 test eax, eax
// 00434734  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043473c  7417                 je 0x434755
// 0043473e  8bc8                 mov ecx, eax
// 00434740  e84bfaffff           call 0x434190
// 00434745  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00434749  64890d00000000       mov dword ptr fs:[0], ecx
// 00434750  59                   pop ecx
// 00434751  83c410               add esp, 0x10
// 00434754  c3                   ret 
// 00434755  33c0                 xor eax, eax
// 00434757  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043475b  64890d00000000       mov dword ptr fs:[0], ecx
// 00434762  59                   pop ecx
// 00434763  83c410               add esp, 0x10
// 00434766  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

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