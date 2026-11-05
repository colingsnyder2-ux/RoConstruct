// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 00640300  unit: RBX::GameTool  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00640300
//
// 00640300  6aff                 push -1
// 00640302  683bf47b00           push 0x7bf43b
// 00640307  64a100000000         mov eax, dword ptr fs:[0]
// 0064030d  50                   push eax
// 0064030e  64892500000000       mov dword ptr fs:[0], esp
// 00640315  51                   push ecx
// 00640316  56                   push esi
// 00640317  6a38                 push 0x38
// 00640319  8bf1                 mov esi, ecx
// 0064031b  e800060600           call 0x6a0920
// 00640320  83c404               add esp, 4
// 00640323  89442404             mov dword ptr [esp + 4], eax
// 00640327  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064032f  85c0                 test eax, eax
// 00640331  741b                 je 0x64034e
// 00640333  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00640336  51                   push ecx
// 00640337  8bc8                 mov ecx, eax
// 00640339  e842ffffff           call 0x640280
// 0064033e  5e                   pop esi
// 0064033f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00640343  64890d00000000       mov dword ptr fs:[0], ecx
// 0064034a  83c410               add esp, 0x10
// 0064034d  c3                   ret 
// 0064034e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00640352  33c0                 xor eax, eax
// 00640354  5e                   pop esi
// 00640355  64890d00000000       mov dword ptr fs:[0], ecx
// 0064035c  83c410               add esp, 0x10
// 0064035f  c3                   ret 

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
