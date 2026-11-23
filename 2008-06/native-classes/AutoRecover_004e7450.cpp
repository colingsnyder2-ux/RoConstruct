// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: G3D Table<Vector3, V>::set-style insert; node layout from disassembly (hash, key, 16-byte value, next).
extern "C" int __fastcall fn_004e6d50(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
extern "C" int __fastcall fn_004e5d90(void* self, int unusedEdx, int a1);
extern "C" BodyRef4* __fastcall fn_004e6050(BodyRef4* self, int unusedEdx, BodyRef4* src);
extern "C" unsigned int __fastcall fn_005183a0(const float* v);
extern "C" void* __cdecl fn_00508530(unsigned int n);

struct Vec3F { float x, y, z; };

struct Node {
    unsigned int hash;
    Vec3F key;
    int value[4];
    Node* next;
};

struct VecTable {
    int unused0;
    int count;
    Node** bucket;
    int numBuckets;
};

extern "C" void __fastcall fn_004e7450(VecTable* self, int unusedEdx, const Vec3F* key, int* value)
{
    unsigned int h = fn_005183a0(&key->x);
    unsigned int b = h % (unsigned int)self->numBuckets;
    Node* n = self->bucket[b];
    Node* created = 0;

    if (n == 0) {
        created = (Node*)fn_00508530(sizeof(Node));
        if (created) {
            Vec3F k = *key;
            fn_004e6d50(created, 0, (int)value[0], (int)value[1], (int)value[2], (int)value[3], (int)h, 0, *(int*)&k.x, *(int*)&k.y, *(int*)&k.z);
        }
    } else {
        int depth = 1;
        bool found = false;
        do {
            if (n->hash == h && n->key.x == key->x && n->key.y == key->y && n->key.z == key->z) {
                fn_004e6050((int)&n->value);
                return;
            }
            n = n->next;
            ++depth;
        } while (n);
        (void)found;
        if (depth > 5 && self->numBuckets < self->count * 10) {
            fn_004e5d90(self, 0, self->numBuckets * 2 + 1);
        }
        b = h % (unsigned int)self->numBuckets;
        created = (Node*)fn_00508530(sizeof(Node));
        if (created) {
            Vec3F k = *key;
            fn_004e6d50(created, 0, (int)value[0], (int)value[1], (int)value[2], (int)value[3], (int)h, (int)self->bucket[b], *(int*)&k.x, *(int*)&k.y, *(int*)&k.z);
        }
    }
    self->bucket[b] = created;
    ++self->count;
}
