// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0053f470  unit: RBX::RenderBase::AggregatingSceneManager  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f470
//
// 0053f470  55                   push ebp
// 0053f471  8bec                 mov ebp, esp
// 0053f473  83ec14               sub esp, 0x14
// 0053f476  894dec               mov dword ptr [ebp - 0x14], ecx
// 0053f479  8d45f8               lea eax, [ebp - 8]
// 0053f47c  50                   push eax
// 0053f47d  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f480  83c108               add ecx, 8
// 0053f483  e8b8fc0000           call 0x54f140
// 0053f488  8d4df0               lea ecx, [ebp - 0x10]
// 0053f48b  51                   push ecx
// 0053f48c  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 0053f48f  83c108               add ecx, 8
// 0053f492  e819150000           call 0x5409b0
// 0053f497  8d55f0               lea edx, [ebp - 0x10]
// 0053f49a  52                   push edx
// 0053f49b  8d4df8               lea ecx, [ebp - 8]
// 0053f49e  e87d1a0000           call 0x540f20
// 0053f4a3  0fb6c0               movzx eax, al
// 0053f4a6  85c0                 test eax, eax
// 0053f4a8  7430                 je 0x53f4da
// 0053f4aa  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f4ad  51                   push ecx
// 0053f4ae  8d4df8               lea ecx, [ebp - 8]
// 0053f4b1  e8da190000           call 0x540e90
// 0053f4b6  83c00c               add eax, 0xc
// 0053f4b9  8bc8                 mov ecx, eax
// 0053f4bb  e8c0190000           call 0x540e80
// 0053f4c0  8bc8                 mov ecx, eax
// 0053f4c2  e819000000           call 0x53f4e0
// 0053f4c7  0fb6d0               movzx edx, al
// 0053f4ca  85d2                 test edx, edx
// 0053f4cc  7402                 je 0x53f4d0
// 0053f4ce  eb0a                 jmp 0x53f4da
// 0053f4d0  8d4df8               lea ecx, [ebp - 8]
// 0053f4d3  e8d8190000           call 0x540eb0
// 0053f4d8  ebbd                 jmp 0x53f497
// 0053f4da  8be5                 mov esp, ebp
// 0053f4dc  5d                   pop ebp
// 0053f4dd  c20400               ret 4

struct Bucket {
    bool __thiscall f(void* argument);
};

struct BucketPointer {
    Bucket* __thiscall get() const;
};

struct Node {
    unsigned char padding[12];
    BucketPointer second;
};

struct Iterator {
    int context;
    int* position;
    bool __thiscall operator!=(const Iterator& other) const;
    Node* __thiscall operator->() const;
    Iterator& __thiscall operator++();
};

struct Container {
    Iterator __thiscall begin();
    Iterator __thiscall end();
};

struct S {
    unsigned char padding[8];
    Container container;
    void __thiscall f(void* argument);
};

#pragma optimize("", off)
void S::f(void* argument)
{
    Iterator current = container.begin();
    Iterator finish = container.end();
    while (current != finish) {
        if (current->second.get()->f(argument))
            break;
        ++current;
    }
}
