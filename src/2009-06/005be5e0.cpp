// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0053f6a0  unit: RBX::RenderBase::AggregatingSceneManager  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f6a0
//
// 0053f6a0  55                   push ebp
// 0053f6a1  8bec                 mov ebp, esp
// 0053f6a3  83ec14               sub esp, 0x14
// 0053f6a6  894dec               mov dword ptr [ebp - 0x14], ecx
// 0053f6a9  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f6ac  83c128               add ecx, 0x28
// 0053f6af  e8ac160000           call 0x540d60
// 0053f6b4  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f6b7  83c148               add ecx, 0x48
// 0053f6ba  e8a1160000           call 0x540d60
// 0053f6bf  8d45f8               lea eax, [ebp - 8]
// 0053f6c2  50                   push eax
// 0053f6c3  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f6c6  83c108               add ecx, 8
// 0053f6c9  e872fa0000           call 0x54f140
// 0053f6ce  8d4df0               lea ecx, [ebp - 0x10]
// 0053f6d1  51                   push ecx
// 0053f6d2  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f6d5  83c108               add ecx, 8
// 0053f6d8  e8d3120000           call 0x5409b0
// 0053f6dd  8d55f0               lea edx, [ebp - 0x10]
// 0053f6e0  52                   push edx
// 0053f6e1  8d4df8               lea ecx, [ebp - 8]
// 0053f6e4  e837180000           call 0x540f20
// 0053f6e9  0fb6c0               movzx eax, al
// 0053f6ec  85c0                 test eax, eax
// 0053f6ee  7423                 je 0x53f713
// 0053f6f0  8d4df8               lea ecx, [ebp - 8]
// 0053f6f3  e898170000           call 0x540e90
// 0053f6f8  83c00c               add eax, 0xc
// 0053f6fb  8bc8                 mov ecx, eax
// 0053f6fd  e87e170000           call 0x540e80
// 0053f702  8bc8                 mov ecx, eax
// 0053f704  e8a70d0000           call 0x5404b0
// 0053f709  8d4df8               lea ecx, [ebp - 8]
// 0053f70c  e89f170000           call 0x540eb0
// 0053f711  ebca                 jmp 0x53f6dd
// 0053f713  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f716  e8f58bf9ff           call 0x4d8310
// 0053f71b  8be5                 mov esp, ebp
// 0053f71d  5d                   pop ebp
// 0053f71e  c3                   ret 

#pragma optimize("", off)

struct Queue {
    void process(int, int);
};

struct Scene {
    char pad[8];
    Queue queue;
};

struct SimpleSceneManager {
    void* vtbl;
    Scene* scene;
    void process();
};

struct B {
    void f();
};

struct Item {
    char pad[12];
    B b;
    void g();
};

struct Handle {
    Item* get();
};

struct Node {
    char pad[12];
    Handle handle;
};

struct Iterator {
    unsigned int value;
    void* owner;
    bool different(Iterator*);
    Node* dereference();
    void advance();
};

struct Container {
    char pad[24];
    unsigned int value;
    unsigned int reserved;
    Iterator* begin(Iterator*);
    Iterator* end(Iterator*);
};

struct VChunk {
    char pad[8];
};

struct Slots {
    char pad[24];
    VChunk* chunk;
    int count;
    VChunk** slot();
};

struct Manager : SimpleSceneManager {
    Container container;
    Slots first;
    Slots second;
    void process();
};

void Manager::process()
{
    first.slot();
    second.slot();

    Iterator current;
    Iterator finish;
    container.begin(&current);
    container.end(&finish);

    while (current.different(&finish)) {
        current.dereference()->handle.get()->g();
        current.advance();
    }

    SimpleSceneManager::process();
}
