// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004d8dc0  unit: RBX::VSky::?$FactoryProduct::Creator  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004d8dc0
//
// 004d8dc0  53                   push ebx
// 004d8dc1  55                   push ebp
// 004d8dc2  8bd9                 mov ebx, ecx
// 004d8dc4  33ed                 xor ebp, ebp
// 004d8dc6  396b0c               cmp dword ptr [ebx + 0xc], ebp
// 004d8dc9  7e3d                 jle 0x4d8e08
// 004d8dcb  56                   push esi
// 004d8dcc  57                   push edi
// 004d8dcd  8d4900               lea ecx, [ecx]
// 004d8dd0  8b4308               mov eax, dword ptr [ebx + 8]
// 004d8dd3  8b34a8               mov esi, dword ptr [eax + ebp*4]
// 004d8dd6  85f6                 test esi, esi
// 004d8dd8  7426                 je 0x4d8e00
// 004d8dda  8d9b00000000         lea ebx, [ebx]
// 004d8de0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004d8de3  8d4e08               lea ecx, [esi + 8]
// 004d8de6  c701f46b8200         mov dword ptr [ecx], 0x826bf4
// 004d8dec  e8cfefffff           call 0x4d7dc0
// 004d8df1  56                   push esi
// 004d8df2  e809ef0200           call 0x507d00
// 004d8df7  83c404               add esp, 4
// 004d8dfa  8bf7                 mov esi, edi
// 004d8dfc  85ff                 test edi, edi
// 004d8dfe  75e0                 jne 0x4d8de0
// 004d8e00  45                   inc ebp
// 004d8e01  3b6b0c               cmp ebp, dword ptr [ebx + 0xc]
// 004d8e04  7cca                 jl 0x4d8dd0
// 004d8e06  5f                   pop edi
// 004d8e07  5e                   pop esi
// 004d8e08  8b4b08               mov ecx, dword ptr [ebx + 8]
// 004d8e0b  51                   push ecx
// 004d8e0c  e80fef0200           call 0x507d20
// 004d8e11  83c404               add esp, 4
// 004d8e14  33c0                 xor eax, eax
// 004d8e16  5d                   pop ebp
// 004d8e17  894308               mov dword ptr [ebx + 8], eax
// 004d8e1a  89430c               mov dword ptr [ebx + 0xc], eax
// 004d8e1d  894304               mov dword ptr [ebx + 4], eax
// 004d8e20  5b                   pop ebx
// 004d8e21  c3                   ret 

namespace G3D {
struct System {
    static void __cdecl free(void*);
    static void __cdecl alignedFree(void*);
};
}

struct Payload {
    void* vtable;
    unsigned char data[12];
    void destroy();
};

struct Node {
    unsigned char data[8];
    Payload value;
    Node* next;
};

struct S {
    unsigned int field0;
    int size;
    Node** buckets;
    int bucketCount;
    void clear();
};

void S::clear()
{
    for (int i = 0; i < bucketCount; ++i) {
        Node* node = buckets[i];
        while (node) {
            Node* next = node->next;
            node->value.vtable = (void*)0x00826bf4;
            node->value.destroy();
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(buckets);
    buckets = 0;
    bucketCount = 0;
    size = 0;
}
