// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D Table<MeshDirectedEdgeKey, Array<int>>::set. Node layout and
// helper roles are guessed from the disassembly; I did not compile or diff this.

extern "C" int __fastcall fn_004e7880(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e8940(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int __fastcall fn_004d7e30(void* self, int unusedEdx);
extern "C" void* __cdecl fn_00508530(unsigned int size);
extern "C" void __fastcall fn_004e5e10(void* self, int unusedEdx, int newSize);

// INFERRED: vtable of the 16-byte Array<int> temporary
extern "C" void* g_00826c0c[];

struct ArrayInt { // INFERRED: 16-byte G3D Array<int> with vtable
    void* vtbl; int a, b, c;
};

struct Node {
    unsigned int hashCode; // INFERRED
    unsigned int key;
    ArrayInt value;
    Node* next;
};

struct EdgeTable {
    void* vtbl;
    int count;
    Node** bucket;
    unsigned int numBuckets;
};

extern "C" void __fastcall fn_004e93b0(EdgeTable* self, int unusedEdx, const unsigned int* key, const ArrayInt* value)
{
    unsigned int hash = *key;
    unsigned int b = hash % self->numBuckets;
    Node* n = self->bucket[b];

    if (n == 0) {
        void* mem = fn_00508530(0x1c);
        Node* nn = 0;
        if (mem) {
            ArrayInt tmp;
            tmp.vtbl = g_00826c0c;
            fn_004e7880(&tmp, 0, (int)value);
            nn = (Node*)fn_004e8940(mem, 0, tmp.a, 0, 0, 0, 0, 0, 0);
        }
        self->bucket[b] = nn;
        ++self->count;
        return;
    }

    bool found = false;
    int depth = 1;
    Node* p = n;
    do {
        found = (p->hashCode == hash);
        if (hash == p->hashCode && p->key == hash) {
            if (&p->value != value) {
                fn_004d7e30(&p->value, 0);
                fn_004e7880(&p->value, 0, (int)value);
            }
            return;
        }
        p = p->next;
        ++depth;
    } while (p);

    if (!found && depth > 5 && self->numBuckets < (unsigned)(self->count * 20)) {
        fn_004e5e10(self, 0, self->numBuckets * 2 + 1);
    }
    b = hash % self->numBuckets;
    void* mem = fn_00508530(0x1c);
    Node* nn = 0;
    if (mem) {
        ArrayInt tmp;
        tmp.vtbl = g_00826c0c;
        fn_004e7880(&tmp, 0, (int)value);
        nn = (Node*)fn_004e8940(mem, 0, tmp.a, hash, (int)self->bucket[b], 0, 0, 0, 0);
    }
    self->bucket[b] = nn;
    ++self->count;
}
