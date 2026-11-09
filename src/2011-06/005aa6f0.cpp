// from server: 63% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __stdcall sub_4d3040(int*);

int S::f(int a) {
    int* p = sub_4d3040(&a + 1);
    int v = *p;
    if (v < 0)
        return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2))
        return 0;
    return begin[v];
}
