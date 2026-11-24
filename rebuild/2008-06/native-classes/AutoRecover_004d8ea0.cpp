// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the object is a G3D-style hash table: +4 = element count, +8 = bucket array, +0xc = bucket count.
// INFERRED: each chain node has a sub-object at +8 (with a vtable) and a next pointer at +0x18.

namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

// INFERRED: unknown global, the vtable of the sub-object stored at node+8.
extern "C" char g_00826c04[];

// INFERRED: the disassembly pushes no stack arguments for this call, so it is declared with none.
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

struct HashTableLike {
    int   unk0;
    int   numElements;
    char** buckets;
    int   numBuckets;
};

extern "C" void __fastcall fn_004d8ea0(HashTableLike* self, int unusedEdx)
{
    for (int i = 0; i < self->numBuckets; ++i) {
        char* node = self->buckets[i];
        while (node) {
            char* next = *(char**)(node + 0x18);
            void* sub = node + 8;
            // INFERRED: reset the sub-object's vtable pointer before destroying it
            *(void**)sub = (void*)g_00826c04;
            fn_004d7e30(sub, 0);
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->numBuckets = 0;
    self->numElements = 0;
}
