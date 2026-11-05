// from server: 84% by atomic.potato
struct S {
    char pad[0x68];
    int* begin;
    int* end;
    int f(int*);
};

extern "C" int* __cdecl sub_5c9530(int*);

int S::f(int* p) {
    int* q = sub_5c9530(p + 1);
    int v = *q;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
