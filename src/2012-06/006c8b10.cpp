// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 006c8cc0  unit: RBX::Reflection::PAVPropertyDescriptor::?$trie::depth_exceeded_exception  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c8cc0
//
// 006c8cc0  6aff                 push -1
// 006c8cc2  6833a8a900           push 0xa9a833
// 006c8cc7  64a100000000         mov eax, dword ptr fs:[0]
// 006c8ccd  50                   push eax
// 006c8cce  64892500000000       mov dword ptr fs:[0], esp
// 006c8cd5  83ec08               sub esp, 8
// 006c8cd8  33c0                 xor eax, eax
// 006c8cda  56                   push esi
// 006c8cdb  8bf1                 mov esi, ecx
// 006c8cdd  8906                 mov dword ptr [esi], eax
// 006c8cdf  894604               mov dword ptr [esi + 4], eax
// 006c8ce2  894608               mov dword ptr [esi + 8], eax
// 006c8ce5  b920000000           mov ecx, 0x20
// 006c8cea  89742408             mov dword ptr [esp + 8], esi
// 006c8cee  c7460c88010000       mov dword ptr [esi + 0xc], 0x188
// 006c8cf5  894e10               mov dword ptr [esi + 0x10], ecx
// 006c8cf8  894e14               mov dword ptr [esi + 0x14], ecx
// 006c8cfb  894618               mov dword ptr [esi + 0x18], eax
// 006c8cfe  89461c               mov dword ptr [esi + 0x1c], eax
// 006c8d01  894620               mov dword ptr [esi + 0x20], eax
// 006c8d04  89442414             mov dword ptr [esp + 0x14], eax
// 006c8d08  c7462404000000       mov dword ptr [esi + 0x24], 4
// 006c8d0f  894e28               mov dword ptr [esi + 0x28], ecx
// 006c8d12  894e2c               mov dword ptr [esi + 0x2c], ecx
// 006c8d15  b801000000           mov eax, 1
// 006c8d1a  88442414             mov byte ptr [esp + 0x14], al
// 006c8d1e  89442404             mov dword ptr [esp + 4], eax
// 006c8d22  8d442404             lea eax, [esp + 4]
// 006c8d26  50                   push eax
// 006c8d27  8bce                 mov ecx, esi
// 006c8d29  e822fcffff           call 0x6c8950
// 006c8d2e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006c8d32  894630               mov dword ptr [esi + 0x30], eax
// 006c8d35  8bc6                 mov eax, esi
// 006c8d37  5e                   pop esi
// 006c8d38  64890d00000000       mov dword ptr fs:[0], ecx
// 006c8d3f  83c414               add esp, 0x14
// 006c8d42  c3                   ret 

struct Storage {
    void* first;
    Storage() : first(0) {}
};

struct PODptr {
    char* ptr;
    unsigned sz;
    PODptr(char* nptr, unsigned nsize) : ptr(nptr), sz(nsize) {}
};

struct Pool : Storage {
    PODptr list;
    unsigned requested_size;
    unsigned next_size;
    unsigned start_size;
    explicit Pool(unsigned nrequested_size, unsigned nnext_size = 32)
        : list(0, 0), requested_size(nrequested_size),
          next_size(nnext_size), start_size(nnext_size) {}
    ~Pool();
};

struct Node;

struct Trie {
    Pool node_pool;
    Pool data_pool;
    Node* root;
    Trie();
    Node* create_node(const int& depth);
};

Trie::Trie()
    : node_pool(0x188), data_pool(4), root(create_node(1))
{
}
