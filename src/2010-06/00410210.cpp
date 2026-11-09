// from server: 100% by Yeetserama
// roc 2010-06 00410210  unit: boost::Vbad_weak_ptr::?$error_info_injector  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00410210
//
// 00410210  6aff                 push -1
// 00410212  68da209800           push 0x9820da
// 00410217  64a100000000         mov eax, dword ptr fs:[0]
// 0041021d  50                   push eax
// 0041021e  64892500000000       mov dword ptr fs:[0], esp
// 00410225  51                   push ecx
// 00410226  68a8000000           push 0xa8
// 0041022b  e870773900           call 0x7a79a0
// 00410230  83c404               add esp, 4
// 00410233  890424               mov dword ptr [esp], eax
// 00410236  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0041023e  85c0                 test eax, eax
// 00410240  7416                 je 0x410258
// 00410242  8bc8                 mov ecx, eax
// 00410244  e807fdffff           call 0x40ff50
// 00410249  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041024d  64890d00000000       mov dword ptr fs:[0], ecx
// 00410254  83c410               add esp, 0x10
// 00410257  c3                   ret 
// 00410258  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0041025c  33c0                 xor eax, eax
// 0041025e  64890d00000000       mov dword ptr fs:[0], ecx
// 00410265  83c410               add esp, 0x10
// 00410268  c3                   ret 
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