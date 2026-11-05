// from server: 100% by Yeetserama
// roc 2007-08 0040d920  unit: ChatEnter  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040d920
//
// 0040d920  6aff                 push -1
// 0040d922  68eaf27500           push 0x75f2ea
// 0040d927  64a100000000         mov eax, dword ptr fs:[0]
// 0040d92d  50                   push eax
// 0040d92e  51                   push ecx
// 0040d92f  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040d934  33c4                 xor eax, esp
// 0040d936  50                   push eax
// 0040d937  8d442408             lea eax, [esp + 8]
// 0040d93b  64a300000000         mov dword ptr fs:[0], eax
// 0040d941  68a8000000           push 0xa8
// 0040d946  e8ab252200           call 0x62fef6
// 0040d94b  83c404               add esp, 4
// 0040d94e  89442404             mov dword ptr [esp + 4], eax
// 0040d952  85c0                 test eax, eax
// 0040d954  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040d95c  7417                 je 0x40d975
// 0040d95e  8bc8                 mov ecx, eax
// 0040d960  e89bfcffff           call 0x40d600
// 0040d965  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040d969  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d970  59                   pop ecx
// 0040d971  83c410               add esp, 0x10
// 0040d974  c3                   ret 
// 0040d975  33c0                 xor eax, eax
// 0040d977  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0040d97b  64890d00000000       mov dword ptr fs:[0], ecx
// 0040d982  59                   pop ecx
// 0040d983  83c410               add esp, 0x10
// 0040d986  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct CRobloxControlColorSelector
{
    char storage[0xa8];
    CRobloxControlColorSelector();
};

CRobloxControlColorSelector* createColorSelector()
{
    return new CRobloxControlColorSelector;
}