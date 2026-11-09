// from server: 65% by atomic.potato
extern "C" int* __stdcall sub_5c78b0(int*);

struct S {
    char pad0[0x68];
    int* begin;
    int* end;
    int f(int);
};

int S::f(int a) {
    int* p = sub_5c78b0(&a + 1);
    int idx = *p;
    if (idx < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)idx >= (unsigned)count)
        return 0;
    return begin[idx];
}
