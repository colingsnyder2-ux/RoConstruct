// from server: 35% by colin
struct Part {
    char pad0[8];
    int field8;

    int getOrCreate(int id);
};

struct HashNode {
    int key;
    int key2;
    char pad8[0x10];
    HashNode* next;
};

struct HashTable {
    char pad0[0x1c];
    HashNode** buckets;
    int modulus;
};

extern HashTable g_hashTable;

struct StringHolder {
    void* vtable;
    char pad4[0x24];
};

struct Container {
    char pad0[0x14];
    StringHolder* holder;
};

extern Container g_container;

struct PartData {
    char pad0[0x50];
};

extern "C" {
    void* __cdecl operator_new(unsigned int size);
    void __cdecl memset(void* dst, int val, unsigned int size);
    void __cdecl free(void* p);
}

void* __cdecl sub_500060(unsigned int size);
void __cdecl sub_500580(void* p, int val, unsigned int size);
void __cdecl sub_4d3e20(void* self, void* a, void* b);
void __cdecl sub_4cdf20(void* self);
int __cdecl sub_4cffc0(void* self, int a);
void __cdecl sub_4d1d00(void* self, int a, void* b);
void __cdecl sub_630bdc(void* a, int b, int c, void* d, void* e);
void __cdecl sub_630af7(void* a, int b, int c, void* d);
int __cdecl sub_4cff60(void* self, int a);
int __cdecl sub_50bc70(int a, int b);
void* __cdecl sub_62fef6(unsigned int size);
void __cdecl sub_4e1aa0(void* self, int a, int b);
void __cdecl sub_474f70(void* self, void* p);

int Part::getOrCreate(int id) {
    unsigned int idx = (unsigned int)id % (unsigned int)g_hashTable.modulus;
    HashNode* node = g_hashTable.buckets[idx];
    while (node) {
        if (node->key == id && node->key2 == id)
            goto found;
        node = node->next;
    }
    {
        StringHolder* sh = (StringHolder*)sub_500060(0x28);
        sub_500580(sh, 0, 0x28);
        sub_4d3e20(&g_container, &sh, &sh);
        sub_4cdf20(&sh);
    }
found:
    {
        unsigned int idx2 = (unsigned int)id % (unsigned int)g_hashTable.modulus;
        HashNode* node2 = g_hashTable.buckets[idx2];
        while (node2) {
            if (node2->key == id && node2->key2 == id)
                break;
            node2 = node2->next;
        }
        PartData* pd = (PartData*)((char*)node2 + 8);
        int val = this->field8;
        if (!sub_4cffc0(pd, val)) {
            sub_630bdc(&val, 4, 4, (void*)0x4cff40, (void*)0x4637f0);
            sub_4d1d00(pd, val, &val);
            sub_630af7(&val, 4, 4, (void*)0x4637f0);
        }
        int r = sub_4cff60(pd, val);
        int idx3 = sub_50bc70(3, 0);
        int* slot = (int*)(r + idx3 * 4);
        if (*slot == 0) {
            PartData* np = (PartData*)sub_62fef6(0x50);
            if (np) {
                sub_4e1aa0(np, id, val);
                r = (int)np;
            } else {
                r = 0;
            }
            sub_474f70(slot, (void*)r);
        }
        return r;
    }
}
