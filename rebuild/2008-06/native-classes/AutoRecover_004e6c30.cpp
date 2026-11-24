// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like a post-increment iterator over a chained hash table.
// It copies the old state to the return slot, then advances to the next node
// (offset 0x20) or to the next non-empty bucket.
struct HashNodeE6C30 {
    char pad[0x20];
    HashNodeE6C30* next;
};

struct HashIterE6C30 {
    int index;                 // 0x00 current bucket
    HashNodeE6C30* node;       // 0x04 current node
    int field8;                // 0x08
    int bucketCount;           // 0x0c
    HashNodeE6C30** buckets;   // 0x10
    int endFlag;               // 0x14 (low byte set to 1 at end)
};

extern "C" HashIterE6C30* __fastcall fn_004e6c30(HashIterE6C30* self, int unusedEdx, HashIterE6C30* out, int unusedPostfix)
{
    out->index = self->index;
    out->node = self->node;
    out->field8 = self->field8;
    out->bucketCount = self->bucketCount;
    out->buckets = self->buckets;
    out->endFlag = self->endFlag;

    HashNodeE6C30* n = self->node->next;
    self->node = n;
    if (n == 0) {
        int count = self->bucketCount;
        for (;;) {
            ++self->index;
            if (self->index >= count) {
                *(unsigned char*)&self->endFlag = 1;
                break;
            }
            n = self->buckets[self->index];
            self->node = n;
            if (n != 0)
                break;
        }
    }
    return out;
}
