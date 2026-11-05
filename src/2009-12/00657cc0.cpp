// from server: 90% by atomic.potato
struct Inner {
    char pad[0x24];
    float x;
    float y;
    float z;
};

struct Outer {
    char pad[0x24];
    float x;
    float y;
    float z;
};

struct Base {
    char pad[0x168];
    Inner *g();
};

struct Mid {
    char pad[0x284];
    void f(Outer *dst);
};

void Inner_copy(Outer *dst, Inner *src);

void Mid::f(Outer *dst)
{
    Inner *src = ((Base *)((char *)this - 0x284))->g();
    Inner_copy(dst, src);
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
