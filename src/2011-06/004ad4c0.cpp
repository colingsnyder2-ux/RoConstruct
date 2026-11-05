// from server: 83% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __cdecl sub_4abd80(int);

int S::f(int a) {
    int* p = sub_4abd80(a);
    int v = *p;
    if (v < 0) return 0;
    unsigned int n = (unsigned int)(end - begin);
    if ((unsigned int)v >= n) return 0;
    return begin[v];
}
