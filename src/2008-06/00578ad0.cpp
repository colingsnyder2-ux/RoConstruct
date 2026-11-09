// from server: 100% by colin
// from server: 99% by colin
// roc 2008-06 00578ad0  unit: RBX::VTool::?$FactoryProduct::Creator  size: 162 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00578ad0
//
// 00578ad0  6aff                 push -1
// 00578ad2  6889087d00           push 0x7d0889
// 00578ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00578add  50                   push eax
// 00578ade  64892500000000       mov dword ptr fs:[0], esp
// 00578ae5  83ec08               sub esp, 8
// 00578ae8  57                   push edi
// 00578ae9  8bf9                 mov edi, ecx
// 00578aeb  8d44241c             lea eax, [esp + 0x1c]
// 00578aef  50                   push eax
// 00578af0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00578af8  c70700000000         mov dword ptr [edi], 0
// 00578afe  e8ed170900           call 0x60a2f0
// 00578b03  83c404               add esp, 4
// 00578b06  84c0                 test al, al
// 00578b08  753d                 jne 0x578b47
// 00578b0a  56                   push esi
// 00578b0b  6a3c                 push 0x3c
// 00578b0d  e80e7e1200           call 0x6a0920
// 00578b12  8bf0                 mov esi, eax
// 00578b14  83c404               add esp, 4
// 00578b17  89742408             mov dword ptr [esp + 8], esi
// 00578b1b  8974240c             mov dword ptr [esp + 0xc], esi
// 00578b1f  c644241801           mov byte ptr [esp + 0x18], 1
// 00578b24  85f6                 test esi, esi
// 00578b26  7413                 je 0x578b3b
// 00578b28  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00578b2c  8d542424             lea edx, [esp + 0x24]
// 00578b30  890e                 mov dword ptr [esi], ecx
// 00578b32  8d4e04               lea ecx, [esi + 4]
// 00578b35  52                   push edx
// 00578b36  e8d5d9ffff           call 0x576510
// 00578b3b  897708               mov dword ptr [edi + 8], esi
// 00578b3e  c70740008300         mov dword ptr [edi], 0x830040
// 00578b44  5e                   pop esi
// 00578b45  eb06                 jmp 0x578b4d
// 00578b47  c70700000000         mov dword ptr [edi], 0
// 00578b4d  8d4c2420             lea ecx, [esp + 0x20]
// 00578b51  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00578b59  e8a2cbffff           call 0x575700
// 00578b5e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00578b62  8bc7                 mov eax, edi
// 00578b64  5f                   pop edi
// 00578b65  64890d00000000       mov dword ptr fs:[0], ecx
// 00578b6c  83c414               add esp, 0x14
// 00578b6f  c24000               ret 0x40

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
    unsigned char data[56];
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
