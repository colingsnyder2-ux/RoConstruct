// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this is G3D::Table<Vector3, Array<int>>::set(const Vector3& key, const Array<int>& value).
// Node layout: +0 hash, +4 Vector3 key, +0x10 value (Array<int>), +0x14 next.
// Table layout: +4 numElements, +8 bucket array, +0xc numBuckets.
// Simplifications: the vector-copy-constructor call (??__C...) used to copy the
// Array<int> value is replaced by a plain 12-byte copy, and the EH registration is omitted.

struct V3Node {
    unsigned hash;
    float x, y, z;
    int value[3];
    V3Node* next;
};

struct V3Table {
    int pad0;
    int numElements;
    V3Node** bucket;
    int numBuckets;
};

extern "C" unsigned __fastcall fn_005183a0(const void* vec, int unusedEdx); // Vector3::hashCode
extern "C" void* __cdecl fn_00508530(unsigned size);                        // G3D::System::malloc
extern "C" int __fastcall fn_004e6e00(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6);
extern "C" int __fastcall fn_004e60f0(void* self, int unusedEdx, const void* a1);
extern "C" void __fastcall fn_004e5e90(void* self, int unusedEdx, int newSize);

static inline int fbits(float f)
{
    union { float f; int i; } u;
    u.f = f;
    return u.i;
}

extern "C" void __fastcall fn_004e7630(V3Table* self, int unusedEdx, const float* key, const int* value)
{
    unsigned h = fn_005183a0(key, 0);
    unsigned idx = h % (unsigned)self->numBuckets;
    V3Node* head = self->bucket[idx];

    if (head == 0) {
        V3Node* node = (V3Node*)fn_00508530(0x18);
        if (node) {
            int tmp[3];
            tmp[0] = value[0];
            tmp[1] = value[1];
            tmp[2] = value[2];
            fn_004e6e00(node, 0, fbits(key[0]), fbits(key[1]), fbits(key[2]), tmp[0], (int)h, 0);
        }
        self->bucket[idx] = node;
        self->numElements++;
        return;
    }

    int count = 1;
    bool allSame = true;
    V3Node* n = head;
    do {
        allSame = allSame && (h == n->hash);
        if (h == n->hash && key[0] == n->x && key[1] == n->y && key[2] == n->z) {
            fn_004e60f0(&n->value, 0, value);
            return;
        }
        n = n->next;
        count++;
    } while (n);

    if (count > 5 && !allSame) {
        if (self->numBuckets < self->numElements * 10) {
            fn_004e5e90(self, 0, self->numBuckets * 2 + 1);
        }
    }

    idx = h % (unsigned)self->numBuckets;
    V3Node* node = (V3Node*)fn_00508530(0x18);
    if (node) {
        V3Node* nextNode = self->bucket[idx];
        int tmp[3];
        tmp[0] = value[0];
        tmp[1] = value[1];
        tmp[2] = value[2];
        fn_004e6e00(node, 0, fbits(key[0]), fbits(key[1]), fbits(key[2]), tmp[0], (int)h, (int)nextNode);
    }
    self->bucket[idx] = node;
    self->numElements++;
}
