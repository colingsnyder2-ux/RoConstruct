// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object is a chained hash-table-like container whose copy
// routine duplicates the bucket array and deep-copies each non-null bucket.
// INFERRED: the layout below is guessed from the offsets the code touches.

namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int n);
};
}

struct BucketTable {
    int field0;          // INFERRED: unknown / vtable
    int field4;          // copied verbatim
    void** buckets;      // +8
    int numBuckets;      // +0xc
};

extern "C" int __fastcall fn_004e6eb0(void* self, int unusedEdx);

extern "C" void __fastcall fn_004e7810(BucketTable* self, int unusedEdx, BucketTable* other)
{
    self->field4 = other->field4;
    int n = other->numBuckets;
    self->numBuckets = n;
    self->buckets = (void**)G3D::System::alignedMalloc(n * 4, 16);
    G3D::System::memset(self->buckets, 0, self->numBuckets * 4);
    for (int i = 0; i < self->numBuckets; ++i) {
        void** src = &other->buckets[i];
        if (*src != 0) {
            self->buckets[i] = (void*)fn_004e6eb0(*src, 0);
        }
    }
}
