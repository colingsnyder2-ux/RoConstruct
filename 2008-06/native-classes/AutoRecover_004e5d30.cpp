// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct fn_Vec3 { float x, y, z; };

// INFERRED: G3D::Table<Vector3,T> node layout from disassembly offsets; value type unknown, int used
struct fn_Node {
    unsigned hash;      // +0
    fn_Vec3 key;        // +4
    int value;          // +0x10
    fn_Node* next;      // +0x14
};

// INFERRED: table layout from [this+8] buckets, [this+0xc] bucket count
struct fn_Table {
    int pad0[2];
    fn_Node** buckets;  // +8
    unsigned numBuckets; // +0xc
};

extern "C" unsigned __fastcall fn_005183a0(const fn_Vec3* self); // G3D::Vector3::hashCode

extern "C" int* __fastcall fn_004e5d30(fn_Table* self, int unusedEdx, const fn_Vec3* key)
{
    unsigned h = fn_005183a0(key);
    fn_Node* n = self->buckets[h % self->numBuckets];
    while (n) {
        if (n->hash == h && key->x == n->key.x && key->y == n->key.y && key->z == n->key.z)
            break;
        n = n->next;
    }
    // INFERRED: original returns &n->value unconditionally (lea eax,[edx+0x10])
    return &n->value;
}
