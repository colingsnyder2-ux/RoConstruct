// from server: 100% by Xemicl
// from server: 100% by sophus
// roc 2012-06 008a5af0  unit: RBX::VAdvArrowTool::?$TToolVerb  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a5af0
//
// 008a5af0  6aff                 push -1
// 008a5af2  68eb29ad00           push 0xad29eb
// 008a5af7  64a100000000         mov eax, dword ptr fs:[0]
// 008a5afd  50                   push eax
// 008a5afe  64892500000000       mov dword ptr fs:[0], esp
// 008a5b05  51                   push ecx
// 008a5b06  56                   push esi
// 008a5b07  57                   push edi
// 008a5b08  6a7c                 push 0x7c
// 008a5b0a  8bf9                 mov edi, ecx
// 008a5b0c  e809c60d00           call 0x98211a
// 008a5b11  8bf0                 mov esi, eax
// 008a5b13  83c404               add esp, 4
// 008a5b16  89742408             mov dword ptr [esp + 8], esi
// 008a5b1a  33c0                 xor eax, eax
// 008a5b1c  89442414             mov dword ptr [esp + 0x14], eax
// 008a5b20  3bf0                 cmp esi, eax
// 008a5b22  7420                 je 0x8a5b44
// 008a5b24  8b470c               mov eax, dword ptr [edi + 0xc]
// 008a5b27  8b88c40a0000         mov ecx, dword ptr [eax + 0xac4]
// 008a5b2d  51                   push ecx
// 008a5b2e  8bce                 mov ecx, esi
// 008a5b30  e89b93e7ff           call 0x71eed0
// 008a5b35  c7066c3cba00         mov dword ptr [esi], 0xba3c6c
// 008a5b3b  c746043c3cba00       mov dword ptr [esi + 4], 0xba3c3c
// 008a5b42  8bc6                 mov eax, esi
// 008a5b44  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008a5b48  5f                   pop edi
// 008a5b49  5e                   pop esi
// 008a5b4a  64890d00000000       mov dword ptr fs:[0], ecx
// 008a5b51  83c410               add esp, 0x10
// 008a5b54  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Base
{
    int field0;
    int field4;
    char padding[0x30];
    Base(void* arg);
};

struct ToolVerb : Base
{
    __forceinline ToolVerb(void* arg);
};

__forceinline ToolVerb::ToolVerb(void* arg) : Base(arg)
{
    field0 = 0xba3c6c;
    field4 = 0xba3c3c;
}

struct FieldC
{
    char padding[0xAC4];
    void* fieldAC4;
};

struct VAdvArrowTool
{
    char padding[0xC];
    FieldC* fieldC;
    ToolVerb* create();
};

ToolVerb* VAdvArrowTool::create()
{
    return new ToolVerb(fieldC->fieldAC4);
}
