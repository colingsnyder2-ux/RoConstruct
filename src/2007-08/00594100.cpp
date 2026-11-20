// from server: 100% by Intel_Inside
// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 00594100  unit: RBX::VAxisMoveTool::?$TToolVerb  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00594100
//
// 00594100  6aff                 push -1
// 00594102  681bb67500           push 0x75b61b
// 00594107  64a100000000         mov eax, dword ptr fs:[0]
// 0059410d  50                   push eax
// 0059410e  64892500000000       mov dword ptr fs:[0], esp
// 00594115  51                   push ecx
// 00594116  56                   push esi
// 00594117  6a78                 push 0x78
// 00594119  8bf1                 mov esi, ecx
// 0059411b  e8d67e0900           call 0x62fef6
// 00594120  83c404               add esp, 4
// 00594123  89442404             mov dword ptr [esp + 4], eax
// 00594127  85c0                 test eax, eax
// 00594129  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00594131  7421                 je 0x594154
// 00594133  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00594136  8b8988010000         mov ecx, dword ptr [ecx + 0x188]
// 0059413c  51                   push ecx
// 0059413d  8bc8                 mov ecx, eax
// 0059413f  e8cc820a00           call 0x5fe210
// 00594144  5e                   pop esi
// 00594145  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00594149  64890d00000000       mov dword ptr fs:[0], ecx
// 00594150  83c410               add esp, 0x10
// 00594153  c3                   ret
// 00594154  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00594158  33c0                 xor eax, eax
// 0059415a  5e                   pop esi
// 0059415b  64890d00000000       mov dword ptr fs:[0], ecx
// 00594162  83c410               add esp, 0x10
// 00594165  c3                   ret

struct Workspace {
    char pad[0x188];
    void* p188;
    void* getValue();
};

__forceinline void* Workspace::getValue()
{
    return p188;
}

struct Tool {
    Tool(void* owner);
    char pad[0x78];
};

struct TToolVerb {
    char pad[0x0c];
    Workspace* container;
    Tool* createTool();
};

Tool* TToolVerb::createTool()
{
    return new Tool(container->getValue());
}