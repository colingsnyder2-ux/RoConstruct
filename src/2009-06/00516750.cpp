// from server: 100% by EspClaude
// roc 2009-06 00516750  unit: RBX::MeshRefPartAdapter  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516750
//
// 00516750  56                   push esi
// 00516751  57                   push edi
// 00516752  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00516756  8bf1                 mov esi, ecx
// 00516758  8bcf                 mov ecx, edi
// 0051675a  e801ec0500           call 0x575360
// 0051675f  33d2                 xor edx, edx
// 00516761  8bc8                 mov ecx, eax
// 00516763  f7760c               div dword ptr [esi + 0xc]
// 00516766  8b4608               mov eax, dword ptr [esi + 8]
// 00516769  8b1490               mov edx, dword ptr [eax + edx*4]
// 0051676c  85d2                 test edx, edx
// 0051676e  7431                 je 0x5167a1
// 00516770  390a                 cmp dword ptr [edx], ecx
// 00516772  7526                 jne 0x51679a
// 00516774  d907                 fld dword ptr [edi]
// 00516776  d85a04               fcomp dword ptr [edx + 4]
// 00516779  dfe0                 fnstsw ax
// 0051677b  f6c444               test ah, 0x44
// 0051677e  7a1a                 jp 0x51679a
// 00516780  d94704               fld dword ptr [edi + 4]
// 00516783  d85a08               fcomp dword ptr [edx + 8]
// 00516786  dfe0                 fnstsw ax
// 00516788  f6c444               test ah, 0x44
// 0051678b  7a0d                 jp 0x51679a
// 0051678d  d94708               fld dword ptr [edi + 8]
// 00516790  d85a0c               fcomp dword ptr [edx + 0xc]
// 00516793  dfe0                 fnstsw ax
// 00516795  f6c444               test ah, 0x44
// 00516798  7b0e                 jnp 0x5167a8
// 0051679a  8b5220               mov edx, dword ptr [edx + 0x20]
// 0051679d  85d2                 test edx, edx
// 0051679f  75cf                 jne 0x516770
// 005167a1  5f                   pop edi
// 005167a2  32c0                 xor al, al
// 005167a4  5e                   pop esi
// 005167a5  c20400               ret 4
// 005167a8  5f                   pop edi
// 005167a9  b001                 mov al, 1
// 005167ab  5e                   pop esi
// 005167ac  c20400               ret 4
// copied from an identical function in another client (function ?contains@Block@ns_ROCX000011@@QAE_NABUVector3@2@@Z)

namespace ns_ROCX000011 {
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;
};

struct Node {
    unsigned int hash;
    Vector3 key;
    unsigned char padding[16];
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
