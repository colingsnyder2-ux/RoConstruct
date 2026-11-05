// from server: 100% by atomic.potato
struct Vector3 {
    float x;
    float y;
    float z;
};

struct Node {
    int key;
    float x;
    float y;
    float z;
    char pad[4];
    Node* next;
};

extern "C" unsigned int __fastcall hashVector3(const Vector3* v);

struct TextureProxyBase {
    char pad0[8];
    Node** buckets;
    unsigned int bucketCount;
    bool has(const Vector3& v);
};

bool TextureProxyBase::has(const Vector3& v)
{
    unsigned int h = hashVector3(&v);
    unsigned int idx = h % bucketCount;
    Node* n = buckets[idx];
    while (n) {
        if (n->key == (int)h &&
            n->x == v.x &&
            n->y == v.y &&
            n->z == v.z)
            return true;
        n = n->next;
    }
    return false;
}
