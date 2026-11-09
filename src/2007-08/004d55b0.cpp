// from server: 35% by colin
// roc 2007-08 004d55b0  unit: RBX::View::Part  size: 395 bytes

extern "C" {
    void* __cdecl sub_500060(unsigned int, unsigned int);
    void* __cdecl sub_500580(void*, int, unsigned int);
    void* __cdecl sub_62fef6(unsigned int);
    void __cdecl sub_630bdc(void*, int, int, void*, void*);
    void __cdecl sub_630af7(void*, int, int, void*);
}

struct PartKey {
    int a;
    int b;
    PartKey* next;
};

struct PartHashNode {
    PartKey key;
    char pad[0x14];
};

struct PartTable {
    PartHashNode** buckets;
    int mask;
};

struct PartMap {
    char pad0[8];
    void* field8;
};

struct Part {
    void* getOrCreate(int id);
};

extern PartTable g_partTable;
extern PartMap g_partMap;

void __fastcall sub_4d4640(void* self, void* unused, void* a, void* b);
int __fastcall sub_4d0030(void* self, void* unused, void* key);
void __fastcall sub_4d1ef0(void* self, void* unused, void* a, void* b);
void* __fastcall sub_4d00a0(void* self, void* unused, void* key);
void __fastcall sub_4d20e0(void* self, void* unused);
void __fastcall sub_4ee0b0(void* self, void* unused, int a, int b);
void __fastcall sub_474f70(void* self, void* unused, void* val);

void* Part::getOrCreate(int id)
{
    PartHashNode* node;
    unsigned int idx;
    void* result;
    void* entry;

    idx = (unsigned int)id % (unsigned int)g_partTable.mask;
    node = g_partTable.buckets[idx];
    while (node != 0) {
        if (node->key.a == id && node->key.b == id)
            break;
        node = (PartHashNode*)node->key.next;
    }

    if (node == 0) {
        void* mem = sub_500060(0x28, 0x10);
        mem = sub_500580(mem, 0, 0x28);
        sub_4d4640(&g_partMap, 0, &mem, &id);
        sub_4d20e0(&mem, 0);
    }

    idx = (unsigned int)id % (unsigned int)g_partTable.mask;
    node = g_partTable.buckets[idx];
    while (node != 0) {
        if (node->key.a == id && node->key.b == id)
            break;
        node = (PartHashNode*)node->key.next;
    }

    entry = (char*)node + 8;
    if (!sub_4d0030(entry, 0, &id)) {
        sub_630bdc(&id, 4, 1, (void*)0x4cff40, (void*)0x4637f0);
        sub_4d1ef0(entry, 0, &id, &id);
        sub_630af7(&id, 4, 1, (void*)0x4637f0);
    }

    result = sub_4d00a0(entry, 0, &id);
    if (*(void**)result == 0) {
        void* obj = sub_62fef6(0x50);
        if (obj != 0) {
            sub_4ee0b0(obj, 0, id, 0);
            result = obj;
        } else {
            result = 0;
        }
        sub_474f70(entry, 0, result);
    }
    return result;
}
