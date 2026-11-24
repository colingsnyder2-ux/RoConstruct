// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D Table<MeshDirectedEdgeKey, Array<int>>::set; layouts taken from the disassembly.

extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" char g_00826bfc[]; // Array<int> vtable

// INFERRED: Array<int> as a 16-byte value (vtable + 3 dwords) copied via fn_004e7880
struct Val {
    void* vt;
    int a, b, c;
    Val(const Val& o) { vt = (void*)g_00826bfc; fn_004e7880(this, 0, (int)&o); }
};

struct Node {
    unsigned hash;   // +0
    unsigned key;    // +4
    Val value;       // +8
    Node* next;      // +0x18
};

extern "C" int __fastcall fn_004e8a00(void* self, int unusedEdx, unsigned key, Val v, unsigned hash, Node* next);

namespace G3D { namespace System { void* malloc(unsigned n); } }

struct EdgeTable {
    int unk0;
    int count;         // +4
    Node** bucket;     // +8
    unsigned nBuckets; // +0xc
    void resize(int n);
    void set(const unsigned& key, const Val& value);
};

void EdgeTable::set(const unsigned& key, const Val& value)
{
    unsigned hash = key;
    unsigned idx = hash % nBuckets;
    Node* n = bucket[idx];
    if (!n) {
        Node* nn = (Node*)G3D::System::malloc(0x1c);
        if (nn) {
            fn_004e8a00(nn, 0, key, value, hash, 0);
            bucket[idx] = nn;
        } else {
            bucket[idx] = 0;
        }
        ++count;
        return;
    }
    int len = 1;
    bool found = true;
    for (;;) {
        found = found && hash == n->hash;
        if (hash == n->hash && n->key == hash) {
            Val* v = &n->value;
            if ((const Val*)v != &value) {
                fn_004d7e30(v, 0);
                fn_004e7880(v, 0, (int)&value);
            }
            return;
        }
        n = n->next;
        ++len;
        if (!n) break;
    }
    if (!found && len > 5 && (int)nBuckets < count * 20) {
        resize(nBuckets * 2 + 1);
    }
    idx = hash % nBuckets;
    Node* nn = (Node*)G3D::System::malloc(0x1c);
    if (nn) {
        fn_004e8a00(nn, 0, key, value, hash, bucket[idx]);
    }
    bucket[idx] = nn;
    ++count;
}
