// from server: 95% by EspClaude
// from server: 100% by colin
// roc 2008-06 0041cb30  unit: VDHTMLWindowService::?$FactoryProduct  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041cb30
//
// 0041cb30  6aff                 push -1
// 0041cb32  6810e27b00           push 0x7be210
// 0041cb37  64a100000000         mov eax, dword ptr fs:[0]
// 0041cb3d  50                   push eax
// 0041cb3e  64892500000000       mov dword ptr fs:[0], esp
// 0041cb45  83ec08               sub esp, 8
// 0041cb48  53                   push ebx
// 0041cb49  55                   push ebp
// 0041cb4a  56                   push esi
// 0041cb4b  57                   push edi
// 0041cb4c  8bf1                 mov esi, ecx
// 0041cb4e  83ec20               sub esp, 0x20
// 0041cb51  89642430             mov dword ptr [esp + 0x30], esp
// 0041cb55  8bdc                 mov ebx, esp
// 0041cb57  6a00                 push 0
// 0041cb59  83ec38               sub esp, 0x38
// 0041cb5c  8964246c             mov dword ptr [esp + 0x6c], esp
// 0041cb60  8bec                 mov ebp, esp
// 0041cb62  83ec24               sub esp, 0x24
// 0041cb65  8d8424a8000000       lea eax, [esp + 0xa8]
// 0041cb6c  8bcc                 mov ecx, esp
// 0041cb6e  89a42490000000       mov dword ptr [esp + 0x90], esp
// 0041cb75  50                   push eax
// 0041cb76  c78424a400000000000000 mov dword ptr [esp + 0xa4], 0
// 0041cb81  bf407b4100           mov edi, 0x417b40
// 0041cb86  e855791700           call 0x5944e0
// 0041cb8b  83ec08               sub esp, 8
// 0041cb8e  8bcc                 mov ecx, esp
// 0041cb90  89a4249c000000       mov dword ptr [esp + 0x9c], esp
// 0041cb97  56                   push esi
// 0041cb98  51                   push ecx
// 0041cb99  c68424b000000001     mov byte ptr [esp + 0xb0], 1
// 0041cba1  e89abe1f00           call 0x618a40
// 0041cba6  83c408               add esp, 8
// 0041cba9  33c0                 xor eax, eax
// 0041cbab  50                   push eax
// 0041cbac  57                   push edi
// 0041cbad  55                   push ebp
// 0041cbae  888424b4000000       mov byte ptr [esp + 0xb4], al
// 0041cbb5  e846c8ffff           call 0x419400
// 0041cbba  83c438               add esp, 0x38
// 0041cbbd  8bcb                 mov ecx, ebx
// 0041cbbf  e89cfcffff           call 0x41c860
// 0041cbc4  8b0d4ccc9600         mov ecx, dword ptr [0x96cc4c]
// 0041cbca  e861d9ffff           call 0x41a530
// 0041cbcf  8d4c2428             lea ecx, [esp + 0x28]
// 0041cbd3  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0041cbdb  e890781700           call 0x594470
// 0041cbe0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041cbe4  5f                   pop edi
// 0041cbe5  5e                   pop esi
// 0041cbe6  5d                   pop ebp
// 0041cbe7  64890d00000000       mov dword ptr fs:[0], ecx
// 0041cbee  5b                   pop ebx
// 0041cbef  83c414               add esp, 0x14
// 0041cbf2  c22400               ret 0x24

// from server: 91% by colin
// roc-lang: cpp
// roc-cl: 50727







struct Service;

struct FunctionRef {
    unsigned char data[0x24];
    FunctionRef(const FunctionRef&);
    ~FunctionRef();
};

struct Shared {
    void* object;
    void* control;
    Shared(const Shared&);
};

Shared __cdecl getShared(Service*);

struct Callback {
    void (__cdecl *function)();
    int adjustment;
};

void __cdecl callback();

struct Bind {
    unsigned char data[56];
    Bind(const Bind&);
};

Bind __cdecl makeBind(Callback, Shared, FunctionRef);

struct FunctionTable {
    void (__cdecl *manager)(void*, void*, int);
};

struct Function {
    FunctionTable* table;
    unsigned int reserved;
    unsigned int storage[6];
    Function(const Function&);
    Function(Bind, int);
};

struct Queue {
    void append(Function);
};

extern Queue* queue;

struct Service {
    void submit(FunctionRef);
};

void Service::submit(FunctionRef text)
{
    Callback target = { callback, 0 };
    queue->append(Function(makeBind(target, getShared(this), text), 0));
}
