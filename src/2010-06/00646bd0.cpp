// from server: 100% by Yeetserama
// roc 2010-06 00646bd0  unit: RBX::VAxisMoveTool::?$TToolVerb  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00646bd0
//
// 00646bd0  6aff                 push -1
// 00646bd2  68d3d39900           push 0x99d3d3
// 00646bd7  64a100000000         mov eax, dword ptr fs:[0]
// 00646bdd  50                   push eax
// 00646bde  64892500000000       mov dword ptr fs:[0], esp
// 00646be5  51                   push ecx
// 00646be6  56                   push esi
// 00646be7  8bf1                 mov esi, ecx
// 00646be9  57                   push edi
// 00646bea  89742408             mov dword ptr [esp + 8], esi
// 00646bee  8d4e24               lea ecx, [esi + 0x24]
// 00646bf1  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00646bf9  c7464890aca100       mov dword ptr [esi + 0x48], 0xa1ac90
// 00646c00  ff1500a49e00         call dword ptr [0x9ea400]
// 00646c06  8b7e20               mov edi, dword ptr [esi + 0x20]
// 00646c09  c644241400           mov byte ptr [esp + 0x14], 0
// 00646c0e  85ff                 test edi, edi
// 00646c10  7410                 je 0x646c22
// 00646c12  8bcf                 mov ecx, edi
// 00646c14  e897180d00           call 0x7184b0
// 00646c19  57                   push edi
// 00646c1a  e87b0d1600           call 0x7a799a
// 00646c1f  83c404               add esp, 4
// 00646c22  8bce                 mov ecx, esi
// 00646c24  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00646c2c  e86f6e0d00           call 0x71daa0
// 00646c31  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00646c35  5f                   pop edi
// 00646c36  5e                   pop esi
// 00646c37  64890d00000000       mov dword ptr fs:[0], ecx
// 00646c3e  83c410               add esp, 0x10
// 00646c41  c3                   ret 
// copied from an identical function in another client (function ??1S@@QAE@XZ)

// from server: 100% by king_originala
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