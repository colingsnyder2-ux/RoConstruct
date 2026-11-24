// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: copy-constructor-like routine for a hash-table style container:
// +4 = count, +8 = bucket array, +0xc = bucket count; cloning non-null chains.
// INFERRED: fn_004e6f50 clones a node chain, returns new head. The target never
// sets edx before the call, so the helper is declared with only the object pointer.

extern "C" int __fastcall fn_004e6f50(void* self);
extern "C" void* __cdecl fn_00508580(unsigned size, unsigned align);
extern "C" void __cdecl fn_00508a30(void* p, unsigned char v, unsigned n);

struct HashTable {
    int pad0;
    int count;
    void** buckets;
    int numBuckets;
};

extern "C" void __fastcall fn_004e7880(HashTable* self, int unusedEdx, HashTable* other)
{
    self->count = other->count;
    self->numBuckets = other->numBuckets;
    // INFERRED: G3D::System::alignedMalloc(size, alignment) and System::memset
    self->buckets = (void**)fn_00508580(self->numBuckets * 4, 16);
    fn_00508a30(self->buckets, 0, self->numBuckets * 4);
    for (int i = 0; i < self->numBuckets; ++i) {
        if (other->buckets[i]) {
            self->buckets[i] = (void*)fn_004e6f50(other->buckets[i]);
        }
    }
}
