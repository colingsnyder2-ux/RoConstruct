// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 005bf110  unit: RBX::AggregatingSceneManager  size: 295 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf110
//
// 005bf110  55                   push ebp
// 005bf111  8bec                 mov ebp, esp
// 005bf113  6aff                 push -1
// 005bf115  68ca1d8600           push 0x861dca
// 005bf11a  64a100000000         mov eax, dword ptr fs:[0]
// 005bf120  50                   push eax
// 005bf121  64892500000000       mov dword ptr fs:[0], esp
// 005bf128  83ec20               sub esp, 0x20
// 005bf12b  894dd4               mov dword ptr [ebp - 0x2c], ecx
// 005bf12e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005bf135  8d45ec               lea eax, [ebp - 0x14]
// 005bf138  50                   push eax
// 005bf139  8d4d08               lea ecx, [ebp + 8]
// 005bf13c  e8dfd3ffff           call 0x5bc520
// 005bf141  05e8000000           add eax, 0xe8
// 005bf146  8bc8                 mov ecx, eax
// 005bf148  e8235e0000           call 0x5c4f70
// 005bf14d  8d4de4               lea ecx, [ebp - 0x1c]
// 005bf150  51                   push ecx
// 005bf151  8d4d08               lea ecx, [ebp + 8]
// 005bf154  e8c7d3ffff           call 0x5bc520
// 005bf159  05e8000000           add eax, 0xe8
// 005bf15e  8bc8                 mov ecx, eax
// 005bf160  e83b5e0000           call 0x5c4fa0
// 005bf165  8d55e4               lea edx, [ebp - 0x1c]
// 005bf168  52                   push edx
// 005bf169  8d4dec               lea ecx, [ebp - 0x14]
// 005bf16c  e8cf0c0000           call 0x5bfe40
// 005bf171  0fb6c0               movzx eax, al
// 005bf174  85c0                 test eax, eax
// 005bf176  7464                 je 0x5bf1dc
// 005bf178  8d4dec               lea ecx, [ebp - 0x14]
// 005bf17b  e8500b0000           call 0x5bfcd0
// 005bf180  8945e0               mov dword ptr [ebp - 0x20], eax
// 005bf183  6a00                 push 0
// 005bf185  8d4ddc               lea ecx, [ebp - 0x24]
// 005bf188  e89380f5ff           call 0x517220
// 005bf18d  c645fc01             mov byte ptr [ebp - 4], 1
// 005bf191  8d4ddc               lea ecx, [ebp - 0x24]
// 005bf194  51                   push ecx
// 005bf195  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005bf198  e8c3b0f1ff           call 0x4da260
// 005bf19d  83c018               add eax, 0x18
// 005bf1a0  8bc8                 mov ecx, eax
// 005bf1a2  e8a9030000           call 0x5bf550
// 005bf1a7  c645fc00             mov byte ptr [ebp - 4], 0
// 005bf1ab  8d4ddc               lea ecx, [ebp - 0x24]
// 005bf1ae  e8addfedff           call 0x49d160
// 005bf1b3  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 005bf1b6  52                   push edx
// 005bf1b7  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005bf1ba  e89171f6ff           call 0x526350
// 005bf1bf  6a01                 push 1
// 005bf1c1  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 005bf1c4  50                   push eax
// 005bf1c5  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005bf1c8  8b11                 mov edx, dword ptr [ecx]
// 005bf1ca  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005bf1cd  8b4210               mov eax, dword ptr [edx + 0x10]
// 005bf1d0  ffd0                 call eax
// 005bf1d2  8d4dec               lea ecx, [ebp - 0x14]
// 005bf1d5  e8160b0000           call 0x5bfcf0
// 005bf1da  eb89                 jmp 0x5bf165
// 005bf1dc  8d4d08               lea ecx, [ebp + 8]
// 005bf1df  51                   push ecx
// 005bf1e0  8d4dd8               lea ecx, [ebp - 0x28]
// 005bf1e3  e8d8670000           call 0x5c59c0
// 005bf1e8  c645fc02             mov byte ptr [ebp - 4], 2
// 005bf1ec  8d55d8               lea edx, [ebp - 0x28]
// 005bf1ef  52                   push edx
// 005bf1f0  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 005bf1f3  e86871f6ff           call 0x526360
// 005bf1f8  c645fc00             mov byte ptr [ebp - 4], 0
// 005bf1fc  8d4dd8               lea ecx, [ebp - 0x28]
// 005bf1ff  e85cdfedff           call 0x49d160
// 005bf204  8d4d08               lea ecx, [ebp + 8]
// 005bf207  e814d3ffff           call 0x5bc520
// 005bf20c  05e8000000           add eax, 0xe8
// 005bf211  8bc8                 mov ecx, eax
// 005bf213  e858040000           call 0x5bf670
// 005bf218  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005bf21f  8d4d08               lea ecx, [ebp + 8]
// 005bf222  e839dfedff           call 0x49d160
// 005bf227  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bf22a  64890d00000000       mov dword ptr fs:[0], ecx
// 005bf231  8be5                 mov esp, ebp
// 005bf233  5d                   pop ebp
// 005bf234  c20400               ret 4

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#pragma optimize("", off)

struct Node;
struct Object;
struct State;

struct Handle {
    void* value;
    Handle(int);
    Handle(const Handle&);
    ~Handle();
    Object* get();
};

struct Iterator {
    unsigned int data[2];
    bool operator!=(const Iterator&) const;
    Node* operator*() const;
    Iterator& operator++();
};

struct Collection {
    Iterator begin();
    Iterator end();
    void clear();
};

struct Object {
    char padding[0xe8];
    Collection collection;
};

struct State {
    int get();
};

struct NodeData {
    char padding[0x18];
    State state;
};

struct Node {
    NodeData* get(Handle*);
};

extern int nodeCount;

struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void destroy(Node*, bool);
    void flush(Node*);
    void remove(Handle*);
    void process(Handle);
};

void Manager::process(Handle object)
{
    Iterator first = object.get()->collection.begin();
    Iterator last = object.get()->collection.end();

    while (first != last) {
        Node* node = *first;
        {
            Handle handle(0);
            node->get(&handle)->state.get();
        }
        flush(node);
        destroy(node, true);
        ++first;
    }

    {
        Handle handle(object);
        remove(&handle);
    }

    object.get()->collection.clear();
}
