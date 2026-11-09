// from server: 40% by TrollStein
struct Part {
    char pad0[0x50];
};

struct Node {
    int key0;
    int key1;
    Node* next;
    char pad[0x14];
};

struct Map {
    char pad0[8];
    Node** buckets;
    char pad1[4];
    unsigned int bucketCount;
};

struct Inner {
    char pad0[8];
    void* ptr;
};

struct Outer {
    char pad0[8];
    Inner inner;
};

extern "C" {
    unsigned int __stdcall sub_500060(unsigned int, unsigned int);
    void* __stdcall sub_500580(void*, unsigned int, unsigned int);
    void __stdcall sub_630bdc(void*, int, int, int, int);
    void __stdcall sub_630af7(void*, int, int, int);
    void* __stdcall sub_62fef6(unsigned int);
}

extern Map g_map;
extern Outer g_outer;

void __stdcall sub_4d44a0(void*, void*);
void __stdcall sub_4d20e0(void*);
int __stdcall sub_4d0030(void*, void*);
void __stdcall sub_4d1ef0(void*, void*, void*);
void* __stdcall sub_4d00a0(void*, void*);
void __stdcall sub_474f70(void*, void*);
void* __stdcall sub_4eb0a0(void*, void*, void*);

Part* __cdecl sub_4d5420(Part* self, int a2)
{
    Node* n;
    unsigned int idx;
    void* mem;
    void* obj;
    void* result;
    void* tmp;
    int flag;
    char buf[8];

    idx = (unsigned int)a2 % g_map.bucketCount;
    n = g_map.buckets[idx];
    while (n) {
        if (n->key0 == a2 && n->key1 == a2)
            break;
        n = n->next;
    }
    if (!n) {
        mem = sub_500580((void*)sub_500060(0x10, 0x28), 0, 0x28);
        sub_4d44a0(&g_outer, &mem);
        sub_4d20e0(&mem);
    }

    idx = (unsigned int)a2 % g_map.bucketCount;
    n = g_map.buckets[idx];
    while (n) {
        if (n->key0 == a2 && n->key1 == a2)
            break;
        n = n->next;
    }

    flag = sub_4d0030(&n->next, &a2);
    if (!flag) {
        sub_630bdc(buf, 4, 1, (int)0x4cff40, (int)0x4637f0);
        sub_4d1ef0(&n->next, &a2, buf);
        sub_630af7(buf, 4, 1, (int)0x4637f0);
    }

    result = sub_4d00a0(&n->next, &a2);
    if (*(void**)result == 0) {
        obj = sub_62fef6(0x50);
        if (obj) {
            tmp = sub_4eb0a0(obj, &a2, self);
        } else {
            tmp = 0;
        }
        sub_474f70(result, tmp);
        return (Part*)tmp;
    }
    return (Part*)*(void**)result;
}
