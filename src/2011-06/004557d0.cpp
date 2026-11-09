// from server: 80% by atomic.potato
struct C {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __stdcall sub_453a50(int*);

int C::f(int a) {
    int* p = sub_453a50((int*)((char*)a + 4));
    int v = *p;
    if (v < 0) return 0;
    int n = (int)(end - begin);
    if ((unsigned)v >= (unsigned)n) return 0;
    return begin[v];
}
