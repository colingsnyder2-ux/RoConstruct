// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int numBytes);
    static void alignedFree(void* ptr);
};
}

// INFERRED: node layout of a G3D-style hash table node (hash code first, chain link at +0x20)
struct HashNode {
    unsigned int hashCode;      // +0x00
    unsigned char payload[0x1c];// +0x04..+0x1f
    HashNode* next;             // +0x20
};

// INFERRED: hash table layout: bucket array at +8, bucket count at +0xc
struct HashTable {
    int unknown0;
    int unknown4;
    HashNode** buckets;
    int numBuckets;
};

extern "C" void __fastcall fn_004e5d90(HashTable* self, int unusedEdx, unsigned int newCount)
{
    HashNode** oldBuckets = self->buckets;

    self->buckets = (HashNode**)G3D::System::alignedMalloc(newCount * 4, 0x10);
    G3D::System::memset(self->buckets, 0, newCount * 4);

    for (int i = 0; i < self->numBuckets; ++i) {
        HashNode* node = oldBuckets[i];
        while (node) {
            unsigned int idx = node->hashCode % newCount;
            HashNode* next = node->next;
            node->next = self->buckets[idx];
            self->buckets[idx] = node;
            node = next;
        }
    }

    G3D::System::alignedFree(oldBuckets);
    self->numBuckets = (int)newCount;
}
