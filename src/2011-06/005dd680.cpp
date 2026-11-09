// from server: 65% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int get(int);
};

extern "C" int* __stdcall sub_5c9db0(int*);

int S::get(int a) {
    int* p = sub_5c9db0(&a);
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
