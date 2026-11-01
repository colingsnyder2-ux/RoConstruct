// from server: 100% by Yeetserama
// roc 2010-06 00470490  unit: CCommonDialog  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00470490
//
// 00470490  6aff                 push -1
// 00470492  68da209800           push 0x9820da
// 00470497  64a100000000         mov eax, dword ptr fs:[0]
// 0047049d  50                   push eax
// 0047049e  64892500000000       mov dword ptr fs:[0], esp
// 004704a5  51                   push ecx
// 004704a6  68ec000000           push 0xec
// 004704ab  e8f0743300           call 0x7a79a0
// 004704b0  83c404               add esp, 4
// 004704b3  890424               mov dword ptr [esp], eax
// 004704b6  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004704be  85c0                 test eax, eax
// 004704c0  7416                 je 0x4704d8
// 004704c2  8bc8                 mov ecx, eax
// 004704c4  e857edffff           call 0x46f220
// 004704c9  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004704cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004704d4  83c410               add esp, 0x10
// 004704d7  c3                   ret 
// 004704d8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004704dc  33c0                 xor eax, eax
// 004704de  64890d00000000       mov dword ptr fs:[0], ecx
// 004704e5  83c410               add esp, 0x10
// 004704e8  c3                   ret 
// copied from an identical function in another client (function ?createColorSelector@@YAPAUCRobloxControlColorSelector@@XZ)

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