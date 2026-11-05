// from server: 65% by atomic.potato
struct W4NormalIdEnumDesc {
    char pad0[0x68];
    int* begin;
    int* end;
    int lookup(int);
};

extern "C" int* __stdcall sub_5be6b0(int*);

int W4NormalIdEnumDesc::lookup(int a) {
    int* p = sub_5be6b0(&a + 1);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v];
}
