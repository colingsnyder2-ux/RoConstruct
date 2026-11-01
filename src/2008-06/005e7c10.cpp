// from server: 100% by colin
#include <intrin.h>
// from server: 92% by king_originala
// roc 2008-06 005e7c10  unit: RBX::Geometry  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7c10
//
// 005e7c10  56                   push esi
// 005e7c11  8b742408             mov esi, dword ptr [esp + 8]
// 005e7c15  57                   push edi
// 005e7c16  8bf9                 mov edi, ecx
// 005e7c18  85f6                 test esi, esi
// 005e7c1a  7447                 je 0x5e7c63
// 005e7c1c  8d642400             lea esp, [esp]
// 005e7c20  8b06                 mov eax, dword ptr [esi]
// 005e7c22  8b500c               mov edx, dword ptr [eax + 0xc]
// 005e7c25  8bce                 mov ecx, esi
// 005e7c27  ffd2                 call edx
// 005e7c29  85c0                 test eax, eax
// 005e7c2b  7513                 jne 0x5e7c40
// 005e7c2d  8b06                 mov eax, dword ptr [esi]
// 005e7c2f  8b5014               mov edx, dword ptr [eax + 0x14]
// 005e7c32  8bce                 mov ecx, esi
// 005e7c34  ffd2                 call edx
// 005e7c36  83f806               cmp eax, 6
// 005e7c39  742f                 je 0x5e7c6a
// 005e7c3b  83f807               cmp eax, 7
// 005e7c3e  742a                 je 0x5e7c6a
// 005e7c40  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 005e7c43  7505                 jne 0x5e7c4a
// 005e7c45  8b7614               mov esi, dword ptr [esi + 0x14]
// 005e7c48  eb03                 jmp 0x5e7c4d
// 005e7c4a  8b7618               mov esi, dword ptr [esi + 0x18]
// 005e7c4d  8d4601               lea eax, [esi + 1]
// 005e7c50  3b473c               cmp eax, dword ptr [edi + 0x3c]
// 005e7c53  7d08                 jge 0x5e7c5d
// 005e7c55  8b4f38               mov ecx, dword ptr [edi + 0x38]
// 005e7c58  8b3481               mov esi, dword ptr [ecx + eax*4]
// 005e7c5b  eb02                 jmp 0x5e7c5f
// 005e7c5d  33f6                 xor esi, esi
// 005e7c5f  85f6                 test esi, esi
// 005e7c61  75bd                 jne 0x5e7c20
// 005e7c63  5f                   pop edi
// 005e7c64  33c0                 xor eax, eax
// 005e7c66  5e                   pop esi
// 005e7c67  c20400               ret 4
// 005e7c6a  5f                   pop edi
// 005e7c6b  8bc6                 mov eax, esi
// 005e7c6d  5e                   pop esi
// 005e7c6e  c20400               ret 4

struct Geometry;

struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int predicate();
    virtual void slot4();
    virtual int kind();

    int padding[2];
    Geometry* owner;
    int reserved;
    int firstIndex;
    int secondIndex;
};

struct Geometry {
    char padding[0x38];
    Node** nodes;
    int count;

    Node* find(Node* node);
};

Node* Geometry::find(Node* node) {
    while (node) {
        if (!node->predicate()) {
            int type = node->kind();
            if (type == 6 || type == 7)
                return node;
        }

        int index;
        if (this == node->owner)
            index = node->firstIndex;
        else
            index = node->secondIndex;

        int next = index + 1;
        if (next < count)
            node = nodes[next];
        else
            node = 0;
        _ReadWriteBarrier();
    }
    return 0;
}
