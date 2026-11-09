// from server: 63% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __stdcall sub_5c70a0(int*);

int S::get(int a) {
    int* p = sub_5c70a0(&a);
    int v = *p;
    if (v < 0)
        return 0;
    if ((unsigned)v >= (unsigned)((end - begin) >> 2))
        return 0;
    return begin[v];
}
