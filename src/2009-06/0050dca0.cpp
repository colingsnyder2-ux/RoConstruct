// from server: 85% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004b0ae0  unit: RBX::Network::Replicator::NewInstanceItem  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004b0ae0
//
// 004b0ae0  6aff                 push -1
// 004b0ae2  68db987c00           push 0x7c98db
// 004b0ae7  64a100000000         mov eax, dword ptr fs:[0]
// 004b0aed  50                   push eax
// 004b0aee  64892500000000       mov dword ptr fs:[0], esp
// 004b0af5  51                   push ecx
// 004b0af6  53                   push ebx
// 004b0af7  56                   push esi
// 004b0af8  57                   push edi
// 004b0af9  8bd9                 mov ebx, ecx
// 004b0afb  6898020000           push 0x298
// 004b0b00  895c2410             mov dword ptr [esp + 0x10], ebx
// 004b0b04  e817fe1e00           call 0x6a0920
// 004b0b09  83c404               add esp, 4
// 004b0b0c  894304               mov dword ptr [ebx + 4], eax
// 004b0b0f  8d730c               lea esi, [ebx + 0xc]
// 004b0b12  8bce                 mov ecx, esi
// 004b0b14  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004b0b1c  e80fc1ffff           call 0x4acc30
// 004b0b21  85f6                 test esi, esi
// 004b0b23  7405                 je 0x4b0b2a
// 004b0b25  8d46f4               lea eax, [esi - 0xc]
// 004b0b28  eb02                 jmp 0x4b0b2c
// 004b0b2a  33c0                 xor eax, eax
// 004b0b2c  8b4004               mov eax, dword ptr [eax + 4]
// 004b0b2f  85c0                 test eax, eax
// 004b0b31  7407                 je 0x4b0b3a
// 004b0b33  0590020000           add eax, 0x290
// 004b0b38  eb02                 jmp 0x4b0b3c
// 004b0b3a  33c0                 xor eax, eax
// 004b0b3c  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004b0b40  8b11                 mov edx, dword ptr [ecx]
// 004b0b42  52                   push edx
// 004b0b43  50                   push eax
// 004b0b44  8d442428             lea eax, [esp + 0x28]
// 004b0b48  8d7e08               lea edi, [esi + 8]
// 004b0b4b  50                   push eax
// 004b0b4c  8bcf                 mov ecx, edi
// 004b0b4e  e8eda90100           call 0x4cb540
// 004b0b53  d9e8                 fld1 
// 004b0b55  8b0f                 mov ecx, dword ptr [edi]
// 004b0b57  d95e18               fstp dword ptr [esi + 0x18]
// 004b0b5a  894e20               mov dword ptr [esi + 0x20], ecx
// 004b0b5d  8bce                 mov ecx, esi
// 004b0b5f  e82c950100           call 0x4ca090
// 004b0b64  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004b0b68  5f                   pop edi
// 004b0b69  c7433000000000       mov dword ptr [ebx + 0x30], 0
// 004b0b70  5e                   pop esi
// 004b0b71  8bc3                 mov eax, ebx
// 004b0b73  5b                   pop ebx
// 004b0b74  64890d00000000       mov dword ptr fs:[0], ecx
// 004b0b7b  83c410               add esp, 0x10
// 004b0b7e  c20800               ret 8

extern "C" void* __cdecl allocate(unsigned int);

struct Storage {
    void* data;
    Storage(unsigned int);
    ~Storage();
};

__forceinline Storage::Storage(unsigned int size)
    : data(allocate(size))
{
}

struct Link {
    void* data;
    unsigned int reserved;
    void initialize(void***, void*, void*);
};

struct State {
    unsigned int prefix[2];
    Link link;
    unsigned int reserved[2];
    float scale;
    unsigned int extra;
    void* current;

    State();
    void finish();
};

struct Item {
    unsigned int prefix;
    Storage storage;
    unsigned int reserved;
    State state;
    unsigned int tail;

    Item(void**, unsigned int);
};

Item::Item(void** argument, unsigned int)
    : storage(0x298), state()
{
    State* s = &state;
    Item* owner = s ? reinterpret_cast<Item*>(
        reinterpret_cast<char*>(s) - 12) : 0;
    void* buffer = owner->storage.data;
    void* end = buffer ? reinterpret_cast<char*>(buffer) + 0x290 : 0;

    s->link.initialize(&argument, end, *argument);
    s->scale = 1.0f;
    s->current = s->link.data;
    s->finish();
    tail = 0;
}
