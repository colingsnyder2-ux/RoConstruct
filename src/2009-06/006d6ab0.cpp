// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e5c90  unit: RBX::JointsService  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e5c90
//
// 005e5c90  56                   push esi
// 005e5c91  8bf1                 mov esi, ecx
// 005e5c93  8b4610               mov eax, dword ptr [esi + 0x10]
// 005e5c96  8b88a0000000         mov ecx, dword ptr [eax + 0xa0]
// 005e5c9c  8b4114               mov eax, dword ptr [ecx + 0x14]
// 005e5c9f  8b560c               mov edx, dword ptr [esi + 0xc]
// 005e5ca2  33c9                 xor ecx, ecx
// 005e5ca4  3b82a0000000         cmp eax, dword ptr [edx + 0xa0]
// 005e5caa  0f95c1               setne cl
// 005e5cad  8bc1                 mov eax, ecx
// 005e5caf  83f801               cmp eax, 1
// 005e5cb2  7505                 jne 0x5e5cb9
// 005e5cb4  8d4e28               lea ecx, [esi + 0x28]
// 005e5cb7  eb0a                 jmp 0x5e5cc3
// 005e5cb9  85c0                 test eax, eax
// 005e5cbb  8d4e58               lea ecx, [esi + 0x58]
// 005e5cbe  8d4628               lea eax, [esi + 0x28]
// 005e5cc1  7403                 je 0x5e5cc6
// 005e5cc3  8d4658               lea eax, [esi + 0x58]
// 005e5cc6  51                   push ecx
// 005e5cc7  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 005e5ccd  50                   push eax
// 005e5cce  e8cde00200           call 0x613da0
// 005e5cd3  d9868c000000         fld dword ptr [esi + 0x8c]
// 005e5cd9  8b8e88000000         mov ecx, dword ptr [esi + 0x88]
// 005e5cdf  d999cc000000         fstp dword ptr [ecx + 0xcc]
// 005e5ce5  e8c6df0200           call 0x613cb0
// 005e5cea  8b8688000000         mov eax, dword ptr [esi + 0x88]
// 005e5cf0  5e                   pop esi
// 005e5cf1  c3                   ret 

struct Frame {
    char data[0x30];
};

struct NodeData {
    char padding[0x14];
    NodeData* owner;
};

struct Node {
    char padding[0xa0];
    NodeData* data;
};

struct Pair {
    char padding[0xcc];
    float value;

    void set(const Frame& first, const Frame& second);
    void f();
};

struct S {
    char padding0[0x0c];
    Node* first;
    Node* second;
    char padding1[0x14];
    Frame frame0;
    Frame frame1;
    Pair* pair;
    float value;

    Pair* f();
};

Pair* S::f()
{
    int reversed = second->data->owner != first->data;
    pair->set(reversed == 0 ? frame0 : frame1,
              reversed == 1 ? frame0 : frame1);
    Pair* p = pair;
    p->value = value;
    p->f();
    return pair;
}
