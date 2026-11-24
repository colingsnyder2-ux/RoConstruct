// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_004e7810(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004e87c0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern "C" int __fastcall fn_004d7dc0(void* self, int unusedEdx);
extern "C" void* __cdecl fn_00508530(unsigned n);
extern "C" void __fastcall fn_004e5e10(void* self, int unusedEdx, int n);

// INFERRED: vtable of G3D Array<int>; unknown global, address-taken
extern "C" char g_00826bf4[];

// INFERRED: G3D Table<MeshDirectedEdgeKey, Array<int>>::set; 16-byte Array<int> value copied via fn_004e7810
struct Arr {
    void* vt;
    int d[3];
    Arr(const Arr& o) {
        vt = (void*)g_00826bf4;
        fn_004e7810(this, 0, (int)&o);
    }
};

struct Node {
    unsigned hash;
    unsigned key;
    Arr value;
    Node* next;
};

struct Tbl {
    int pad;
    int size;
    Node** bucket;
    unsigned numBuckets;
    void set(const unsigned* key, const Arr& value);
};

extern "C" void __fastcall fn_004e9070(Tbl* self, int unusedEdx, const unsigned* key, const Arr* value) {
    self->set(key, *value);
}

void Tbl::set(const unsigned* key, const Arr& value) {
    unsigned h = *key;
    unsigned b = h % numBuckets;
    Node* n = bucket[b];
    if (!n) {
        Node* m = (Node*)fn_00508530(0x1c);
        Node* r = 0;
        if (m) {
            Arr tmp(value);
            r = (Node*)(void*)fn_004e87c0(m, 0, (int)*key, ((int*)&tmp)[0], ((int*)&tmp)[1], ((int*)&tmp)[2], ((int*)&tmp)[3], (int)h, 0);
        }
        bucket[b] = r;
        ++size;
        return;
    }
    int count = 1;
    bool conflict = true;
    while (n) {
        conflict = conflict && n->hash == h;
        if (h == n->hash && n->key == h) {
            Arr* v = &n->value;
            if (v != &value) {
                fn_004d7dc0(v, 0);
                fn_004e7810(v, 0, (int)&value);
            }
            return;
        }
        n = n->next;
        ++count;
    }
    if (!conflict && count > 5 && numBuckets < (unsigned)(size * 4)) {
        fn_004e5e10(this, 0, numBuckets * 2 + 1);
    }
    b = h % numBuckets;
    Node* m = (Node*)fn_00508530(0x1c);
    Node* r = 0;
    if (m) {
        Arr tmp(value);
        r = (Node*)(void*)fn_004e87c0(m, 0, (int)*key, ((int*)&tmp)[0], ((int*)&tmp)[1], ((int*)&tmp)[2], ((int*)&tmp)[3], (int)h, (int)bucket[b]);
    }
    bucket[b] = r;
    ++size;
}
