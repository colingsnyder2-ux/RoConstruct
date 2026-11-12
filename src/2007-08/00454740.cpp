// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00454740  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454740
//
// 00454740  6aff                 push -1
// 00454742  68d6157400           push 0x7415d6
// 00454747  64a100000000         mov eax, dword ptr fs:[0]
// 0045474d  50                   push eax
// 0045474e  51                   push ecx
// 0045474f  53                   push ebx
// 00454750  55                   push ebp
// 00454751  56                   push esi
// 00454752  57                   push edi
// 00454753  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454758  33c4                 xor eax, esp
// 0045475a  50                   push eax
// 0045475b  8d442418             lea eax, [esp + 0x18]
// 0045475f  64a300000000         mov dword ptr fs:[0], eax
// 00454765  8bf1                 mov esi, ecx
// 00454767  89742414             mov dword ptr [esp + 0x14], esi
// 0045476b  e880d81f00           call 0x651ff0
// 00454770  8dbecc020000         lea edi, [esi + 0x2cc]
// 00454776  33ed                 xor ebp, ebp
// 00454778  8bcf                 mov ecx, edi
// 0045477a  896c2420             mov dword ptr [esp + 0x20], ebp
// 0045477e  e85df8ffff           call 0x453fe0
// 00454783  8d9ee8020000         lea ebx, [esi + 0x2e8]
// 00454789  8bcb                 mov ecx, ebx
// 0045478b  c644242001           mov byte ptr [esp + 0x20], 1
// 00454790  e8bbf8ffff           call 0x454050
// 00454795  c70624227900         mov dword ptr [esi], 0x792224
// 0045479b  c70710227900         mov dword ptr [edi], 0x792210
// 004547a1  c703fc217900         mov dword ptr [ebx], 0x7921fc
// 004547a7  89ae04030000         mov dword ptr [esi + 0x304], ebp
// 004547ad  89ae08030000         mov dword ptr [esi + 0x308], ebp
// 004547b3  89ae0c030000         mov dword ptr [esi + 0x30c], ebp
// 004547b9  89ae10030000         mov dword ptr [esi + 0x310], ebp
// 004547bf  89ae14030000         mov dword ptr [esi + 0x314], ebp
// 004547c5  8bc6                 mov eax, esi
// 004547c7  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004547cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004547d2  59                   pop ecx
// 004547d3  5f                   pop edi
// 004547d4  5e                   pop esi
// 004547d5  5d                   pop ebp
// 004547d6  5b                   pop ebx
// 004547d7  83c410               add esp, 0x10
// 004547da  c3                   ret 
struct Root
{
    char storage[0x2c8];

    Root();
    virtual ~Root();
};

struct ListenerA
{
    char storage[0x18];

    ListenerA();
    virtual ~ListenerA();
};

struct ListenerB
{
    char storage[0x18];

    ListenerB();
    virtual ~ListenerB();
};

struct S : Root, ListenerA, ListenerB
{
    int field304;
    int field308;
    int field30c;
    int field310;
    int field314;

    S();
    virtual ~S();
};

S::S() : field304(0), field308(0), field30c(0), field310(0), field314(0)
{
}
