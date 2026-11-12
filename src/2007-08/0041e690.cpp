// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 0041e690  unit: RBX::VInstance::?$MarshaledListener::EventData  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041e690
//
// 0041e690  6aff                 push -1
// 0041e692  68a6b87300           push 0x73b8a6
// 0041e697  64a100000000         mov eax, dword ptr fs:[0]
// 0041e69d  50                   push eax
// 0041e69e  51                   push ecx
// 0041e69f  53                   push ebx
// 0041e6a0  55                   push ebp
// 0041e6a1  56                   push esi
// 0041e6a2  57                   push edi
// 0041e6a3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041e6a8  33c4                 xor eax, esp
// 0041e6aa  50                   push eax
// 0041e6ab  8d442418             lea eax, [esp + 0x18]
// 0041e6af  64a300000000         mov dword ptr fs:[0], eax
// 0041e6b5  8bf1                 mov esi, ecx
// 0041e6b7  89742414             mov dword ptr [esp + 0x14], esi
// 0041e6bb  e830392300           call 0x651ff0
// 0041e6c0  8dbecc020000         lea edi, [esi + 0x2cc]
// 0041e6c6  33db                 xor ebx, ebx
// 0041e6c8  8bcf                 mov ecx, edi
// 0041e6ca  895c2420             mov dword ptr [esp + 0x20], ebx
// 0041e6ce  e87df9ffff           call 0x41e050
// 0041e6d3  8daee8020000         lea ebp, [esi + 0x2e8]
// 0041e6d9  8bcd                 mov ecx, ebp
// 0041e6db  c644242001           mov byte ptr [esp + 0x20], 1
// 0041e6e0  e83bfaffff           call 0x41e120
// 0041e6e5  c706cc7f7800         mov dword ptr [esi], 0x787fcc
// 0041e6eb  c707b47f7800         mov dword ptr [edi], 0x787fb4
// 0041e6f1  c74500a07f7800       mov dword ptr [ebp], 0x787fa0
// 0041e6f8  899e04030000         mov dword ptr [esi + 0x304], ebx
// 0041e6fe  899e08030000         mov dword ptr [esi + 0x308], ebx
// 0041e704  889e0c030000         mov byte ptr [esi + 0x30c], bl
// 0041e70a  8bc6                 mov eax, esi
// 0041e70c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041e710  64890d00000000       mov dword ptr fs:[0], ecx
// 0041e717  59                   pop ecx
// 0041e718  5f                   pop edi
// 0041e719  5e                   pop esi
// 0041e71a  5d                   pop ebp
// 0041e71b  5b                   pop ebx
// 0041e71c  83c410               add esp, 0x10
// 0041e71f  c3                   ret 
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
    bool field30c;

    S();
    virtual ~S();
};

S::S() : field304(0), field308(0), field30c(false)
{
}
