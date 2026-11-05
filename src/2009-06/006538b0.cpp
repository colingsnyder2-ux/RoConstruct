// from server: 100% by EspClaude
// roc 2009-06 006538b0  unit: RBX::VAxisMoveTool::?$TToolVerb  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006538b0
//
// 006538b0  6aff                 push -1
// 006538b2  68030f8700           push 0x870f03
// 006538b7  64a100000000         mov eax, dword ptr fs:[0]
// 006538bd  50                   push eax
// 006538be  64892500000000       mov dword ptr fs:[0], esp
// 006538c5  51                   push ecx
// 006538c6  56                   push esi
// 006538c7  8bf1                 mov esi, ecx
// 006538c9  57                   push edi
// 006538ca  89742408             mov dword ptr [esp + 8], esi
// 006538ce  8d4e24               lea ecx, [esi + 0x24]
// 006538d1  c744241401000000     mov dword ptr [esp + 0x14], 1
// 006538d9  c746481cb78c00       mov dword ptr [esi + 0x48], 0x8cb71c
// 006538e0  ff15c4e48900         call dword ptr [0x89e4c4]
// 006538e6  8b7e20               mov edi, dword ptr [esi + 0x20]
// 006538e9  c644241400           mov byte ptr [esp + 0x14], 0
// 006538ee  85ff                 test edi, edi
// 006538f0  7410                 je 0x653902
// 006538f2  8bcf                 mov ecx, edi
// 006538f4  e897f10500           call 0x6b2a90
// 006538f9  57                   push edi
// 006538fa  e833510c00           call 0x718a32
// 006538ff  83c404               add esp, 4
// 00653902  8bce                 mov ecx, esi
// 00653904  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0065390c  e86f220600           call 0x6b5b80
// 00653911  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00653915  5f                   pop edi
// 00653916  5e                   pop esi
// 00653917  64890d00000000       mov dword ptr fs:[0], ecx
// 0065391e  83c410               add esp, 0x10
// 00653921  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

extern void (__thiscall *destroyString)(void *);

struct Base {
    char storage[32];
    ~Base();
};

struct Item {
    ~Item();
};

void __cdecl operator delete(void *);

struct Owner {
    Item *pointer;
    ~Owner();
};

struct String {
    char storage[28];
    ~String();
};

struct VirtualPart {
    virtual ~VirtualPart();
};

struct S : Base {
    Owner owner;
    String text;
    char padding[8];
    VirtualPart part;
    ~S();
};

__forceinline Owner::~Owner()
{
    delete pointer;
}

__forceinline String::~String()
{
    destroyString(this);
}

__forceinline VirtualPart::~VirtualPart()
{
}

S::~S()
{
}