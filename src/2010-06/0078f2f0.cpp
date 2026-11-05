// from server: 100% by Yeetserama
// roc 2010-06 0078f2f0  unit: RBX::VGroupDragTool::?$Named  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0078f2f0
//
// 0078f2f0  6aff                 push -1
// 0078f2f2  6828ae9a00           push 0x9aae28
// 0078f2f7  64a100000000         mov eax, dword ptr fs:[0]
// 0078f2fd  50                   push eax
// 0078f2fe  64892500000000       mov dword ptr fs:[0], esp
// 0078f305  51                   push ecx
// 0078f306  56                   push esi
// 0078f307  8bf1                 mov esi, ecx
// 0078f309  57                   push edi
// 0078f30a  89742408             mov dword ptr [esp + 8], esi
// 0078f30e  c706a43da500         mov dword ptr [esi], 0xa53da4
// 0078f314  c746048c3da500       mov dword ptr [esi + 4], 0xa53d8c
// 0078f31b  8b7e1c               mov edi, dword ptr [esi + 0x1c]
// 0078f31e  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0078f326  85ff                 test edi, edi
// 0078f328  7410                 je 0x78f33a
// 0078f32a  8bcf                 mov ecx, edi
// 0078f32c  e87f91f8ff           call 0x7184b0
// 0078f331  57                   push edi
// 0078f332  e863860100           call 0x7a799a
// 0078f337  83c404               add esp, 4
// 0078f33a  8bce                 mov ecx, esi
// 0078f33c  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0078f344  e857e7f8ff           call 0x71daa0
// 0078f349  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0078f34d  5f                   pop edi
// 0078f34e  5e                   pop esi
// 0078f34f  64890d00000000       mov dword ptr fs:[0], ecx
// 0078f356  83c410               add esp, 0x10
// 0078f359  c3                   ret 
// copied from an identical function in another client (function ??1S@@UAE@XZ)

// from server: 100% by king_originala
void __cdecl operator delete(void *);

struct Primary {
    virtual ~Primary();
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    unsigned int reserved[5];
    virtual ~Base();
};

struct Owned {
    ~Owned();
};

struct S : Base {
    Owned *owned;
    virtual ~S();
};

S::~S()
{
    delete owned;
}