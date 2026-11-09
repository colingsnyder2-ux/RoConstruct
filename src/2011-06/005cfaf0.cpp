// from server: 83% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __cdecl sub_5c4920(int);

int S::f(int a) {
    int* p = sub_5c4920(a);
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
