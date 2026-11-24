// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

// INFERRED: the 4-arg declaration in the prompt does not match the call site (no pushes),
// so this is declared with no stack args; the symbol is C-linkage so the name is the same.
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

// INFERRED: unknown global at 0x826c0c, used as a vtable for the node sub-object.
extern "C" char g_00826c0c[];

// INFERRED: G3D::Table-like hash container: +4 size, +8 bucket array, +0xc bucket count.
// Nodes have a sub-object at +8 (vtable g_00826c0c) and a next pointer at +0x18.
struct HashTableLike {
    int   pad0;
    int   count;
    void** buckets;
    int   numBuckets;
};

extern "C" void __fastcall fn_004d8f10(HashTableLike* self, int unusedEdx)
{
    for (int i = 0; i < self->numBuckets; ++i) {
        char* node = (char*)self->buckets[i];
        if (node) {
            do {
                char* next = *(char**)(node + 0x18);
                void* sub = node + 8;
                *(void**)sub = (void*)g_00826c0c;
                fn_004d7e30(sub, 0);
                G3D::System::free(node);
                node = next;
            } while (node);
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->numBuckets = 0;
    self->count = 0;
}
