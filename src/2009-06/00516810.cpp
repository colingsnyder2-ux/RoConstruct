// from server: 100% by EspClaude
// roc 2009-06 00516810  unit: RBX::MeshRefPartAdapter  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516810
//
// 00516810  56                   push esi
// 00516811  57                   push edi
// 00516812  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00516816  8bf1                 mov esi, ecx
// 00516818  8bcf                 mov ecx, edi
// 0051681a  e841eb0500           call 0x575360
// 0051681f  33d2                 xor edx, edx
// 00516821  8bc8                 mov ecx, eax
// 00516823  f7760c               div dword ptr [esi + 0xc]
// 00516826  8b4608               mov eax, dword ptr [esi + 8]
// 00516829  8b1490               mov edx, dword ptr [eax + edx*4]
// 0051682c  85d2                 test edx, edx
// 0051682e  7431                 je 0x516861
// 00516830  390a                 cmp dword ptr [edx], ecx
// 00516832  7526                 jne 0x51685a
// 00516834  d907                 fld dword ptr [edi]
// 00516836  d85a04               fcomp dword ptr [edx + 4]
// 00516839  dfe0                 fnstsw ax
// 0051683b  f6c444               test ah, 0x44
// 0051683e  7a1a                 jp 0x51685a
// 00516840  d94704               fld dword ptr [edi + 4]
// 00516843  d85a08               fcomp dword ptr [edx + 8]
// 00516846  dfe0                 fnstsw ax
// 00516848  f6c444               test ah, 0x44
// 0051684b  7a0d                 jp 0x51685a
// 0051684d  d94708               fld dword ptr [edi + 8]
// 00516850  d85a0c               fcomp dword ptr [edx + 0xc]
// 00516853  dfe0                 fnstsw ax
// 00516855  f6c444               test ah, 0x44
// 00516858  7b0e                 jnp 0x516868
// 0051685a  8b5214               mov edx, dword ptr [edx + 0x14]
// 0051685d  85d2                 test edx, edx
// 0051685f  75cf                 jne 0x516830
// 00516861  5f                   pop edi
// 00516862  32c0                 xor al, al
// 00516864  5e                   pop esi
// 00516865  c20400               ret 4
// 00516868  5f                   pop edi
// 00516869  b001                 mov al, 1
// 0051686b  5e                   pop esi
// 0051686c  c20400               ret 4
// copied from an identical function in another client (function ?contains@Block@ns_ROCX000012@@QAE_NABUVector3@2@@Z)

namespace ns_ROCX000012 {
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Node {
    unsigned int hash;
    Vector3 key;
    unsigned char padding[4];
    Node* next;
};

struct Block {
    unsigned char padding[8];
    Node** buckets;
    unsigned int bucketCount;

    bool contains(const Vector3& key);
};

#pragma float_control(precise, off, push)

bool Block::contains(const Vector3& key)
{
    unsigned int hash = key.hashCode();
    Node* node = buckets[hash % bucketCount];
    while (node) {
        if (node->hash == hash &&
            node->key.x == key.x &&
            node->key.y == key.y &&
            node->key.z == key.z)
            return true;
        node = node->next;
    }
    return false;
}

#pragma float_control(pop)
}
