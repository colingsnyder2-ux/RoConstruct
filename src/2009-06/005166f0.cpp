// from server: 100% by EspClaude
// roc 2009-06 005166f0  unit: RBX::MeshRefPartAdapter  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005166f0
//
// 005166f0  56                   push esi
// 005166f1  57                   push edi
// 005166f2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005166f6  8bf1                 mov esi, ecx
// 005166f8  8bcf                 mov ecx, edi
// 005166fa  e861ec0500           call 0x575360
// 005166ff  33d2                 xor edx, edx
// 00516701  8bc8                 mov ecx, eax
// 00516703  f7760c               div dword ptr [esi + 0xc]
// 00516706  8b4608               mov eax, dword ptr [esi + 8]
// 00516709  8b1490               mov edx, dword ptr [eax + edx*4]
// 0051670c  85d2                 test edx, edx
// 0051670e  7431                 je 0x516741
// 00516710  390a                 cmp dword ptr [edx], ecx
// 00516712  7526                 jne 0x51673a
// 00516714  d907                 fld dword ptr [edi]
// 00516716  d85a04               fcomp dword ptr [edx + 4]
// 00516719  dfe0                 fnstsw ax
// 0051671b  f6c444               test ah, 0x44
// 0051671e  7a1a                 jp 0x51673a
// 00516720  d94704               fld dword ptr [edi + 4]
// 00516723  d85a08               fcomp dword ptr [edx + 8]
// 00516726  dfe0                 fnstsw ax
// 00516728  f6c444               test ah, 0x44
// 0051672b  7a0d                 jp 0x51673a
// 0051672d  d94708               fld dword ptr [edi + 8]
// 00516730  d85a0c               fcomp dword ptr [edx + 0xc]
// 00516733  dfe0                 fnstsw ax
// 00516735  f6c444               test ah, 0x44
// 00516738  7b07                 jnp 0x516741
// 0051673a  8b5220               mov edx, dword ptr [edx + 0x20]
// 0051673d  85d2                 test edx, edx
// 0051673f  75cf                 jne 0x516710
// 00516741  5f                   pop edi
// 00516742  8d4210               lea eax, [edx + 0x10]
// 00516745  5e                   pop esi
// 00516746  c20400               ret 4
// copied from an identical function in another client (function ?find@Block@ns_ROCX000010@@QAEPAUValue@2@ABUVector3@2@@Z)

namespace ns_ROCX000010 {
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Value {
    unsigned char storage[16];
};

struct Node {
    unsigned int hash;
    Vector3 key;
    Value value;
    Node* next;
};

struct Block {
    unsigned char padding[8];
    Node** buckets;
    unsigned int bucketCount;

    Value* find(const Vector3& key);
};

#pragma float_control(precise, off, push)

Value* Block::find(const Vector3& key)
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

#pragma float_control(pop)
}
