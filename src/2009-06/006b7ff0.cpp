// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 00618260  unit: RBX::NewNullTool  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00618260
//
// 00618260  6aff                 push -1
// 00618262  683bf47b00           push 0x7bf43b
// 00618267  64a100000000         mov eax, dword ptr fs:[0]
// 0061826d  50                   push eax
// 0061826e  64892500000000       mov dword ptr fs:[0], esp
// 00618275  51                   push ecx
// 00618276  56                   push esi
// 00618277  6a48                 push 0x48
// 00618279  8bf1                 mov esi, ecx
// 0061827b  e8a0860800           call 0x6a0920
// 00618280  83c404               add esp, 4
// 00618283  89442404             mov dword ptr [esp + 4], eax
// 00618287  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0061828f  85c0                 test eax, eax
// 00618291  741b                 je 0x6182ae
// 00618293  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00618296  51                   push ecx
// 00618297  8bc8                 mov ecx, eax
// 00618299  e8c2feffff           call 0x618160
// 0061829e  5e                   pop esi
// 0061829f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006182a3  64890d00000000       mov dword ptr fs:[0], ecx
// 006182aa  83c410               add esp, 0x10
// 006182ad  c3                   ret 
// 006182ae  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006182b2  33c0                 xor eax, eax
// 006182b4  5e                   pop esi
// 006182b5  64890d00000000       mov dword ptr fs:[0], ecx
// 006182bc  83c410               add esp, 0x10
// 006182bf  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Context;

struct Tool {
    char storage[72];
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
