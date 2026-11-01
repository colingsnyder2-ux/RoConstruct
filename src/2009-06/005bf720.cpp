// from server: 100% by EspClaude
// from server: 75% by EspClaude
// roc 2009-06 005bf720  unit: RBX::AggregatingSceneManager::Bucket  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf720
//
// 005bf720  55                   push ebp
// 005bf721  8bec                 mov ebp, esp
// 005bf723  6aff                 push -1
// 005bf725  68201e8600           push 0x861e20
// 005bf72a  64a100000000         mov eax, dword ptr fs:[0]
// 005bf730  50                   push eax
// 005bf731  64892500000000       mov dword ptr fs:[0], esp
// 005bf738  83ec48               sub esp, 0x48
// 005bf73b  894dbc               mov dword ptr [ebp - 0x44], ecx
// 005bf73e  8b4508               mov eax, dword ptr [ebp + 8]
// 005bf741  50                   push eax
// 005bf742  8d4dec               lea ecx, [ebp - 0x14]
// 005bf745  51                   push ecx
// 005bf746  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 005bf749  e8e2110000           call 0x5c0930
// 005bf74e  8d55e4               lea edx, [ebp - 0x1c]
// 005bf751  52                   push edx
// 005bf752  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 005bf755  e8d64cffff           call 0x5b4430
// 005bf75a  50                   push eax
// 005bf75b  8d4dec               lea ecx, [ebp - 0x14]
// 005bf75e  e83d1d0000           call 0x5c14a0
// 005bf763  0fb6c0               movzx eax, al
// 005bf766  85c0                 test eax, eax
// 005bf768  7528                 jne 0x5bf792
// 005bf76a  8d4dec               lea ecx, [ebp - 0x14]
// 005bf76d  e8bec5feff           call 0x5abd30
// 005bf772  50                   push eax
// 005bf773  e898cffeff           call 0x5ac710
// 005bf778  83c404               add esp, 4
// 005bf77b  50                   push eax
// 005bf77c  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005bf77f  51                   push ecx
// 005bf780  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 005bf783  83c108               add ecx, 8
// 005bf786  e8a5120000           call 0x5c0a30
// 005bf78b  0fb6d0               movzx edx, al
// 005bf78e  85d2                 test edx, edx
// 005bf790  747f                 je 0x5bf811
// 005bf792  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005bf795  8945c8               mov dword ptr [ebp - 0x38], eax
// 005bf798  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 005bf79b  894dcc               mov dword ptr [ebp - 0x34], ecx
// 005bf79e  8d4dd0               lea ecx, [ebp - 0x30]
// 005bf7a1  e85afffeff           call 0x5af700
// 005bf7a6  8945b8               mov dword ptr [ebp - 0x48], eax
// 005bf7a9  8b55b8               mov edx, dword ptr [ebp - 0x48]
// 005bf7ac  8955b4               mov dword ptr [ebp - 0x4c], edx
// 005bf7af  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005bf7b6  8b45b4               mov eax, dword ptr [ebp - 0x4c]
// 005bf7b9  50                   push eax
// 005bf7ba  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005bf7bd  51                   push ecx
// 005bf7be  8d4dd4               lea ecx, [ebp - 0x2c]
// 005bf7c1  e8ca1a0000           call 0x5c1290
// 005bf7c6  8945b0               mov dword ptr [ebp - 0x50], eax
// 005bf7c9  8b55b0               mov edx, dword ptr [ebp - 0x50]
// 005bf7cc  8955ac               mov dword ptr [ebp - 0x54], edx
// 005bf7cf  c645fc01             mov byte ptr [ebp - 4], 1
// 005bf7d3  8b45ac               mov eax, dword ptr [ebp - 0x54]
// 005bf7d6  50                   push eax
// 005bf7d7  8b4dcc               mov ecx, dword ptr [ebp - 0x34]
// 005bf7da  51                   push ecx
// 005bf7db  8b55c8               mov edx, dword ptr [ebp - 0x38]
// 005bf7de  52                   push edx
// 005bf7df  8d45c0               lea eax, [ebp - 0x40]
// 005bf7e2  50                   push eax
// 005bf7e3  8b4dbc               mov ecx, dword ptr [ebp - 0x44]
// 005bf7e6  e8250b0000           call 0x5c0310
// 005bf7eb  8b08                 mov ecx, dword ptr [eax]
// 005bf7ed  8b5004               mov edx, dword ptr [eax + 4]
// 005bf7f0  894dec               mov dword ptr [ebp - 0x14], ecx
// 005bf7f3  8955f0               mov dword ptr [ebp - 0x10], edx
// 005bf7f6  c645fc00             mov byte ptr [ebp - 4], 0
// 005bf7fa  8d4dd4               lea ecx, [ebp - 0x2c]
// 005bf7fd  e8ae070000           call 0x5bffb0
// 005bf802  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005bf809  8d4dd0               lea ecx, [ebp - 0x30]
// 005bf80c  e83f040000           call 0x5bfc50
// 005bf811  8d4dec               lea ecx, [ebp - 0x14]
// 005bf814  e837d6feff           call 0x5ace50
// 005bf819  83c00c               add eax, 0xc
// 005bf81c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bf81f  64890d00000000       mov dword ptr fs:[0], ecx
// 005bf826  8be5                 mov esp, ebp
// 005bf828  5d                   pop ebp
// 005bf829  c20400               ret 4

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#pragma optimize("", off)

struct Node;

struct Iterator {
    void* container;
    void* current;

    bool equal(const Iterator& other) const;
    Node* position() const;
    Node* node() const;
};

struct Temporary {
    unsigned int value;

    Temporary();
    ~Temporary();
};

struct Entry {
    unsigned int data[4];

    Entry(const unsigned int& key, const Temporary& value);
    ~Entry();
};

struct Filter {
    bool accept(const unsigned int& key, unsigned int value);
};

extern "C" unsigned int __cdecl classify(Node* node);

struct Bucket {
    unsigned char padding[8];
    Filter filter;

    Iterator find(const unsigned int& key);
    Iterator end();
    Iterator insert(Iterator hint, const Entry& value);
    void* f(const unsigned int& key);
};

void* Bucket::f(const unsigned int& key)
{
    Iterator it = find(key);
    if (it.equal(end()) || filter.accept(key, classify(it.position()))) {
        it = insert(Iterator(it), Entry(key, Temporary()));
    }
    return reinterpret_cast<unsigned char*>(it.node()) + 12;
}
