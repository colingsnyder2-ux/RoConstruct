// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct Vec3Node {
    unsigned hash;
    float x, y, z;
    int pad[4]; // INFERRED: layout gap up to next pointer at 0x20
    Vec3Node* next;
};

struct Vec3Table {
    int unk0;
    int unk4;
    Vec3Node** buckets;
    unsigned numBuckets;
    bool contains(const float* v);
};

// G3D::Vector3::hashCode() const
extern "C" unsigned __fastcall fn_005183a0(const float* v, int unusedEdx);

extern "C" bool __fastcall fn_004e5c70(Vec3Table* self, int unusedEdx, const float* v)
{
    unsigned h = fn_005183a0(v, 0);
    Vec3Node* n = self->buckets[h % self->numBuckets];
    while (n) {
        if (n->hash == h && v[0] == n->x && v[1] == n->y && v[2] == n->z)
            return true;
        n = n->next;
    }
    return false;
}
