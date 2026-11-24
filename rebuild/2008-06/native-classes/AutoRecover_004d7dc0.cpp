// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this is a G3D::Table-style clear(): a bucket array of singly linked nodes is walked,
// each node's 4-element member array is destroyed, the node is freed, then the bucket array is freed.

namespace G3D {
class System {
public:
    static void free(void* p);
    static void alignedFree(void* p);
};
}

// destructor of the 4-byte element (0x00502a70), thiscall
extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);

struct TableElem {
    int v;
    // INFERRED: element destructor lives at 0x502a70
    ~TableElem() { fn_00502a70(this, 0); }
};

struct TableNode {
    int hash;               // INFERRED: 0x00
    int pad[3];             // INFERRED: 0x04..0x0f
    TableElem elems[4];     // 0x10..0x1f
    TableNode* next;        // 0x20
};

struct TableObj {
    int unk0;
    int numEntries;         // +4
    TableNode** buckets;    // +8
    int numBuckets;         // +0xc
};

extern "C" void __fastcall fn_004d7dc0(TableObj* self, int unusedEdx)
{
    for (int i = 0; i < self->numBuckets; ++i) {
        TableNode* n = self->buckets[i];
        while (n) {
            TableNode* next = n->next;
            n->~TableNode();
            G3D::System::free(n);
            n = next;
        }
    }
    G3D::System::alignedFree(self->buckets);
    self->buckets = 0;
    self->numBuckets = 0;
    self->numEntries = 0;
}
