// from server: 63% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __stdcall sub_5c7350(int*);

int S::f(int a) {
    int* p = sub_5c7350(&a + 1);
    int v = *p;
    if (v < 0) return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2)) return 0;
    return begin[v];
}
