// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00694cd0  unit: RBX::Soundscape::VSoundId::?$TypedPropertyDescriptor  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00694cd0
//
// 00694cd0  b801000000           mov eax, 1
// 00694cd5  56                   push esi
// 00694cd6  8bf1                 mov esi, ecx
// 00694cd8  8405d0c5e200         test byte ptr [0xe2c5d0], al
// 00694cde  7531                 jne 0x694d11
// 00694ce0  0905d0c5e200         or dword ptr [0xe2c5d0], eax
// 00694ce6  68c05db100           push 0xb15dc0
// 00694ceb  c705c4c5e20078c0d900 mov dword ptr [0xe2c5c4], 0xd9c078
// 00694cf5  c705ccc5e200d0085700 mov dword ptr [0xe2c5cc], 0x5708d0
// 00694cff  c705c8c5e20090a75900 mov dword ptr [0xe2c5c8], 0x59a790
// 00694d09  e8e7e42e00           call 0x9831f5
// 00694d0e  83c404               add esp, 4
// 00694d11  8b06                 mov eax, dword ptr [esi]
// 00694d13  3dc4c5e200           cmp eax, 0xe2c5c4
// 00694d18  750f                 jne 0x694d29
// 00694d1a  8b442408             mov eax, dword ptr [esp + 8]
// 00694d1e  8b08                 mov ecx, dword ptr [eax]
// 00694d20  894e04               mov dword ptr [esi + 4], ecx
// 00694d23  8bc6                 mov eax, esi
// 00694d25  5e                   pop esi
// 00694d26  c20400               ret 4
// 00694d29  85c0                 test eax, eax
// 00694d2b  7412                 je 0x694d3f
// 00694d2d  8b4004               mov eax, dword ptr [eax + 4]
// 00694d30  8d5604               lea edx, [esi + 4]
// 00694d33  52                   push edx
// 00694d34  ffd0                 call eax
// 00694d36  83c404               add esp, 4
// 00694d39  c70600000000         mov dword ptr [esi], 0
// 00694d3f  8d4604               lea eax, [esi + 4]
// 00694d42  85c0                 test eax, eax
// 00694d44  7408                 je 0x694d4e
// 00694d46  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00694d4a  8b11                 mov edx, dword ptr [ecx]
// 00694d4c  8910                 mov dword ptr [eax], edx
// 00694d4e  c706c4c5e200         mov dword ptr [esi], 0xe2c5c4
// 00694d54  8bc6                 mov eax, esi
// 00694d56  5e                   pop esi
// 00694d57  c20400               ret 4

inline void* operator new(unsigned int, void* p) throw() { return p; }

void destroy_fn(void* p);
void clone_fn(void* p);

struct Table {
    void (*destroy)(void*);
    void (*clone)(void*);
    Table() {
        clone = clone_fn;
        destroy = destroy_fn;
    }
    virtual ~Table();
};

struct Holder {
    Table* table;
    int object;
    Holder& assign(const int& x);
};

Holder& Holder::assign(const int& x) {
    static Table t;
    if (table == &t) {
        object = x;
        return *this;
    }
    if (table) {
        table->destroy(&object);
        table = 0;
    }
    new (&object) int(x);
    table = &t;
    return *this;
}
