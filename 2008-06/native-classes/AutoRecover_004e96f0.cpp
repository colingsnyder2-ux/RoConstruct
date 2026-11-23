// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D Table<MeshDirectedEdgeKey, Array<int>>::set; layouts taken from the disassembly.
// Unverified: not compiled or diffed against the target.
extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e8ac0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" void* __cdecl fn_00508530(unsigned size); // G3D::System::malloc
extern "C" void __fastcall fn_004e5e10(void* self, int unusedEdx, int n); // Table::resize

struct ArrInt { // INFERRED: 16-byte value with vtable
    virtual ~ArrInt() {}
    int a, b, c;
};

struct Node {
    unsigned hash;
    unsigned key;
    ArrInt value;
    Node* next;
};

struct MeshTable {
    int pad;
    int count;
    Node** bucket;
    unsigned numBuckets;

    void set(const unsigned* key, const ArrInt* value);
};

void MeshTable::set(const unsigned* key, const ArrInt* value)
{
    unsigned h = *key;
    unsigned i = h % numBuckets;
    Node* n = bucket[i];

    if (!n) {
        Node* nn = (Node*)fn_00508530(0x1c);
        if (nn) {
            ArrInt tmp(*value);
            bucket[i] = (Node*)fn_004e8ac0(nn, 0, (int)*key, 0, 0, 0, 0, 0, 0);
        } else {
            bucket[i] = 0;
        }
        ++count;
        return;
    }

    int depth = 1;
    bool found = true;
    for (; n; n = n->next, ++depth) {
        if (found && h == n->hash)
            found = true;
        else
            found = false;
        if (h == n->hash && n->key == h) {
            if (&n->value != value) {
                fn_004d7e30(&n->value, 0);
                fn_004e7880(&n->value, 0, (int)value);
            }
            return;
        }
    }

    if (!found && depth > 5 && (int)numBuckets < count * 10)
        fn_004e5e10(this, 0, numBuckets * 2 + 1);

    i = h % numBuckets;
    Node* nn = (Node*)fn_00508530(0x1c);
    Node* r = 0;
    if (nn) {
        ArrInt tmp(*value);
        r = (Node*)fn_004e8ac0(nn, 0, (int)*key, (int)bucket[i], 0, 0, 0, 0, 0);
    }
    bucket[i] = r;
    ++count;
}
