// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 44% by colin
// roc 2007-08 00594040  unit: RBX::VResizeTool::?$TToolVerb  size: 102 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00594040
//
// 00594040  6aff                 push -1
// 00594042  681bb67500           push 0x75b61b
// 00594047  64a100000000         mov eax, dword ptr fs:[0]
// 0059404d  50                   push eax
// 0059404e  64892500000000       mov dword ptr fs:[0], esp
// 00594055  51                   push ecx
// 00594056  56                   push esi
// 00594057  6a4c                 push 0x4c
// 00594059  8bf1                 mov esi, ecx
// 0059405b  e896be0900           call 0x62fef6
// 00594060  83c404               add esp, 4
// 00594063  89442404             mov dword ptr [esp + 4], eax
// 00594067  85c0                 test eax, eax
// 00594069  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00594071  7421                 je 0x594094
// 00594073  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00594076  8b8988010000         mov ecx, dword ptr [ecx + 0x188]
// 0059407c  51                   push ecx
// 0059407d  8bc8                 mov ecx, eax
// 0059407f  e85cfeffff           call 0x593ee0
// 00594084  5e                   pop esi
// 00594085  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00594089  64890d00000000       mov dword ptr fs:[0], ecx
// 00594090  83c410               add esp, 0x10
// 00594093  c3                   ret 
// 00594094  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00594098  33c0                 xor eax, eax
// 0059409a  5e                   pop esi
// 0059409b  64890d00000000       mov dword ptr fs:[0], ecx
// 005940a2  83c410               add esp, 0x10
// 005940a5  c3                   ret 

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
    char pad[0x4c];
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
