// from server: 100% by EspClaude
// roc 2009-06 006cc1e0  unit: RBX::GrabTool  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cc1e0
//
// 006cc1e0  6aff                 push -1
// 006cc1e2  687b9c8600           push 0x869c7b
// 006cc1e7  64a100000000         mov eax, dword ptr fs:[0]
// 006cc1ed  50                   push eax
// 006cc1ee  64892500000000       mov dword ptr fs:[0], esp
// 006cc1f5  51                   push ecx
// 006cc1f6  56                   push esi
// 006cc1f7  6a38                 push 0x38
// 006cc1f9  8bf1                 mov esi, ecx
// 006cc1fb  e838c80400           call 0x718a38
// 006cc200  83c404               add esp, 4
// 006cc203  89442404             mov dword ptr [esp + 4], eax
// 006cc207  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006cc20f  85c0                 test eax, eax
// 006cc211  741b                 je 0x6cc22e
// 006cc213  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006cc216  51                   push ecx
// 006cc217  8bc8                 mov ecx, eax
// 006cc219  e842ffffff           call 0x6cc160
// 006cc21e  5e                   pop esi
// 006cc21f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006cc223  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc22a  83c410               add esp, 0x10
// 006cc22d  c3                   ret 
// 006cc22e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006cc232  33c0                 xor eax, eax
// 006cc234  5e                   pop esi
// 006cc235  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc23c  83c410               add esp, 0x10
// 006cc23f  c3                   ret 
// copied from an identical function in another client (function ?create@Verb@@QAEPAUTool@@XZ)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context;

struct Tool {
    char storage[56];
    Tool(Context* context);
};

struct Verb {
    char padding[24];
    Context* context;
    Tool* create();
};

Tool* Verb::create()
{
    return new Tool(context);
}