// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

// INFERRED: caller pushes no stack args, so the callee takes none.
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);

// INFERRED: unknown global (vtable of the node base) stored into node+8.
extern "C" char g_00826bfc[];

struct Node {
    int pad0[2];
    void* vtbl;     // +8
    int pad1[4];
    Node* next;     // +0x18
};

// INFERRED: G3D Array-like layout: +4 allocated, +8 data, +0xc count
struct NodeBucketArray {
    int pad0;
    int allocated;
    Node** data;
    int count;
};

extern "C" int __fastcall fn_004d8e30(NodeBucketArray* self, int unusedEdx)
{
    for (int i = 0; i < self->count; ++i) {
        Node* n = self->data[i];
        while (n) {
            Node* next = n->next;
            n->vtbl = g_00826bfc;
            fn_004d7e30(&n->vtbl, 0);
            G3D::System::free(n);
            n = next;
        }
    }
    G3D::System::alignedFree(self->data);
    self->data = 0;
    self->count = 0;
    self->allocated = 0;
    return 0;
}
