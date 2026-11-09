// from server: 78% by atomic.potato
struct Inner {
    int* get(int* p);
};

extern "C" int* __stdcall sub_5c5430(int* p);

struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int* p);
};

int S::f(int* p) {
    int idx = *sub_5c5430(p + 1);
    if (idx < 0)
        return 0;
    unsigned int count = (unsigned int)((end - begin) >> 2);
    if ((unsigned int)idx >= count)
        return 0;
    return begin[idx];
}
