// from server: 65% by atomic.potato
struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

extern "C" int* __stdcall sub_5c8c90(int*);

int S::f(int a) {
    int* p = sub_5c8c90(&a + 1);
    int idx = *p;
    if (idx < 0) return 0;
    int count = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)count) return 0;
    return begin[idx];
}
