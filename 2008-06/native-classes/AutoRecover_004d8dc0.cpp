// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is a G3D::Table-style hash table clear(); the layout below is guessed from the offsets used.
namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

// INFERRED: the disassembly pushes no stack args for this call, so it is declared with none (the supplied 4-arg declaration looks wrong).
extern "C" void __fastcall fn_004d7dc0(void* self);

// INFERRED: unknown global at 0x826bf4 is the vtable of the node's embedded polymorphic member.
extern "C" char g_00826bf4[];

struct HashNodeSub {
    void* vtable;
};

struct HashNode {
    int pad0;
    int pad1;
    HashNodeSub sub;   // +8, polymorphic member
    int pad2;
    int pad3;
    int pad4;  // INFERRED: next pointer sits at +0x18 in the disassembly
    HashNode* next;    // +0x18
};

struct HashTable {
    int pad0;
    int numElements;     // +4
    HashNode** buckets;  // +8
    int numBuckets;      // +0xc
};

extern "C" void __fastcall fn_004d8dc0(HashTable* self, int unusedEdx)
{
    for (int i = 0; i < self->numBuckets; ++i) {
        HashNode* node = self->buckets[i];
        while (node) {
            HashNode* next = node->next;
            node->sub.vtable = g_00826bf4;
            fn_004d7dc0(&node->sub);
            G3D::System::free(node);
            node = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->numBuckets = 0;
    self->numElements = 0;
}
