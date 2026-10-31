// from server: 100% by EspClaude
// roc 2009-06 005167b0  unit: RBX::MeshRefPartAdapter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005167b0
//
// 005167b0  56                   push esi
// 005167b1  57                   push edi
// 005167b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005167b6  8bf1                 mov esi, ecx
// 005167b8  8bcf                 mov ecx, edi
// 005167ba  e8a1eb0500           call 0x575360
// 005167bf  33d2                 xor edx, edx
// 005167c1  8bc8                 mov ecx, eax
// 005167c3  f7760c               div dword ptr [esi + 0xc]
// 005167c6  8b4608               mov eax, dword ptr [esi + 8]
// 005167c9  8b1490               mov edx, dword ptr [eax + edx*4]
// 005167cc  85d2                 test edx, edx
// 005167ce  7431                 je 0x516801
// 005167d0  390a                 cmp dword ptr [edx], ecx
// 005167d2  7526                 jne 0x5167fa
// 005167d4  d907                 fld dword ptr [edi]
// 005167d6  d85a04               fcomp dword ptr [edx + 4]
// 005167d9  dfe0                 fnstsw ax
// 005167db  f6c444               test ah, 0x44
// 005167de  7a1a                 jp 0x5167fa
// 005167e0  d94704               fld dword ptr [edi + 4]
// 005167e3  d85a08               fcomp dword ptr [edx + 8]
// 005167e6  dfe0                 fnstsw ax
// 005167e8  f6c444               test ah, 0x44
// 005167eb  7a0d                 jp 0x5167fa
// 005167ed  d94708               fld dword ptr [edi + 8]
// 005167f0  d85a0c               fcomp dword ptr [edx + 0xc]
// 005167f3  dfe0                 fnstsw ax
// 005167f5  f6c444               test ah, 0x44
// 005167f8  7b07                 jnp 0x516801
// 005167fa  8b5214               mov edx, dword ptr [edx + 0x14]
// 005167fd  85d2                 test edx, edx
// 005167ff  75cf                 jne 0x5167d0
// 00516801  5f                   pop edi
// 00516802  8d4210               lea eax, [edx + 0x10]
// 00516805  5e                   pop esi
// 00516806  c20400               ret 4
// copied from an identical function in another client (function ?find@Block@ns_ROCX000013@@QAEPAPAXABUVector3@2@@Z)

namespace ns_ROCX000013 {
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Node {
    unsigned int hash;
    Vector3 key;
    void* value;
    Node* next;
};

struct Block {
    unsigned int reserved[2];
    Node** buckets;
    unsigned int bucketCount;

    void** find(const Vector3& key);
};

void** Block::find(const Vector3& key)
{
    unsigned int hash = key.hashCode();
    Node* node = buckets[hash % bucketCount];

    while (node) {
        if (node->hash == hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z)
            break;
        node = node->next;
    }

    return &node->value;
}
}
