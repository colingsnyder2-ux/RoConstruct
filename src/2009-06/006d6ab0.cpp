// from server: 100% by EspClaude
// from server: 86% by EspClaude
// roc 2009-06 006d6ab0  unit: RBX::MotorJoint  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d6ab0
//
// 006d6ab0  56                   push esi
// 006d6ab1  8bf1                 mov esi, ecx
// 006d6ab3  8b4614               mov eax, dword ptr [esi + 0x14]
// 006d6ab6  8b88e4000000         mov ecx, dword ptr [eax + 0xe4]
// 006d6abc  8b4104               mov eax, dword ptr [ecx + 4]
// 006d6abf  8b5610               mov edx, dword ptr [esi + 0x10]
// 006d6ac2  33c9                 xor ecx, ecx
// 006d6ac4  3b82e4000000         cmp eax, dword ptr [edx + 0xe4]
// 006d6aca  0f95c1               setne cl
// 006d6acd  8bc1                 mov eax, ecx
// 006d6acf  83f801               cmp eax, 1
// 006d6ad2  7505                 jne 0x6d6ad9
// 006d6ad4  8d4e38               lea ecx, [esi + 0x38]
// 006d6ad7  eb0a                 jmp 0x6d6ae3
// 006d6ad9  85c0                 test eax, eax
// 006d6adb  8d4e68               lea ecx, [esi + 0x68]
// 006d6ade  8d4638               lea eax, [esi + 0x38]
// 006d6ae1  7403                 je 0x6d6ae6
// 006d6ae3  8d4668               lea eax, [esi + 0x68]
// 006d6ae6  51                   push ecx
// 006d6ae7  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 006d6aed  50                   push eax
// 006d6aee  e82d80ffff           call 0x6ceb20
// 006d6af3  d9869c000000         fld dword ptr [esi + 0x9c]
// 006d6af9  8b8e98000000         mov ecx, dword ptr [esi + 0x98]
// 006d6aff  d999cc000000         fstp dword ptr [ecx + 0xcc]
// 006d6b05  e80680ffff           call 0x6ceb10
// 006d6b0a  8b8698000000         mov eax, dword ptr [esi + 0x98]
// 006d6b10  5e                   pop esi
// 006d6b11  c3                   ret 

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
    char padding[0x4];
    NodeData* owner;
};

struct Node {
    char padding[0xe4];
    NodeData* data;
};

struct Pair {
    char padding[0xcc];
    float value;

    void set(const Frame& first, const Frame& second);
    void f();
};

struct S {
    char padding0[0x10];
    Node* first;
    Node* second;
    char padding1[0x20];
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
