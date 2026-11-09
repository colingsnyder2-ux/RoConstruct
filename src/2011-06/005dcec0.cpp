// from server: 80% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int f(int*);
};

extern "C" int* __stdcall sub_5c4670(int*);

int S::f(int* p) {
    int* q = sub_5c4670(p + 1);
    int v = *q;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
