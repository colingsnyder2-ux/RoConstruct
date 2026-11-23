// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were provided, so G3D::Vector3 and the table layout are declared locally.
namespace G3D {
struct Vector3 {
    float x, y, z;
    unsigned int hashCode() const;   // resolves to ?hashCode@Vector3@G3D@@QBEIXZ
};
}

// INFERRED: value payload is 16 bytes (node +0x10..+0x20), contents unknown.
struct Fn4e5c10Value {
    unsigned int data[4];
};

// INFERRED: chained hash node layout from the offsets used in the disassembly.
struct Fn4e5c10Node {
    unsigned int hash;          // +0x00
    G3D::Vector3 key;           // +0x04
    Fn4e5c10Value value;        // +0x10
    Fn4e5c10Node* next;         // +0x20
};

// INFERRED: table has buckets pointer at +8 and bucket count at +0xc.
struct Fn4e5c10Table {
    unsigned int pad0;
    unsigned int pad1;
    Fn4e5c10Node** buckets;     // +0x08
    unsigned int numBuckets;    // +0x0c
};

extern "C" Fn4e5c10Value* __fastcall fn_004e5c10(Fn4e5c10Table* self, int unusedEdx, const G3D::Vector3* key)
{
    unsigned int h = key->hashCode();
    Fn4e5c10Node* n = self->buckets[h % self->numBuckets];
    while (n) {
        if (n->hash == h &&
            key->x == n->key.x &&
            key->y == n->key.y &&
            key->z == n->key.z)
            break;
        n = n->next;
    }
    // Note: when not found, n is null and the original returns &n->value (offset 0x10) without a check.
    return &n->value;
}
