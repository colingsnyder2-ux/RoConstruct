// from server: 100% by colin
struct Vec3 {
    float x;
    float y;
    float z;
};

struct Entry {
    int key;
    float x;
    float y;
    float z;
    int pad[4];
    Entry* next;
};

struct HashTable {
    int unknown0;
    int unknown4;
    Entry** buckets;
    unsigned int bucketCount;

    Vec3* find(Vec3* key);
};

extern "C" unsigned int __fastcall hashVec3(Vec3* v);

Vec3* HashTable::find(Vec3* key)
{
    unsigned int h = hashVec3(key);
    unsigned int idx = h % bucketCount;
    Entry* e = buckets[idx];
    while (e != 0)
    {
        if (e->key == (int)h)
        {
            if (e->x == key->x && e->y == key->y && e->z == key->z)
                break;
        }
        e = e->next;
    }
    return (Vec3*)((char*)e + 0x10);
}
