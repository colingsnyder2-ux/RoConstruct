// from server: 100% by user
// roc 2008-06 0049c440  unit: RBX::Network::VPlayers::?$BoundFuncDesc  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049c440
//
// 0049c440  6aff                 push -1
// 0049c442  6819727c00           push 0x7c7219
// 0049c447  64a100000000         mov eax, dword ptr fs:[0]
// 0049c44d  50                   push eax
// 0049c44e  64892500000000       mov dword ptr fs:[0], esp
// 0049c455  83ec08               sub esp, 8
// 0049c458  57                   push edi
// 0049c459  8bf9                 mov edi, ecx
// 0049c45b  8d44241c             lea eax, [esp + 0x1c]
// 0049c45f  50                   push eax
// 0049c460  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0049c468  c70700000000         mov dword ptr [edi], 0
// 0049c46e  e87dde1600           call 0x60a2f0
// 0049c473  83c404               add esp, 4
// 0049c476  84c0                 test al, al
// 0049c478  753d                 jne 0x49c4b7
// 0049c47a  56                   push esi
// 0049c47b  6a28                 push 0x28
// 0049c47d  e89e442000           call 0x6a0920
// 0049c482  8bf0                 mov esi, eax
// 0049c484  83c404               add esp, 4
// 0049c487  89742408             mov dword ptr [esp + 8], esi
// 0049c48b  8974240c             mov dword ptr [esp + 0xc], esi
// 0049c48f  c644241801           mov byte ptr [esp + 0x18], 1
// 0049c494  85f6                 test esi, esi
// 0049c496  7413                 je 0x49c4ab
// 0049c498  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0049c49c  8d542424             lea edx, [esp + 0x24]
// 0049c4a0  890e                 mov dword ptr [esi], ecx
// 0049c4a2  8d4e04               lea ecx, [esi + 4]
// 0049c4a5  52                   push edx
// 0049c4a6  e8b5b1f7ff           call 0x417660
// 0049c4ab  897708               mov dword ptr [edi + 8], esi
// 0049c4ae  c707e0298200         mov dword ptr [edi], 0x8229e0
// 0049c4b4  5e                   pop esi
// 0049c4b5  eb06                 jmp 0x49c4bd
// 0049c4b7  c70700000000         mov dword ptr [edi], 0
// 0049c4bd  8d4c2420             lea ecx, [esp + 0x20]
// 0049c4c1  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0049c4c9  e872b2ffff           call 0x497740
// 0049c4ce  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049c4d2  8bc7                 mov eax, edi
// 0049c4d4  5f                   pop edi
// 0049c4d5  64890d00000000       mov dword ptr fs:[0], ecx
// 0049c4dc  83c414               add esp, 0x14
// 0049c4df  c22c00               ret 0x2c

typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

__forceinline void* __cdecl operator new(size_t, void* p)
{
    return p;
}

__forceinline void __cdecl operator delete(void*, void*)
{
}

struct Callback
{
    unsigned char data[36];
    Callback(const Callback&);
    ~Callback();
};

bool __cdecl func_0060a2f0(const int*);
extern unsigned char function_table;

struct CallbackHolder
{
    Callback callback;
    __forceinline CallbackHolder(const Callback& c) : callback(c) {}
};

struct Node
{
    int value;
    CallbackHolder holder;

    Node(int, const Callback&);
};

__forceinline Node::Node(int v, const Callback& c)
    : value(v), holder(c)
{
}

struct Creator
{
    const void* table;
    unsigned int reserved;
    Node* target;

    Creator(int, Callback, unsigned int);
};

Creator::Creator(int value, Callback callback, unsigned int unused)
{
    table = 0;
    if (!func_0060a2f0(&value))
    {
        Node* p = static_cast<Node*>(operator new(sizeof(Node)));
        new (p) Node(value, callback);
        target = p;
        table = &function_table;
    }
    else
    {
        table = 0;
    }
}
