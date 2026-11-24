// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: hash-table style iterator, post-increment returning the old value
// via a hidden return pointer. Layout deduced from field offsets.
struct HNode {
    char pad[0x18];
    HNode* next;
};

struct HIter {
    int bucket;          // +0
    HNode* node;         // +4
    int f8;              // +8
    int bucketCount;     // +0xc
    HNode** buckets;     // +0x10
    union {
        int raw;
        unsigned char atEnd;
    } flag;              // +0x14
};

extern "C" HIter* __fastcall fn_004e6c90(HIter* self, int unusedEdx, HIter* ret, int dummy)
{
    ret->bucket = self->bucket;
    ret->node = (HNode*)self->node;
    ret->f8 = self->f8;
    ret->bucketCount = self->bucketCount;
    ret->buckets = self->buckets;
    ret->flag.raw = self->flag.raw;

    self->node = self->node->next;
    if (self->node == 0) {
        int count = self->bucketCount;
        for (;;) {
            ++self->bucket;
            if (self->bucket >= count) {
                self->flag.atEnd = 1;
                break;
            }
            self->node = self->buckets[self->bucket];
            if (self->node != 0)
                break;
        }
    }
    return ret;
}
