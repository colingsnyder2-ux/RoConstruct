// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: hash-table iterator (bucket index, node, bucket count, bucket array, end flag); postfix ++ returns old state in *out.
struct HashNode {
    int pad[5];
    HashNode* next; // 0x14
};

struct HashIter {
    int bucket;         // 0x00
    HashNode* node;     // 0x04
    int f8;             // 0x08
    int bucketCount;    // 0x0c
    HashNode** buckets; // 0x10
    union {
        int f14;
        char done;      // 0x14
    };
};

extern "C" HashIter* __fastcall fn_004e6cf0(HashIter* self, int unusedEdx, HashIter* out, int unusedPostfix)
{
    out->bucket = self->bucket;
    out->node = self->node;
    out->f8 = self->f8;
    out->bucketCount = self->bucketCount;
    out->buckets = self->buckets;
    out->f14 = self->f14;

    self->node = self->node->next;
    if (!self->node) {
        do {
            ++self->bucket;
            if (self->bucket >= self->bucketCount) {
                self->done = 1;
                return out;
            }
            self->node = self->buckets[self->bucket];
        } while (!self->node);
    }
    return out;
}
