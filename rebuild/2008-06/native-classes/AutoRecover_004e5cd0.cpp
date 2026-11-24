// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: local layouts from disassembly; no native header found.
struct Vec3 { float x, y, z; };

struct Vec3Node {
    unsigned int hash;   // +0
    Vec3 key;            // +4
    unsigned int pad;    // +0x10 INFERRED: unused by this function
    Vec3Node* next;      // +0x14
};

struct Vec3Table {
    unsigned int pad0;       // +0
    unsigned int pad1;       // +4
    Vec3Node** buckets;      // +8
    unsigned int bucketCount; // +0xc
};

extern "C" unsigned int __fastcall fn_005183a0(const Vec3* self); // G3D::Vector3::hashCode

extern "C" bool __fastcall fn_004e5cd0(Vec3Table* self, int unusedEdx, const Vec3* v)
{
    unsigned int h = fn_005183a0(v);
    Vec3Node* n = self->buckets[h % self->bucketCount];
    for (; n; n = n->next) {
        if (n->hash == h && v->x == n->key.x && v->y == n->key.y && v->z == n->key.z)
            return true;
    }
    return false;
}
