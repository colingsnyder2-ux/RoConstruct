// from server: 80% by atomic.potato
struct S_005dd6c0 {
    char pad_0000[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern int* __stdcall sub_005ca060(int*);

int S_005dd6c0::f(int a) {
    int* p = sub_005ca060((int*)((char*)a + 4));
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
